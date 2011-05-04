/*******************************************************************************
 * Copyright (c) 2011, Jean-David Gadina <macmade@eosgarden.com>
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/
 
/* $Id$ */

/*!
 * @file        __XSMemoryDebug.c
 * @brief       Private implementation for the memory debug functions
 * @author      Jean-David Gadina <macmade@eosgarden.com>
 */

#include "__XSMemoryDebug.h"
#include "__XSLog.h"

#ifdef _WIN32

#include <DbgHelp.h>

#endif

#define __XSMEMORY_HR   "#----------------------------------------------------------------------------------------------------------------------\n"

static __XSMemoryRecord * __xs_memory_records             = NULL;
static size_t             __xs_memory_records_count       = 0;
static size_t             __xs_memory_records_alloc       = 0;
static size_t             __xs_memory_records_freed       = 0;
static size_t             __xs_memory_records_active      = 0;
static size_t             __xs_memory_total_memory        = 0;
static size_t             __xs_memory_total_memory_active = 0;
static bool               __xs_memory_fault_caught        = NO;
static size_t             __xs_memory_backtrace_size      = 0;

BOOL                      __xs_memory_debug_enabled       = YES;

#ifdef _WIN32
void                    * __xs_memory_backtrace[ 100 ];
#else
static void             * __xs_memory_backtrace[ 100 ];
#endif

void __XSMemoryDebug_InstallSignalHandlers( void )
{
    #ifdef _WIN32

    signal( SIGSEGV, __XSMemoryDebug_SignalHandler );

    #else

    struct sigaction sa1;
    struct sigaction sa2;
    
    sa1.sa_handler = __XSMemoryDebug_SignalHandler;
    sa1.sa_flags   = 0;
    sigemptyset( &sa1.sa_mask );
    
    if( sigaction( SIGSEGV, &sa1, &sa2 ) != 0 )
    {
        XSFatalError( "cannot set a handler for SIGSEGV" );
    }
    
    if( sigaction( SIGBUS, &sa1, &sa2 ) != 0 )
    {
        XSFatalError( "cannot set a handler for SIGBUS" );
    }

    #endif
}

__XSMemoryRecord * __XSMemoryDebug_GetRecord( __XSMemoryObject * ptr )
{
    size_t i;
    
    if( __xs_memory_records_alloc == 0 )
    {
        if( NULL == ( __xs_memory_records = ( __XSMemoryRecord * )calloc( sizeof( __XSMemoryRecord ), __XSMEMORY_RECORD_ALLOC ) ) )
        {
            XSFatalError( "unable to allocate memory for the memory records" );
        }
        
        __xs_memory_records_alloc = __XSMEMORY_RECORD_ALLOC;
    }
    if( __xs_memory_records_count == __xs_memory_records_alloc )
    {
        if( NULL == ( __xs_memory_records = ( __XSMemoryRecord * )realloc( __xs_memory_records, sizeof( __XSMemoryRecord ) * ( __xs_memory_records_count + __XSMEMORY_RECORD_ALLOC ) ) ) )
        {
            XSFatalError( "unable to allocate memory for the memory records" );
        }
        
        __xs_memory_records_alloc += __XSMEMORY_RECORD_ALLOC;
    }
    
    for( i = 0; i < __xs_memory_records_count; i++ )
    {
        if( __xs_memory_records[ i ].object == ptr )
        {
            return &( __xs_memory_records[ i ] );
        }
    }
    
    return NULL;
}

__XSMemoryRecord * __XSMemoryDebug_NewRecord( __XSMemoryObject * ptr, const char * file, int line, const char * func )
{
    __XSMemoryRecord * record;
    
    record = __XSMemoryDebug_GetRecord( ptr );
    
    if( record == NULL )
    {
        record = &( __xs_memory_records[ __xs_memory_records_count++ ] );
    }
    else if( record->freed == NO )
    {
        __XSMemoryDebug_Warning( "pointer beeing allocated was not freed", record );
        
        return NULL;
    }
    
    record->object    = ptr;
    record->size      = ptr->size;
    record->allocID   = ptr->allocID;
    record->classID   = ptr->classID;
    record->freed     = NO;
    record->allocFile = file;
    record->allocLine = line;
    record->allocFunc = func;
    
    strcpy( ( char * )record->hash, ( char * )ptr->hash );
    
    __xs_memory_records_active      += 1;
    __xs_memory_total_memory        += record->size;
    __xs_memory_total_memory_active += record->size;
    
    return record;
}

__XSMemoryRecord * __XSMemoryDebug_UpdateRecord( __XSMemoryObject * oldPtr, __XSMemoryObject * newPtr, const char * file, int line, const char * func )
{
    __XSMemoryRecord * record;
    
    record = __XSMemoryDebug_GetRecord( oldPtr );
    
    if( record == NULL )
    {
        __XSMemoryDebug_Warning( "pointer beeing reallocated was not allocated", record );
        
        return NULL;
    }
    
    if( __XSMemoryDebug_CheckCorruption( newPtr ) )
    {
        __XSMemoryDebug_Warning( "heap corruption", record );
        
        return NULL;
    }
    
    __xs_memory_total_memory        -= record->size;
    __xs_memory_total_memory_active -= record->size;
    
    record->object    = newPtr;
    record->size      = newPtr->size;
    record->allocID   = newPtr->allocID;
    record->classID   = newPtr->classID;
    record->freed     = NO;
    record->allocFile = file;
    record->allocLine = line;
    record->allocFunc = func;
    
    __xs_memory_total_memory        += record->size;
    __xs_memory_total_memory_active += record->size;
    
    strcpy( ( char * )record->hash, ( char * )newPtr->hash );
    
    return record;
}

__XSMemoryRecord * __XSMemoryDebug_ReleaseRecord( __XSMemoryObject * ptr, BOOL marsAsFree, const char * file, int line, const char * func )
{
    __XSMemoryRecord * record;
    
    record = __XSMemoryDebug_GetRecord( ptr );
    
    if( record == NULL )
    {
        __XSMemoryDebug_Warning( "pointer beeing freed was not allocated", NULL );
        
        return NULL;
    }
    else if( record->freed == YES )
    {
        __XSMemoryDebug_Warning( "pointer beeing freed was already freed", record );
        
        return NULL;
    }
    
    if( __XSMemoryDebug_CheckCorruption( ptr ) )
    {
        __XSMemoryDebug_Warning( "heap corruption", record );
        
        return NULL;
    }
    
    if( marsAsFree == YES )
    {
        record->freed     = YES;
        record->freeFile = file;
        record->freeLine = line;
        record->freeFunc = func;
        
        __xs_memory_records_active      -= 1;
        __xs_memory_records_freed       += 1;
        __xs_memory_total_memory_active -= record->size;
    }
    
    return record;
}

BOOL __XSMemoryDebug_CheckCorruption( __XSMemoryObject * o )
{
    char * fence1;
    char * fence2;
    
    fence1  = ( char * )o->fence + 1;
    fence2  = ( char * )o->data;
    fence2 += o->size + 1;
    
    if( strcmp( fence1, "XS_MEMDATA" ) || strcmp( fence2, "XS_MEMDATA" ) )
    {
        return YES;
    }
    
    return NO;
}

void __XSMemoryDebug_SignalHandler( int signo )
{
    if( signo == SIGSEGV )
    {
        __xs_memory_fault_caught = YES;
        
        __XSMemoryDebug_Warning( "segmentation fault - SIGSEGV", NULL );
        XSLog( "SIGSEGV - Segmentation fault: program's execution stopped" );
    }
    else if( signo == SIGBUS )
    {
        __xs_memory_fault_caught = YES;
        
        __XSMemoryDebug_Warning( "bus error - SIGBUS", NULL );
        XSLog( "SIGBUS - Bus error: program's execution stopped" );
    }
    
    pthread_exit( NULL );
    exit( EXIT_FAILURE );
}

void __XSMemoryDebug_Warning( const char * message, __XSMemoryRecord * record )
{
    
    __XSLog_Pause();
    
    printf( __XSMEMORY_HR );
    printf( "# XSFoundation - Memory warning: %s\n", message );
    
    __XSMemoryDebug_AskOption( record );
}

void __XSMemoryDebug_PrintRecord( __XSMemoryRecord * record )
{
    Str255       size;
    const char * className;
    
    memset( size,  0, 256 );
    
    if( record->size < 1000 )
    {
        sprintf( ( char * )size, "%lu bytes", record->size );
    }
    else if( record->size < 1000000 )
    {
        sprintf( ( char * )size, "%.2f KB", ( double )record->size / ( double )1000 );
    }
    else if( record->size < 1000000000 )
    {
        sprintf( ( char * )size, "%.2f MB", ( double )record->size / ( double )1000000 );
    }
    else if( record->size < 1000000000000 )
    {
        sprintf( ( char * )size, "%.2f GB", ( double )record->size / ( double )1000000000 );
    }
    else
    {
        sprintf( ( char * )size, "%.2f TB", ( double )record->size / ( double )1000000000000 );
    }
    
    className = XSRuntime_GetClassNameForClassID( record->classID );
    
    printf( __XSMEMORY_HR );
    printf
    (
        "#    \n"
        "#    Record informations:\n"
        "#    \n"
        "#    Address:               %p\n"
        "#    Size:                  %s\n"
        "#    Allocation ID:         %lu (0x%08X)\n"
        "#    Allocation hash:       %s\n"
        "#    Class ID:              %lu (0x%08X)\n"
        "#    Class name:            %s\n"
        "#    Retain count:          %lu\n"
        "#    Allocated in file:     %s\n"
        "#    Allocated at line:     %i\n"
        "#    Allocated in function: %s\n"
        "#    Freed:                 %s\n"
        "#    Freed in file:         %s\n"
        "#    Freed at line:         %i\n"
        "#    Freed in function:     %s\n"
        "# \n",
        ( void * )record->object,
        size,
        record->allocID,
        ( unsigned int )record->allocID,
        record->hash,
        record->classID,
        ( unsigned int )record->classID,
        className,
        record->object->retainCount,
        record->allocFile,
        record->allocLine,
        record->allocFunc,
        ( record->freed ) ? "yes" : "no",
        ( record->freed ) ? record->freeFile : "N/A",
        ( record->freed ) ? record->freeLine : 0,
        ( record->freed ) ? record->freeFunc : "N/A"
    );
}

void __XSMemoryDebug_PrintRecords( BOOL active, BOOL freed )
{
    size_t i;
    
    for( i = 0; i < __xs_memory_records_count; i++ )
    {
        if( __xs_memory_records[ i ].freed == YES && freed == YES )
        {
            __XSMemoryDebug_PrintRecord( &( __xs_memory_records[ i ] ) );
        }
        else if( __xs_memory_records[ i ].freed == NO && active == YES )
        {
            __XSMemoryDebug_PrintRecord( &( __xs_memory_records[ i ] ) );
        }
    }
}

void __XSMemoryDebug_PrintStatistics( void )
{
    Str255       memTotal;
    Str255       memActive;
    
    memset( memTotal,  0, 256 );
    memset( memActive, 0, 256 );
    
    if( __xs_memory_total_memory < 1000 )
    {
        sprintf( ( char * )memTotal, "%lu bytes", __xs_memory_total_memory );
    }
    else if( __xs_memory_total_memory < 1000000 )
    {
        sprintf( ( char * )memTotal, "%.2f KB", ( double )__xs_memory_total_memory / ( double )1000 );
    }
    else if( __xs_memory_total_memory < 1000000000 )
    {
        sprintf( ( char * )memTotal, "%.2f MB", ( double )__xs_memory_total_memory / ( double )1000000 );
    }
    else if( __xs_memory_total_memory < 1000000000000 )
    {
        sprintf( ( char * )memTotal, "%.2f GB", ( double )__xs_memory_total_memory / ( double )1000000000 );
    }
    else
    {
        sprintf( ( char * )memTotal, "%.2f TB", ( double )__xs_memory_total_memory / ( double )1000000000000 );
    }
    
    if( __xs_memory_total_memory_active < 1000 )
    {
        sprintf( ( char * )memActive, "%lu bytes", __xs_memory_total_memory_active );
    }
    else if( __xs_memory_total_memory_active < 1000000 )
    {
        sprintf( ( char * )memActive, "%.2f KB", ( double )__xs_memory_total_memory_active / ( double )1000 );
    }
    else if( __xs_memory_total_memory_active < 1000000000 )
    {
        sprintf( ( char * )memActive, "%.2f MB", ( double )__xs_memory_total_memory_active / ( double )1000000 );
    }
    else if( __xs_memory_total_memory_active < 1000000000000 )
    {
        sprintf( ( char * )memActive, "%.2f GB", ( double )__xs_memory_total_memory_active / ( double )1000000000 );
    }
    else
    {
        sprintf( ( char * )memActive, "%.2f TB", ( double )__xs_memory_total_memory_active / ( double )1000000000000 );
    }
    
    printf( __XSMEMORY_HR );
    printf
    (
        "#    \n"
        "#    Memory statistics:\n"
        "#    \n"
        "#    Number of memory allocations:        %lu\n"
        "#    Number of memory allocations active: %lu\n"
        "#    Number of memory allocations freed:  %lu\n"
        "#    Total memory usage:                  %s\n"
        "#    Active memory in use:                %s\n"
        "# \n",
        __xs_memory_records_count,
        __xs_memory_records_active,
        __xs_memory_records_freed,
        memTotal,
        memActive
    );
}

void __XSMemoryDebug_AskOption( __XSMemoryRecord * record )
{
    unsigned char c;
    
    #if defined( __XS_MEMORY_DEBUG_HAVE_EXECINFO_H ) || defined( _WIN32 )
    
    if( __xs_memory_backtrace_size == 0 )
    {
        __XSMemoryDebug_GetBacktrace();
    }
    
    #endif
    
    if( record != NULL )
    {
        __XSMemoryDebug_PrintRecord( record );
    }
    
    printf( __XSMEMORY_HR );
    printf
    (
        "#    \n"
        "#    Available options:\n"
        "#    \n"
        "#    c: continues the program's execution (default)\n"
        "#    q: aborts the program's execution\n"
        #if defined( __XS_MEMORY_DEBUG_HAVE_EXECINFO_H ) || defined( _WIN32 )
        "#    t: display the backtrace (function call stack)\n"
        #endif
        "#    s: prints the status of the memory allocations\n"
        "#    p: prints all memory records (active and freed)\n"
        "#    a: prints the active memory records\n"
        "#    f: prints the freed memory records\n"
    );
    
    if( record != NULL )
    {
        printf( "#    d: dump the memory record\n" );
    }
    
    printf( "# \n" );
    printf( __XSMEMORY_HR );
    printf( "\nEnter your choice: " );
    fflush( stdin );
    
    c = getchar();
    
    printf( "\n" );
    
    if( c == '\n' )
    {
        c = 'c';
    }
    else
    {
        while( getchar() != '\n' );
    }
    
    switch( c )
    {
        case 'c':
            
            printf( "Continuing the program's execution...\n" );
            __XSLog_Resume();
            return;
        
        case 'q':
            
            __xs_memory_fault_caught = YES;

            printf( "Aborting the program's execution...\n" );
            __XSLog_Resume();
            pthread_exit( NULL );
            exit( EXIT_FAILURE );
            break;
            
        case 's':
            
            __XSMemoryDebug_PrintStatistics();
            break;
            
        case 'p':
            
            __XSMemoryDebug_PrintRecords( YES, YES );
            break;
            
        case 'a':
            
            __XSMemoryDebug_PrintRecords( YES, NO );
            break;
            
        case 'f':
            
            __XSMemoryDebug_PrintRecords( NO, YES );
            break;
            
        case 'd':
            
            __XSMemoryDebug_DumpRecord( record );
            break;
        
        #if defined( __XS_MEMORY_DEBUG_HAVE_EXECINFO_H ) || defined( _WIN32 )
        
        case 't':
            
            __XSMemoryDebug_PrintBacktrace();
            break;
        
        #endif
        
        default:
            
            break;
    }
    
    __XSMemoryDebug_AskOption( record );
}

void __XSMemoryDebug_Finalize( void )
{
    size_t i;
    
    if( __xs_memory_records_active == 0 || __xs_memory_fault_caught == YES || __xs_memory_debug_enabled == NO )
    {
        return;
    }
    
    XSLog( "Memory warning: %lu objects are not freed - leaking memory!", __xs_memory_records_active );
    
    for( i = 0; i < __xs_memory_records_count; i++ )
    {
        if( __xs_memory_records[ i ].freed == NO && __xs_memory_records[ i ].allocID > 0 )
        {
            __XSMemoryDebug_Warning( "unfreed memory record at application exit point", &( __xs_memory_records[ i ] ) );
        }
    }
}

void __XSMemoryDebug_DumpRecord( __XSMemoryRecord * record )
{
    long unsigned int i;
    long unsigned int j;
    unsigned char     c;
    unsigned char   * ptr;
    size_t            size;
    
    printf( __XSMEMORY_HR );
    printf( "# \n" );
    
    ptr  = ( unsigned char * )record->object;
    size = record->size + sizeof( __XSMemoryObject ) + 12;
    
    for( i = 0; i < size; i += 25 )
    {
        printf( "#   %010lu: ", i );
        
        for( j = i; j < i + 25; j++ )
        {
            if( j < size )
            {
                printf( "%02X ", ( unsigned char )ptr[ j ] );
            }
            else
            {
                printf( "   " );
            }
        }
        
        printf( "| " );
        
        for( j = i; j < i + 25; j++ )
        {
            c = 0;
            
            if( j < size )
            {
                c = ( unsigned char )ptr[ j ];
                
                if( ( c & 0x80 ) == 0 && isprint( ( int )c ) && c != 0x20 )
                {
                    printf( "%c", c );
                    
                }
                else
                {
                    printf( "." );
                }
            }
        }
        
        printf( "\n" );
    }
    printf( "# \n" );
}

#if defined( __XS_MEMORY_DEBUG_HAVE_EXECINFO_H ) || defined( _WIN32 )

void __XSMemoryDebug_GetBacktrace( void )
{
    #ifdef _WIN32

    SymInitialize( GetCurrentProcess(), NULL, TRUE );

    __xs_memory_backtrace_size = CaptureStackBackTrace( 0, 100, __xs_memory_backtrace, NULL );

    #else

    __xs_memory_backtrace_size = backtrace( __xs_memory_backtrace, 100 );

    #endif
}

void __XSMemoryDebug_PrintBacktrace( void )
{
    size_t  i;

    #ifdef _WIN32
    SYMBOL_INFO * symbol;
    HANDLE        process;
    #else
    char ** symbols;
    #endif

    printf( __XSMEMORY_HR );
    printf( "# \n" );
    printf( "#   Displaying %u stack frames:\n", ( int )( __xs_memory_backtrace_size - 5 ) );
    printf( "# \n" );

    #ifdef _WIN32
    
    process            = GetCurrentProcess();
    symbol             = ( SYMBOL_INFO * )calloc( sizeof( SYMBOL_INFO ) + 256 * sizeof( char ), 1 );
    symbol->MaxNameLen = 255;
    symbol->SizeOfStruct = sizeof( SYMBOL_INFO );

    for( i = 5; i < __xs_memory_backtrace_size; i++ )
    {
        SymFromAddr( process, ( DWORD64 )( __xs_memory_backtrace[ i ] ), 0, symbol );
        printf( "#   %02u: 0x%016x %s\n", i, ( unsigned int )symbol->Address, symbol->Name );
    }

    free( symbol );

    #else
    
    symbols = backtrace_symbols( __xs_memory_backtrace, __xs_memory_backtrace_size );
    
    for( i = 5; i < __xs_memory_backtrace_size; i++ )
    {
        printf( "#   %s\n", symbols[ i ] );
    }
    
    free( symbols );

    #endif
    
    printf( "# \n" );
}

#endif

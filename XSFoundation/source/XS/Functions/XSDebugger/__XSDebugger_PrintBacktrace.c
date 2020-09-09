/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2020 Jean-David Gadina - www.xs-labs.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 ******************************************************************************/

/*!
 * @file        __XSDebugger_PrintBacktrace.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSDebugger_PrintBacktrace
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSDebugger.h>

#ifdef _WIN32
#include <DbgHelp.h>
#endif

void __XSDebugger_PrintBacktrace( void )
{
    void ** bt;
    
    #ifndef DEBUG
    
    ( void )bt;
    
    return;
    
    #else
    
    fprintf
    (
        stderr,
        "\n"
        "#-------------------------------------------------------------------------------\n"
    );
    
    bt = calloc( sizeof( void * ), 100 );
    
    if( bt == NULL )
    {
        goto error;
    }
    
    #if defined( _WIN32 )
    
    {
        SYMBOL_INFO * symbol;
        HANDLE        process;
        int           n;
        int           i;
        
        process = GetCurrentProcess();
        
        SymInitialize( process, NULL, TRUE );

        n      = CaptureStackBackTrace( 0, 100, bt, NULL );
        symbol = calloc( sizeof( SYMBOL_INFO ) + 256, 1 );
        
        if( symbol == NULL )
        {
            goto error;
        }
        
        symbol->MaxNameLen = 255;
        symbol->SizeOfStruct = sizeof( SYMBOL_INFO );

        for( i = 1; i < n; i++ )
        {
            SymFromAddr( process, ( DWORD64 )( bt[ i ] ), 0, symbol );
            printf( "#   %02u: 0x%016x %s\n", i, ( unsigned int )symbol->Address, symbol->Name );
        }

        free( symbol );
    }
    
    #elif defined( __XS_DEBUGGER_HAVE_EXECINFO_H )
    
    {
        char ** syms;
        int     i;
        int     n;
        
        n    = backtrace( bt, 100 );
        syms = backtrace_symbols( bt, n );
        
        if( syms == NULL )
        {
            goto error;
        }
        
        for( i = 1; i < n; i++ )
        {
            printf( "# %s\n", syms[ i ] );
        }
        
        free( syms );
    }
    
    goto end;
    
    #else
    
    goto error;
    
    #endif
    
    error:
        
        fprintf( stderr, "# Error: backtrace is not available\n" );
    
    goto end;
    
    end:
    
    free( bt );
    
    fprintf
    (
        stderr,
        "#-------------------------------------------------------------------------------\n"
        "\n"
    );
    
    #endif
}

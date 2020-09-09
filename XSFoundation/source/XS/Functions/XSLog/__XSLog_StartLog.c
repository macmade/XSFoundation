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
 * @file        __XSLog_StartLog.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definitions for __XSLog_StartLog
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSLog.h>
#include <XS/__private/Functions/XSRuntime.h>

void __XSLog_StartLog( XSLogLevel level, const char * file, int line, const char * func )
{
    
    const char * levelName;
    const char * filename;
    char         date[ 255 ];
    XSUInt64     milliseconds;
    
    if( XSAtomic_CompareAndSwapInteger( XSInitStatusNotInited, XSInitStatusInitializing, &__XSLog_MutexStatus ) )
    {
        XSThreading_MutexCreate( &__XSLog_Mutex );
        
        while( XSAtomic_CompareAndSwapInteger( XSInitStatusInitializing, XSInitStatusInited, &__XSLog_MutexStatus ) == false );
        
        XSRuntime_RegisterFinalizer( __XSLog_Exit );
    }
    
    while( XSAtomic_CompareAndSwapInteger( XSInitStatusInited, XSInitStatusInited, &__XSLog_MutexStatus ) == false );
    
    levelName = NULL;
    
    if( level == XSLogLevelFatal     ) { levelName = "Fatal";   }
    if( level == XSLogLevelError     ) { levelName = "Error";   }
    if( level == XSLogLevelWarning   ) { levelName = "Warning"; }
    if( level == XSLogLevelNotice    ) { levelName = "Notice";  }
    if( level == XSLogLevelDebug     ) { levelName = "Debug";   }
    
    XSThreading_MutexLock( &__XSLog_Mutex );
    
    #ifdef _WIN32
    
    {
        time_t     t;
        struct tm  now;
        SYSTEMTIME time;
        
        time( &t );
        GetSystemTime( &time );
        localtime_s( &now, &t );
        strftime( ( char * )date, 255, "%Y-%m-%d %H:%M:%S", &now );
        
        milliseconds = time.wMilliseconds;
    }
    
    #else
    
    {
        time_t         t;
        struct tm    * now;
        struct timeval tv;
        
        t   = time( NULL );
        now = localtime( &t );
        
        gettimeofday( &tv, NULL );
        strftime( ( char * )date, 255, "%Y-%m-%d %H:%M:%S", now );
        
        milliseconds = ( XSUInt64 )( tv.tv_usec / 1000 );
    }
    
    #endif
    
    #ifdef DEBUG
    
    #ifdef _WIN32
    filename = strrchr( file, '\' );
    #else
    filename = strrchr( file, '/' );
    #endif
    
    filename = ( filename == NULL ) ? file : filename + 1;
    
    if( strlen( filename ) == 0 )
    {
        filename = "unknown";
    }
    
    if( strlen( func ) == 0 )
    {
        func = "unknown";
    }
    
    if( levelName != NULL )
    {
        fprintf
        (
            stderr,
            "%s.%lu %s[%lu:%lX] <%s:%s:%i>: %s - ",
            date,
            ( unsigned long )milliseconds,
            XSProcess_GetProcessName(),
            ( unsigned long )XSProcess_GetProcessID(),
            ( unsigned long )XSThreading_GetCurrentThreadID(),
            func,
            filename,
            line,
            levelName
        );
    }
    else
    {
        fprintf
        (
            stderr,
            "%s.%lu %s[%lu:%lX] <%s:%s:%i>: ",
            date,
            ( unsigned long )milliseconds,
            XSProcess_GetProcessName(),
            ( unsigned long )XSProcess_GetProcessID(),
            ( unsigned long )XSThreading_GetCurrentThreadID(),
            func,
            filename,
            line
        );
    }
    
    #else
    
    ( void )file;
    ( void )filename;
    ( void )line;
    ( void )func;
    
    if( levelName != NULL )
    {
        fprintf
        (
            stderr,
            "%s.%lu %s[%lu:%lX]: %s - ",
            date,
            ( unsigned long )milliseconds,
            XSProcess_GetProcessName(),
            ( unsigned long )XSProcess_GetProcessID(),
            ( unsigned long )XSThreading_GetCurrentThreadID(),
            levelName
        );
    }
    else
    {
        fprintf
        (
            stderr,
            "%s.%lu %s[%lu:%lX]: ",
            date,
            ( unsigned long )milliseconds,
            XSProcess_GetProcessName(),
            ( unsigned long )XSProcess_GetProcessID(),
            ( unsigned long )XSThreading_GetCurrentThreadID()
        );
    }
    
    #endif
}

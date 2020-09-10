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
 * @file        XSVLogWithInfos.c
 * @copyright   (c) 202o - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definitions for XSVLogWithInfos
 */

#include <XS/XS.h>
#include <XS/Private/Functions/Log.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <sys/time.h>
#endif

void XSVLogWithInfos( XSLogLevel level, const char * file, int line, const char * func, const char * fmt, va_list args )
{
    const char * levelName;
    const char * filename;
    const char * process;
    uint64_t     processID;
    uint64_t     threadID;
    uint64_t     milliseconds;
    char         date[ 255 ];

    if( ( XSAtomicRead64( &XSLogCurrentLevel ) & level ) == 0 )
    {
        return;
    }

    process   = XSGetCurrentProcessName();
    processID = XSGetCurrentThreadID();
    threadID  = XSGetCurrentThreadID();
    levelName = NULL;

#if defined( DEBUG )

    filename = strrchr( file, '\\' );

#elif defined( DEBUG )

    filename = strrchr( file, '/' );

#else

    ( void )file;

    filename = NULL;

#endif

#ifdef DEBUG

    if( strlen( filename ) == 0 )
    {
        filename = "unknown";
    }

#endif

    if( strlen( func ) == 0 )
    {
        func = "unknown";
    }

    if( level == XSLogLevelFatal )
    {
        levelName = "Fatal";
    }
    if( level == XSLogLevelError )
    {
        levelName = "Error";
    }
    if( level == XSLogLevelWarning )
    {
        levelName = "Warning";
    }
    if( level == XSLogLevelNotice )
    {
        levelName = "Notice";
    }
    if( level == XSLogLevelDebug )
    {
        levelName = "Debug";
    }

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
        struct tm *    now;
        struct timeval tv;

        t   = time( NULL );
        now = localtime( &t );

        gettimeofday( &tv, NULL );
        strftime( ( char * )date, 255, "%Y-%m-%d %H:%M:%S", now );

        milliseconds = ( uint64_t )( tv.tv_usec / 1000 );
    }

#endif

    XSSpinLockLock( &XSLogLock );

    while( XSAtomicRead64( &XSLogIsPaused ) == 1 )
    {}

    if( levelName != NULL && filename != NULL )
    {
        fprintf(
            stderr,
            "%s.%llu %s[%llu:%llX] <%s:%s:%i>: %s - ",
            date,
            milliseconds,
            process,
            processID,
            threadID,
            func,
            filename,
            line,
            levelName );
    }
    else if( filename != NULL )
    {
        fprintf(
            stderr,
            "%s.%llu %s[%llu:%llX] <%s:%s:%i>: ",
            date,
            milliseconds,
            process,
            processID,
            threadID,
            func,
            filename,
            line );
    }
    else if( levelName != NULL )
    {
        fprintf(
            stderr,
            "%s.%llu %s[%llu:%llX]: %s - ",
            date,
            milliseconds,
            process,
            processID,
            threadID,
            levelName );
    }
    else
    {
        fprintf(
            stderr,
            "%s.%llu %s[%llu:%llX]: ",
            date,
            milliseconds,
            process,
            processID,
            threadID );
    }

    vfprintf( stderr, fmt, args );
    fprintf( stderr, "\n" );

    XSSpinLockUnlock( &XSLogLock );
}

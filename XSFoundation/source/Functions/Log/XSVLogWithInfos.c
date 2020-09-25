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
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void XSVLogWithInfos( XSLogLevel level, const char * file, int line, const char * func, const char * fmt, va_list args )
{
    XSLogInfo info;
    bool      hasLevel;
    bool      hasFile;
    bool      hasFunc;

    if( ( XSAtomicRead64( &XSLogCurrentLevel ) & level ) == 0 )
    {
        return;
    }

    info = XSLogGetInfo( level, file, line, func );

    XSSpinLockLock( &XSLogLock );

    while( XSAtomicRead64( &XSLogIsPaused ) == 1 )
    {}

    hasLevel = info.level != NULL;
    hasFile  = strlen( info.file ) > 0;
    hasFunc  = strlen( info.func ) > 0;

    if( hasLevel && hasFile && hasFunc )
    {
        fprintf(
            stderr,
            "%s.%llu %s[%llu:%llX] <%s:%s:%i>: %s - ",
            info.date,
            ( unsigned long long )( info.milliseconds ),
            info.process,
            ( unsigned long long )( info.processID ),
            ( unsigned long long )( info.threadID ),
            info.func,
            info.file,
            info.line,
            info.level );
    }
    else if( hasFile && hasFunc )
    {
        fprintf(
            stderr,
            "%s.%llu %s[%llu:%llX] <%s:%s:%i>: ",
            info.date,
            ( unsigned long long )( info.milliseconds ),
            info.process,
            ( unsigned long long )( info.processID ),
            ( unsigned long long )( info.threadID ),
            info.func,
            info.file,
            info.line );
    }
    else if( hasLevel )
    {
        fprintf(
            stderr,
            "%s.%llu %s[%llu:%llX]: %s - ",
            info.date,
            ( unsigned long long )( info.milliseconds ),
            info.process,
            ( unsigned long long )( info.processID ),
            ( unsigned long long )( info.threadID ),
            info.level );
    }
    else
    {
        fprintf(
            stderr,
            "%s.%llu %s[%llu:%llX]: ",
            info.date,
            ( unsigned long long )( info.milliseconds ),
            info.process,
            ( unsigned long long )( info.processID ),
            ( unsigned long long )( info.threadID ) );
    }

    vfprintf( stderr, fmt, args );
    fprintf( stderr, "\n" );

    XSSpinLockUnlock( &XSLogLock );
}

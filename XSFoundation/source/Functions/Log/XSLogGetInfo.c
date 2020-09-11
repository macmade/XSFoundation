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
 * @file        XSLogGetInfo.c
 * @copyright   (c) 202o - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definitions for XSLogGetInfo
 */

#include <XS/XS.h>
#include <XS/Private/Functions/Log.h>
#include <string.h>

XSLogInfo XSLogGetInfo( XSLogLevel level, const char * file, int line, const char * func )
{
    XSLogInfo    info;
    const char * filename;

    memset( &info, 0, sizeof( XSLogInfo ) );

    info.process   = XSGetCurrentProcessName();
    info.processID = XSGetCurrentThreadID();
    info.threadID  = XSGetCurrentThreadID();
    info.level     = NULL;
    info.line      = ( line > 0 ) ? ( unsigned int )line : 0;

    switch( level )
    {
        case XSLogLevelAll: info.level = NULL; break;
        case XSLogLevelInfo: info.level = NULL; break;
        case XSLogLevelFatal: info.level = "Fatal"; break;
        case XSLogLevelError: info.level = "Error"; break;
        case XSLogLevelWarning: info.level = "Warning"; break;
        case XSLogLevelNotice: info.level = "Notice"; break;
        case XSLogLevelDebug: info.level = "Debug"; break;
    }

    XSLogGetCurrentDateTime( info.date, sizeof( info.date ), &( info.milliseconds ) );

#ifdef DEBUG

    if( func != NULL )
    {
        strncpy( info.func, func, sizeof( info.func ) - 1 );
    }
    else
    {
        strncpy( info.func, "unknown", sizeof( info.func ) - 1 );
    }

    if( file != NULL )
    {
        filename = strrchr( file, XS_PATH_SEPARATOR );
    }
    else
    {
        filename = NULL;
    }

    if( filename != NULL )
    {
        strncpy( info.file, filename + 1, sizeof( info.file ) - 1 );
    }
    else
    {
        strncpy( info.file, "unknown", sizeof( info.file ) - 1 );
    }

#else

    ( void )file;
    ( void )filename;
    ( void )func;
    ( void )line;

#endif

    return info;
}

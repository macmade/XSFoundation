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
 * @file        XSLogGetCurrentDateTime.c
 * @copyright   (c) 202o - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definitions for XSLogGetCurrentDateTime
 */

#include <XS/XS.h>
#include <XS/Private/Functions/Log.h>
#include <time.h>
#include <string.h>

#ifdef _WIN32

#pragma warning( push )
#pragma warning( disable: 5105 )
#include <Windows.h>
#pragma warning( pop )

void XSLogGetCurrentDateTime( char * buf, size_t size, uint64_t * milliseconds )
{
    time_t     t;
    struct tm  now;
    SYSTEMTIME st;

    if( buf == NULL || size == 0 )
    {
        return;
    }

    memset( buf, 0, size );
    time( &t );
    GetSystemTime( &st );
    localtime_s( &now, &t );
    strftime( buf, size, "%Y-%m-%d %H:%M:%S", &now );

    if( milliseconds != NULL )
    {
        *( milliseconds ) = st.wMilliseconds;
    }
}

#else

#include <sys/time.h>

void XSLogGetCurrentDateTime( char * buf, size_t size, uint64_t * milliseconds )
{
    time_t         t;
    struct tm *    now;
    struct timeval tv;

    if( buf == NULL || size == 0 )
    {
        return;
    }

    memset( buf, 0, size );

    t   = time( NULL );
    now = localtime( &t );

    gettimeofday( &tv, NULL );
    strftime( buf, size, "%Y-%m-%d %H:%M:%S", now );

    if( milliseconds != NULL )
    {
        *( milliseconds ) = ( uint64_t )( tv.tv_usec / 1000 );
    }
}

#endif

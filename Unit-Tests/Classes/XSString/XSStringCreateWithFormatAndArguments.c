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
 * @file        XSStringCreateWithFormatAndArguments.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>
#include <stdarg.h>

static XSStringRef CreateString( const char * fmt, ... )
{
    XSStringRef str;
    va_list     ap;

    va_start( ap, fmt );

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-nonliteral"
#endif

    str = XSStringCreateWithFormatAndArguments( fmt, ap );

#ifdef __clang__
#pragma clang diagnostic pop
#endif

    va_end( ap );

    return str;
}

Test( XSString, XSStringCreateWithFormatAndArguments )
{
    XSStringRef str1 = CreateString( NULL );
    XSStringRef str2 = CreateString( "" );
    XSStringRef str3 = CreateString( "%s %i", "hello, world", 42 );

    AssertTrue( str1 != NULL );
    AssertTrue( str2 != NULL );
    AssertTrue( str3 != NULL );

    AssertEqual( XSStringGetLength( str1 ), 0 );
    AssertEqual( XSStringGetLength( str2 ), 0 );
    AssertEqual( XSStringGetLength( str3 ), 15 );

    AssertStringEqual( XSStringGetCString( str1 ), "" );
    AssertStringEqual( XSStringGetCString( str2 ), "" );
    AssertStringEqual( XSStringGetCString( str3 ), "hello, world 42" );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( str3 );
}

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
 * @file        XSStringGetCString.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSString, XSStringGetCString )
{
    const char * cp1  = NULL;
    const char * cp2  = "";
    const char * cp3  = "hello, world";
    XSStringRef  str1 = XSStringCreateWithCString( cp1 );
    XSStringRef  str2 = XSStringCreateWithCString( cp2 );
    XSStringRef  str3 = XSStringCreateWithCString( cp3 );

    AssertTrue( XSStringGetCString( NULL ) == NULL );
    AssertTrue( XSStringGetCString( str1 ) != NULL );
    AssertTrue( XSStringGetCString( str2 ) != NULL );
    AssertTrue( XSStringGetCString( str3 ) != NULL );

    AssertTrue( XSStringGetCString( str2 ) != cp2 );
    AssertTrue( XSStringGetCString( str3 ) != cp3 );

    AssertStringEqual( XSStringGetCString( str1 ), "" );
    AssertStringEqual( XSStringGetCString( str2 ), "" );
    AssertStringEqual( XSStringGetCString( str3 ), "hello, world" );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( str3 );
}

Test( XSString, XSStringGetCString_LongString )
{
    const char * cp1  = NULL;
    const char * cp2  = "";
    const char * cp3  = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.";
    XSStringRef  str1 = XSStringCreateWithCString( cp1 );
    XSStringRef  str2 = XSStringCreateWithCString( cp2 );
    XSStringRef  str3 = XSStringCreateWithCString( cp3 );

    AssertTrue( XSStringGetCString( NULL ) == NULL );
    AssertTrue( XSStringGetCString( str1 ) != NULL );
    AssertTrue( XSStringGetCString( str2 ) != NULL );
    AssertTrue( XSStringGetCString( str3 ) != NULL );

    AssertTrue( XSStringGetCString( str2 ) != cp2 );
    AssertTrue( XSStringGetCString( str3 ) != cp3 );

    AssertStringEqual( XSStringGetCString( str1 ), "" );
    AssertStringEqual( XSStringGetCString( str2 ), "" );
    AssertStringEqual( XSStringGetCString( str3 ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( str3 );
}

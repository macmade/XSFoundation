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
 * @file        XSStringWithCStringNoCopy.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSString, XSStringWithCStringNoCopy )
{
    const char *         cp1  = "";
    const char *         cp2  = "hello, world";
    XSAutoreleasePoolRef ap   = XSAutoreleasePoolCreate();
    XSStringRef          str1 = XSStringWithCStringNoCopy( cp1 );
    XSStringRef          str2 = XSStringWithCStringNoCopy( cp2 );
    XSStringRef          str3 = XSStringWithCStringNoCopy( NULL );

    AssertTrue( str1 != NULL );
    AssertTrue( str2 != NULL );
    AssertTrue( str3 != NULL );

    AssertEqual( XSStringGetLength( str1 ), 0u );
    AssertEqual( XSStringGetLength( str2 ), 12u );
    AssertEqual( XSStringGetLength( str3 ), 0u );

    AssertStringEqual( XSStringGetCString( str2 ), "hello, world" );

    AssertTrue( XSStringGetCString( str1 ) == cp1 );
    AssertTrue( XSStringGetCString( str2 ) == cp2 );
    AssertTrue( XSStringGetCString( str3 ) != NULL );

    XSRetain( str1 );
    XSRetain( str2 );
    XSRetain( str3 );

    AssertEqual( XSGetRetainCount( str1 ), 2 );
    AssertEqual( XSGetRetainCount( str2 ), 2 );
    AssertEqual( XSGetRetainCount( str3 ), 2 );

    XSRelease( ap );

    AssertEqual( XSGetRetainCount( str1 ), 1 );
    AssertEqual( XSGetRetainCount( str2 ), 1 );
    AssertEqual( XSGetRetainCount( str3 ), 1 );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( str3 );
}

Test( XSString, XSStringWithCStringNoCopy_LongString )
{
    const char *         cp1  = "";
    const char *         cp2  = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.";
    XSAutoreleasePoolRef ap   = XSAutoreleasePoolCreate();
    XSStringRef          str1 = XSStringWithCStringNoCopy( cp1 );
    XSStringRef          str2 = XSStringWithCStringNoCopy( cp2 );
    XSStringRef          str3 = XSStringWithCStringNoCopy( NULL );

    AssertTrue( str1 != NULL );
    AssertTrue( str2 != NULL );
    AssertTrue( str3 != NULL );

    AssertEqual( XSStringGetLength( str1 ), 0u );
    AssertEqual( XSStringGetLength( str2 ), 144u );
    AssertEqual( XSStringGetLength( str3 ), 0u );

    AssertStringEqual( XSStringGetCString( str2 ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );

    AssertTrue( XSStringGetCString( str1 ) == cp1 );
    AssertTrue( XSStringGetCString( str2 ) == cp2 );
    AssertTrue( XSStringGetCString( str3 ) != NULL );

    XSRetain( str1 );
    XSRetain( str2 );
    XSRetain( str3 );

    AssertEqual( XSGetRetainCount( str1 ), 2 );
    AssertEqual( XSGetRetainCount( str2 ), 2 );
    AssertEqual( XSGetRetainCount( str3 ), 2 );

    XSRelease( ap );

    AssertEqual( XSGetRetainCount( str1 ), 1 );
    AssertEqual( XSGetRetainCount( str2 ), 1 );
    AssertEqual( XSGetRetainCount( str3 ), 1 );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( str3 );
}

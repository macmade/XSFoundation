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
 * @file        XSStringCreateMutableCopy.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSMutableString, XSStringCreateMutableCopy )
{
    XSStringRef        str1  = XSStringCreateWithCString( NULL );
    XSStringRef        str2  = XSStringCreateWithCString( "" );
    XSStringRef        str3  = XSStringCreateWithCString( "hello, world" );
    XSMutableStringRef copy1 = XSStringCreateMutableCopy( str1 );
    XSMutableStringRef copy2 = XSStringCreateMutableCopy( str2 );
    XSMutableStringRef copy3 = XSStringCreateMutableCopy( str3 );
    XSMutableStringRef copy4 = XSStringCreateMutableCopy( NULL );

    AssertTrue( copy1 != NULL );
    AssertTrue( copy2 != NULL );
    AssertTrue( copy3 != NULL );
    AssertTrue( copy4 == NULL );

    AssertTrue( XSStringIsMutable( copy1 ) );
    AssertTrue( XSStringIsMutable( copy2 ) );
    AssertTrue( XSStringIsMutable( copy3 ) );

    AssertEqual( XSStringGetLength( copy1 ), 0 );
    AssertEqual( XSStringGetLength( copy2 ), 0 );
    AssertEqual( XSStringGetLength( copy3 ), 12 );

    AssertStringEqual( XSStringGetCString( copy1 ), "" );
    AssertStringEqual( XSStringGetCString( copy2 ), "" );
    AssertStringEqual( XSStringGetCString( copy3 ), "hello, world" );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( str3 );
    XSRelease( copy1 );

    XSRelease( copy2 );
    XSRelease( copy3 );
}

Test( XSMutableString, XSStringCreateMutableCopy_LongString )
{
    XSStringRef        str1  = XSStringCreateWithCString( NULL );
    XSStringRef        str2  = XSStringCreateWithCString( "" );
    XSStringRef        str3  = XSStringCreateWithCString( "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );
    XSMutableStringRef copy1 = XSStringCreateMutableCopy( str1 );
    XSMutableStringRef copy2 = XSStringCreateMutableCopy( str2 );
    XSMutableStringRef copy3 = XSStringCreateMutableCopy( str3 );
    XSMutableStringRef copy4 = XSStringCreateMutableCopy( NULL );

    AssertTrue( copy1 != NULL );
    AssertTrue( copy2 != NULL );
    AssertTrue( copy3 != NULL );
    AssertTrue( copy4 == NULL );

    AssertTrue( XSStringIsMutable( copy1 ) );
    AssertTrue( XSStringIsMutable( copy2 ) );
    AssertTrue( XSStringIsMutable( copy3 ) );

    AssertEqual( XSStringGetLength( copy1 ), 0 );
    AssertEqual( XSStringGetLength( copy2 ), 0 );
    AssertEqual( XSStringGetLength( copy3 ), 12 );

    AssertStringEqual( XSStringGetCString( copy1 ), "" );
    AssertStringEqual( XSStringGetCString( copy2 ), "" );
    AssertStringEqual( XSStringGetCString( copy3 ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( str3 );
    XSRelease( copy1 );

    XSRelease( copy2 );
    XSRelease( copy3 );
}

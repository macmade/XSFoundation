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
 * @file        XSStringCreateWithFormat.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSString, XSStringCreateWithFormat )
{
    XSStringRef str1 = XSStringCreateWithFormat( NULL );
    XSStringRef str2 = XSStringCreateWithFormat( "" );
    XSStringRef str3 = XSStringCreateWithFormat( "%s %i", "hello, world", 42 );

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

Test( XSString, XSStringCreateWithFormat_LongString )
{
    XSStringRef str1 = XSStringCreateWithFormat( NULL );
    XSStringRef str2 = XSStringCreateWithFormat( "" );
    XSStringRef str3 = XSStringCreateWithFormat( "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. %s %i", "hello, world", 42 );

    AssertTrue( str1 != NULL );
    AssertTrue( str2 != NULL );
    AssertTrue( str3 != NULL );

    AssertEqual( XSStringGetLength( str1 ), 0 );
    AssertEqual( XSStringGetLength( str2 ), 0 );
    AssertEqual( XSStringGetLength( str3 ), 160 );

    AssertStringEqual( XSStringGetCString( str1 ), "" );
    AssertStringEqual( XSStringGetCString( str2 ), "" );
    AssertStringEqual( XSStringGetCString( str3 ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. hello, world 42" );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( str3 );
}

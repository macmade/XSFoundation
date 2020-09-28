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
 * @file        XSStringContainsString.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSString, XSStringContainsString )
{
    XSStringRef str1    = XSStringCreateWithCString( "" );
    XSStringRef str2    = XSStringCreateWithCString( "hello, world" );
    XSStringRef search1 = XSStringCreateWithCString( "" );
    XSStringRef search2 = XSStringCreateWithCString( "hello" );
    XSStringRef search3 = XSStringCreateWithCString( "world" );
    XSStringRef search4 = XSStringCreateWithCString( "lo, wo" );
    XSStringRef search5 = XSStringCreateWithCString( "," );
    XSStringRef search6 = XSStringCreateWithCString( "universe" );
    XSStringRef search7 = XSStringCreateWithCString( "hello, world & universe" );

    AssertFalse( XSStringContainsString( NULL, NULL ) );
    AssertFalse( XSStringContainsString( str1, NULL ) );
    AssertFalse( XSStringContainsString( NULL, search1 ) );

    AssertFalse( XSStringContainsString( str1, search1 ) );
    AssertFalse( XSStringContainsString( str2, search1 ) );

    AssertTrue( XSStringContainsString( str2, search2 ) );
    AssertTrue( XSStringContainsString( str2, search3 ) );
    AssertTrue( XSStringContainsString( str2, search4 ) );
    AssertTrue( XSStringContainsString( str2, search5 ) );
    AssertFalse( XSStringContainsString( str2, search6 ) );
    AssertFalse( XSStringContainsString( str2, search7 ) );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( search1 );
    XSRelease( search2 );
    XSRelease( search3 );
    XSRelease( search3 );
    XSRelease( search4 );
    XSRelease( search5 );
    XSRelease( search6 );
    XSRelease( search7 );
}

Test( XSString, XSStringContainsString_LongString )
{
    XSStringRef str1    = XSStringCreateWithCString( "" );
    XSStringRef str2    = XSStringCreateWithCString( "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );
    XSStringRef search1 = XSStringCreateWithCString( "" );
    XSStringRef search2 = XSStringCreateWithCString( "Lorem" );
    XSStringRef search3 = XSStringCreateWithCString( "volutpat." );
    XSStringRef search4 = XSStringCreateWithCString( "amet, consectetuer" );
    XSStringRef search5 = XSStringCreateWithCString( "," );
    XSStringRef search6 = XSStringCreateWithCString( "Ut wisi enim." );
    XSStringRef search7 = XSStringCreateWithCString( "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat. Ut wisi enim." );
    XSStringRef search8 = XSStringCreateWithCString( "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );

    AssertFalse( XSStringContainsString( NULL, NULL ) );
    AssertFalse( XSStringContainsString( str1, NULL ) );
    AssertFalse( XSStringContainsString( NULL, search1 ) );

    AssertFalse( XSStringContainsString( str1, search1 ) );
    AssertFalse( XSStringContainsString( str2, search1 ) );

    AssertTrue( XSStringContainsString( str2, search2 ) );
    AssertTrue( XSStringContainsString( str2, search3 ) );
    AssertTrue( XSStringContainsString( str2, search4 ) );
    AssertTrue( XSStringContainsString( str2, search5 ) );
    AssertFalse( XSStringContainsString( str2, search6 ) );
    AssertFalse( XSStringContainsString( str2, search7 ) );
    AssertTrue( XSStringContainsString( str2, search8 ) );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( search1 );
    XSRelease( search2 );
    XSRelease( search3 );
    XSRelease( search3 );
    XSRelease( search4 );
    XSRelease( search5 );
    XSRelease( search6 );
    XSRelease( search7 );
    XSRelease( search8 );
}

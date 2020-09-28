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
 * @file        XSStringHasPrefix.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSString, XSStringHasPrefix )
{
    XSStringRef str1  = XSStringCreateWithCString( "" );
    XSStringRef str2  = XSStringCreateWithCString( "hello, world" );
    XSStringRef pref1 = XSStringCreateWithCString( "" );
    XSStringRef pref2 = XSStringCreateWithCString( "hello" );
    XSStringRef pref3 = XSStringCreateWithCString( "world" );

    AssertFalse( XSStringHasPrefix( NULL, NULL ) );
    AssertFalse( XSStringHasPrefix( str1, NULL ) );
    AssertFalse( XSStringHasPrefix( NULL, pref1 ) );

    AssertFalse( XSStringHasPrefix( str1, pref1 ) );
    AssertFalse( XSStringHasPrefix( str2, pref1 ) );

    AssertTrue( XSStringHasPrefix( str2, pref2 ) );
    AssertFalse( XSStringHasPrefix( str2, pref3 ) );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( pref1 );
    XSRelease( pref2 );
    XSRelease( pref3 );
}

Test( XSString, XSStringHasPrefix_LongString )
{
    XSStringRef str1  = XSStringCreateWithCString( "" );
    XSStringRef str2  = XSStringCreateWithCString( "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );
    XSStringRef pref1 = XSStringCreateWithCString( "" );
    XSStringRef pref2 = XSStringCreateWithCString( "Lorem" );
    XSStringRef pref3 = XSStringCreateWithCString( "ipusm" );

    AssertFalse( XSStringHasPrefix( NULL, NULL ) );
    AssertFalse( XSStringHasPrefix( str1, NULL ) );
    AssertFalse( XSStringHasPrefix( NULL, pref1 ) );

    AssertFalse( XSStringHasPrefix( str1, pref1 ) );
    AssertFalse( XSStringHasPrefix( str2, pref1 ) );

    AssertTrue( XSStringHasPrefix( str2, pref2 ) );
    AssertFalse( XSStringHasPrefix( str2, pref3 ) );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( pref1 );
    XSRelease( pref2 );
    XSRelease( pref3 );
}

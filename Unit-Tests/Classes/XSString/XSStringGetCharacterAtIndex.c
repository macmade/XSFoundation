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
 * @file        XSStringGetCharacterAtIndex.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSString, XSStringGetCharacterAtIndex )
{
    XSStringRef str1 = XSStringCreateWithCString( "" );
    XSStringRef str2 = XSStringCreateWithCString( "hello, world" );

    AssertEqual( XSStringGetCharacterAtIndex( NULL, 0 ), 0 );
    AssertEqual( XSStringGetCharacterAtIndex( NULL, 1 ), 0 );
    AssertEqual( XSStringGetCharacterAtIndex( NULL, 42 ), 0 );

    AssertEqual( XSStringGetCharacterAtIndex( str1, 0 ), 0 );
    AssertEqual( XSStringGetCharacterAtIndex( str1, 1 ), 0 );
    AssertEqual( XSStringGetCharacterAtIndex( str1, 42 ), 0 );

    AssertEqual( XSStringGetCharacterAtIndex( str2, 0 ), 'h' );
    AssertEqual( XSStringGetCharacterAtIndex( str2, 1 ), 'e' );
    AssertEqual( XSStringGetCharacterAtIndex( str2, 11 ), 'd' );
    AssertEqual( XSStringGetCharacterAtIndex( str2, 12 ), 0 );
    AssertEqual( XSStringGetCharacterAtIndex( str2, 42 ), 0 );

    XSRelease( str1 );
    XSRelease( str2 );
}

Test( XSString, XSStringGetCharacterAtIndex_LongString )
{
    XSStringRef str1 = XSStringCreateWithCString( "" );
    XSStringRef str2 = XSStringCreateWithCString( "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );

    AssertEqual( XSStringGetCharacterAtIndex( NULL, 0 ), 0 );
    AssertEqual( XSStringGetCharacterAtIndex( NULL, 1 ), 0 );
    AssertEqual( XSStringGetCharacterAtIndex( NULL, 42 ), 0 );

    AssertEqual( XSStringGetCharacterAtIndex( str1, 0 ), 0 );
    AssertEqual( XSStringGetCharacterAtIndex( str1, 1 ), 0 );
    AssertEqual( XSStringGetCharacterAtIndex( str1, 42 ), 0 );

    AssertEqual( XSStringGetCharacterAtIndex( str2, 0 ), 'L' );
    AssertEqual( XSStringGetCharacterAtIndex( str2, 1 ), 'o' );
    AssertEqual( XSStringGetCharacterAtIndex( str2, 143 ), '.' );
    AssertEqual( XSStringGetCharacterAtIndex( str2, 144 ), 0 );
    AssertEqual( XSStringGetCharacterAtIndex( str2, 200 ), 0 );

    XSRelease( str1 );
    XSRelease( str2 );
}

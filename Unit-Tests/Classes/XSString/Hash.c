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
 * @file        Hash.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSString, Hash )
{
    XSStringRef str1 = XSStringCreateWithCString( "" );
    XSStringRef str2 = XSStringCreateWithCString( "hello, world" );
    XSStringRef str3 = XSStringCreateWithCString( "hello, universe" );
    uint64_t    h1   = XSHash( str1 );
    uint64_t    h2   = XSHash( str2 );
    uint64_t    h3   = XSHash( str3 );

    AssertTrue( h1 == 0 );
    AssertTrue( h2 != 0 );
    AssertTrue( h3 != 0 );

    AssertEqual( h1, XSHash( str1 ) );
    AssertEqual( h2, XSHash( str2 ) );
    AssertEqual( h3, XSHash( str3 ) );

    AssertNotEqual( h2, h3 );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( str3 );
}

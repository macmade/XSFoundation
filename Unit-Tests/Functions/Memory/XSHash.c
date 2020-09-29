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
 * @file        XSHash.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( Memory, XSHash )
{
    XSStringRef          str = XSStringCreateWithCString( "hello, world" );
    XSAutoreleasePoolRef ap  = XSAutoreleasePoolCreate();
    const char *         mem = XSAlloc( 42 );
    uint64_t             h1  = XSHash( str );
    uint64_t             h2  = XSHash( ap );
    uint64_t             h3  = XSHash( mem );

    AssertTrue( XSHash( NULL ) == 0 );
    AssertTrue( h1 != 0 );
    AssertTrue( h2 != 0 );
    AssertTrue( h3 != 0 );

    AssertTrue( h1 == XSHash( str ) );
    AssertTrue( h2 == XSHash( ap ) );
    AssertTrue( h3 == XSHash( mem ) );

    AssertNotEqual( h1, ( uint64_t )str );
    AssertEqual( h2, ( uint64_t )ap );
    AssertEqual( h3, ( uint64_t )mem );

    XSRelease( str );
    XSRelease( ap );
    XSRelease( mem );
}

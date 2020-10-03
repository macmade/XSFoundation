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

Test( XSData, Hash )
{
    uint8_t   bytes[ 1024 ];
    XSDataRef data1;
    XSDataRef data2;
    XSDataRef data3;
    XSDataRef data4;
    uint64_t  h1;
    uint64_t  h2;
    uint64_t  h3;
    uint64_t  h4;

    for( size_t i = 0; i < sizeof( bytes ); i++ )
    {
        bytes[ i ] = ( uint8_t )i;
    }

    data1 = XSDataCreateWithBytes( bytes, 0 );
    data2 = XSDataCreateWithBytes( bytes, 10 );
    data3 = XSDataCreateWithBytes( bytes + 1, 10 );
    data4 = XSDataCreateWithBytes( bytes, sizeof( bytes ) );
    h1    = XSHash( data1 );
    h2    = XSHash( data2 );
    h3    = XSHash( data3 );
    h4    = XSHash( data4 );

    AssertTrue( h1 != 0 );
    AssertTrue( h2 != 0 );
    AssertTrue( h3 != 0 );
    AssertTrue( h4 != 0 );

    AssertEqual( h1, XSHash( data1 ) );
    AssertEqual( h2, XSHash( data2 ) );
    AssertEqual( h3, XSHash( data3 ) );
    AssertEqual( h4, XSHash( data4 ) );

    AssertNotEqual( h1, h2 );
    AssertNotEqual( h1, h3 );
    AssertNotEqual( h1, h4 );
    AssertNotEqual( h2, h3 );
    AssertNotEqual( h2, h4 );
    AssertNotEqual( h3, h4 );

    XSRelease( data1 );
    XSRelease( data2 );
    XSRelease( data3 );
    XSRelease( data4 );
}

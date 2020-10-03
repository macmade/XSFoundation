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
 * @file        Copy.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>
#include <string.h>

Test( XSData, Copy )
{
    uint8_t   bytes[ 1024 ];
    XSDataRef data1;
    XSDataRef data2;
    XSDataRef data3;
    XSDataRef copy1;
    XSDataRef copy2;
    XSDataRef copy3;

    for( size_t i = 0; i < sizeof( bytes ); i++ )
    {
        bytes[ i ] = ( uint8_t )i;
    }

    data1 = XSDataCreateWithBytes( bytes, sizeof( bytes ) );
    data2 = XSDataCreateWithBytes( bytes, 10 );
    data3 = XSDataCreateWithBytes( NULL, 0 );
    copy1 = XSCopy( data1 );
    copy2 = XSCopy( data2 );
    copy3 = XSCopy( data3 );

    AssertTrue( copy1 != NULL );
    AssertTrue( copy2 != NULL );
    AssertTrue( copy3 != NULL );

    AssertEqual( XSDataGetLength( data1 ), sizeof( bytes ) );
    AssertEqual( XSDataGetLength( copy1 ), sizeof( bytes ) );
    AssertTrue( data1 != copy1 );
    AssertTrue( XSDataGetBytesPointer( data1 ) != XSDataGetBytesPointer( copy1 ) );
    AssertTrue( memcmp( XSDataGetBytesPointer( data1 ), bytes, sizeof( bytes ) ) == 0 );
    AssertTrue( memcmp( XSDataGetBytesPointer( copy1 ), bytes, sizeof( bytes ) ) == 0 );

    AssertEqual( XSDataGetLength( data2 ), 10 );
    AssertEqual( XSDataGetLength( copy2 ), 10 );
    AssertTrue( data2 != copy2 );
    AssertTrue( XSDataGetBytesPointer( data2 ) != XSDataGetBytesPointer( copy2 ) );
    AssertTrue( memcmp( XSDataGetBytesPointer( data2 ), bytes, 10 ) == 0 );
    AssertTrue( memcmp( XSDataGetBytesPointer( copy2 ), bytes, 10 ) == 0 );

    AssertTrue( XSRuntimeIsConstantObject( data3 ) );
    AssertFalse( XSRuntimeIsConstantObject( copy3 ) );
    AssertEqual( XSDataGetLength( data3 ), 0u );
    AssertEqual( XSDataGetLength( copy3 ), 0u );
    AssertTrue( data3 != copy3 );
    AssertTrue( XSDataGetBytesPointer( data3 ) != XSDataGetBytesPointer( copy3 ) );
}

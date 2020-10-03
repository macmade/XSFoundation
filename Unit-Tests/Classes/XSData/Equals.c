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
 * @file        Equals.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSData, Equals )
{
    uint8_t   bytes1[ 1024 ];
    uint8_t   bytes2[ 1024 ];
    XSDataRef data1;
    XSDataRef data2;
    XSDataRef data3;
    XSDataRef data4;
    XSDataRef data5;
    XSDataRef data6;
    XSDataRef data7;
    XSDataRef data8;

    for( size_t i = 0; i < sizeof( bytes1 ); i++ )
    {
        bytes1[ i ] = ( uint8_t )i;
        bytes2[ i ] = ( uint8_t )i + 1;
    }

    data1 = XSDataCreateWithBytes( bytes1, sizeof( bytes1 ) );
    data2 = XSDataCreateWithBytes( bytes2, sizeof( bytes2 ) );
    data3 = XSDataCreateWithBytes( bytes1, sizeof( bytes1 ) );
    data4 = XSDataCreateWithBytes( bytes2, sizeof( bytes2 ) );
    data5 = XSDataCreateWithBytes( bytes1, 10 );
    data6 = XSDataCreateWithBytes( bytes2, 10 );
    data7 = XSDataCreateWithBytes( bytes1, 10 );
    data8 = XSDataCreateWithBytes( bytes2, 10 );

    AssertTrue( XSEquals( data1, data3 ) );
    AssertTrue( XSEquals( data2, data4 ) );
    AssertTrue( XSEquals( data5, data7 ) );
    AssertTrue( XSEquals( data6, data8 ) );

    AssertFalse( XSEquals( data1, data2 ) );
    AssertFalse( XSEquals( data1, data5 ) );
    AssertFalse( XSEquals( data1, data6 ) );
    AssertFalse( XSEquals( data2, data1 ) );
    AssertFalse( XSEquals( data2, data5 ) );
    AssertFalse( XSEquals( data2, data6 ) );
    AssertFalse( XSEquals( data5, data1 ) );
    AssertFalse( XSEquals( data5, data2 ) );
    AssertFalse( XSEquals( data5, data6 ) );
    AssertFalse( XSEquals( data6, data1 ) );
    AssertFalse( XSEquals( data6, data2 ) );
    AssertFalse( XSEquals( data6, data5 ) );

    XSRelease( data1 );
    XSRelease( data2 );
    XSRelease( data3 );
    XSRelease( data4 );
    XSRelease( data5 );
    XSRelease( data6 );
    XSRelease( data7 );
    XSRelease( data8 );
}

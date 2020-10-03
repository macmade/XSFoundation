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
 * @file        ToString.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSData, ToString )
{
    uint8_t   bytes[ 1024 ];
    XSDataRef data1;
    XSDataRef data2;
    XSDataRef data3;
    XSDataRef data4;

    data1 = XSDataCreateWithBytes( bytes, sizeof( bytes ) );
    data2 = XSDataCreateWithBytes( bytes, 10 );
    data3 = XSDataCreateWithBytes( bytes, 1 );
    data4 = XSDataCreateWithBytes( bytes, 0 );

    AssertTrue( XSStringContainsCString( XSRuntimeGetDescription( data1 ), "1024 bytes" ) );
    AssertTrue( XSStringContainsCString( XSRuntimeGetDescription( data2 ), "10 bytes" ) );
    AssertTrue( XSStringContainsCString( XSRuntimeGetDescription( data3 ), "1 byte" ) );
    AssertTrue( XSStringContainsCString( XSRuntimeGetDescription( data4 ), "empty" ) );

    XSRelease( data1 );
    XSRelease( data2 );
    XSRelease( data3 );
    XSRelease( data4 );
}

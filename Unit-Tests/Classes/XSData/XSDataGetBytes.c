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
 * @file        XSDataGetBytes.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>
#include <string.h>

Test( XSData, XSDataGetBytes )
{
    uint8_t   clear[ 10 ];
    uint8_t   bytes[ 10 ];
    uint8_t   buf[ 10 ];
    XSDataRef data;

    memset( clear, 0, sizeof( clear ) );
    memset( buf, 0, sizeof( buf ) );

    for( size_t i = 0; i < sizeof( bytes ); i++ )
    {
        bytes[ i ] = ( uint8_t )i;
    }

    data = XSDataCreateWithBytes( bytes, sizeof( bytes ) );

    AssertFalse( XSDataGetBytes( data, buf, XSMakeRange( 0, 0 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    AssertFalse( XSDataGetBytes( data, buf, XSMakeRange( 0, sizeof( bytes ) + 1 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    AssertFalse( XSDataGetBytes( data, buf, XSMakeRange( 1, sizeof( bytes ) + 2 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    AssertFalse( XSDataGetBytes( data, buf, XSMakeRange( sizeof( bytes ), 1 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    memset( buf, 0, sizeof( buf ) );
    AssertTrue( XSDataGetBytes( data, buf, XSMakeRange( 0, 1 ) ) );
    AssertTrue( buf[ 0 ] == 0 );
    AssertTrue( buf[ 1 ] == 0 );
    AssertTrue( buf[ 2 ] == 0 );

    memset( buf, 0, sizeof( buf ) );
    AssertTrue( XSDataGetBytes( data, buf, XSMakeRange( 0, 2 ) ) );
    AssertTrue( buf[ 0 ] == 0 );
    AssertTrue( buf[ 1 ] == 1 );
    AssertTrue( buf[ 2 ] == 0 );

    memset( buf, 0, sizeof( buf ) );
    AssertTrue( XSDataGetBytes( data, buf, XSMakeRange( 1, 1 ) ) );
    AssertTrue( buf[ 0 ] == 1 );
    AssertTrue( buf[ 1 ] == 0 );
    AssertTrue( buf[ 2 ] == 0 );

    memset( buf, 0, sizeof( buf ) );
    AssertTrue( XSDataGetBytes( data, buf, XSMakeRange( 1, 2 ) ) );
    AssertTrue( buf[ 0 ] == 1 );
    AssertTrue( buf[ 1 ] == 2 );
    AssertTrue( buf[ 2 ] == 0 );

    memset( buf, 0, sizeof( buf ) );
    AssertTrue( XSDataGetBytes( data, buf, XSMakeRange( 0, sizeof( bytes ) ) ) );
    AssertTrue( memcmp( buf, bytes, sizeof( buf ) ) == 0 );

    memset( buf, 0, sizeof( buf ) );
    AssertTrue( XSDataGetBytes( data, buf, XSMakeRange( 0, sizeof( bytes ) - 1 ) ) );
    AssertTrue( buf[ 0 ] == 1 );
    AssertTrue( buf[ 1 ] == 2 );
    AssertTrue( buf[ sizeof( bytes ) - 2 ] == bytes[ sizeof( bytes ) - 2 ] );
    AssertTrue( buf[ sizeof( bytes ) - 1 ] == 0 );

    XSRelease( data );
}

Test( XSData, XSDataGetBytes_BigData )
{
    uint8_t   clear[ 1024 ];
    uint8_t   bytes[ 1024 ];
    uint8_t   buf[ 1024 ];
    XSDataRef data;

    memset( clear, 0, sizeof( clear ) );
    memset( buf, 0, sizeof( buf ) );

    for( size_t i = 0; i < sizeof( bytes ); i++ )
    {
        bytes[ i ] = ( uint8_t )i;
    }

    data = XSDataCreateWithBytes( bytes, sizeof( bytes ) );

    AssertFalse( XSDataGetBytes( data, buf, XSMakeRange( 0, 0 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    AssertFalse( XSDataGetBytes( data, buf, XSMakeRange( 0, sizeof( bytes ) + 1 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    AssertFalse( XSDataGetBytes( data, buf, XSMakeRange( 1, sizeof( bytes ) + 2 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    AssertFalse( XSDataGetBytes( data, buf, XSMakeRange( sizeof( bytes ), 1 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    memset( buf, 0, sizeof( buf ) );
    AssertTrue( XSDataGetBytes( data, buf, XSMakeRange( 0, 1 ) ) );
    AssertTrue( buf[ 0 ] == 0 );
    AssertTrue( buf[ 1 ] == 0 );
    AssertTrue( buf[ 2 ] == 0 );

    memset( buf, 0, sizeof( buf ) );
    AssertTrue( XSDataGetBytes( data, buf, XSMakeRange( 0, 2 ) ) );
    AssertTrue( buf[ 0 ] == 0 );
    AssertTrue( buf[ 1 ] == 1 );
    AssertTrue( buf[ 2 ] == 0 );

    memset( buf, 0, sizeof( buf ) );
    AssertTrue( XSDataGetBytes( data, buf, XSMakeRange( 1, 1 ) ) );
    AssertTrue( buf[ 0 ] == 1 );
    AssertTrue( buf[ 1 ] == 0 );
    AssertTrue( buf[ 2 ] == 0 );

    memset( buf, 0, sizeof( buf ) );
    AssertTrue( XSDataGetBytes( data, buf, XSMakeRange( 1, 2 ) ) );
    AssertTrue( buf[ 0 ] == 1 );
    AssertTrue( buf[ 1 ] == 2 );
    AssertTrue( buf[ 2 ] == 0 );

    memset( buf, 0, sizeof( buf ) );
    AssertTrue( XSDataGetBytes( data, buf, XSMakeRange( 0, sizeof( bytes ) ) ) );
    AssertTrue( memcmp( buf, bytes, sizeof( buf ) ) == 0 );

    memset( buf, 0, sizeof( buf ) );
    AssertTrue( XSDataGetBytes( data, buf, XSMakeRange( 0, sizeof( bytes ) - 1 ) ) );
    AssertTrue( buf[ 0 ] == 1 );
    AssertTrue( buf[ 1 ] == 2 );
    AssertTrue( buf[ sizeof( bytes ) - 2 ] == bytes[ sizeof( bytes ) - 2 ] );
    AssertTrue( buf[ sizeof( bytes ) - 1 ] == 0 );

    XSRelease( data );
}

Test( XSData, XSDataGetBytes_NULL )
{
    uint8_t   clear[ 128 ];
    uint8_t   buf[ 128 ];
    uint8_t   bytes[ 128 ];
    XSDataRef data;

    for( size_t i = 0; i < sizeof( bytes ); i++ )
    {
        bytes[ i ] = ( uint8_t )i;
    }

    memset( clear, 0, sizeof( clear ) );
    memset( buf, 0, sizeof( buf ) );

    data = XSDataCreateWithBytes( bytes, sizeof( bytes ) );

    AssertFalse( XSDataGetBytes( NULL, NULL, XSMakeRange( 0, 0 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    AssertFalse( XSDataGetBytes( NULL, NULL, XSMakeRange( 0, 10 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    AssertFalse( XSDataGetBytes( NULL, NULL, XSMakeRange( 10, 0 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    AssertFalse( XSDataGetBytes( NULL, buf, XSMakeRange( 0, 0 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    AssertFalse( XSDataGetBytes( NULL, buf, XSMakeRange( 0, 10 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    AssertFalse( XSDataGetBytes( NULL, buf, XSMakeRange( 10, 0 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    AssertFalse( XSDataGetBytes( data, NULL, XSMakeRange( 0, 0 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    AssertFalse( XSDataGetBytes( data, NULL, XSMakeRange( 0, 10 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    AssertFalse( XSDataGetBytes( data, NULL, XSMakeRange( 10, 0 ) ) );
    AssertTrue( memcmp( buf, clear, sizeof( buf ) ) == 0 );

    XSRelease( data );
}

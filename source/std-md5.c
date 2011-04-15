/*******************************************************************************
 * Copyright (c) 1991-2, RSA Data Security, Inc. Created 1991.
 * All rights reserved.
 * 
 * License to copy and use this software is granted provided that it
 * is identified as the "RSA Data Security, Inc. MD5 Message-Digest
 * Algorithm" in all material mentioning or referencing this software
 * or this function.
 * 
 * License is also granted to make and use derivative works provided
 * that such works are identified as "derived from the RSA Data
 * Security, Inc. MD5 Message-Digest Algorithm" in all material
 * mentioning or referencing the derived work.
 * 
 * RSA Data Security, Inc. makes no representations concerning either
 * the merchantability of this software or the suitability of this
 * software for any particular purpose. It is provided "as is"
 * without express or implied warranty of any kind.
 ******************************************************************************/

/* $Id$ */

/*!
 * @file        md5.c
 * @copyright   RSA Data Security, Inc.
 * @abstract    Implelemtation of the MD5 hash algorithm
 */

#include "std/std-md5.h"
#include <string.h>

/* Constants for the __MD5_Transform function */
#define S11      7
#define S12     12
#define S13     17
#define S14     22
#define S21      5
#define S22      9
#define S23     14
#define S24     20
#define S31      4
#define S32     11
#define S33     16
#define S34     23
#define S41      6
#define S42     10
#define S43     15
#define S44     21

/*!
 * @function    __MD5_Transform
 * @abstract    
 * @param       
 * @param       
 * @result      void
 */
static void __MD5_Transform( unsigned long int state[ 4 ], unsigned char block[ 64 ] );

/*!
 * @function    __MD5_Encode
 * @abstract    
 * @param       
 * @param       
 * @param       
 * @result      void
 */
static void __MD5_Encode( unsigned char * output, unsigned long int * input, unsigned int length );

/*!
 * @function    __MD5_Decode
 * @abstract    
 * @param       
 * @param       
 * @param       
 * @result      void
 */
static void __MD5_Decode( unsigned long int * output, unsigned char * input, unsigned int length );

/*!
 * @var         MD5_PADDING
 * @abstract    
 */
static unsigned char MD5_PADDING[ 64 ] =
{
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

/* Basic MD5 functions */
#define F( x, y, z ) ( ( ( x ) & ( y ) ) | ( ( ~x ) & ( z ) ) )
#define G( x, y, z ) ( ( ( x ) & ( z ) ) | ( ( y ) & ( ~z ) ) )
#define H( x, y, z ) ( ( x ) ^ ( y ) ^ ( z ) )
#define I( x, y, z ) ( ( y ) ^ ( ( x ) | ( ~z ) ) )

/*!
 * @define      MD5_ROTATE_LEFT
 * @abstract    Rotates x left n bits
 */
#define MD5_ROTATE_LEFT( x, n ) ( ( ( x ) << ( n ) ) | ( ( x ) >> ( 32 - ( n ) ) ) )

/*!
 * @define      FF
 * @abstract    Transformations for round 1
 */
#define FF( a, b, c, d, x, s, ac )                                              \
{                                                                               \
    ( a ) += F( ( b ), ( c ), ( d ) ) + ( x ) + ( unsigned long int )( ac );    \
    ( a ) = MD5_ROTATE_LEFT( ( a ), ( s ) );                                    \
    ( a ) += ( b );                                                             \
}

/*!
 * @define      FF
 * @abstract    Transformations for round 2
 */
#define GG( a, b, c, d, x, s, ac )                                              \
{                                                                               \
    ( a ) += G( ( b ), ( c ), ( d ) ) + ( x ) + ( unsigned long int )( ac );    \
    ( a ) = MD5_ROTATE_LEFT( ( a ), ( s ) );                                    \
    ( a ) += ( b );                                                             \
}

/*!
 * @define      FF
 * @abstract    Transformations for round 3
 */
#define HH( a, b, c, d, x, s, ac )                                              \
{                                                                               \
    ( a ) += H( ( b ), ( c ), ( d ) ) + ( x ) + ( unsigned long int )( ac );    \
    ( a ) = MD5_ROTATE_LEFT( ( a ), ( s ) );                                    \
    ( a ) += ( b );                                                             \
}

/*!
 * @define      FF
 * @abstract    Transformations for round 4
 */
#define II( a, b, c, d, x, s, ac )                                              \
{                                                                               \
    ( a ) += I( ( b ), ( c ), ( d ) ) + ( x ) + ( unsigned long int )( ac );    \
    ( a ) = MD5_ROTATE_LEFT( ( a ), ( s ) );                                    \
    ( a ) += ( b );                                                             \
}

void MD5_Init( MD5_CTX * context )
{
  context->count[ 0 ] = 0;
  context->count[ 1 ] = 0;
  context->state[ 0 ] = 0x67452301;
  context->state[ 1 ] = 0xEFCDAB89;
  context->state[ 2 ] = 0x98BADCFE;
  context->state[ 3 ] = 0x10325476;
}

void MD5_Update( MD5_CTX * context, unsigned char * data, unsigned int length )

{
    unsigned int i;
    unsigned int idx;
    unsigned int partLen;
    
    idx = ( unsigned int )( ( context->count[ 0 ] >> 3 ) & 0x3F );
    
    if( ( context->count[ 0 ] += ( ( unsigned long int )length << 3 ) ) < ( ( unsigned long int )length << 3 ) )
    {
        context->count[ 1 ]++;
    }
    
    context->count[ 1 ] += ( ( unsigned long int )length >> 29 );
    
    partLen = 64 - idx;

    if( length >= partLen )
    {
        memcpy( ( unsigned char * )&context->buffer[ idx ], ( unsigned char * )data, partLen );
        __MD5_Transform( context->state, context->buffer );
        
        for( i = partLen; i + 63 < length; i += 64 )
        {
            __MD5_Transform( context->state, &data[ i ] );
        }
        
        idx = 0;
    }
    else
    {
        i = 0;
    }
    
    memcpy( ( unsigned char * )&context->buffer[ idx ], ( unsigned char * )&data[ i ], length - i );
}

void MD5_Final( unsigned char digest[ 16 ], MD5_CTX * context )
{
    unsigned char bits[ 8 ];
    unsigned int  idx;
    unsigned int  padLen;
    
    __MD5_Encode( bits, context->count, 8 );
    
    idx    = ( unsigned int )( ( context->count[ 0 ] >> 3 ) & 0x3F );
    padLen = ( idx < 56 ) ? ( 56 - idx ) : ( 120 - idx );
    
    MD5_Update( context, MD5_PADDING, padLen );
    MD5_Update( context, bits, 8 );
    __MD5_Encode( digest, context->state, 16 );
    memset( ( unsigned char * )context, 0, sizeof( *( context ) ) );
}

static void __MD5_Transform( unsigned long int state[ 4 ], unsigned char block[ 64 ] )
{
    unsigned long int a;
    unsigned long int b;
    unsigned long int c;
    unsigned long int d;
    unsigned long int x[ 16 ];
    
    a = state[ 0 ];
    b = state[ 1 ];
    c = state[ 2 ];
    d = state[ 3 ];
    
    __MD5_Decode( x, block, 64 );
    
    /* Round 1 */
    FF( a, b, c, d, x[  0 ], S11, 0xD76AA478 ); /* 1 */
    FF( d, a, b, c, x[  1 ], S12, 0xE8C7B756 ); /* 2 */
    FF( c, d, a, b, x[  2 ], S13, 0x242070DB ); /* 3 */
    FF( b, c, d, a, x[  3 ], S14, 0xC1BDCEEE ); /* 4 */
    FF( a, b, c, d, x[  4 ], S11, 0xF57C0FAF ); /* 5 */
    FF( d, a, b, c, x[  5 ], S12, 0x4787C62A ); /* 6 */
    FF( c, d, a, b, x[  6 ], S13, 0xA8304613 ); /* 7 */
    FF( b, c, d, a, x[  7 ], S14, 0xFD469501 ); /* 8 */
    FF( a, b, c, d, x[  8 ], S11, 0x698098D8 ); /* 9 */
    FF( d, a, b, c, x[  9 ], S12, 0x8B44F7AF ); /* 10 */
    FF( c, d, a, b, x[ 10 ], S13, 0xFFFF5BB1 ); /* 11 */
    FF( b, c, d, a, x[ 11 ], S14, 0x895CD7BE ); /* 12 */
    FF( a, b, c, d, x[ 12 ], S11, 0x6B901122 ); /* 13 */
    FF( d, a, b, c, x[ 13 ], S12, 0xFD987193 ); /* 14 */
    FF( c, d, a, b, x[ 14 ], S13, 0xA679438E ); /* 15 */
    FF( b, c, d, a, x[ 15 ], S14, 0x49B40821 ); /* 16 */
    
    /* Round 2 */
    GG( a, b, c, d, x[  1 ], S21, 0xF61E2562 ); /* 17 */
    GG( d, a, b, c, x[  6 ], S22, 0xC040B340 ); /* 18 */
    GG( c, d, a, b, x[ 11 ], S23, 0x265E5A51 ); /* 19 */
    GG( b, c, d, a, x[  0 ], S24, 0xE9B6C7AA ); /* 20 */
    GG( a, b, c, d, x[  5 ], S21, 0xD62F105D ); /* 21 */
    GG( d, a, b, c, x[ 10 ], S22,  0x2441453 ); /* 22 */
    GG( c, d, a, b, x[ 15 ], S23, 0xD8A1E681 ); /* 23 */
    GG( b, c, d, a, x[  4 ], S24, 0xE7D3FBC8 ); /* 24 */
    GG( a, b, c, d, x[  9 ], S21, 0x21E1CDE6 ); /* 25 */
    GG( d, a, b, c, x[ 14 ], S22, 0xC33707D6 ); /* 26 */
    GG( c, d, a, b, x[  3 ], S23, 0xF4D50D87 ); /* 27 */
    GG( b, c, d, a, x[  8 ], S24, 0x455A14ED ); /* 28 */
    GG( a, b, c, d, x[ 13 ], S21, 0xA9E3E905 ); /* 29 */
    GG( d, a, b, c, x[  2 ], S22, 0xFCEFA3F8 ); /* 30 */
    GG( c, d, a, b, x[  7 ], S23, 0x676F02D9 ); /* 31 */
    GG( b, c, d, a, x[ 12 ], S24, 0x8D2A4C8A ); /* 32 */
    
    /* Round 3 */
    HH( a, b, c, d, x[  5 ], S31, 0xFFFA3942 ); /* 33 */
    HH( d, a, b, c, x[  8 ], S32, 0x8771F681 ); /* 34 */
    HH( c, d, a, b, x[ 11 ], S33, 0x6D9D6122 ); /* 35 */
    HH( b, c, d, a, x[ 14 ], S34, 0xFDE5380C ); /* 36 */
    HH( a, b, c, d, x[  1 ], S31, 0xA4BEEA44 ); /* 37 */
    HH( d, a, b, c, x[  4 ], S32, 0x4BDECFA9 ); /* 38 */
    HH( c, d, a, b, x[  7 ], S33, 0xF6BB4B60 ); /* 39 */
    HH( b, c, d, a, x[ 10 ], S34, 0xBEBFBC70 ); /* 40 */
    HH( a, b, c, d, x[ 13 ], S31, 0x289B7EC6 ); /* 41 */
    HH( d, a, b, c, x[  0 ], S32, 0xEAA127FA ); /* 42 */
    HH( c, d, a, b, x[  3 ], S33, 0xD4EF3085 ); /* 43 */
    HH( b, c, d, a, x[  6 ], S34,  0x4881D05 ); /* 44 */
    HH( a, b, c, d, x[  9 ], S31, 0xD9D4D039 ); /* 45 */
    HH( d, a, b, c, x[ 12 ], S32, 0xE6DB99E5 ); /* 46 */
    HH( c, d, a, b, x[ 15 ], S33, 0x1FA27CF8 ); /* 47 */
    HH( b, c, d, a, x[  2 ], S34, 0xC4AC5665 ); /* 48 */
    
    /* Round 4 */
    II( a, b, c, d, x[  0 ], S41, 0xF4292244 ); /* 49 */
    II( d, a, b, c, x[  7 ], S42, 0x432AFF97 ); /* 50 */
    II( c, d, a, b, x[ 14 ], S43, 0xAB9423A7 ); /* 51 */
    II( b, c, d, a, x[  5 ], S44, 0xFC93A039 ); /* 52 */
    II( a, b, c, d, x[ 12 ], S41, 0x655B59C3 ); /* 53 */
    II( d, a, b, c, x[  3 ], S42, 0x8F0CCC92 ); /* 54 */
    II( c, d, a, b, x[ 10 ], S43, 0xFFEFF47D ); /* 55 */
    II( b, c, d, a, x[  1 ], S44, 0x85845DD1 ); /* 56 */
    II( a, b, c, d, x[  8 ], S41, 0x6FA87E4F ); /* 57 */
    II( d, a, b, c, x[ 15 ], S42, 0xFE2CE6E0 ); /* 58 */
    II( c, d, a, b, x[  6 ], S43, 0xA3014314 ); /* 59 */
    II( b, c, d, a, x[ 13 ], S44, 0x4E0811A1 ); /* 60 */
    II( a, b, c, d, x[  4 ], S41, 0xF7537E82 ); /* 61 */
    II( d, a, b, c, x[ 11 ], S42, 0xBD3AF235 ); /* 62 */
    II( c, d, a, b, x[  2 ], S43, 0x2AD7D2BB ); /* 63 */
    II( b, c, d, a, x[  9 ], S44, 0xEB86D391 ); /* 64 */
    
    state[ 0 ] += a;
    state[ 1 ] += b;
    state[ 2 ] += c;
    state[ 3 ] += d;
    
    memset( ( unsigned char * )x, 0, sizeof( x ) );
}

static void __MD5_Encode( unsigned char * output, unsigned long int * input, unsigned int length )
{
    unsigned int i;
    unsigned int j;
    
    for( i = 0, j = 0; j < length; i++, j += 4 )
    {
        output[ j     ] = ( unsigned char )(   input[ i ]         & 0xFF );
        output[ j + 1 ] = ( unsigned char )( ( input[ i ] >>  8 ) & 0xFF );
        output[ j + 2 ] = ( unsigned char )( ( input[ i ] >> 16 ) & 0xFF );
        output[ j + 3 ] = ( unsigned char )( ( input[ i ] >> 24 ) & 0xFF );
    }
}

static void __MD5_Decode( unsigned long int * output, unsigned char * input, unsigned int length )
{
    unsigned int i;
    unsigned int j;
    
    for( i = 0, j = 0; j < length; i++, j += 4 )
    {
        output[ i ] =   ( ( unsigned long int )input[ j ] )
                    | ( ( ( unsigned long int )input[ j + 1 ] ) <<  8 )
                    | ( ( ( unsigned long int )input[ j + 2 ] ) << 16 )
                    | ( ( ( unsigned long int )input[ j + 3 ] ) << 24 );
    }
}

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
 * @file        XSStringMakeConstantString.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSStringMakeConstantString
 */

#include <XS/XS.h>
#include <XS/Private/Classes/XSString.h>
#include <string.h>
#include <stdlib.h>

XSStringRef XSStringMakeConstantString( const char * cstr )
{
    uint64_t    i;
    XSStringRef s;

    if( cstr == NULL )
    {
        cstr = "";
    }

    XSSpinLockLock( &XSStringConstantStringsLock );

    if( XSStringConstantStrings == NULL )
    {
        XSStringConstantStrings = calloc( 256, sizeof( struct XSString * ) );

        if( XSStringConstantStrings == NULL )
        {
            XSSpinLockUnlock( &XSStringConstantStringsLock );
            XSBadAlloc();
        }

        XSStringConstantStringsCapacity = 256;
    }

    for( i = 0; i < XSStringConstantStringsCapacity; i++ )
    {
        if( XSStringConstantStrings[ i ] != NULL && ( XSStringConstantStrings[ i ]->storage.cptr == cstr || strcmp( XSStringConstantStrings[ i ]->storage.cptr, cstr ) == 0 ) )
        {
            XSSpinLockUnlock( &XSStringConstantStringsLock );

            return XSStringConstantStrings[ i ];
        }
    }

    s = XSStringCreateWithCStringNoCopy( cstr );

    if( s == NULL )
    {
        XSSpinLockUnlock( &XSStringConstantStringsLock );
        XSBadAlloc();
    }

    XSRuntimeSetObjectAsConstant( s );

add:

    for( i = 0; i < XSStringConstantStringsCapacity; i++ )
    {
        if( XSStringConstantStrings[ i ] == NULL )
        {
            XSStringConstantStrings[ i ] = s;

            XSSpinLockUnlock( &XSStringConstantStringsLock );

            return s;
        }
    }

    XSStringConstantStrings = realloc( ( void * )XSStringConstantStrings, 2 * XSStringConstantStringsCapacity * sizeof( struct XSString * ) );

    if( XSStringConstantStrings == NULL )
    {
        XSSpinLockUnlock( &XSStringConstantStringsLock );
        XSBadAlloc();
    }

    memset( ( void * )( XSStringConstantStrings + XSStringConstantStringsCapacity ), 0, XSStringConstantStringsCapacity * sizeof( struct XSString * ) );

    XSStringConstantStringsCapacity *= 2;

    goto add;
}

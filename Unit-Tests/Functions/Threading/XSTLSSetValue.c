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
 * @file        XSTLSSetValue.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( Threading, XSTLSSetValue )
{
    XSTLSKey key;
    char *   mem1;
    char *   mem2;

    mem1 = XSAlloc( 128 );
    mem2 = XSAlloc( 128 );

    AssertTrue( mem1 != NULL );
    AssertTrue( mem2 != NULL );
    AssertEqual( XSGetRetainCount( mem1 ), 1 );
    AssertEqual( XSGetRetainCount( mem2 ), 1 );

    AssertTrue( XSTLSKeyCreate( &key ) );

    XSTLSSetValue( &key, mem1, XSObjectAssociationAssign );
    AssertTrue( XSTLSGetValue( &key ) == mem1 );
    AssertEqual( XSGetRetainCount( mem1 ), 1 );

    XSTLSSetValue( &key, mem2, XSObjectAssociationAssign );
    AssertTrue( XSTLSGetValue( &key ) == mem2 );
    AssertEqual( XSGetRetainCount( mem1 ), 1 );
    AssertEqual( XSGetRetainCount( mem2 ), 1 );

    XSTLSSetValue( &key, mem2, XSObjectAssociationRetain );
    AssertTrue( XSTLSGetValue( &key ) == mem2 );
    AssertEqual( XSGetRetainCount( mem2 ), 2 );

    XSTLSSetValue( &key, mem1, XSObjectAssociationAssign );
    AssertTrue( XSTLSGetValue( &key ) == mem1 );
    AssertEqual( XSGetRetainCount( mem1 ), 1 );
    AssertEqual( XSGetRetainCount( mem2 ), 1 );

    {
        char * copy;

        for( size_t i = 0; i < 128; i++ )
        {
            mem1[ i ] = 42;
        }

        XSTLSSetValue( &key, mem1, XSObjectAssociationCopy );

        copy = XSTLSGetValue( &key );

        AssertFalse( copy == mem1 );
        AssertEqual( XSGetRetainCount( copy ), 1 );

        for( size_t i = 0; i < 128; i++ )
        {
            AssertEqual( copy[ i ], 42 );
        }

        XSRetain( copy );
        AssertEqual( XSGetRetainCount( copy ), 2 );

        XSTLSSetValue( &key, NULL, XSObjectAssociationAssign );
        AssertEqual( XSGetRetainCount( copy ), 1 );
        XSRelease( copy );
        AssertTrue( XSTLSGetValue( &key ) == NULL );
    }

    XSTLSKeyDelete( &key );
    XSRelease( mem1 );
    XSRelease( mem2 );
}

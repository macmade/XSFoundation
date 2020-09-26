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
 * @file        XSTLSGetValue.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( Threading, XSTLSGetValue )
{
    XSTLSKey key1;
    XSTLSKey key2;
    int      x;
    int      y;

    x = 42;
    y = 43;

    AssertTrue( XSTLSKeyCreate( &key1 ) );
    AssertTrue( XSTLSKeyCreate( &key2 ) );

    AssertTrue( XSTLSGetValue( &key1 ) == NULL );
    AssertTrue( XSTLSGetValue( &key2 ) == NULL );

    XSTLSSetValue( &key1, &x, XSObjectAssociationAssign );
    XSTLSSetValue( &key2, &y, XSObjectAssociationAssign );

    AssertTrue( XSTLSGetValue( &key1 ) != NULL );
    AssertTrue( XSTLSGetValue( &key2 ) != NULL );
    AssertEqual( *( ( int * )XSTLSGetValue( &key1 ) ), x );
    AssertEqual( *( ( int * )XSTLSGetValue( &key2 ) ), y );

    XSTLSSetValue( &key1, &y, XSObjectAssociationAssign );
    XSTLSSetValue( &key2, &x, XSObjectAssociationAssign );

    AssertTrue( XSTLSGetValue( &key1 ) != NULL );
    AssertTrue( XSTLSGetValue( &key2 ) != NULL );
    AssertEqual( *( ( int * )XSTLSGetValue( &key1 ) ), y );
    AssertEqual( *( ( int * )XSTLSGetValue( &key2 ) ), x );

    XSTLSKeyDelete( &key1 );
    XSTLSKeyDelete( &key2 );

    AssertTrue( XSTLSGetValue( &key1 ) == NULL );
    AssertTrue( XSTLSGetValue( &key2 ) == NULL );
}

Test( Threading, XSTLSGetValue_Null )
{
    AssertTrue( XSTLSGetValue( NULL ) == NULL );
}

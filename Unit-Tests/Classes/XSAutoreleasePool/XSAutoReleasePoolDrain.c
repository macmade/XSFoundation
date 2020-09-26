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
 * @file        XSAutoReleasePoolDrain.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSAutoreleasePool, XSAutoReleasePoolDrain )
{
    XSAutoreleasePoolRef ap;
    char *               objects[ 1024 ];

    ap = XSAutoreleasePoolCreate();

    AssertTrue( ap != NULL );

    for( size_t i = 0; i < 1024; i++ )
    {
        objects[ i ] = XSAlloc( 8 );

        AssertTrue( objects[ i ] != NULL );
        XSRetain( objects[ i ] );
        AssertEqual( XSGetRetainCount( objects[ i ] ), 2 );

        XSAutoreleasePoolAddObject( ap, objects[ i ] );
        AssertEqual( XSGetRetainCount( objects[ i ] ), 2 );
    }

    XSAutoreleasePoolDrain( ap );

    for( size_t i = 0; i < 1024; i++ )
    {
        AssertEqual( XSGetRetainCount( objects[ i ] ), 1 );
    }

    XSAutoreleasePoolDrain( ap );

    for( size_t i = 0; i < 1024; i++ )
    {
        AssertEqual( XSGetRetainCount( objects[ i ] ), 1 );
    }

    XSRelease( ap );

    for( size_t i = 0; i < 1024; i++ )
    {
        AssertEqual( XSGetRetainCount( objects[ i ] ), 1 );
        XSRelease( objects[ i ] );
    }
}

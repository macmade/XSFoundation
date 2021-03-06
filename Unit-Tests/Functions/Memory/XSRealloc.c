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
 * @file        XSRealloc.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>
#include <string.h>

Test( Memory, XSRealloc )
{
    char * memory = XSAlloc( 42 );

    AssertTrue( memory != NULL );
    AssertEqual( XSGetRetainCount( memory ), 1 );

    memset( memory, 1, 42 );

    memory = XSRealloc( memory, 1024 );

    AssertTrue( memory != NULL );
    AssertEqual( XSGetRetainCount( memory ), 1 );

    for( size_t i = 0; i < 1024; i++ )
    {
        if( i < 42 )
        {
            AssertEqual( memory[ i ], 1 );
        }
        else
        {
            AssertEqual( memory[ i ], 0 );
        }
    }

    XSRetain( memory );
    AssertEqual( XSGetRetainCount( memory ), 2 );

    memory = XSRealloc( memory, 42 );

    AssertTrue( memory != NULL );
    AssertEqual( XSGetRetainCount( memory ), 2 );

    for( size_t i = 0; i < 42; i++ )
    {
        AssertEqual( memory[ i ], 1 );
    }

    XSRelease( memory );
    XSRelease( memory );
}

Test( Memory, XSRealloc_Null )
{
    AssertTrue( XSRealloc( NULL, 42 ) == NULL );
}

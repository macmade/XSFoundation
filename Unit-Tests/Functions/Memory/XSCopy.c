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
 * @file        XSCopy.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>
#include <string.h>

Test( Memory, XSCopy )
{
    char * memory = XSAlloc( 42 );

    AssertTrue( memory != NULL );

    XSRetain( memory );
    AssertEqual( XSGetRetainCount( memory ), 2 );

    memset( memory, 1, 42 );

    {
        char * copy = XSCopy( memory );

        AssertEqual( XSGetRetainCount( memory ), 2 );
        AssertEqual( XSGetRetainCount( copy ), 1 );

        for( size_t i = 0; i < 42; i++ )
        {
            AssertEqual( memory[ i ], 1 );
            AssertEqual( copy[ i ], 1 );
        }

        XSRelease( copy );
    }

    XSRelease( memory );
    XSRelease( memory );
}

Test( Memory, XSCopy_Null )
{
    AssertTrue( XSCopy( NULL ) == NULL );
}

Test( Memory, XSCopy_Object )
{
    XSStringRef str1 = XSStringCreateWithCString( "hello, world" );
    XSStringRef str2 = XSCopy( str1 );

    AssertTrue( str2 != NULL );
    AssertTrue( str2 != str1 );

    AssertTrue( XSRuntimeIsInstance( str2 ) );
    AssertTrue( XSRuntimeGetClassID( str1 ) == XSRuntimeGetClassID( str2 ) );
    AssertTrue( XSEquals( str1, str2 ) );

    XSRelease( str1 );
    XSRelease( str2 );
}

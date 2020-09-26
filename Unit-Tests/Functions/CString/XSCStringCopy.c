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
 * @file        XSCStringCopy.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( CString, XSCStringCopy_Full )
{
    {
        char buf[ 1024 ];

        buf[ 1023 ] = 42;

        AssertTrue( XSCStringCopy( buf, sizeof( buf ), "hello, world", 0 ) );
        AssertStringEqual( buf, "hello, world" );
        AssertEqual( buf[ 1023 ], 0 );
    }

    {
        char buf[ 1024 ];

        buf[ 0 ]    = 42;
        buf[ 1023 ] = 42;

        AssertTrue( XSCStringCopy( buf, 13, "hello, world", 0 ) );
        AssertStringEqual( buf, "hello, world" );
        AssertEqual( buf[ 1023 ], 42 );
    }

    {
        char buf[ 1024 ];

        buf[ 0 ]    = 42;
        buf[ 1023 ] = 42;

        AssertTrue( XSCStringCopy( buf, 13, "hello, world", 12 ) );
        AssertStringEqual( buf, "hello, world" );
        AssertEqual( buf[ 1023 ], 42 );
    }
}

Test( CString, XSCStringCopy_Null )
{
    AssertFalse( XSCStringCopy( NULL, 0, "hello, world", 0 ) );

    {
        char buf[ 1024 ];

        buf[ 0 ]    = 42;
        buf[ 1023 ] = 42;

        AssertTrue( XSCStringCopy( buf, sizeof( buf ), NULL, 0 ) );
        AssertEqual( buf[ 0 ], 0 );
        AssertEqual( buf[ 1023 ], 0 );
    }
}

Test( CString, XSCStringCopy_Partial )
{
    char buf[ 1024 ];

    buf[ 1023 ] = 42;

    AssertTrue( XSCStringCopy( buf, sizeof( buf ), "hello, world", 5 ) );
    AssertStringEqual( buf, "hello" );
    AssertEqual( buf[ 1023 ], 0 );
}

Test( CString, XSCStringCopy_Error )
{
    {
        char buf[ 1024 ];

        buf[ 0 ]    = 42;
        buf[ 1023 ] = 42;

        AssertFalse( XSCStringCopy( buf, 0, "hello, world", 0 ) );
        AssertEqual( buf[ 0 ], 42 );
        AssertEqual( buf[ 1023 ], 42 );
    }

    {
        char buf[ 1024 ];

        buf[ 0 ]    = 42;
        buf[ 1023 ] = 42;

        AssertFalse( XSCStringCopy( buf, 12, "hello, world", 0 ) );
        AssertEqual( buf[ 0 ], 0 );
        AssertEqual( buf[ 1023 ], 42 );
    }
}

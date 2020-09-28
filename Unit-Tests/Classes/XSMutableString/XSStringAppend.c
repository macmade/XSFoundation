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
 * @file        XSStringAppend.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSMutableString, XSStringAppend )
{
    XSMutableStringRef mutable = XSStringCreateMutable();
    XSStringRef str1           = XSStringCreateWithCString( "hello" );
    XSStringRef str2           = XSStringCreateWithCString( "" );
    XSStringRef str3           = XSStringCreateWithCString( ", world" );
    XSStringRef str4           = XSStringCreateWithCString( "." );

    XSStringAppend( mutable, str1 );
    AssertEqual( XSStringGetLength( mutable ), 5 );
    AssertStringEqual( XSStringGetCString( mutable ), "hello" );

    XSStringAppend( mutable, NULL );
    AssertEqual( XSStringGetLength( mutable ), 5 );
    AssertStringEqual( XSStringGetCString( mutable ), "hello" );

    XSStringAppend( mutable, str2 );
    AssertEqual( XSStringGetLength( mutable ), 5 );
    AssertStringEqual( XSStringGetCString( mutable ), "hello" );

    XSStringAppend( mutable, str3 );
    AssertEqual( XSStringGetLength( mutable ), 12 );
    AssertStringEqual( XSStringGetCString( mutable ), "hello, world" );

    {
        size_t expected = XSStringGetLength( mutable );

        for( size_t i = 0; i < 1024; i++ )
        {
            expected++;

            XSStringAppend( mutable, str4 );
            AssertEqual( XSStringGetLength( mutable ), expected );
        }
    }

    XSRelease( mutable );
    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( str3 );
    XSRelease( str4 );
}

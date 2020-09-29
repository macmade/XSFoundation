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
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSString, XSStringMakeConstantString )
{
    XSStringRef str1 = XSStringMakeConstantString( "hello, world" );
    XSStringRef str2 = XSStringMakeConstantString( "hello, world" );
    XSStringRef str3 = XSStringMakeConstantString( "hello, universe" );
    XSStringRef str4 = XSStringMakeConstantString( "" );
    XSStringRef str5 = XSStringMakeConstantString( NULL );

    AssertTrue( str1 != NULL );
    AssertTrue( str2 != NULL );
    AssertTrue( str3 != NULL );
    AssertTrue( str4 != NULL );
    AssertTrue( str5 != NULL );

    AssertTrue( XSRuntimeIsConstantObject( str1 ) );
    AssertTrue( XSRuntimeIsConstantObject( str2 ) );
    AssertTrue( XSRuntimeIsConstantObject( str3 ) );
    AssertTrue( XSRuntimeIsConstantObject( str4 ) );
    AssertTrue( XSRuntimeIsConstantObject( str5 ) );

    AssertEqual( XSStringGetLength( str1 ), 12 );
    AssertEqual( XSStringGetLength( str2 ), 12 );
    AssertEqual( XSStringGetLength( str3 ), 15 );
    AssertEqual( XSStringGetLength( str4 ), 0 );
    AssertEqual( XSStringGetLength( str5 ), 0 );

    AssertStringEqual( XSStringGetCString( str1 ), "hello, world" );
    AssertStringEqual( XSStringGetCString( str2 ), "hello, world" );
    AssertStringEqual( XSStringGetCString( str3 ), "hello, universe" );
    AssertStringEqual( XSStringGetCString( str4 ), "" );
    AssertStringEqual( XSStringGetCString( str5 ), "" );

    AssertTrue( str1 == str2 );
    AssertTrue( str4 == str5 );
}

Test( XSString, XSStringMakeConstantString_Different )
{
    char        cp1[] = "hello, world";
    char        cp2[] = "hello, world";
    XSStringRef str1  = XSStringMakeConstantString( cp1 );
    XSStringRef str2  = XSStringMakeConstantString( cp2 );

    AssertTrue( cp1 != cp2 );
    AssertTrue( str1 == str2 );
}

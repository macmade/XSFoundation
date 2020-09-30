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
 * @file        XSStringCreateSubstringWithRange.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSString, XSStringCreateSubstringWithRange )
{
    XSStringRef str   = XSStringCreateWithCString( "hello, world" );
    XSStringRef null1 = XSStringCreateSubstringWithRange( str, XSMakeRange( 0, 0 ) );
    XSStringRef null2 = XSStringCreateSubstringWithRange( str, XSMakeRange( 1, 0 ) );
    XSStringRef null3 = XSStringCreateSubstringWithRange( str, XSMakeRange( 0, 14 ) );
    XSStringRef null4 = XSStringCreateSubstringWithRange( str, XSMakeRange( 1, 13 ) );
    XSStringRef null5 = XSStringCreateSubstringWithRange( str, XSMakeRange( 13, 1 ) );
    XSStringRef null6 = XSStringCreateSubstringWithRange( str, XSMakeRange( 12, 2 ) );
    XSStringRef sub1  = XSStringCreateSubstringWithRange( str, XSMakeRange( 0, 1 ) );
    XSStringRef sub2  = XSStringCreateSubstringWithRange( str, XSMakeRange( 1, 1 ) );
    XSStringRef sub3  = XSStringCreateSubstringWithRange( str, XSMakeRange( 0, 2 ) );
    XSStringRef sub4  = XSStringCreateSubstringWithRange( str, XSMakeRange( 2, 2 ) );
    XSStringRef sub5  = XSStringCreateSubstringWithRange( str, XSMakeRange( 11, 1 ) );
    XSStringRef sub6  = XSStringCreateSubstringWithRange( str, XSMakeRange( 11, 2 ) );
    XSStringRef sub7  = XSStringCreateSubstringWithRange( str, XSMakeRange( 12, 1 ) );
    XSStringRef sub8  = XSStringCreateSubstringWithRange( str, XSMakeRange( 0, 12 ) );
    XSStringRef sub9  = XSStringCreateSubstringWithRange( str, XSMakeRange( 0, 13 ) );

    AssertTrue( XSStringCreateSubstringWithRange( NULL, XSMakeRange( 1, 1 ) ) == NULL );

    AssertTrue( null1 == NULL );
    AssertTrue( null2 == NULL );
    AssertTrue( null3 == NULL );
    AssertTrue( null4 == NULL );
    AssertTrue( null5 == NULL );
    AssertTrue( null6 == NULL );

    AssertTrue( sub1 != NULL );
    AssertTrue( sub2 != NULL );
    AssertTrue( sub3 != NULL );
    AssertTrue( sub4 != NULL );
    AssertTrue( sub5 != NULL );
    AssertTrue( sub6 != NULL );
    AssertTrue( sub7 != NULL );
    AssertTrue( sub8 != NULL );
    AssertTrue( sub9 != NULL );

    AssertEqual( XSStringGetLength( sub1 ), 1u );
    AssertEqual( XSStringGetLength( sub2 ), 1u );
    AssertEqual( XSStringGetLength( sub3 ), 2u );
    AssertEqual( XSStringGetLength( sub4 ), 2u );
    AssertEqual( XSStringGetLength( sub5 ), 1u );
    AssertEqual( XSStringGetLength( sub6 ), 1u );
    AssertEqual( XSStringGetLength( sub7 ), 0u );
    AssertEqual( XSStringGetLength( sub8 ), 12u );
    AssertEqual( XSStringGetLength( sub9 ), 12u );

    AssertStringEqual( XSStringGetCString( sub1 ), "h" );
    AssertStringEqual( XSStringGetCString( sub2 ), "e" );
    AssertStringEqual( XSStringGetCString( sub3 ), "he" );
    AssertStringEqual( XSStringGetCString( sub4 ), "ll" );
    AssertStringEqual( XSStringGetCString( sub5 ), "d" );
    AssertStringEqual( XSStringGetCString( sub6 ), "d" );
    AssertStringEqual( XSStringGetCString( sub7 ), "" );
    AssertStringEqual( XSStringGetCString( sub8 ), "hello, world" );
    AssertStringEqual( XSStringGetCString( sub9 ), "hello, world" );

    AssertTrue( XSRuntimeIsConstantObject( sub7 ) );

    XSRelease( str );
    XSRelease( sub1 );
    XSRelease( sub2 );
    XSRelease( sub3 );
    XSRelease( sub4 );
    XSRelease( sub5 );
    XSRelease( sub6 );
    XSRelease( sub7 );
    XSRelease( sub8 );
    XSRelease( sub9 );
}

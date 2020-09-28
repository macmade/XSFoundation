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
 * @file        XSEquals.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( Memory, XSEquals )
{
    char * mem1 = XSAlloc( 10 );
    char * mem2 = XSAlloc( 10 );

    AssertTrue( mem1 != NULL );
    AssertTrue( mem2 != NULL );

    for( size_t i = 0; i < 10; i++ )
    {
        mem1[ i ] = 42;
        mem2[ i ] = 42;
    }

    AssertTrue( XSEquals( mem1, mem1 ) );
    AssertFalse( XSEquals( mem1, mem2 ) );

    XSRelease( mem1 );
    XSRelease( mem2 );
}

Test( Memory, XSEquals_Null )
{
    char * mem1 = XSAlloc( 10 );

    AssertFalse( XSEquals( mem1, NULL ) );
    AssertFalse( XSEquals( NULL, mem1 ) );
    AssertFalse( XSEquals( NULL, NULL ) );

    XSRelease( mem1 );
}

Test( Memory, XSEquals_Object_NoCallback )
{
    XSAutoreleasePoolRef ap1 = XSAutoreleasePoolCreate();
    XSAutoreleasePoolRef ap2 = XSAutoreleasePoolCreate();

    AssertFalse( XSEquals( ap1, NULL ) );
    AssertFalse( XSEquals( NULL, ap1 ) );

    AssertTrue( XSEquals( ap1, ap1 ) );
    AssertFalse( XSEquals( ap1, ap2 ) );

    XSRelease( ap1 );
    XSRelease( ap2 );
}

Test( Memory, XSEquals_Object_Callback )
{
    XSStringRef str1 = XSStringCreateWithCString( "hello, world" );
    XSStringRef str2 = XSStringCreateWithCString( "hello, world" );
    XSStringRef str3 = XSStringCreateWithCString( "hello, universe" );

    AssertFalse( XSEquals( str1, NULL ) );
    AssertFalse( XSEquals( NULL, str2 ) );

    AssertTrue( XSEquals( str1, str1 ) );
    AssertTrue( XSEquals( str1, str2 ) );
    AssertFalse( XSEquals( str1, str3 ) );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( str3 );
}

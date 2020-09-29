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
 * @file        XSRuntimeGetDescription.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( Runtime, XSRuntimeGetDescription )
{
    const char *         mem     = XSAlloc( 42 );
    XSStringRef          str     = XSStringCreateWithCString( "hello, world" );
    XSAutoreleasePoolRef ap      = XSAutoreleasePoolCreate();
    XSBooleanRef         boolean = XSBooleanTrue();
    XSStringRef          d1      = XSStringCreateWithFormat( "<%p>", ( const void * )mem );
    XSStringRef          d2      = XSStringCreateWithFormat( "<XSString %p> hello, world", ( const void * )str );
    XSStringRef          d3      = XSStringCreateWithFormat( "<XSAutoreleasePool %p>", ( const void * )ap );
    XSStringRef          d4      = XSStringCreateWithFormat( "<XSBoolean %p> True", ( const void * )boolean );

    AssertStringEqual( XSStringGetCString( XSRuntimeGetDescription( NULL ) ), "(null)" );
    AssertStringEqual( XSStringGetCString( XSRuntimeGetDescription( mem ) ), XSStringGetCString( d1 ) );
    AssertStringEqual( XSStringGetCString( XSRuntimeGetDescription( str ) ), XSStringGetCString( d2 ) );
    AssertStringEqual( XSStringGetCString( XSRuntimeGetDescription( ap ) ), XSStringGetCString( d3 ) );
    AssertStringEqual( XSStringGetCString( XSRuntimeGetDescription( boolean ) ), XSStringGetCString( d4 ) );

    XSRelease( mem );
    XSRelease( str );
    XSRelease( ap );
    XSRelease( d1 );
    XSRelease( d2 );
    XSRelease( d3 );
    XSRelease( d4 );
}

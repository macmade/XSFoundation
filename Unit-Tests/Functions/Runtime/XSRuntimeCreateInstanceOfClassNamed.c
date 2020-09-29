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
 * @file        XSRuntimeCreateInstanceOfClassNamed.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( Runtime, XSRuntimeCreateInstanceOfClassNamed )
{
    XSObjectRef          obj1 = XSRuntimeCreateInstanceOfClassNamed( NULL );
    XSObjectRef          obj2 = XSRuntimeCreateInstanceOfClassNamed( "NotAClass" );
    XSStringRef          str  = XSRuntimeCreateInstanceOfClassNamed( "XSString" );
    XSAutoreleasePoolRef ap   = XSRuntimeCreateInstanceOfClassNamed( "XSAutoreleasePool" );

    AssertTrue( obj1 == NULL );
    AssertTrue( obj2 == NULL );
    AssertTrue( str != NULL );
    AssertTrue( ap != NULL );

    AssertTrue( XSRuntimeGetClassID( str ) == XSStringGetClassID() );
    AssertTrue( XSRuntimeGetClassID( ap ) == XSAutoreleasePoolGetClassID() );

    AssertTrue( XSRuntimeIsInstance( str ) );
    AssertTrue( XSRuntimeIsInstance( ap ) );

    XSRelease( str );
    XSRelease( ap );
    AssertTrue( true );
}

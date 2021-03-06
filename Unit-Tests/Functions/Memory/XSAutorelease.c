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
 * @file        XSAutorelease.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( Memory, XSAutorelease )
{
    void * mem = XSAlloc( 128 );

    XSRetain( mem );
    XSRetain( mem );
    AssertEqual( XSGetRetainCount( mem ), 3 );

    XSAutorelease( mem );
    XSAutoreleasePoolDrain( XSAutoreleasePoolGetCurrent() );

    AssertEqual( XSGetRetainCount( mem ), 3 );

    {
        XSAutoreleasePoolRef ap = XSAutoreleasePoolCreate();

        XSAutorelease( mem );
        XSAutoreleasePoolDrain( ap );
        AssertEqual( XSGetRetainCount( mem ), 2 );

        XSAutorelease( mem );
        XSRelease( ap );
    }

    AssertEqual( XSGetRetainCount( mem ), 1 );
    XSRelease( mem );
}

Test( Memory, XSAutorelease_Null )
{
    XSAutorelease( NULL );
    AssertTrue( true );
}

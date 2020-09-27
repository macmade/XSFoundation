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
 * @file        XSAutoreleasePoolGetCurrent.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSAutoreleasePool, XSAutoreleasePoolGetCurrent )
{
    XSAutoreleasePoolRef ap1;
    XSAutoreleasePoolRef ap2;

    AssertTrue( XSAutoreleasePoolGetCurrent() == NULL );

    ap1 = XSAutoreleasePoolCreate();

    AssertTrue( XSAutoreleasePoolGetCurrent() == ap1 );

    ap2 = XSAutoreleasePoolCreate();

    AssertTrue( XSAutoreleasePoolGetCurrent() == ap2 );

    XSRelease( ap2 );

    AssertTrue( XSAutoreleasePoolGetCurrent() == ap1 );

    XSRelease( ap1 );

    AssertTrue( XSAutoreleasePoolGetCurrent() == NULL );
}

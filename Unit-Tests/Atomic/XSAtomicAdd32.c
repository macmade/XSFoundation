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
 * @file        XSAtomicAdd32.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( Atomic, XSAtomicAdd32 )
{
    int32_t i = 0;

    AssertEqual( XSAtomicAdd32( 1, &i ), 1 );
    AssertEqual( i, 1 );
    AssertEqual( XSAtomicAdd32( 1, &i ), 2 );
    AssertEqual( i, 2 );
    AssertEqual( XSAtomicAdd32( 40, &i ), 42 );
    AssertEqual( i, 42 );
    AssertEqual( XSAtomicAdd32( -42, &i ), 0 );
    AssertEqual( i, 0 );
    AssertEqual( XSAtomicAdd32( -42, &i ), -42 );
    AssertEqual( i, -42 );
}

Test( Atomic, XSAtomicAdd32_Min )
{
    int32_t i = INT32_MIN;

    AssertEqual( XSAtomicAdd32( -1, &i ), INT32_MAX );
}

Test( Atomic, XSAtomicAdd32_Max )
{
    int32_t i = INT32_MAX;

    AssertEqual( XSAtomicAdd32( 1, &i ), INT32_MIN );
}

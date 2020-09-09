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

/* $Id$ */

/*!
 * @file        XSAtomic_CompareAndSwap64.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSAtomic_CompareAndSwap64
 */

#include <XS/XS.h>

#if defined( __XEOS__ )

#include <system.h>

/* XEOS */
bool XSAtomic_CompareAndSwap64( XSInt64 oldValue, XSInt64 newValue, volatile XSInt64 * value )
{
    return ( System_Atomic_CompareAndSwap64( ( int64_t )oldValue, ( int64_t )newValue, ( volatile int64_t * )value ) ) ? true : false;
}

#elif defined( _WIN32 )

#include <Windows.h>
#include <Winnt.h>

/* Windows */
bool XSAtomic_CompareAndSwap64( XSInt64 oldValue, XSInt64 newValue, volatile XSInt64 * value )
{
    return ( InterlockedCompareExchange64( ( volatile LONGLONG * )value, newValue, oldValue ) == oldValue ) ? true : false;
}

#else

#include <libkern/OSAtomic.h>

#pragma clang diagnostic ignored "-Wdeprecated-declarations"

/* Mac OS X */
bool XSAtomic_CompareAndSwap64( XSInt64 oldValue, XSInt64 newValue, volatile XSInt64 * value )
{
    return ( OSAtomicCompareAndSwap64( ( int64_t )oldValue, ( int64_t )newValue, ( volatile int64_t * )value ) ) ? true : false;
}

#endif

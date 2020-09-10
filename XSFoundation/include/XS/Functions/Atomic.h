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
 * @header      Atomic.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Atomic functions
 */

#ifndef XS_FUNCTIONS_ATOMIC_H
#define XS_FUNCTIONS_ATOMIC_H

#include <XS/Macros.h>
#include <stdint.h>
#include <stdbool.h>

XS_EXTERN_C_BEGIN

/*!
 * @function    XSAtomicIncrement32
 * @abstract    Atomically increments a 32 bits value
 * @param       value   The 32 bits value to increment
 * @return      The new value
 */
XS_EXPORT int32_t XSAtomicIncrement32( volatile int32_t * value );

/*!
 * @function    XSAtomicIncrement64
 * @abstract    Atomically increments a 64 bits value
 * @param       value   The 64 bits value to increment
 * @return      The new value
 */
XS_EXPORT int64_t XSAtomicIncrement64( volatile int64_t * value );

/*!
 * @function    XSAtomicDecrement32
 * @abstract    Atomically decrements a 32 bits value
 * @param       value   The 32 bits value to decrement
 * @return      The new value
 */
XS_EXPORT int32_t XSAtomicDecrement32( volatile int32_t * value );

/*!
 * @function    XSAtomicDecrement64
 * @abstract    Atomically decrements a 64 bits value
 * @param       value   The 64 bits value to decrement
 * @return      The new value
 */
XS_EXPORT int64_t XSAtomicDecrement64( volatile int64_t * value );

/*!
 * @function    XSAtomicCompareAndSwap32
 * @abstract    Atomically compares and swaps a 32 bits value
 * @param       oldValue    The 32 bits value to test
 * @param       newValue    The 32 bits value to swap
 * @param       value       The 32 bits value to compare and swap
 * @return      True if the comparison was equal and the swap occured
 */
XS_EXPORT bool XSAtomicCompareAndSwap32( int32_t oldValue, int32_t newValue, volatile int32_t * value );

/*!
 * @function    XSAtomicCompareAndSwap64
 * @abstract    Atomically compares and swaps a 64 bits value
 * @param       oldValue    The 64 bits value to test
 * @param       newValue    The 64 bits value to swap
 * @param       value       The 64 bits value to compare and swap
 * @return      True if the comparison was equal and the swap occured
 */
XS_EXPORT bool XSAtomicCompareAndSwap64( int64_t oldValue, int64_t newValue, volatile int64_t * value );

/*!
 * @function    XSAtomicCompareAndSwapPointer
 * @abstract    Atomically compares and swaps a pointer value
 * @param       oldValue    The pointer value to test
 * @param       newValue    The pointer value to swap
 * @param       value       The pointer value to compare and swap
 * @return      True if the comparison was equal and the swap occured
 */
XS_EXPORT bool XSAtomicCompareAndSwapPointer( void * oldValue, void * newValue, void * volatile * value );

/*!
 * @function    XSAtomicAdd32
 * @abstract    Atomically adds to a 32 bits value
 * @param       amount  The amount to add
 * @param       value   The 32 bits value to modify
 * @return      The new value
 */
XS_EXPORT int32_t XSAtomicAdd32( int32_t amount, volatile int32_t * value );

/*!
 * @function    XSAtomicAdd64
 * @abstract    Atomically adds to a 64 bits value
 * @param       amount  The amount to add
 * @param       value   The 64 bits value to modify
 * @return      The new value
 */
XS_EXPORT int64_t XSAtomicAdd64( int64_t amount, volatile int64_t * value );

/*!
 * @function    XSAtomic_Read32
 * @abstract    Atomically reads a 32 bits value
 * @param       value   The 32 bits value to read
 * @return      The 32 bits value
 */
XS_EXPORT int32_t XSAtomicRead32( volatile int32_t * value );

/*!
 * @function    XSAtomic_Read64
 * @abstract    Atomically reads a 64 bits value
 * @param       value   The 64 bits value to read
 * @return      The 64 bits value
 */
XS_EXPORT int64_t XSAtomicRead64( volatile int64_t * value );

XS_EXTERN_C_END

#endif /* XS_FUNCTIONS_ATOMIC_H */

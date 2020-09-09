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
 * @header      XSAtomic.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSFoundation atomic functions
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_FUNCTIONS_XS_ATOMIC_H__
#define __XS_FUNCTIONS_XS_ATOMIC_H__

XS_EXTERN_C_BEGIN

#include <XS/XSTypes.h>

/*!
 * @function    XSAtomic_Increment32
 * @abstract    Atomically increments a 32 bits value
 * @param       value   The 32 bits value to increment
 * @return      The new value
 */
XS_EXPORT XSInt32 XSAtomic_Increment32( volatile XSInt32 * value );

/*!
 * @function    XSAtomic_Increment64
 * @abstract    Atomically increments a 64 bits value
 * @param       value   The 64 bits value to increment
 * @return      The new value
 */
XS_EXPORT XSInt64 XSAtomic_Increment64( volatile XSInt64 * value );

/*!
 * @function    XSAtomic_IncrementInteger
 * @abstract    Atomically increments an integer value
 * @param       value   The integer value to increment
 * @return      The new value
 */
XS_EXPORT XSInteger XSAtomic_IncrementInteger( volatile XSInteger * value );

/*!
 * @function    XSAtomic_Decrement32
 * @abstract    Atomically decrements a 32 bits value
 * @param       value   The 32 bits value to decrement
 * @return      The new value
 */
XS_EXPORT XSInt32 XSAtomic_Decrement32( volatile XSInt32 * value );

/*!
 * @function    XSAtomic_Decrement64
 * @abstract    Atomically decrements a 64 bits value
 * @param       value   The 64 bits value to decrement
 * @return      The new value
 */
XS_EXPORT XSInt64 XSAtomic_Decrement64( volatile XSInt64 * value );

/*!
 * @function    XSAtomic_DecrementInteger
 * @abstract    Atomically decrements an integer value
 * @param       value   The integer value to decrement
 * @return      The new value
 */
XS_EXPORT XSInteger XSAtomic_DecrementInteger( volatile XSInteger * value );

/*!
 * @function    XSAtomic_CompareAndSwap32
 * @abstract    Atomically compares and swaps a 32 bits value
 * @param       oldValue    The 32 bits value to test
 * @param       newValue    The 32 bits value to swap
 * @param       value       The 32 bits value to compare and swap
 * @return      True if the comparison was equal and the swap occured
 */
XS_EXPORT bool XSAtomic_CompareAndSwap32( XSInt32 oldValue, XSInt32 newValue, volatile XSInt32 * value );

/*!
 * @function    XSAtomic_CompareAndSwap64
 * @abstract    Atomically compares and swaps a 64 bits value
 * @param       oldValue    The 64 bits value to test
 * @param       newValue    The 64 bits value to swap
 * @param       value       The 64 bits value to compare and swap
 * @return      True if the comparison was equal and the swap occured
 */
XS_EXPORT bool XSAtomic_CompareAndSwap64( XSInt64 oldValue, XSInt64 newValue, volatile XSInt64 * value );

/*!
 * @function    XSAtomic_CompareAndSwapInteger
 * @abstract    Atomically compares and swaps an integer value
 * @param       oldValue    The integer value to test
 * @param       newValue    The integer value to swap
 * @param       value       The integer value to compare and swap
 * @return      True if the comparison was equal and the swap occured
 */
XS_EXPORT bool XSAtomic_CompareAndSwapInteger( XSInteger oldValue, XSInteger newValue, volatile XSInteger * value );

/*!
 * @function    XSAtomic_CompareAndSwapPointer
 * @abstract    Atomically compares and swaps a pointer value
 * @param       oldValue    The pointer value to test
 * @param       newValue    The pointer value to swap
 * @param       value       The pointer value to compare and swap
 * @return      True if the comparison was equal and the swap occured
 */
XS_EXPORT bool XSAtomic_CompareAndSwapPointer( void * oldValue, void * newValue, void * volatile * value );

/*!
 * @function    XSAtomic_Add32
 * @abstract    Atomically adds to a 32 bits value
 * @param       amount  The amount to add
 * @param       value   The 32 bits value to modify
 * @return      The new value
 */
XSInt32 XSAtomic_Add32( XSInt32 amount, volatile XSInt32 * value );

/*!
 * @function    XSAtomic_Add64
 * @abstract    Atomically adds to a 64 bits value
 * @param       amount  The amount to add
 * @param       value   The 64 bits value to modify
 * @return      The new value
 */
XSInt64 XSAtomic_Add64( XSInt64 amount, volatile XSInt64 * value );

/*!
 * @function    XSAtomic_AddInteger
 * @abstract    Atomically adds to an integer value
 * @param       amount  The amount to add
 * @param       value   The integer value to modify
 * @return      The new value
 */
XSInteger XSAtomic_AddInteger( XSInteger amount, volatile XSInteger * value );

/*!
 * @function    XSAtomic_Read32
 * @abstract    Atomically reads a 32 bits value
 * @param       value   The 32 bits value to read
 * @return      The 32 bits value
 */
XSInt32 XSAtomic_Read32( volatile XSInt32 * value );

/*!
 * @function    XSAtomic_Read64
 * @abstract    Atomically reads a 64 bits value
 * @param       value   The 64 bits value to read
 * @return      The 64 bits value
 */
XSInt64 XSAtomic_Read64( volatile XSInt64 * value );

/*!
 * @function    XSAtomic_ReadInteger
 * @abstract    Atomically reads an integer value
 * @param       value   The integer value to read
 * @return      The integer value
 */
XSInteger XSAtomic_ReadInteger( volatile XSInteger * value );

XS_EXTERN_C_END

#endif /* __XS_FUNCTIONS_XS_ATOMIC_H__ */

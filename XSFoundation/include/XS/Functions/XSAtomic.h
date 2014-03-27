/*******************************************************************************
 * XSFoundation - XEOS C Foundation Library
 * 
 * Copyright (c) 2010-2014, Jean-David Gadina - www.xs-labs.com
 * All rights reserved.
 * 
 * XEOS Software License - Version 1.0 - December 21, 2012
 * 
 * Permission is hereby granted, free of charge, to any person or organisation
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to deal in the Software, with or without
 * modification, without restriction, including without limitation the rights
 * to use, execute, display, copy, reproduce, transmit, publish, distribute,
 * modify, merge, prepare derivative works of the Software, and to permit
 * third-parties to whom the Software is furnished to do so, all subject to the
 * following conditions:
 * 
 *      1.  Redistributions of source code, in whole or in part, must retain the
 *          above copyright notice and this entire statement, including the
 *          above license grant, this restriction and the following disclaimer.
 * 
 *      2.  Redistributions in binary form must reproduce the above copyright
 *          notice and this entire statement, including the above license grant,
 *          this restriction and the following disclaimer in the documentation
 *          and/or other materials provided with the distribution, unless the
 *          Software is distributed by the copyright owner as a library.
 *          A "library" means a collection of software functions and/or data
 *          prepared so as to be conveniently linked with application programs
 *          (which use some of those functions and data) to form executables.
 * 
 *      3.  The Software, or any substancial portion of the Software shall not
 *          be combined, included, derived, or linked (statically or
 *          dynamically) with software or libraries licensed under the terms
 *          of any GNU software license, including, but not limited to, the GNU
 *          General Public License (GNU/GPL) or the GNU Lesser General Public
 *          License (GNU/LGPL).
 * 
 *      4.  All advertising materials mentioning features or use of this
 *          software must display an acknowledgement stating that the product
 *          includes software developed by the copyright owner.
 * 
 *      5.  Neither the name of the copyright owner nor the names of its
 *          contributors may be used to endorse or promote products derived from
 *          this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT OWNER AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE, TITLE AND NON-INFRINGEMENT ARE DISCLAIMED.
 * 
 * IN NO EVENT SHALL THE COPYRIGHT OWNER, CONTRIBUTORS OR ANYONE DISTRIBUTING
 * THE SOFTWARE BE LIABLE FOR ANY CLAIM, DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN ACTION OF CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/* $Id$ */

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

XS_EXTERN_C_END

#endif /* __XS_FUNCTIONS_XS_ATOMIC_H__ */

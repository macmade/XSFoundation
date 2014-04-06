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
 * @header      XSSemaphore.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSSemaphore class
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_SEMAPHORE_H__
#define __XS_CLASSES_XS_SEMAPHORE_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     XSSemaphoreRef
 * @abstract    Opaque type for XSSemaphore
 */
typedef struct __XSSemaphore * XSSemaphoreRef;

/*!
 * @function    XSSemaphore_GetClassID
 * @abstract    Gets the class ID for XSSemaphore
 * @return      The class ID for XSSemaphore
 */
XS_EXPORT XSStatic XSClassID XSSemaphore_GetClassID( void );

/*!
 * @function    XSSemaphore_Create
 * @abstract    Creates an unnamed semaphore
 * @param       count   The maximum count for the semaphore
 * @return      The semaphore object
 */
XS_EXPORT XSStatic XSSemaphoreRef XSSemaphore_Create( XSUInteger count );

/*!
 * @function    XSSemaphore_GetClassID
 * @abstract    Creates a named semaphore
 * @param       name    The semaphore name
 * @param       count   The maximum count for the semaphore
 * @return      The semaphore object
 */
XS_EXPORT XSStatic XSSemaphoreRef XSSemaphore_CreateWithName( const char * name, XSUInteger count );

/*!
 * @function    XSSemaphore_Wait
 * @abstract    Locks a semaphore
 * @param       semaphore   The semaphore object
 */
XS_EXPORT void XSSemaphore_Wait( XSSemaphoreRef semaphore );

/*!
 * @function    XSSemaphore_TryWait
 * @abstract    Tries to lock a semaphore
 * @param       semaphore   The semaphore object
 * @discussion  If the semaphore can't be locked, this function will return
 *              immediately, rather than waiting.
 * @result      True if the semaphore was locked, otherwise false
 */
XS_EXPORT bool XSSemaphore_TryWait( XSSemaphoreRef semaphore );

/*!
 * @function    XSSemaphore_Signal
 * @abstract    Unlocks a semaphore
 * @param       semaphore   The semaphore object
 */
XS_EXPORT void XSSemaphore_Signal( XSSemaphoreRef semaphore );

/*!
 * @function    XSSemaphore_Signal
 * @abstract    Checks whether a semaphore is named or not
 * @param       semaphore   The semaphore object
 * @result      True if the semaphore is named, otherwise false
 */
XS_EXPORT bool XSSemaphore_IsNamed( XSSemaphoreRef semaphore );

/*!
 * @function    XSSemaphore_GetName
 * @abstract    Gets the name of a semaphore
 * @param       semaphore   The semaphore object
 * @return      The semaphore name, or NULL if the semaphore is unnamed
 */
XS_EXPORT const char * XSSemaphore_GetName( XSSemaphoreRef semaphore );

#endif /* __XS_CLASSES_XS_SEMAPHORE_H__ */

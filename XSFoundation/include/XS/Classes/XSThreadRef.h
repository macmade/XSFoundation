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
 * @header      XSThreadRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSThread class
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_THREAD_H__
#define __XS_CLASSES_XS_THREAD_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     XSThreadRef
 * @abstract    Opaque type for XSThread
 */
typedef struct __XSThread * XSThreadRef;

/*!
 * @typedef     XSThread_Method
 * @abstract    Threaded method
 */
typedef void ( * XSThread_Method )( XSObjectRef object );

/*!
 * @typedef     XSThread_MethodWithArgument
 * @abstract    Threaded method with an argument
 */
typedef void ( * XSThread_MethodWithArgument )( XSObjectRef object, void * arg );

/*!
 * @typedef     XSThread_Function
 * @abstract    Threaded function
 */
typedef void ( * XSThread_Function )( void );

/*!
 * @typedef     XSThread_FunctionWithArgument
 * @abstract    Threaded function with an argument
 */
typedef void ( * XSThread_FunctionWithArgument )( void * arg );

/*!
 * @function    XSThread_GetClassID
 * @abstract    Gets the class ID for XSThread
 * @return      The class ID for XSThread
 */
XS_EXPORT XSStatic XSClassID XSThread_GetClassID( void );

/*!
 * @function    XSThread_GetMainThread
 * @abstract    Gets the instance of the main thread
 * @return      The instance of the main thread
 */
XS_EXPORT XSStatic XSThreadRef XSThread_GetMainThread( void );

/*!
 * @function    XSThread_GetCurrentThread
 * @abstract    Gets the instance of the current thread
 * @return      The instance of the current thread
 */
XS_EXPORT XSStatic XSThreadRef XSThread_GetCurrentThread( void );

/*!
 * @function    XSThread_GetCurrentThreadID
 * @abstract    Gets the instance of the current thread
 * @return      The instance of the current thread
 */
XS_EXPORT XSStatic XSUInteger XSThread_GetCurrentThreadID( void );

/*!
 * @function    XSThread_DetachMethod
 * @abstract    Creates a thread with an object's method as entry point
 * @param       object      The receiver object
 * @param       method      The receiver object's method to detach
 */
XS_EXPORT XSStatic void XSThread_DetachMethod( XSObjectRef object, XSThread_Method method );

/*!
 * @function    XSThread_DetachMethodWithArgument
 * @abstract    Creates a thread with an object's method as entry point and with an argument
 * @param       object      The receiver object
 * @param       method      The receiver object's method to detach
 * @param       arg         The argument to pass to the threaded method
 */
XS_EXPORT XSStatic void XSThread_DetachMethodWithArgument( XSObjectRef object, XSThread_MethodWithArgument method, void * arg );

/*!
 * @function    XSThread_DetachFunction
 * @abstract    Creates a thread with an object's method as entry point
 * @param       func        The function to detach
 */
XS_EXPORT XSStatic void XSThread_DetachFunction( XSThread_Function func );

/*!
 * @function    XSThread_DetachFunctionWithArgument
 * @abstract    Creates a thread with an object's method as entry point and with an argument
 * @param       func        The function to detach
 * @param       arg         The argument to pass to the threaded function
 */
XS_EXPORT XSStatic void XSThread_DetachFunctionWithArgument( XSThread_FunctionWithArgument func, void * arg );

/*!
 * @function    XSThread_GetID
 * @abstract    Gets the ID of a thread
 * @param       thread      The thread object
 * @return      The thread ID
 */
XS_EXPORT XSUInteger XSThread_GetID( XSThreadRef thread );

/*!
 * @function    XSThread_IsMainThread
 * @abstract    Checks if a thread is the main thread
 * @param       thread      The thread object
 * @return      True if the thread is the main thread, otherwise false
 */
XS_EXPORT bool XSThread_IsMainThread( XSThreadRef thread );


#endif /* __XS_CLASSES_XS_THREAD_H__ */

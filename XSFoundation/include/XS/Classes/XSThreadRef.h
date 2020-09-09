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
typedef const struct __XSThread * XSThreadRef;

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

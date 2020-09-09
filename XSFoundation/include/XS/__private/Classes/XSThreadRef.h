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
 * @abstract    Private definitions for XSThreadRef.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_THREAD_H__
#define __XS___PRIVATE_CLASSES_XS_THREAD_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     __XSThread_Type
 * @abstract    Thread type
 */
typedef enum
{
    __XSThread_TypeMethod               = 0x00, /*! Thread detached with a method */
    __XSThread_TypeMethodWithArgument   = 0x01, /*! Thread detached with a method and an argument */
    __XSThread_TypeFunction             = 0x02, /*! Thread detached with a function */
    __XSThread_TypeFunctionWithArgument = 0x03  /*! Thread detached with a function and an argument */
}
__XSThread_Type;

/*!
 * @typedef     __XSThread_Arguments
 * @abstract    Thread arguments
 */
typedef struct
{
    void                          * arg;                    /*! The thread function/method argument */
    XSObjectRef                     object;                 /*! The receiver object, if any */
    XSThread_Method                 method;                 /*! The method to call, if any */
    XSThread_MethodWithArgument     methodWithArgument;     /*! The method to call with an argument, if any */
    XSThread_Function               function;               /*! The function to call, if any */
    XSThread_FunctionWithArgument   functionWithArgument;   /*! The function to call with an argument, if any */
    __XSThread_Type                 type;                   /*! The thread type */
    char                            __pad_0[ 4 ];           /*! Padding */
    
    #ifdef _WIN32
    HANDLE                          handle;
    #endif
}
__XSThread_Arguments;

/*!
 * @var         __XSThread_TLSKey
 * @abstract    The TLS key for threads
 */
XS_EXTERN XSTLSKey __XSThread_TLSKey;

/*!
 * @var         __XSThread_MainThread
 * @abstract    The main thread
 */
XS_EXTERN XSThreadRef __XSThread_MainThread;

/*!
 * @struct      __XSThread
 * @abstract    Structure for XSThread
 */
struct __XSThread
{
    XSUInteger threadID;    /* The thread ID */
};

/*!
 * @var         __XSThread_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSThread_ClassID;

/*!
 * @var         __XSThread_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSThread_Class;

/*!
 * @function    __XSThread_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSThread_Initialize( void );

/*!
 * @function    __XSThread_Finalize
 * @abstract    Class finalizer
 */
XSStatic void __XSThread_Exit( void );

/*!
 * @function    __XSThread_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSThreadRef __XSThread_Constructor( XSThreadRef object );

/*!
 * @function    __XSThread_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSThread_Destructor( XSThreadRef object );

/*!
 * @function    __XSThread_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSThreadRef __XSThread_Copy( XSThreadRef source, XSThreadRef destination );

/*!
 * @function    __XSThread_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSThread_Equals( XSThreadRef object1, XSThreadRef object2 );

/*!
 * @function    __XSThread_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSThread_ToString( XSThreadRef object );

/*!
 * @function    __XSThread_Create
 * @abstract    Creates an XSThread object
 * @return      The XSThread object
 */
XSStatic struct __XSThread * __XSThread_Create( void );

/*!
 * @function    __XSThread_Proxy
 * @abstract    Thread proxy
 * @param       args        The thread arguments
 */
XSStatic void __XSThread_Detach( __XSThread_Arguments * args );

/*!
 * @function    __XSThread_Proxy
 * @abstract    Thread proxy
 * @param       args        The thread arguments
 */
#ifdef _WIN32
DWORD XSStatic__XSThread_Proxy( __XSThread_Arguments * args );
#else
void * __XSThread_Proxy( __XSThread_Arguments * args );
#endif

#endif /* __XS___PRIVATE_CLASSES_XS_THREAD_H__ */

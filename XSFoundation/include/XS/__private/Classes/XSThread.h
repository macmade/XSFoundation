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
 * @header      XSThread.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSThread.h
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

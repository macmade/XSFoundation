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
 * @header      XSRuntime.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @abstract    XSFoundation runtime functions
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_RUNTIME_H__
#define __XS_RUNTIME_H__

XS_EXTERN_C_BEGIN

#include <XS/XSTypes.h>

/*!
 * @function    XSRuntime_Initialize
 * @abstract    Initializes the XSFoundation runtime
 * @discussion  This function must be called before using any XSFoundation
 *              function.
 */
XS_EXPORT void XSRuntime_Initialize( void );

/*!
 * @function    XSRuntime_RegisterClass
 * @abstract    Registers a class for the runtime
 * @discussion  All runtime classes needs to be registered before the runtime
 *              can use them and create instances.
 *              This function needs to be called once per class,
 *              ie using pthread_once().
 * @param       cls         The class information structure to register
 * @result      The runtime type ID for the class
 */
XS_EXPORT XSClassID XSRuntime_RegisterClass( const XSClassInfo * const cls );

/*!
 * @function    XSRuntime_CreateInstance
 * @abstract    Initializes a new instance of a registered class
 * @param       classID     The class type ID
 * @result      The allocated instance
 */
XS_EXPORT XSObjectRef XSRuntime_CreateInstance( XSClassID classID );

/*!
 * @function    XSRuntime_CreateInstanceOfClassNamed
 * @abstract    Initializes a new instance of a class with a specific name
 * @param       name        The name of the class
 * @result      The allocated instance
 */
XS_EXPORT XSObjectRef XSRuntime_CreateInstanceOfClassNamed( const char * name );

/*!
 * @function    XSRuntime_GetDescription
 * @abstract    Gets an object's description
 * @param       object      The pointer to the object
 * @result      The object's description
 */
XS_EXPORT const char * XSRuntime_GetDescription( XSObjectRef object );

/*!
 * @function    XSRuntime_IsInstance
 * @abstract    Checks whether a pointer is an object instance
 * @param       ptr         The pointer to check
 * @result      True if the pointer represents an instance, otherwise false
 */
XS_EXPORT bool XSRuntime_IsInstance( void * ptr );

/*!
 * @function    XSRuntime_IsRegisteredClass
 * @abstract    Checks whether a class type ID corresponds to a registered class
 * @param       classID     The class type ID
 * @result      True if the class ID represents an valid class, otherwise false
 */
XS_EXPORT bool XSRuntime_IsRegisteredClass( XSClassID classID );

/*!
 * @function    XSRuntime_GetClassID
 * @abstract    Gets the class type ID for an object
 * @param       object      The object
 * @result      The class type ID for the object
 */
XS_EXPORT XSClassID XSRuntime_GetClassID( XSObjectRef object );

/*!
 * @function    XSRuntime_GetClassIDOfClassNamed
 * @abstract    Gets the class type ID for a class with a specific name
 * @param       className   The name of the class
 * @result      The class type ID
 */
XS_EXPORT XSClassID XSRuntime_GetClassIDOfClassNamed( const char * className );

/*!
 * @function    XSRuntime_GetClassName
 * @abstract    Gets the class name for an class type ID
 * @param       classID     The class type ID
 * @result      The name of the class
 */
XS_EXPORT const char * XSRuntime_GetClassName( XSClassID classID );

/*!
 * @function    XSRuntime_GetObjectClassName
 * @abstract    Gets the class name for an object
 * @param       object      The object
 * @result      The name of the class
 */
XS_EXPORT const char * XSRuntime_GetObjectClassName( XSObjectRef object );

/*!
 * @function    XSRuntime_FatalError
 * @abstract    Issues a fatal error message and aborts the program
 * @param       file        The file in which the fatal error occured
 * @param       line        The line number of the file in which the fatal error occured
 * @param       ...         The error message with optional format arguments
 * @discussion  Please do not call this function directly. Use the XSFatalError
 *              macro instead.
 */
void XSRuntime_FatalError( const char * file, int line, ... ) XS_NORETURN_ATTRIBUTE;

XS_EXTERN_C_END

#endif /* __XS_RUNTIME_H__ */

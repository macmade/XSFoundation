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
 * @header      XSRuntime.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSFoundation runtime functions
 */

#ifndef XS_FUNCTIONS_RUNTIME_H
#define XS_FUNCTIONS_RUNTIME_H

#include <XS/Macros.h>
#include <XS/Types/XSClassType.h>
#include <XS/Types/XSClassInfo.h>
#include <XS/Types/XSObjectRef.h>
#include <stdbool.h>

XS_EXTERN_C_BEGIN

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
 * @return      The runtime type ID for the class
 */
XS_EXPORT XSClassID XSRuntime_RegisterClass( const XSClassInfo * const cls );

/*!
 * @function    XSRuntime_CreateInstance
 * @abstract    Initializes a new instance of a registered class
 * @param       classID     The class type ID
 * @return      The allocated instance
 */
XS_EXPORT void * XSRuntime_CreateInstance( XSClassID classID );

/*!
 * @function    XSRuntime_CreateInstanceOfClassNamed
 * @abstract    Initializes a new instance of a class with a specific name
 * @param       name        The name of the class
 * @return      The allocated instance
 */
XS_EXPORT void * XSRuntime_CreateInstanceOfClassNamed( const char * name );

/*!
 * @function    XSRuntime_GetSharedInstance
 * @abstract    Gets the shared instance of a registered class
 * @param       classID     The class type ID
 * @return      The shared instance if it exists, otherwise NULL
 */
XS_EXPORT XSObjectRef XSRuntime_GetSharedInstance( XSClassID classID );

/*!
 * @function    XSRuntime_GetDescription
 * @abstract    Gets an object's description
 * @param       object      The pointer to the object
 * @return      The object's description
 */
XS_EXPORT const char * XSRuntime_GetDescription( XSObjectRef object );

/*!
 * @function    XSRuntime_IsInstance
 * @abstract    Checks whether a pointer is an object instance
 * @param       ptr         The pointer to check
 * @return      True if the pointer represents an instance, otherwise false
 */
XS_EXPORT bool XSRuntime_IsInstance( void * ptr );

/*!
 * @function    XSRuntime_IsRegisteredClass
 * @abstract    Checks whether a class type ID corresponds to a registered class
 * @param       classID     The class type ID
 * @return      True if the class ID represents an valid class, otherwise false
 */
XS_EXPORT bool XSRuntime_IsRegisteredClass( XSClassID classID );

/*!
 * @function    XSRuntime_GetClassID
 * @abstract    Gets the class type ID for an object
 * @param       object      The object
 * @return      The class type ID for the object
 */
XS_EXPORT XSClassID XSRuntime_GetClassID( XSObjectRef object );

/*!
 * @function    XSRuntime_GetClassIDOfClassNamed
 * @abstract    Gets the class type ID for a class with a specific name
 * @param       className   The name of the class
 * @return      The class type ID
 */
XS_EXPORT XSClassID XSRuntime_GetClassIDOfClassNamed( const char * className );

/*!
 * @function    XSRuntime_GetClassType
 * @abstract    Gets the class type for an class type ID
 * @param       classID     The class type ID
 * @return      The type of the class
 */
XS_EXPORT XSClassType XSRuntime_GetClassType( XSClassID classID );

/*!
 * @function    XSRuntime_GetClassName
 * @abstract    Gets the class name for an class type ID
 * @param       classID     The class type ID
 * @return      The name of the class
 */
XS_EXPORT const char * XSRuntime_GetClassName( XSClassID classID );

/*!
 * @function    XSRuntime_RegisterFinalizer
 * @abstract    Registers a finalizer function, to be called when the program exits
 * @param       func        The finalizer function
 * @discussion  Based on its address, a finalizer function will only be
 *              registered once.
 */
void XSRuntime_RegisterFinalizer( void ( *func )( void ) );

XS_EXTERN_C_END

#endif /* XS_FUNCTIONS_RUNTIME_H */

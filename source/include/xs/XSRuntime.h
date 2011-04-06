/*******************************************************************************
 * Copyright (c) 2011, Jean-David Gadina <macmade@eosgarden.com>
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/
 
/* $Id$ */

/*!
 * @header      XSRuntime.h
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    ...
 */

#ifndef _XS_RUNTIME_H_
#define _XS_RUNTIME_H_
#pragma once

#include "XSMacros.h"

XS_EXTERN_C_BEGIN

#include "XS.h"

/*!
 * @function    XSRuntime_Initialize
 * @abstract    Initialize the XSFoundation runtime.
 * @description Do not call this function. Use the XSFOUNDATION_START()
 *              macro instead.
 * @result      void
 */
void XSRuntime_Initialize( void );

/*!
 * @function    XSRuntime_Finalize
 * @abstract    Finilization the XSFoundation runtime.
 * @description Do not call this function. Use the XSFOUNDATION_END()
 *              macro instead.
 * @result      void
 */
void XSRuntime_Finalize( void );

/*!
 * @function    XSRuntime_RegisterClass
 * @abstract    Registers a class for the runtime
 * @description All runtime classes needs to be registered before the runtime
 *              can use them and create instances.
 *              This function needs to be called once per class,
 *              ie using pthread_once().
 * @param       cls     The class structure to register
 * @result      The runtime type ID for the class
 */
XSTypeID XSRuntime_RegisterClass( const XSRuntimeClass * const cls );

/*!
 * @function    XSRuntime_CreateInstance
 * @abstract    Creates a new instance of a registered class
 * @param       The type ID of the class
 * @param       The size of the object structure for the class
 * @result      The allocated instance
 */
XSTypeRef XSRuntime_CreateInstance( XSTypeID typeID, size_t extraBytes );

/*!
 * @function    XSRuntime_IsInstance
 * @abstract    Checks whether a pointer is an object instance
 * @param       ptr     The pointer to check
 * @result      True if the pointer represents an instance, otherwise false
 */
BOOL XSRuntime_IsInstance( void * ptr );

/*!
 * @function    XSRuntime_GetClassForTypeID
 * @abstract    Gets the class structure for a specific type ID
 * @param       The type ID of the class
 * @result      The class corresponding to the type ID
 */
Class XSRuntime_GetClassForTypeID( XSTypeID typeID );

/*!
 * @function    XSRuntime_GetClassForTypeID
 * @abstract    Gets the type ID for a specific class
 * @param       The class
 * @result      The type ID of the class
 */
XSTypeID XSRuntime_GetTypeIDForClass( Class cls );

/*!
 * @function    XSRuntime_GetClassForObject
 * @abstract    Gets the class for an object
 * @param       object  The object
 * @result      The object's class
 */
Class XSRuntime_GetClassForObject( id object );

/*!
 * @function    XSRuntime_GetTypeIDForObject
 * @abstract    Gets the class type ID for an object
 * @param       object  The object
 * @result      The class type ID for the object
 */
XSTypeID XSRuntime_GetTypeIDForObject( id object );

/*!
 * @function    XSRuntime_GetClassNameForObject
 * @abstract    Gets the class name for an object
 * @param       object  The object
 * @result      The name of the class
 */
const char * XSRuntime_GetClassNameForObject( id object );

/*!
 * @function    XSRuntime_IsInstanceOfClass
 * @abstract    Checks whether an object is an instance of a class
 * @param       object  The object
 * @param       cls     The class
 * @result      True if the object is an instance of the class, otherwise false
 */
BOOL XSRuntime_IsInstanceOfClass( id object, Class cls );

/*!
 * @function    XSRuntime_IsInstanceOfClassName
 * @abstract    Checks whether an object is an instance of a class name
 * @param       object  The object
 * @param       name    The name of the class
 * @result      True if the object is an instance of the class name, otherwise false
 */
BOOL XSRuntime_IsInstanceOfClassName( id object, const char * name );
    
XS_EXTERN_C_END

#endif /* _XS_RUNTIME_H_ */

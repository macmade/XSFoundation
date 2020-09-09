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
 * @header      XSBooleanRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSBoolean class
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_BOOLEAN_H__
#define __XS_CLASSES_XS_BOOLEAN_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     XSBooleanRef
 * @abstract    Opaque type for XSBoolean
 */
typedef struct __XSBoolean * XSBooleanRef;

/*!
 * @function    XSBoolean_GetClassID
 * @abstract    Gets the class ID for XSBoolean
 * @return      The class ID for XSBoolean
 */
XS_EXPORT XSStatic XSClassID XSBoolean_GetClassID( void );

/*!
 * @function    XSBoolean_Create
 * @abstract    Creates a boolean object
 * @param       value       The boolean value
 * @return      The boolean object
 */
XS_EXPORT XSStatic XSBooleanRef XSBoolean_Create( bool value );

/*!
 * @function    XSBoolean_GetValue
 * @abstract    Gets the value of a boolean object
 * @param       object      The boolean object
 * @return      The boolean object's value
 */
XS_EXPORT bool XSBoolean_GetValue( XSBooleanRef object );

/*!
 * @function    XSBoolean_SetValue
 * @abstract    Sets the value of a boolean object
 * @param       object      The boolean object
 * @param       value       The boolean value
 */
XS_EXPORT void XSBoolean_SetValue( XSBooleanRef object, bool value );

#endif /* __XS_CLASSES_XS_BOOLEAN_H__ */

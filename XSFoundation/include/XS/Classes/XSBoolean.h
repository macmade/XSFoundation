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
 * @header      XSBoolean.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSBoolean class
 */

#ifndef XS_CLASSES_XS_BOOLEAN_H
#define XS_CLASSES_XS_BOOLEAN_H

#include <XS/Macros.h>
#include <XS/Types.h>
#include <stdbool.h>

XS_EXTERN_C_BEGIN

/*!
 * @typedef     XSBooleanRef
 * @abstract    Opaque type for XSBoolean
 */
typedef const struct XSBoolean * XSBooleanRef;

/*!
 * @function    XSBooleanGetClassID
 * @abstract    Gets the class ID for XSBoolean
 * @return      The class ID for XSBoolean
 */
XS_EXPORT XSClassID XSBooleanGetClassID( void );

/*!
 * @function    XSBooleanTrue
 * @abstract    Gets a boolean object representing `true`
 * @return      The boolean object
 */
XS_EXPORT XSBooleanRef XSBooleanTrue( void );

/*!
 * @function    XSBooleanFalse
 * @abstract    Gets a boolean object representing `false`
 * @return      The boolean object
 */
XS_EXPORT XSBooleanRef XSBooleanFalse( void );

/*!
 * @function    XSBooleanGetValue
 * @abstract    Gets the value of a boolean object
 * @param       boolean     The boolean object
 * @return      The boolean value
 */
XS_EXPORT bool XSBooleanGetValue( XSBooleanRef boolean );

XS_EXTERN_C_END

#endif /* XS_CLASSES_XS_BOOLEAN_H */

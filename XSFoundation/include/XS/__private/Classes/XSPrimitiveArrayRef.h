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
 * @header      XSPrimitiveArrayRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSPrimitiveArrayRef.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_PRIMITIVE_ARRAY_H__
#define __XS___PRIVATE_CLASSES_XS_PRIMITIVE_ARRAY_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @struct      __XSPrimitiveArray
 * @abstract    Structure for XSPrimitiveArray
 */
struct __XSPrimitiveArray
{
    void * temp; /*! Not yet implemented... */
};

/*!
 * @var         __XSPrimitiveArray_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSPrimitiveArray_ClassID;

/*!
 * @var         __XSPrimitiveArray_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSPrimitiveArray_Class;

/*!
 * @function    __XSPrimitiveArray_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSPrimitiveArray_Initialize( void );

/*!
 * @function    __XSPrimitiveArray_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSPrimitiveArrayRef __XSPrimitiveArray_Constructor( XSPrimitiveArrayRef object );

/*!
 * @function    __XSPrimitiveArray_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSPrimitiveArray_Destructor( XSPrimitiveArrayRef object );

/*!
 * @function    __XSPrimitiveArray_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSPrimitiveArrayRef __XSPrimitiveArray_Copy( XSPrimitiveArrayRef source, XSPrimitiveArrayRef destination );

/*!
 * @function    __XSPrimitiveArray_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSPrimitiveArray_Equals( XSPrimitiveArrayRef object1, XSPrimitiveArrayRef object2 );

/*!
 * @function    __XSPrimitiveArray_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSPrimitiveArray_ToString( XSPrimitiveArrayRef object );

/*!
 * @function    __XSPrimitiveArray_Create
 * @abstract    Creates an XSPrimitiveArray object
 * @return      The XSPrimitiveArray object
 */
XSStatic struct __XSPrimitiveArray * __XSPrimitiveArray_Create( void );

#endif /* __XS___PRIVATE_CLASSES_XS_PRIMITIVE_ARRAY_H__ */

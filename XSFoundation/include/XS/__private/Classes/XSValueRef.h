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
 * @header      XSValueRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSValueRef.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_VALUE_H__
#define __XS___PRIVATE_CLASSES_XS_VALUE_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @struct      __XSValue
 * @abstract    Structure for XSValue
 */
struct __XSValue
{
    const void        * pointer;        /*! Pointer value */
    XSPoint             point;          /*! XSPoint value */
    XSSize              size;           /*! XSSize value */
    XSRect              rect;           /*! XSRect value */
    XSEdgeInsets        insets;         /*! XSEdgeInsets value */
    XSRange             range;          /*! XSRange value */
    XSValue_ValueType   type;           /*! Value type */
    XSObjectAssociation association;    /*! Association for pointer values */
};

/*!
 * @var         __XSValue_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSValue_ClassID;

/*!
 * @var         __XSValue_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSValue_Class;

/*!
 * @function    __XSValue_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSValue_Initialize( void );

/*!
 * @function    __XSValue_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSValueRef __XSValue_Constructor( XSValueRef object );

/*!
 * @function    __XSValue_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSValue_Destructor( XSValueRef object );

/*!
 * @function    __XSValue_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSValueRef __XSValue_Copy( XSValueRef source, XSValueRef destination );

/*!
 * @function    __XSValue_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSValue_Equals( XSValueRef object1, XSValueRef object2 );

/*!
 * @function    __XSValue_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSValue_ToString( XSValueRef object );

/*!
 * @function    __XSValue_Create
 * @abstract    Creates an XSValue object
 * @return      The XSValue object
 */
XSStatic struct __XSValue * __XSValue_Create( void );

#endif /* __XS___PRIVATE_CLASSES_XS_VALUE_H__ */

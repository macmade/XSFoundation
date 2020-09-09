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
 * @header      XSValueRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSValue class
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_VALUE_H__
#define __XS_CLASSES_XS_VALUE_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     XSValue_ValueType
 * @abstract    Value type for XSValue objects
 */
typedef enum
{
    XSValue_ValueTypeUnknown    = 0x00, /*! Unknown/Invalid value type */
    XSValue_ValueTypePointer    = 0x01, /*! Pointer value */
    XSValue_ValueTypePoint      = 0x02, /*! XSPoint value */
    XSValue_ValueTypeSize       = 0x03, /*! XSSize value */
    XSValue_ValueTypeRect       = 0x04, /*! XSRect value */
    XSValue_ValueTypeEdgeInsets = 0x05, /*! XSEdgeInsets value */
    XSValue_ValueTypeRange      = 0x06  /*! XSRange value */
}
XSValue_ValueType;

/*!
 * @typedef     XSValueRef
 * @abstract    Opaque type for XSValue
 */
typedef const struct __XSValue * XSValueRef;

/*!
 * @function    XSValue_GetClassID
 * @abstract    Gets the class ID for XSValue
 * @return      The class ID for XSValue
 */
XS_EXPORT XSStatic XSClassID XSValue_GetClassID( void );

/*!
 * @function    XSValue_ValueWithPointer
 * @abstract    Gets an XSValue object from a pointer
 * @param       pointer     The pointer value
 * @param       association The association type for the pointer value
 * @return      An XSValue object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSValueRef XSValue_ValueWithPointer( const void * pointer, XSObjectAssociation association );

/*!
 * @function    XSValue_ValueWithPoint
 * @abstract    Gets an XSValue object from an XSPoint value
 * @param       point       The XSPoint value
 * @return      An XSValue object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSValueRef XSValue_ValueWithPoint( XSPoint point );

/*!
 * @function    XSValue_ValueWithSize
 * @abstract    Gets an XSValue object from an XSSize value
 * @param       size        The XSSize value
 * @return      An XSValue object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSValueRef XSValue_ValueWithSize( XSSize size );

/*!
 * @function    XSValue_ValueWithRect
 * @abstract    Gets an XSValue object from an XSRect value
 * @param       rect        The XSRect value
 * @return      An XSValue object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSValueRef XSValue_ValueWithRect( XSRect rect );

/*!
 * @function    XSValue_ValueWithEdgeInsets
 * @abstract    Gets an XSValue object from an XSEdgeInsets value
 * @param       insets      The XSEdgeInsets value
 * @return      An XSValue object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSValueRef XSValue_ValueWithEdgeInsets( XSEdgeInsets insets );

/*!
 * @function    XSValue_ValueWithRange
 * @abstract    Gets an XSValue object from an XSRange value
 * @param       range       The XSRange value
 * @return      An XSValue object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSValueRef XSValue_ValueWithRange( XSRange range );

/*!
 * @function    XSValue_CreateWithPointer
 * @abstract    Creates an XSValue object from a pointer
 * @param       pointer     The pointer value
 * @param       association The association type for the pointer value
 * @return      An XSValue object
 */
XS_EXPORT XSStatic XSValueRef XSValue_CreateWithPointer( const void * pointer, XSObjectAssociation association );

/*!
 * @function    XSValue_CreateWithPoint
 * @abstract    Creates an XSValue object from an XSPoint value
 * @param       point       The XSPoint value
 * @return      An XSValue object
 */
XS_EXPORT XSStatic XSValueRef XSValue_CreateWithPoint( XSPoint point );

/*!
 * @function    XSValue_CreateWithSize
 * @abstract    Creates an XSValue object from an XSSize value
 * @param       size        The XSSize value
 * @return      An XSValue object
 */
XS_EXPORT XSStatic XSValueRef XSValue_CreateWithSize( XSSize size );

/*!
 * @function    XSValue_CreateWithRect
 * @abstract    Creates an XSValue object from an XSRect value
 * @param       rect        The XSRect value
 * @return      An XSValue object
 */
XS_EXPORT XSStatic XSValueRef XSValue_CreateWithRect( XSRect rect );

/*!
 * @function    XSValue_CreateWithEdgeInsets
 * @abstract    Creates an XSValue object from an XSEdgeInsets value
 * @param       insets      The XSEdgeInsets value
 * @return      An XSValue object
 */
XS_EXPORT XSStatic XSValueRef XSValue_CreateWithEdgeInsets( XSEdgeInsets insets );

/*!
 * @function    XSValue_CreateWithRange
 * @abstract    Creates an XSValue object from an XSRange value
 * @param       range       The XSRange value
 * @return      An XSValue object
 */
XS_EXPORT XSStatic XSValueRef XSValue_CreateWithRange( XSRange range );

/*!
 * @function    XSValue_GetValueType
 * @abstract    Gets the value type of an XSValue object
 * @param       object      The XSValue object
 * @return      The XSValue object's type
 */
XS_EXPORT XSValue_ValueType XSValue_GetValueType( XSValueRef object );

/*!
 * @function    XSValue_GetPointerValue
 * @abstract    Gets the pointer value of an XSValue object
 * @param       object      The XSValue object
 * @return      The pointer value
 */
XS_EXPORT void * XSValue_GetPointerValue( XSValueRef object );

/*!
 * @function    XSValue_GetPointValue
 * @abstract    Gets the XSPoint value of an XSValue object
 * @param       object      The XSValue object
 * @return      The XSPoint value
 */
XS_EXPORT XSPoint XSValue_GetPointValue( XSValueRef object );

/*!
 * @function    XSValue_GetSizeValue
 * @abstract    Gets the XSSize value of an XSValue object
 * @param       object      The XSValue object
 * @return      The XSSize value
 */
XS_EXPORT XSSize XSValue_GetSizeValue( XSValueRef object );

/*!
 * @function    XSValue_GetRectValue
 * @abstract    Gets the XSRect value of an XSValue object
 * @param       object      The XSValue object
 * @return      The XSRect value
 */
XS_EXPORT XSRect XSValue_GetRectValue( XSValueRef object );

/*!
 * @function    XSValue_GetEdgeInsetsValue
 * @abstract    Gets the XSEdgeInsets value of an XSValue object
 * @param       object      The XSValue object
 * @return      The XSEdgeInsets value
 */
XS_EXPORT XSEdgeInsets XSValue_GetEdgeInsetsValue( XSValueRef object );

/*!
 * @function    XSValue_GetRangeValue
 * @abstract    Gets the XSRange value of an XSValue object
 * @param       object      The XSValue object
 * @return      The XSRange value
 */
XS_EXPORT XSRange XSValue_GetRangeValue( XSValueRef object );

#endif /* __XS_CLASSES_XS_VALUE_H__ */

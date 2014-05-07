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
typedef struct __XSValue * XSValueRef;

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
XS_EXPORT XSStatic XSAutoreleased XSValueRef XSValue_ValueWithPointer( void * pointer, XSObjectAssociation association );

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
XS_EXPORT XSStatic XSValueRef XSValue_CreateWithPointer( void * pointer, XSObjectAssociation association );

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

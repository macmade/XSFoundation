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
 * @header      XSNumberRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSNumber class
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_NUMBER_H__
#define __XS_CLASSES_XS_NUMBER_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     XSNumberRef
 * @abstract    Opaque type for XSNumber
 */
typedef const struct __XSNumber * XSNumberRef;

/*!
 * @function    XSNumber_GetClassID
 * @abstract    Gets the class ID for XSNumber
 * @return      The class ID for XSNumber
 */
XS_EXPORT XSStatic XSClassID XSNumber_GetClassID( void );

/*!
 * @function    XSNumber_NumberWithBool
 * @abstract    Gets a number object from a boolean value
 * @param       value       The boolean value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithBool( bool value );

/*!
 * @function    XSNumber_NumberWithChar
 * @abstract    Gets a number object from a char value
 * @param       value       The char value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithChar( char value );

/*!
 * @function    XSNumber_NumberWithUnsignedChar
 * @abstract    Gets a number object from an unsigned char value
 * @param       value       The unsigned char value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithUnsignedChar( unsigned char value );

/*!
 * @function    XSNumber_NumberWithShort
 * @abstract    Gets a number object from a short value
 * @param       value       The short value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithShort( short value );

/*!
 * @function    XSNumber_NumberWithUnsignedShort
 * @abstract    Gets a number object from an unsigned short value
 * @param       value       The unsigned short value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithUnsignedShort( unsigned short value );

/*!
 * @function    XSNumber_NumberWithInt
 * @abstract    Gets a number object from an int value
 * @param       value       The int value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithInt( int value );

/*!
 * @function    XSNumber_NumberWithUnsignedInt
 * @abstract    Gets a number object from an unsigned int value
 * @param       value       The unsigned int value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithUnsignedInt( unsigned int value );

/*!
 * @function    XSNumber_NumberWithLong
 * @abstract    Gets a number object from a long value
 * @param       value       The long value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithLong( long value );

/*!
 * @function    XSNumber_NumberWithUnsignedLong
 * @abstract    Gets a number object from an unsigned long value
 * @param       value       The unsigned long value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithUnsignedLong( unsigned long value );

/*!
 * @function    XSNumber_NumberWithXSInt8
 * @abstract    Gets a number object from an XSInt8 value
 * @param       value       The XSInt8 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSInt8( XSInt8 value );

/*!
 * @function    XSNumber_NumberWithXSUInt8
 * @abstract    Gets a number object from an XSUInt8 value
 * @param       value       The XSUInt8 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSUInt8( XSUInt8 value );

/*!
 * @function    XSNumber_NumberWithXSInt16
 * @abstract    Gets a number object from an XSInt16 value
 * @param       value       The XSInt16 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSInt16( XSInt16 value );

/*!
 * @function    XSNumber_NumberWithXSUInt16
 * @abstract    Gets a number object from an XSUInt16 value
 * @param       value       The XSUInt16 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSUInt16( XSUInt16 value );

/*!
 * @function    XSNumber_NumberWithXSInt32
 * @abstract    Gets a number object from an XSInt32 value
 * @param       value       The XSInt32 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSInt32( XSInt32 value );

/*!
 * @function    XSNumber_NumberWithXSUInt32
 * @abstract    Gets a number object from an XSUInt32 value
 * @param       value       The XSUInt32 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSUInt32( XSUInt32 value );

/*!
 * @function    XSNumber_NumberWithXSInt64
 * @abstract    Gets a number object from an XSInt64 value
 * @param       value       The XSInt64 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSInt64( XSInt64 value );

/*!
 * @function    XSNumber_NumberWithXSUInt64
 * @abstract    Gets a number object from an XSUInt64 value
 * @param       value       The XSUInt64 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSUInt64( XSUInt64 value );

/*!
 * @function    XSNumber_NumberWithXSInteger
 * @abstract    Gets a number object from an XSInteger value
 * @param       value       The XSInteger value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSInteger( XSInteger value );

/*!
 * @function    XSNumber_NumberWithXSUInteger
 * @abstract    Gets a number object from an XSUInteger value
 * @param       value       The XSUInteger value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSUInteger( XSUInteger value );

/*!
 * @function    XSNumber_NumberWithFloat
 * @abstract    Gets a number object from a float value
 * @param       value       The float value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithFloat( float value );

/*!
 * @function    XSNumber_NumberWithDouble
 * @abstract    Gets a number object from a double value
 * @param       value       The double value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithDouble( double value );

/*!
 * @function    XSNumber_NumberWithXSFloat32
 * @abstract    Gets a number object from an XSFloat32 value
 * @param       value       The XSFloat32 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSFloat32( XSFloat32 value );

/*!
 * @function    XSNumber_NumberWithXSFloat64
 * @abstract    Gets a number object from an XSFloat64 value
 * @param       value       The XSFloat64 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSFloat64( XSFloat64 value );

/*!
 * @function    XSNumber_NumberWithXSFloat
 * @abstract    Gets a number object from an XSFloat value
 * @param       value       The XSFloat value
 * @return      The number object
 */
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSFloat( XSFloat value );

/*!
 * @function    XSNumber_CreateWithBool
 * @abstract    Creates a number object from a bool value
 * @param       value       The bool value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithBool( bool value );

/*!
 * @function    XSNumber_CreateWithChar
 * @abstract    Creates a number object from a char value
 * @param       value       The char value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithChar( char value );

/*!
 * @function    XSNumber_CreateWithUnsignedChar
 * @abstract    Creates a number object from an unsigned char value
 * @param       value       The unsigned char value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithUnsignedChar( unsigned char value );

/*!
 * @function    XSNumber_CreateWithShort
 * @abstract    Creates a number object from a short value
 * @param       value       The short value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithShort( short value );

/*!
 * @function    XSNumber_CreateWithUnsignedShort
 * @abstract    Creates a number object from an unsigned short value
 * @param       value       The unsigned short value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithUnsignedShort( unsigned short value );

/*!
 * @function    XSNumber_CreateWithInt
 * @abstract    Creates a number object from a int value
 * @param       value       The int value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithInt( int value );

/*!
 * @function    XSNumber_CreateWithUnsignedInt
 * @abstract    Creates a number object from an unsigned int value
 * @param       value       The unsigned int value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithUnsignedInt( unsigned int value );

/*!
 * @function    XSNumber_CreateWithLong
 * @abstract    Creates a number object from a long value
 * @param       value       The long value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithLong( long value );

/*!
 * @function    XSNumber_CreateWithUnsignedLong
 * @abstract    Creates a number object from an unsigned long value
 * @param       value       The unsigned long value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithUnsignedLong( unsigned long value );

/*!
 * @function    XSNumber_CreateWithXSInt8
 * @abstract    Creates a number object from an XSInt8 value
 * @param       value       The XSInt8 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSInt8( XSInt8 value );

/*!
 * @function    XSNumber_CreateWithXSUInt8
 * @abstract    Creates a number object from an XSUInt8 value
 * @param       value       The XSUInt8 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSUInt8( XSUInt8 value );

/*!
 * @function    XSNumber_CreateWithXSInt16
 * @abstract    Creates a number object from an XSInt16 value
 * @param       value       The XSInt16 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSInt16( XSInt16 value );

/*!
 * @function    XSNumber_CreateWithXSUInt16
 * @abstract    Creates a number object from an XSUInt16 value
 * @param       value       The XSUInt16 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSUInt16( XSUInt16 value );

/*!
 * @function    XSNumber_CreateWithXSInt32
 * @abstract    Creates a number object from an XSInt32 value
 * @param       value       The XSInt32 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSInt32( XSInt32 value );

/*!
 * @function    XSNumber_CreateWithXSUInt32
 * @abstract    Creates a number object from an XSUInt32 value
 * @param       value       The XSUInt32 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSUInt32( XSUInt32 value );

/*!
 * @function    XSNumber_CreateWithXSInt64
 * @abstract    Creates a number object from an XSInt64 value
 * @param       value       The XSInt64 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSInt64( XSInt64 value );

/*!
 * @function    XSNumber_CreateWithXSUInt64
 * @abstract    Creates a number object from an XSUInt64 value
 * @param       value       The XSUInt64 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSUInt64( XSUInt64 value );

/*!
 * @function    XSNumber_CreateWithXSInteger
 * @abstract    Creates a number object from an XSInteger value
 * @param       value       The XSInteger value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSInteger( XSInteger value );

/*!
 * @function    XSNumber_CreateWithXSUInteger
 * @abstract    Creates a number object from an XSUInteger value
 * @param       value       The XSUInteger value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSUInteger( XSUInteger value );

/*!
 * @function    XSNumber_CreateWithFloat
 * @abstract    Creates a number object from a float value
 * @param       value       The float value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithFloat( float value );

/*!
 * @function    XSNumber_CreateWithDouble
 * @abstract    Creates a number object from a double value
 * @param       value       The double value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithDouble( double value );

/*!
 * @function    XSNumber_CreateWithXSFloat32
 * @abstract    Creates a number object from an XSFloat32 value
 * @param       value       The XSFloat32 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSFloat32( XSFloat32 value );

/*!
 * @function    XSNumber_CreateWithXSFloat64
 * @abstract    Creates a number object from an XSFloat64 value
 * @param       value       The XSFloat64 value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSFloat64( XSFloat64 value );

/*!
 * @function    XSNumber_CreateWithXSFloat
 * @abstract    Creates a number object from an XSFloat value
 * @param       value       The XSFloat value
 * @return      The number object
 */
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSFloat( XSFloat value );

/*!
 * @function    XSNumber_IsFloatType
 * @abstract    Checks whether a number object is floating-point type
 * @param       number      The number object
 * @return      True if the number object is floating point type, otherwise false
 */
XS_EXPORT bool XSNumber_IsFloatType( XSNumberRef number );

/*!
 * @function    XSNumber_CompareWithNumber
 * @abstract    Compares a number object with another number object
 * @param       number      The number object
 * @param       otherNumber The other number object
 * @return      The comparison result between the two numbers
 */
XS_EXPORT XSComparisonResult XSNumber_CompareWithNumber( XSNumberRef number, XSNumberRef otherNumber );

/*!
 * @function    XSNumber_GetBoolValue
 * @abstract    Gets the bool value of a number
 * @param       number      The number object
 * @return      The bool value
 */
XS_EXPORT bool XSNumber_GetBoolValue( XSNumberRef number );

/*!
 * @function    XSNumber_GetCharValue
 * @abstract    Gets the char value of a number
 * @param       number      The number object
 * @return      The char value
 */
XS_EXPORT char XSNumber_GetCharValue( XSNumberRef number );

/*!
 * @function    XSNumber_GetUnsignedCharValue
 * @abstract    Gets the unsigned char value of a number
 * @param       number      The number object
 * @return      The unsigned char value
 */
XS_EXPORT unsigned char XSNumber_GetUnsignedCharValue( XSNumberRef number );

/*!
 * @function    XSNumber_GetShortValue
 * @abstract    Gets the short value of a number
 * @param       number      The number object
 * @return      The short value
 */
XS_EXPORT short XSNumber_GetShortValue( XSNumberRef number );

/*!
 * @function    XSNumber_GetUnsignedShortValue
 * @abstract    Gets the unsigned short value of a number
 * @param       number      The number object
 * @return      The unsigned short value
 */
XS_EXPORT unsigned short XSNumber_GetUnsignedShortValue( XSNumberRef number );

/*!
 * @function    XSNumber_GetIntValue
 * @abstract    Gets the int value of a number
 * @param       number      The number object
 * @return      The int value
 */
XS_EXPORT int XSNumber_GetIntValue( XSNumberRef number );

/*!
 * @function    XSNumber_GetUnsignedIntValue
 * @abstract    Gets the unsigned int value of a number
 * @param       number      The number object
 * @return      The unsigned int value
 */
XS_EXPORT unsigned int XSNumber_GetUnsignedIntValue( XSNumberRef number );

/*!
 * @function    XSNumber_GetLongValue
 * @abstract    Gets the long value of a number
 * @param       number      The number object
 * @return      The long value
 */
XS_EXPORT long XSNumber_GetLongValue( XSNumberRef number );

/*!
 * @function    XSNumber_GetUnsignedLongValue
 * @abstract    Gets the unsigned long value of a number
 * @param       number      The number object
 * @return      The unsigned long value
 */
XS_EXPORT unsigned long XSNumber_GetUnsignedLongValue( XSNumberRef number );

/*!
 * @function    XSNumber_GetXSInt8Value
 * @abstract    Gets the XSInt8 value of a number
 * @param       number      The number object
 * @return      The XSInt8 value
 */
XS_EXPORT XSInt8 XSNumber_GetXSInt8Value( XSNumberRef number );

/*!
 * @function    XSNumber_GetXSUInt8Value
 * @abstract    Gets the XSUInt8 value of a number
 * @param       number      The number object
 * @return      The XSUInt8 value
 */
XS_EXPORT XSUInt8 XSNumber_GetXSUInt8Value( XSNumberRef number );

/*!
 * @function    XSNumber_GetXSInt16Value
 * @abstract    Gets the XSInt16 value of a number
 * @param       number      The number object
 * @return      The XSInt16 value
 */
XS_EXPORT XSInt16 XSNumber_GetXSInt16Value( XSNumberRef number );

/*!
 * @function    XSNumber_GetXSUInt16Value
 * @abstract    Gets the XSUInt16 value of a number
 * @param       number      The number object
 * @return      The XSUInt16 value
 */
XS_EXPORT XSUInt16 XSNumber_GetXSUInt16Value( XSNumberRef number );

/*!
 * @function    XSNumber_GetXSInt32Value
 * @abstract    Gets the XSInt32 value of a number
 * @param       number      The number object
 * @return      The XSInt32 value
 */
XS_EXPORT XSInt32 XSNumber_GetXSInt32Value( XSNumberRef number );

/*!
 * @function    XSNumber_GetXSUInt32Value
 * @abstract    Gets the XSUInt32 value of a number
 * @param       number      The number object
 * @return      The XSUInt32 value
 */
XS_EXPORT XSUInt32 XSNumber_GetXSUInt32Value( XSNumberRef number );

/*!
 * @function    XSNumber_GetXSInt64Value
 * @abstract    Gets the XSInt64 value of a number
 * @param       number      The number object
 * @return      The XSInt64 value
 */
XS_EXPORT XSInt64 XSNumber_GetXSInt64Value( XSNumberRef number );

/*!
 * @function    XSNumber_GetXSUInt64Value
 * @abstract    Gets the XSUInt64 value of a number
 * @param       number      The number object
 * @return      The XSUInt64 value
 */
XS_EXPORT XSUInt64 XSNumber_GetXSUInt64Value( XSNumberRef number );

/*!
 * @function    XSNumber_GetXSIntegerValue
 * @abstract    Gets the XSInteger value of a number
 * @param       number      The number object
 * @return      The XSInteger value
 */
XS_EXPORT XSInteger XSNumber_GetXSIntegerValue( XSNumberRef number );

/*!
 * @function    XSNumber_GetXSUIntegerValue
 * @abstract    Gets the XSUInteger value of a number
 * @param       number      The number object
 * @return      The XSUInteger value
 */
XS_EXPORT XSUInteger XSNumber_GetXSUIntegerValue( XSNumberRef number );

/*!
 * @function    XSNumber_GetFloatValue
 * @abstract    Gets the float value of a number
 * @param       number      The number object
 * @return      The float value
 */
XS_EXPORT float XSNumber_GetFloatValue( XSNumberRef number );

/*!
 * @function    XSNumber_GetDoubleValue
 * @abstract    Gets the double value of a number
 * @param       number      The number object
 * @return      The double value
 */
XS_EXPORT double XSNumber_GetDoubleValue( XSNumberRef number );

/*!
 * @function    XSNumber_GetXSFloat32Value
 * @abstract    Gets the XSFloat32 value of a number
 * @param       number      The number object
 * @return      The XSFloat32 value
 */
XS_EXPORT XSFloat32 XSNumber_GetXSFloat32Value( XSNumberRef number );

/*!
 * @function    XSNumber_GetXSFloat64Value
 * @abstract    Gets the XSFloat64 value of a number
 * @param       number      The number object
 * @return      The XSFloat64 value
 */
XS_EXPORT XSFloat64 XSNumber_GetXSFloat64Value( XSNumberRef number );

/*!
 * @function    XSNumber_GetXSFloatValue
 * @abstract    Gets the XSFloat value of a number
 * @param       number      The number object
 * @return      The XSFloat value
 */
XS_EXPORT XSFloat XSNumber_GetXSFloatValue( XSNumberRef number );

#endif /* __XS_CLASSES_XS_NUMBER_H__ */

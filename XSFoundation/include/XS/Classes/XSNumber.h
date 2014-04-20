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
 * @header      XSNumber.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSNumber class
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
typedef struct __XSNumber * XSNumberRef;

/*!
 * @function    XSNumber_GetClassID
 * @abstract    Gets the class ID for XSNumber
 * @return      The class ID for XSNumber
 */
XS_EXPORT XSStatic XSClassID XSNumber_GetClassID( void );

XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithBool( bool value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithChar( char value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithUnsignedChar( unsigned char value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithShort( short value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithUnsignedShort( unsigned short value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithInt( int value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithUnsignedInt( unsigned int value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithLong( long value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithUnsignedLong( unsigned long value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSInt8( XSInt8 value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSUInt8( XSUInt8 value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSInt16( XSInt16 value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSUInt16( XSUInt16 value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSInt32( XSInt32 value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSUInt32( XSUInt32 value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSInt64( XSInt64 value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSUInt64( XSUInt64 value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSInteger( XSInteger value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSUInteger( XSUInteger value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithFloat( float value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithDouble( double value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSFloat32( XSFloat32 value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSFloat64( XSFloat64 value );
XS_EXPORT XSStatic XSAutoreleased XSNumberRef XSNumber_NumberWithXSFloat( XSFloat value );

XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithBool( bool value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithChar( char value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithUnsignedChar( unsigned char value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithShort( short value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithUnsignedShort( unsigned short value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithInt( int value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithUnsignedInt( unsigned int value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithLong( long value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithUnsignedLong( unsigned long value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSInt8( XSInt8 value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSUInt8( XSUInt8 value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSInt16( XSInt16 value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSUInt16( XSUInt16 value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSInt32( XSInt32 value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSUInt32( XSUInt32 value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSInt64( XSInt64 value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSUInt64( XSUInt64 value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSInteger( XSInteger value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSUInteger( XSUInteger value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithFloat( float value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithDouble( double value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSFloat32( XSFloat32 value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSFloat64( XSFloat64 value );
XS_EXPORT XSStatic XSNumberRef XSNumber_CreateWithXSFloat( XSFloat value );

XS_EXPORT bool XSNumber_IsFloatType( XSNumberRef number );
XS_EXPORT XSComparisonResult XSNumber_CompareWithNumber( XSNumberRef number, XSNumberRef otherNumber );

XS_EXPORT bool XSNumber_GetBoolValue( XSNumberRef number );
XS_EXPORT char XSNumber_GetCharValue( XSNumberRef number );
XS_EXPORT unsigned char XSNumber_GetUnsignedCharValue( XSNumberRef number );
XS_EXPORT short XSNumber_GetShortValue( XSNumberRef number );
XS_EXPORT unsigned short XSNumber_GetUnsignedShortValue( XSNumberRef number );
XS_EXPORT int XSNumber_GetIntValue( XSNumberRef number );
XS_EXPORT unsigned int XSNumber_GetUnsignedIntValue( XSNumberRef number );
XS_EXPORT long XSNumber_GetLongValue( XSNumberRef number );
XS_EXPORT unsigned long XSNumber_GetUnsignedLongValue( XSNumberRef number );
XS_EXPORT XSInt8 XSNumber_GetXSInt8Value( XSNumberRef number );
XS_EXPORT XSUInt8 XSNumber_GetXSUInt8Value( XSNumberRef number );
XS_EXPORT XSInt16 XSNumber_GetXSInt16Value( XSNumberRef number );
XS_EXPORT XSUInt16 XSNumber_GetXSUInt16Value( XSNumberRef number );
XS_EXPORT XSInt32 XSNumber_GetXSInt32Value( XSNumberRef number );
XS_EXPORT XSUInt32 XSNumber_GetXSUInt32Value( XSNumberRef number );
XS_EXPORT XSInt64 XSNumber_GetXSInt64Value( XSNumberRef number );
XS_EXPORT XSUInt64 XSNumber_GetXSUInt64Value( XSNumberRef number );
XS_EXPORT XSInteger XSNumber_GetXSIntegerValue( XSNumberRef number );
XS_EXPORT XSUInteger XSNumber_GetXSUIntegerValue( XSNumberRef number );
XS_EXPORT float XSNumber_GetFloatValue( XSNumberRef number );
XS_EXPORT double XSNumber_GetDoubleValue( XSNumberRef number );
XS_EXPORT XSFloat32 XSNumber_GetXSFloat32Value( XSNumberRef number );
XS_EXPORT XSFloat64 XSNumber_GetXSFloat64Value( XSNumberRef number );
XS_EXPORT XSFloat XSNumber_GetXSFloatValue( XSNumberRef number );

#endif /* __XS_CLASSES_XS_NUMBER_H__ */

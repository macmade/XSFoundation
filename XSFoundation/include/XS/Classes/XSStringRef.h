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
 * @header          XSStringRef.h
 * @copyright       (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author          Jean-David Gadina - www.xs-labs.com
 * @abstract        XSString class
 * @discussion      ...
 * @ignorefuncmacro XS_FORMAT_ATTRIBUTE
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_STRING_H__
#define __XS_CLASSES_XS_STRING_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @define      XSSTR
 * @abstract    Gets an XSString object from a C string
 * @param       _s_     The C string (const char *)
 * @return      An XSString object (autoreleased)
 */
#define XSSTR( _s_ )    XSString_StringWithCString( _s_ )

/*!
 * @typedef     XSStringRef
 * @abstract    Opaque type for XSString
 */
typedef const struct __XSString * XSStringRef;

/*!
 * @typedef     XSMutableStringRef
 * @abstract    Opaque type for XSMutableString
 */
typedef struct __XSString * XSMutableStringRef;

/*!
 * @function    XSString_GetClassID
 * @abstract    Gets the class ID for XSString
 * @return      The class ID for XSString
 */
XS_EXPORT XSStatic XSClassID XSString_GetClassID( void );

/*!
 * @function    XSString_StringWithCString
 * @abstract    Gets an XSString object from a C string
 * @param       s       The C string (const char *)
 * @return      An XSString object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSStringRef XSString_StringWithCString( const char * s );

/*!
 * @function    XSString_StringWithFormat
 * @abstract    Gets an XSString object from a format string with arguments
 * @param       format  The format string
 * @param       ...     The format arguments
 * @return      An XSString object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSStringRef XSString_StringWithFormat( const char * format, ... ) XS_FORMAT_ATTRIBUTE( printf, 1, 2 );

/*!
 * @function    XSString_StringWithFormatAndArgs
 * @abstract    Gets an XSString object from a format string with arguments
 * @param       format  The format string
 * @param       args     The format arguments
 * @return      An XSString object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSStringRef XSString_StringWithFormatAndArgs( const char * format, va_list args ) XS_FORMAT_ATTRIBUTE( printf, 1, 0 );

/*!
 * @function    XSString_CreateWithCString
 * @abstract    Creates an XSString object from a C string
 * @param       s       The C string (const char *)
 * @return      An XSString object
 */
XS_EXPORT XSStatic XSStringRef XSString_CreateWithCString( const char * s );

/*!
 * @function    XSString_CreateWithFormat
 * @abstract    Creates an XSString object from a format string with arguments
 * @param       format  The format string
 * @param       ...     The format arguments
 * @return      An XSString object
 */
XS_EXPORT XSStatic XSStringRef XSString_CreateWithFormat( const char * format, ... ) XS_FORMAT_ATTRIBUTE( printf, 1, 2 );

/*!
 * @function    XSString_CreateWithFormatAndArgs
 * @abstract    Creates an XSString object from a format string with arguments
 * @param       format  The format string
 * @param       args    The format arguments
 * @return      An XSString object
 */
XS_EXPORT XSStatic XSStringRef XSString_CreateWithFormatAndArgs( const char * format, va_list args ) XS_FORMAT_ATTRIBUTE( printf, 1, 0 );

/*!
 * @function    XSString_GetLength
 * @abstract    Gets the length of a string
 * @param       object  The string object
 * @return      The length of the string
 */
XS_EXPORT XSUInteger XSString_GetLength( XSStringRef object );

/*!
 * @function    XSString_GetCString
 * @abstract    Gets the internal C string pointer
 * @param       object  The string object
 * @discussion  Do not alter the content of the C string.
 * @return      A pointer to the C string
 */
XS_EXPORT const char * XSString_GetCString( XSStringRef object );

/*!
 * @function    XSString_SubstringFromIndex
 * @abstract    Gets a substring from a specific index to the end of the string
 * @param       object  The string object
 * @param       i       The index
 * @return      The substring (autoreleased)
 */
XS_EXPORT XSAutoreleased XSStringRef XSString_SubstringFromIndex( XSStringRef object, XSUInteger i );

/*!
 * @function    XSString_SubstringToIndex
 * @abstract    Gets a substring from the start of the string to a specific index
 * @param       object  The string object
 * @param       i       The index
 * @return      The substring (autoreleased)
 */
XS_EXPORT XSAutoreleased XSStringRef XSString_SubstringToIndex( XSStringRef object, XSUInteger i );

/*!
 * @function    XSString_SubstringWithRange
 * @abstract    Gets a substring based on a specific range
 * @param       object  The string object
 * @param       range   The range
 * @return      The substring (autoreleased)
 */
XS_EXPORT XSAutoreleased XSStringRef XSString_SubstringWithRange( XSStringRef object, XSRange range );

/*!
 * @function    XSString_LowercaseString
 * @abstract    Gets a lowercase version of a string
 * @param       object  The string object
 * @return      The lowercase string (autoreleased)
 */
XS_EXPORT XSAutoreleased XSStringRef XSString_LowercaseString( XSStringRef object );

/*!
 * @function    XSString_UppercaseString
 * @abstract    Gets an uppercase version of a string
 * @param       object  The string object
 * @return      The uppercase string (autoreleased)
 */
XS_EXPORT XSAutoreleased XSStringRef XSString_UppercaseString( XSStringRef object );

/*!
 * @function    XSString_StringByAppendingString
 * @abstract    Gets a string by appending a string to another
 * @param       object  The string object
 * @param       s       The string to append
 * @return      The resulting string (autoreleased)
 */
XS_EXPORT XSAutoreleased XSStringRef XSString_StringByAppendingString( XSStringRef object, XSStringRef s );

/*!
 * @function    XSString_StringByAppendingCString
 * @abstract    Gets a string by appending a C string to a string
 * @param       object  The string object
 * @param       s       The C string to append
 * @return      The resulting string (autoreleased)
 */
XS_EXPORT XSAutoreleased XSStringRef XSString_StringByAppendingCString( XSStringRef object, const char * s );

/*!
 * @function    XSString_StringByAppendingFormat
 * @abstract    Gets a string by appending a format string with arguments to a string
 * @param       object  The string object
 * @param       format  The format string
 * @param       ...     The format arguments
 * @return      The resulting string (autoreleased)
 */
XS_EXPORT XSAutoreleased XSStringRef XSString_StringByAppendingFormat( XSStringRef object, const char * format, ... ) XS_FORMAT_ATTRIBUTE( printf, 2, 3 );

/*!
 * @function    XSString_RangeOfString
 * @abstract    Gets the range of a string in a string
 * @param       object  The string object
 * @param       s       The string to search for
 * @discussion  If the 's' string is not found in the receiver string, the
 *              range's location will be equal to XSNotFound.
 * @return      The range of the 's' string in the receiver string
 */
XS_EXPORT XSRange XSString_RangeOfString( XSStringRef object, XSStringRef s );

/*!
 * @function    XSString_RangeOfCString
 * @abstract    Gets the range of a C string in a string
 * @param       object  The string object
 * @param       s       The C string to search for
 * @discussion  If the C string is not found in the receiver string, the
 *              range's location will be equal to XSNotFound.
 * @return      The range of the C string in the receiver string
 */
XS_EXPORT XSRange XSString_RangeOfCString( XSStringRef object, const char * s );

/*!
 * @function    XSString_IsEqualToString
 * @abstract    Compares two string for equality
 * @param       object  The string object
 * @param       s       The string to compare with
 * @return      True if both strings are equal, otherwise false
 */
XS_EXPORT bool XSString_IsEqualToString( XSStringRef object, XSStringRef s );

/*!
 * @function    XSString_ContainsCString
 * @abstract    Checks whether a string contains a C string
 * @param       object  The string object
 * @param       s       The C string to check for
 * @return      True if the receiver string contains the C string, otherwise false
 */
XS_EXPORT bool XSString_ContainsCString( XSStringRef object, const char * s );

/*!
 * @function    XSString_ContainsString
 * @abstract    Checks whether a string contains another string
 * @param       object  The string object
 * @param       s       The string to check for
 * @return      True if the receiver string contains the 's' string, otherwise false
 */
XS_EXPORT bool XSString_ContainsString( XSStringRef object, XSStringRef s );

/*!
 * @function    XSString_StringFromXSPoint
 * @abstract    Gets an XSString object from an XSPoint value
 * @param       point   The XSPoint value
 * @return      An XSString object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSStringRef XSString_StringFromXSPoint( XSPoint point );

/*!
 * @function    XSString_StringFromXSSize
 * @abstract    Gets an XSString object from an XSSize value
 * @param       size    The XSSize value
 * @return      An XSString object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSStringRef XSString_StringFromXSSize( XSSize size );

/*!
 * @function    XSString_StringFromXSRect
 * @abstract    Gets an XSString object from an XSRect value
 * @param       rect    The XSRect value
 * @return      An XSString object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSStringRef XSString_StringFromXSRect( XSRect rect );

/*!
 * @function    XSString_StringFromXSEdgeInsets
 * @abstract    Gets an XSString object from an XSEdgeInsets value
 * @param       insets  The XSEdgeInsets value
 * @return      An XSString object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSStringRef XSString_StringFromXSEdgeInsets( XSEdgeInsets insets );

/*!
 * @function    XSString_StringFromXSRange
 * @abstract    Gets an XSString object from an XSRange value
 * @param       range   The XSRange value
 * @return      An XSString object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSStringRef XSString_StringFromXSRange( XSRange range );

#endif /* __XS_CLASSES_XS_STRING_H__ */

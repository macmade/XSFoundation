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
 * @discussion  XSStringRef objects are thread-safe
 */
typedef const struct __XSString * XSStringRef;

/*!
 * @typedef     XSMutableStringRef
 * @abstract    Opaque type for XSMutableString
 * @discussion  XSMutableStringRef objects are thread-safe
 */
typedef struct __XSString * XSMutableStringRef;

/*!
 * @function    XSString_GetClassID
 * @abstract    Gets the class ID for XSString
 * @return      The class ID for XSString
 */
XS_EXPORT XSStatic XSClassID XSString_GetClassID( void );

/*!
 * @function    XSString_String
 * @abstract    Gets an empty string
 * @return      An empty immutable string
 */
XS_EXPORT XSStatic XSAutoreleased XSStringRef XSString_String( void );

/*!
 * @function    XSString_MutableString
 * @abstract    Gets an empty mutable string
 * @return      An empty mutable string
 */
XS_EXPORT XSStatic XSAutoreleased XSMutableStringRef XSString_MutableString( void );

/*!
 * @function    XSString_MutableStringWithCapacity
 * @abstract    Hets an empty mutable string with an initial capacity
 * @param       capacity    The initial string capacity
 * @return      An empty mutable string
 */
XS_EXPORT XSStatic XSAutoreleased XSMutableStringRef XSString_MutableStringWithCapacity( XSUInteger capacity );

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
 * @function    XSString_Create
 * @abstract    Creates an empty string
 * @return      An empty immutable string
 */
XS_EXPORT XSStatic XSStringRef XSString_Create( void );

/*!
 * @function    XSString_CreateMutable
 * @abstract    Creates an empty mutable string
 * @return      An empty mutable string
 */
XS_EXPORT XSStatic XSMutableStringRef XSString_CreateMutable( void );

/*!
 * @function    XSString_CreateMutableWithCapacity
 * @abstract    Creates an empty mutable string with an initial capacity
 * @param       capacity    The initial string capacity
 * @return      An empty mutable string
 */
XS_EXPORT XSStatic XSMutableStringRef XSString_CreateMutableWithCapacity( XSUInteger capacity );

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
 * @function    XSString_CreateMutableCopy
 * @abstract    Creates a mutable copy of a string
 * @param       object      The string object
 * @return      The mutable copy of the string
 */
XS_EXPORT XSMutableStringRef XSString_CreateMutableCopy( XSStringRef object );

/*!
 * @function    XSString_IsMutable
 * @abstract    Checks if a string is mutable
 * @param       object      The string object
 * @return      True if the string is mutable, otherwise false
 */
XS_EXPORT bool XSString_IsMutable( XSStringRef object );

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








XS_EXPORT void XSString_AppendString( XSMutableStringRef object, XSStringRef s );
XS_EXPORT void XSString_AppendCString( XSMutableStringRef object, const char * s );
XS_EXPORT void XSString_AppendCharacters( XSMutableStringRef object, const char * s, XSUInteger length );
XS_EXPORT void XSString_AppendCharacter( XSMutableStringRef object, const char c );
XS_EXPORT void XSString_AppendFormat( XSMutableStringRef object, const char * format, ... ) XS_FORMAT_ATTRIBUTE( printf, 2, 3 );
XS_EXPORT void XSString_AppendFormatAndArgs( XSMutableStringRef object, const char * format, va_list args ) XS_FORMAT_ATTRIBUTE( printf, 2, 0 );








/*!
 * @function    XSString_StringWithFormatAndArgs
 * @abstract    Gets an XSString object from a format string with arguments
 * @param       format  The format string
 * @param       args     The format arguments
 * @return      An XSString object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSStringRef XSString_StringWithFormatAndArgs( const char * format, va_list args ) XS_FORMAT_ATTRIBUTE( printf, 1, 0 );

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

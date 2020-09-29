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
 * @header      XSString.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSString class
 */

#ifndef XS_CLASSES_XS_STRING_H
#define XS_CLASSES_XS_STRING_H

#include <XS/Macros.h>
#include <XS/Types.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdint.h>

XS_EXTERN_C_BEGIN

/*!
 * @define      XSSTR
 * @abstract    Creates an immutable string from a constant compile-time string.
 * @param       _s_     A constant C string
 * @discussion  The returned object is a constant. Retaining or releasing it
 *              will have no effect - it will remain valid until the program
 *              terminates.
 * @see         XSStringMakeConstantString
 */
#define XSSTR( _s_ ) XSStringMakeConstantString( "" _s_ "" )

/*!
 * @function    XSStringGetClassID
 * @abstract    Gets the class ID for XSString
 * @return      The class ID for XSString
 */
XS_EXPORT XSClassID XSStringGetClassID( void );

/*!
 * @function    XSStringCreateWithCString
 * @abstract    Creates a string with a C string
 * @param       cstr    The C string
 * @return      A string object
 */
XS_EXPORT XSStringRef XSStringCreateWithCString( const char * cstr );

/*!
 * @function    XSStringCreateWithCStringNoCopy
 * @abstract    Creates a string with a C string
 * @param       cstr    The C string
 * @return      A string object
 * @discussion  The C string is not copied. The caller has the responsibility
 *              to maintain it alive until the return object is deallocated.
 */
XS_EXPORT XSStringRef XSStringCreateWithCStringNoCopy( const char * cstr );

/*!
 * @function    XSStringCreateWithBytes
 * @abstract    Creates a string with bytes
 * @param       bytes   The bytes
 * @param       length  The number of bytes
 * @return      A string object
 */
XS_EXPORT XSStringRef XSStringCreateWithBytes( const uint8_t * bytes, size_t length );

/*!
 * @function    XSStringCreateWithFormat
 * @abstract    Creates a string with a format string
 * @param       fmt     The format string
 * @param       ...     Arguments for the format string
 * @return      A string object
 */
XS_EXPORT XSStringRef XSStringCreateWithFormat( const char * fmt, ... ) XS_FORMAT_ATTRIBUTE( printf, 1, 2 );

/*!
 * @function    XSStringCreateWithFormatAndArguments
 * @abstract    Creates a string with a format string
 * @param       fmt     The format string
 * @param       ap      Arguments for the format string
 * @return      A string object
 */
XS_EXPORT XSStringRef XSStringCreateWithFormatAndArguments( const char * fmt, va_list ap ) XS_FORMAT_ATTRIBUTE( printf, 1, 0 );

/*!
 * @function    XSStringWithCString
 * @abstract    Creates a string with a C string
 * @param       cstr    The C string
 * @return      A string object
 * @discussion  The returned object is autoreleased.
 */
XS_EXPORT XS_AUTORELEASED XSStringRef XSStringWithCString( const char * cstr );

/*!
 * @function    XSStringWithCStringNoCopy
 * @abstract    Creates a string with a C string
 * @param       cstr    The C string
 * @return      A string object
 * @discussion  The C string is not copied. The caller has the responsibility
 *              to maintain it alive until the return object is deallocated.
 *              The returned object is autoreleased.
 */
XS_EXPORT XS_AUTORELEASED XSStringRef XSStringWithCStringNoCopy( const char * cstr );

/*!
 * @function    XSStringWithBytes
 * @abstract    Creates a string with bytes
 * @param       bytes   The bytes
 * @param       length  The number of bytes
 * @return      A string object
 * @discussion  The returned object is autoreleased.
 */
XS_EXPORT XS_AUTORELEASED XSStringRef XSStringWithBytes( const uint8_t * bytes, size_t length );

/*!
 * @function    XSStringWithFormat
 * @abstract    Creates a string with a format string
 * @param       fmt     The format string
 * @param       ...     Arguments for the format string
 * @return      A string object
 * @discussion  The returned object is autoreleased.
 */
XS_EXPORT XS_AUTORELEASED XSStringRef XSStringWithFormat( const char * fmt, ... ) XS_FORMAT_ATTRIBUTE( printf, 1, 2 );

/*!
 * @function    XSStringWithFormatAndArguments
 * @abstract    Creates a string with a format string
 * @param       fmt     The format string
 * @param       ap      Arguments for the format string
 * @return      A string object
 * @discussion  The returned object is autoreleased.
 */
XS_EXPORT XS_AUTORELEASED XSStringRef XSStringWithFormatAndArguments( const char * fmt, va_list ap ) XS_FORMAT_ATTRIBUTE( printf, 1, 0 );

/*!
 * @function    XSStringHasPrefix
 * @abstract    Checks whether a string has a prefix
 * @param       str     The string object
 * @param       prefix  The prefix string
 * @return      True if the string has the prefix, otherwise false
 */
XS_EXPORT bool XSStringHasPrefix( XSStringRef str, XSStringRef prefix );

/*!
 * @function    XSStringHasSuffix
 * @abstract    Checks whether a string has a suffix
 * @param       str     The string object
 * @param       suffix  The suffix string
 * @return      True if the string has the suffix, otherwise false
 */
XS_EXPORT bool XSStringHasSuffix( XSStringRef str, XSStringRef suffix );

/*!
 * @function    XSStringContainsString
 * @abstract    Checks whether a string contains another string
 * @param       str     The string object
 * @param       search  The string to search
 * @return      True if the string contains the search string, otherwise false
 */
XS_EXPORT bool XSStringContainsString( XSStringRef str, XSStringRef search );

/*!
 * @function    XSStringHasCStringPrefix
 * @abstract    Checks whether a string has a prefix
 * @param       str     The string object
 * @param       prefix  The prefix C string
 * @return      True if the string has the prefix, otherwise false
 */
XS_EXPORT bool XSStringHasCStringPrefix( XSStringRef str, const char * prefix );

/*!
 * @function    XSStringHasCStringSuffix
 * @abstract    Checks whether a string has a suffix
 * @param       str     The string object
 * @param       suffix  The suffix C string
 * @return      True if the string has the suffix, otherwise false
 */
XS_EXPORT bool XSStringHasCStringSuffix( XSStringRef str, const char * suffix );

/*!
 * @function    XSStringContainsCString
 * @abstract    Checks whether a string contains a C string
 * @param       str     The string object
 * @param       search  The C string to search
 * @return      True if the string contains the C string, otherwise false
 */
XS_EXPORT bool XSStringContainsCString( XSStringRef str, const char * search );

/*!
 * @function    XSStringGetCharacterAtIndex
 * @abstract    Gets the character at a specific index
 * @param       str     The string object
 * @param       index   The index of the character
 * @return      The character at the specified index
 * @discussion  Returns 0 is the string is NULL or if the index is out of bounds.
 */
XS_EXPORT char XSStringGetCharacterAtIndex( XSStringRef str, size_t index );

/*!
 * @function    XSStringGetCString
 * @abstract    Gets the internal C string of a string object
 * @param       str     The string object
 * @return      The C string
 * @discussion  Any modification to the returned C string results in undefined
 *              behavior.
 */
XS_EXPORT const char * XSStringGetCString( XSStringRef str );

/*!
 * @function    XSStringGetLength
 * @abstract    Gets the length of a string object
 * @param       str     The string object
 * @return      The string's length
 */
XS_EXPORT size_t XSStringGetLength( XSStringRef str );

/*!
 * @function    XSStringIsMutable
 * @abstract    Checks if a string is mutable
 * @param       str     The string object
 * @return      True if the string is mutable, otherwise false
 */
XS_EXPORT bool XSStringIsMutable( XSStringRef str );

/*!
 * @function    XSStringMakeConstantString
 * @abstract    Creates an immutable string from a constant compile-time string.
 * @param       cstr    A constant C string
 * @return      An immutable string object
 * @discussion  The returned object is a constant. Retaining or releasing it
 *              will have no effect - it will remain valid until the program
 *              terminates.
 * @see         XSSTR
 */
XS_EXPORT XSStringRef XSStringMakeConstantString( const char * cstr );

XS_EXTERN_C_END

#endif /* XS_CLASSES_XS_STRING_H */

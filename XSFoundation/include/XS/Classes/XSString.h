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
 * @typedef     XSStringRef
 * @abstract    Opaque type for XSString (immutable)
 */
typedef const struct XSString * XSStringRef;

/*!
 * @function    XSStringGetClassID
 * @abstract    Gets the class ID for XSString
 * @return      The class ID for XSString
 */
XS_EXPORT XSClassID XSStringGetClassID( void );

XSStringRef XSStringCreateWithCString( const char * cstr );
XSStringRef XSStringCreateWithBytes( const uint8_t * bytes, size_t length );
XSStringRef XSStringCreateWithFormat( const char * fmt, ... ) XS_FORMAT_ATTRIBUTE( printf, 1, 2 );
XSStringRef XSStringCreateWithFormatAndArguments( const char * fmt, va_list ap ) XS_FORMAT_ATTRIBUTE( printf, 1, 0 );

XS_AUTORELEASED XSStringRef XSStringWithCString( const char * cstr );
XS_AUTORELEASED XSStringRef XSStringWithBytes( const uint8_t * bytes, size_t length );
XS_AUTORELEASED XSStringRef XSStringWithFormat( const char * fmt, ... ) XS_FORMAT_ATTRIBUTE( printf, 1, 2 );
XS_AUTORELEASED XSStringRef XSStringWithFormatAndArguments( const char * fmt, va_list ap ) XS_FORMAT_ATTRIBUTE( printf, 1, 0 );

bool         XSStringHasPrefix( XSStringRef str, XSStringRef prefix );
bool         XSStringHasSuffix( XSStringRef str, XSStringRef suffix );
bool         XSStringContainsString( XSStringRef str, XSStringRef search );
bool         XSStringHasCStringPrefix( XSStringRef str, const char * prefix );
bool         XSStringHasCStringSuffix( XSStringRef str, const char * suffix );
bool         XSStringContainsCString( XSStringRef str, const char * search );
char         XSStringGetCharacterAtIndex( XSStringRef str, size_t index );
const char * XSStringGetCString( XSStringRef str );
size_t       XSStringGetLength( XSStringRef str );

XS_EXTERN_C_END

#endif /* XS_CLASSES_XS_STRING_H */

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
 * @header      String.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    CS string functions
 */

#ifndef XS_FUNCTIONS_STRING_H
#define XS_FUNCTIONS_STRING_H

#include <XS/Macros.h>
#include <stdbool.h>
#include <stddef.h>

XS_EXTERN_C_BEGIN

/*!
 * @function    XSCStringCopy
 * @abstract    Copies a null-terminated C string into a buffer
 * @param       buf     The buffer in which to copy the string
 * @param       size    The size of the buffer, in bytes
 * @param       str     The string to copy
 * @param       count   The number of bytes to copy, or 0 for the whole string
 * @return      True if the string was copied, otherwise false
 * @discussion  This function will attempt to copy `count` bytes from `str`
 *              into `buf`, assuming there is enough room for it, including
 *              the termination character.
 *              The destination buffer will be zero-initialized whether or not
 *              the string is copied.
 */
XS_EXPORT bool XSCStringCopy( char * buf, size_t size, const char * str, size_t count );

XS_EXTERN_C_END

#endif /* XS_FUNCTIONS_STRING_H */

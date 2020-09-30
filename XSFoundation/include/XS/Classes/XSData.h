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
 * @header      XSData.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSData class
 */

#ifndef XS_CLASSES_XS_DATA_H
#define XS_CLASSES_XS_DATA_H

#include <XS/Macros.h>
#include <XS/Types.h>
#include <stdint.h>
#include <stdbool.h>

XS_EXTERN_C_BEGIN

/*!
 * @typedef     XSDataRef
 * @abstract    Opaque type for XSData
 */
typedef const struct XSData * XSDataRef;

/*!
 * @function    XSDataGetClassID
 * @abstract    Gets the class ID for XSData
 * @return      The class ID for XSData
 */
XS_EXPORT XSClassID XSDataGetClassID( void );

/*!
 * @function    XSDataCreateWithBytes
 * @abstract    Creates a data object from a bytes buffer
 * @param       bytes   The bytes buffer
 * @param       length  The length of the bytes buffer
 * @return      A data object
 */
XSDataRef XSDataCreateWithBytes( uint8_t * bytes, size_t length );

/*!
 * @function    XSDataCreateWithBytes
 * @abstract    Creates a data object from a bytes buffer
 * @param       bytes   The bytes buffer
 * @param       length  The length of the bytes buffer
 * @return      A data object
 * @discussion  The bytes buffer is not copied. The caller has the
 *              responsibility to maintain it alive until the return object
 *              is deallocated.
 */
XSDataRef XSDataCreateWithBytesNoCopy( uint8_t * bytes, size_t length );

/*!
 * @function    XSDataCreateWithBytes
 * @abstract    Creates a data object from a bytes buffer
 * @param       bytes   The bytes buffer
 * @param       length  The length of the bytes buffer
 * @return      A data object
 * @discussion  The returned object is autoreleased.
 */
XS_AUTORELEASED XSDataRef XSDataWithBytes( uint8_t * bytes, size_t length );

/*!
 * @function    XSDataCreateWithBytes
 * @abstract    Creates a data object from a bytes buffer
 * @param       bytes   The bytes buffer
 * @param       length  The length of the bytes buffer
 * @return      A data object
 * @discussion  The bytes buffer is not copied. The caller has the
 *              responsibility to maintain it alive until the return object
 *              is deallocated.
 *              The returned object is autoreleased.
 */
XS_AUTORELEASED XSDataRef XSDataWithBytesNoCopy( uint8_t * bytes, size_t length );

/*!
 * @function    XSDataGetLength
 * @abstract    Gets the length of the data
 * @param       data    The data object
 * @return      The length of the data
 */
size_t XSDataGetLength( XSDataRef data );

/*!
 * @function    XSDataGetBytesPointer
 * @abstract    Gets the internal byte buffer of a data object
 * @param       data    The data object
 * @return      The internal byte buffer
 * @discussion  Any modification to the returned buffer results in undefined
 *              behavior.
 */
const uint8_t * XSDataGetBytesPointer( XSDataRef data );

/*!
 * @function    XSDataGetBytes
 * @abstract    Gets bytes from a specific range
 * @param       data    The data object
 * @param       buf     The buffer in which to copy the bytes
 * @param       range   The range of the bytes to copy
 * @return      True if the copy was successfull, otherwise false
 * @discussion  This function will return false if the range's length is zero or
 *              if the range exceeds the data length.
 *              The passed buffer will not be modified in such a case.
 */
bool XSDataGetBytes( XSDataRef data, uint8_t * buf, XSRange range );

XS_EXTERN_C_END

#endif /* XS_CLASSES_XS_DATA_H */

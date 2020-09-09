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
 * @header      XSDataRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSData class
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_DATA_H__
#define __XS_CLASSES_XS_DATA_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     XSDataRef
 * @abstract    Opaque type for XSData
 * @discussion  XSDataRef objects are thread-safe
 */
typedef const struct __XSData * XSDataRef;

/*!
 * @typedef     XSMutableDataRef
 * @abstract    Opaque type for XSMutableData
 * @discussion  XSMutableDataRef objects are thread-safe
 */
typedef struct __XSData * XSMutableDataRef;

/*!
 * @typedef     XSData_BufferReleaseType
 * @abstract    Release type for XSData internal buffer
 */
typedef enum
{
    XSData_BufferReleaseTypeNone    = 0x00, /*! No release */
    XSData_BufferReleaseTypeRelease = 0x01, /*! Release - For memory allocated with XSAlloc */
    XSData_BufferReleaseTypeFree    = 0x02  /*! Free - For memory allocated with malloc */
}
XSData_BufferReleaseType;

/*!
 * @function    XSData_GetClassID
 * @abstract    Gets the class ID for XSData
 * @return      The class ID for XSData
 */
XS_EXPORT XSStatic XSClassID XSData_GetClassID( void );

/*!
 * @function    XSData_Data
 * @abstract    Gets an empty data object
 * @return      An empty immutable data object
 */
XS_EXPORT XSStatic XSAutoreleased XSDataRef XSData_Data( void );

/*!
 * @function    XSData_DataWithBytes
 * @abstract    Gets a data object with specific bytes
 * @param       bytes       A pointer to the byte buffer
 * @param       length      The number of bytes in the buffer
 * @return      An immutable data object
 * @discussion  The bytes in the buffer will be copied to an internal buffer.
 * @see         XSData_DataWithBytesNoCopy
 */
XS_EXPORT XSStatic XSAutoreleased XSDataRef XSData_DataWithBytes( XSUInt8 * bytes, XSUInteger length );

/*!
 * @function    XSData_DataWithBytesNoCopy
 * @abstract    Gets a data object with specific bytes
 * @param       bytes               A pointer to the byte buffer
 * @param       length              The number of bytes in the buffer
 * @param       bufferReleaseType   The release type for the passed byte buffer (when the data object is deallocated)
 * @return      An immutable data object
 * @discussion  The bytes in the buffer will not be copied.
 * @see         XSData_BufferReleaseType
 */
XS_EXPORT XSStatic XSAutoreleased XSDataRef XSData_DataWithBytesNoCopy( XSUInt8 * bytes, XSUInteger length, XSData_BufferReleaseType bufferReleaseType );

/*!
 * @function    XSData_DataWithContentsOfFileAtPath
 * @abstract    Gets a data object with the contents of a file
 * @param       path    The path to the file
 * @return      An immutable data object
 * @discussion  NULL will be returned if the file does not exist or if the file
 *              is not accessible.
 */
XS_EXPORT XSStatic XSAutoreleased XSDataRef XSData_DataWithContentsOfFileAtPath( const char * path );

/*!
 * @function    XSData_DataWithData
 * @abstract    Gets an data object from another data object
 * @param       data    The data object
 * @return      An immutable data object based on the given data object
 */
XS_EXPORT XSStatic XSAutoreleased XSDataRef XSData_DataWithData( XSDataRef data );

/*!
 * @function    XSData_MutableData
 * @abstract    Gets an empty mutable data object
 * @return      An empty mutable data object
 */
XS_EXPORT XSStatic XSAutoreleased XSMutableDataRef XSData_MutableData( void );

/*!
 * @function    XSData_MutableDataWithInitialCapacity
 * @abstract    Gets an empty mutable data object with an initial capacity
 * @param       capacity    The initial capacity of the internal byte buffer
 * @return      An empty mutable data object
 */
XS_EXPORT XSStatic XSAutoreleased XSMutableDataRef XSData_MutableDataWithInitialCapacity( XSUInteger capacity );

/*!
 * @function    XSData_Create
 * @abstract    Creates an empty data object
 * @return      An empty immutable data object
 */
XS_EXPORT XSStatic XSDataRef XSData_Create( void );

/*!
 * @function    XSData_CreateWithBytes
 * @abstract    Creates a data object with specific bytes
 * @param       bytes       A pointer to the byte buffer
 * @param       length      The number of bytes in the buffer
 * @return      An immutable data object
 * @discussion  The bytes in the buffer will be copied to an internal buffer.
 * @see         XSData_DataWithBytesNoCopy
 */
XS_EXPORT XSStatic XSDataRef XSData_CreateWithBytes( XSUInt8 * bytes, XSUInteger length );

/*!
 * @function    XSData_CreateWithBytesNoCopy
 * @abstract    Creates a data object with specific bytes
 * @param       bytes               A pointer to the byte buffer
 * @param       length              The number of bytes in the buffer
 * @param       bufferReleaseType   The release type for the passed byte buffer (when the data object is deallocated)
 * @return      An immutable data object
 * @discussion  The bytes in the buffer will not be copied.
 * @see         XSData_BufferReleaseType
 */
XS_EXPORT XSStatic XSDataRef XSData_CreateWithBytesNoCopy( XSUInt8 * bytes, XSUInteger length, XSData_BufferReleaseType bufferReleaseType );

/*!
 * @function    XSData_CreateWithContentsOfFileAtPath
 * @abstract    Creates a data object with the contents of a file
 * @param       path    The path to the file
 * @return      An immutable data object
 * @discussion  NULL will be returned if the file does not exist or if the file
 *              is not accessible.
 */
XS_EXPORT XSStatic XSDataRef XSData_CreateWithContentsOfFileAtPath( const char * path );

/*!
 * @function    XSData_CreateWithData
 * @abstract    Creates an data object from another data object
 * @param       data    The data object
 * @return      An immutable data object based on the given data object
 */
XS_EXPORT XSStatic XSDataRef XSData_CreateWithData( XSDataRef data );

/*!
 * @function    XSData_CreateMutable
 * @abstract    Creates an empty mutable data object
 * @return      An empty mutable data object
 */
XS_EXPORT XSStatic XSMutableDataRef XSData_CreateMutable( void );

/*!
 * @function    XSData_CreateMutableWithInitialCapacity
 * @abstract    Creates an empty mutable data object with an initial capacity
 * @param       capacity    The initial capacity of the internal byte buffer
 * @return      An empty mutable data object
 */
XS_EXPORT XSStatic XSMutableDataRef XSData_CreateMutableWithInitialCapacity( XSUInteger capacity );

/*!
 * @function    XSData_CreateMutableCopy
 * @abstract    Creates a mutable copy of a data object
 * @param       data    The data object
 * @return      The mutable copy of the data object
 */
XS_EXPORT XSMutableDataRef XSData_CreateMutableCopy( XSDataRef data );

/*!
 * @function    XSData_IsMutable
 * @abstract    Checks if a data object is mutable
 * @param       data    The data object
 * @return      True if the data object is mutable, otherwise false
 */
XS_EXPORT bool XSData_IsMutable( XSDataRef data );

/*!
 * @function    XSData_GetLength
 * @abstract    Gets the length of a data object
 * @param       data    The data object
 * @return      The number of bytes contained in the data object
 */
XS_EXPORT XSUInteger XSData_GetLength( XSDataRef data );

/*!
 * @function    XSData_GetBytesPointer
 * @abstract    Gets a read-only pointer to the internal byte buffer of a data oject
 * @param       data    The data object
 * @return      A pointer to the byte buffer
 * @discussion  The returned pointer is read-only. Never attempts to modify
 *              its contents.
 */
XS_EXPORT const XSUInt8 * XSData_GetBytesPointer( XSDataRef data );

/*!
 * @function    XSData_GetBytesInRange
 * @abstract    Gets bytes in a specific range from a data object
 * @param       data    The data object
 * @param       buffer  The buffer in which to place the bytes
 * @param       range   The range of the bytes to get from the data object
 * @discussion  The passed buffer must have the necessary capacity to store
 *              the required number of bytes.
 *              Results are undefined if the passed buffer is NULL or if the
 *              specified range is not contained in the data object's range.
 */
XS_EXPORT void XSData_GetBytesInRange( XSDataRef data, XSUInt8 * buffer, XSRange range );

/*!
 * @function    XSData_SubDataWithRange
 * @abstract    Gets a data object containing bytes from another data object at a specific range
 * @param       data    The data object
 * @param       range   The range of the bytes for the new data object. Pass XSRangeZero to get all bytes from the data object
 * @return      Am immutable data object 
 */
XS_EXPORT XSDataRef XSData_SubDataWithRange( XSDataRef data, XSRange range );

/*!
 * @function    XSData_RangeOfData
 * @abstract    Searches a data object for data contained in another data object
 * @param       data            The data object
 * @param       search          The data object containing the bytes to search for
 * @param       searchRange     The search range. Pass XSRangeZero to search in the whole data object
 * @return      The range of the data
 * @discussion  If the data was not found, the location of the returned range will by XSNotFound.
 */
XS_EXPORT XSRange XSData_RangeOfData( XSDataRef data, XSDataRef search, XSRange searchRange );

/*!
 * @function    XSData_AppendBytes
 * @abstract    Append bytes to a data object
 * @param       data    The data object
 * @param       bytes   The buffer containing the bytes to append
 * @param       length  The length of the byte buffer
 */
XS_EXPORT void XSData_AppendBytes( XSMutableDataRef data, XSUInt8 * bytes, XSUInteger length );

/*!
 * @function    XSData_AppendByte
 * @abstract    Append a single byte to a data object
 * @param       data    The data object
 * @param       byte    The byte to append
 */
XS_EXPORT void XSData_AppendByte( XSMutableDataRef data, XSUInt8 byte );

/*!
 * @function    XSData_AppendData
 * @abstract    Appends a data object to a data object
 * @param       data            The data object
 * @param       dataToAppend    The data object to append
 */
XS_EXPORT void XSData_AppendData( XSMutableDataRef data, XSDataRef dataToAppend );

/*!
 * @function    XSData_ResetBytesInRange
 * @abstract    Resets bytes at a specific range in a data object
 * @param       data    The data object
 * @param       range   The range of the bytes to reset. Pass XSRangeZero to reset the whole data object
 * @discussion  Bytes in the specific range will be set to zero.
 */
XS_EXPORT void XSData_ResetBytesInRange( XSMutableDataRef data, XSRange range );

/*!
 * @function    XSData_ReplaceBytesInRangeWithBytes
 * @abstract    Replaces bytes in a data object with other bytes
 * @param       data        The data object
 * @param       range       The range of the bytes to replace. Pass XSRangeZero to replace bytes in the whole data object
 * @param       newBytes    The bytes
 */
XS_EXPORT void XSData_ReplaceBytesInRangeWithBytes( XSMutableDataRef data, XSRange range, XSUInt8 * newBytes );

#endif /* __XS_CLASSES_XS_DATA_H__ */

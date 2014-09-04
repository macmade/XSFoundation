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
XS_EXPORT XSStatic XSAutoreleased XSDataRef XSData_MutableData( void );

/*!
 * @function    XSData_MutableDataWithInitialCapacity
 * @abstract    Gets an empty mutable data object with an initial capacity
 * @param       capacity    The initial capacity of the internal byte buffer
 * @return      An empty mutable data object
 */
XS_EXPORT XSStatic XSAutoreleased XSDataRef XSData_MutableDataWithInitialCapacity( XSUInteger capacity );

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
XS_EXPORT XSStatic XSDataRef XSData_CreateMutable( void );

/*!
 * @function    XSData_CreateMutableWithInitialCapacity
 * @abstract    Creates an empty mutable data object with an initial capacity
 * @param       capacity    The initial capacity of the internal byte buffer
 * @return      An empty mutable data object
 */
XS_EXPORT XSStatic XSDataRef XSData_CreateMutableWithInitialCapacity( XSUInteger capacity );

/*!
 * @function    XSData_CreateMutableCopy
 * @abstract    Creates a mutable copy of a data object
 * @param       data    The data object
 * @return      The mutable copy of the data object
 */
XS_EXPORT XSDataRef XSData_CreateMutableCopy( XSDataRef data );

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
XS_EXPORT void XSData_AppendBytes( XSDataRef data, XSUInt8 * bytes, XSUInteger length );

/*!
 * @function    XSData_AppendByte
 * @abstract    Append a single byte to a data object
 * @param       data    The data object
 * @param       byte    The byte to append
 */
XS_EXPORT void XSData_AppendByte( XSDataRef data, XSUInt8 byte );

/*!
 * @function    XSData_AppendData
 * @abstract    Appends a data object to a data object
 * @param       data            The data object
 * @param       dataToAppend    The data object to append
 */
XS_EXPORT void XSData_AppendData( XSDataRef data, XSDataRef dataToAppend );

/*!
 * @function    XSData_ResetBytesInRange
 * @abstract    Resets bytes at a specific range in a data object
 * @param       data    The data object
 * @param       range   The range of the bytes to reset. Pass XSRangeZero to reset the whole data object
 * @discussion  Bytes in the specific range will be set to zero.
 */
XS_EXPORT void XSData_ResetBytesInRange( XSDataRef data, XSRange range );

/*!
 * @function    XSData_ReplaceBytesInRangeWithBytes
 * @abstract    Replaces bytes in a data object with other bytes
 * @param       data        The data object
 * @param       range       The range of the bytes to replace. Pass XSRangeZero to replace bytes in the whole data object
 * @param       newBytes    The bytes
 */
XS_EXPORT void XSData_ReplaceBytesInRangeWithBytes( XSDataRef data, XSRange range, XSUInt8 * newBytes );

#endif /* __XS_CLASSES_XS_DATA_H__ */

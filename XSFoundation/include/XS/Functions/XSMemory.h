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
 * @header      XSMemory.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSFoundation memory allocation functions
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_FUNCTIONS_XS_MEMORY_H__
#define __XS_FUNCTIONS_XS_MEMORY_H__

XS_EXTERN_C_BEGIN

#include <XS/XSTypes.h>

/*!
 * @define      XSAlloc
 * @abstract    Allocates memory
 * @param       _bytes_     The number of bytes to allocate
 * @discussion  The allocated memory will be zero-filled
 * @return      The allocated memory, or NULL
 */
#define XSAlloc( _bytes_ )              XSAllocWithInfos( _bytes_, 0, __FILE__, __LINE__, __func__ )

/*!
 * @define      XSRealloc
 * @abstract    Reallocates memory
 * @param       _memory_    The memory data to reallocate
 * @param       _bytes_     The number of bytes to reallocate
 * @discussion  If the requested bytes are larger than the previous allocation
 *              size, additional data will be zero-filled.
 * @return      The reallocated memory, or NULL
 */
#define XSRealloc( _memory_, _bytes_ )  XSReallocWithInfos( _memory_, _bytes_, __FILE__, __LINE__, __func__ )

/*!
 * @define      XSAutoAlloc
 * @abstract    Allocates memory which will be automatically released
 * @param       _bytes_     The number of bytes to allocate
 * @discussion  The memory data will be placed in the instance of the current
 *              auto-release pool, and will be released the next time
 *              the auto-release pool is drained.
 *              The allocated memory will be zero-filled
 * @return      The allocated memory, or NULL
 */
#define XSAutoAlloc( _bytes_ )          XSAutoAllocWithInfos( _bytes_, 0, __FILE__, __LINE__, __func__ )

/*!
 * @define      XSRetain
 * @abstract    Retains memory data
 * @param       _memory_    The memory data to retain
 * @return      The memory data
 */
#define XSRetain( _memory_ )            XSRetainWithInfos( _memory_, __FILE__, __LINE__, __func__ )

/*!
 * @define      XSRelease
 * @abstract    Releases memory data
 * @param       _memory_    The memory data to release
 * @discussion  Memory may be freed if the retain count for the memory
 *              data reaches 0.
 */
#define XSRelease( _memory_ )           XSReleaseWithInfos( _memory_, __FILE__, __LINE__, __func__ )

/*!
 * @define      XSCopy
 * @abstract    Copies a memory data object
 * @param       _memory_    The memory data object to copy
 * @return      The copy of the memory data object
 */
#define XSCopy( _memory_ )              XSCopyWithInfos( _memory_, __FILE__, __LINE__, __func__ )

/*!
 * @function    XSAllocWithInfos
 * @abstract    Allocates memory
 * @param       bytes       The number of bytes to allocate
 * @param       classID     The class ID, if any
 * @param       file        The file in which the allocation occurs
 * @param       line        The line number of the file in which the allocation occurs
 * @param       func        The function in which the allocation occurs
 * @discussion  Do not use this function directly. Use the XSAlloc macro
 *              instead.
 * @return      The allocated memory, or NULL
 */
XS_EXPORT void * XSAllocWithInfos( XSUInteger bytes, XSClassID classID, const char * file, int line, const char * func );

/*!
 * @function    XSAutoAllocWithInfos
 * @abstract    Allocates memory which will be automatically released
 * @param       bytes       The number of bytes to allocate
 * @param       classID     The class ID, if any
 * @param       file        The file in which the allocation occurs
 * @param       line        The line number of the file in which the allocation occurs
 * @param       func        The function in which the allocation occurs
 * @discussion  Do not use this function directly. Use the XSAutoAlloc macro
 *              instead.
 * @return      The allocated memory, or NULL
 */
XS_EXPORT void * XSAutoAllocWithInfos( XSUInteger bytes, XSClassID classID, const char * file, int line, const char * func );

/*!
 * @function    XSReallocWithInfos
 * @abstract    Reallocates memory
 * @param       memory      The memory data to reallocate
 * @param       bytes       The number of bytes to reallocate
 * @param       file        The file in which the reallocation occurs
 * @param       line        The line number of the file in which the reallocation occurs
 * @param       func        The function in which the reallocation occurs
 * @discussion  Do not use this function directly. Use the XSRealloc macro
 *              instead.
 * @return      The reallocated memory, or NULL
 */
XS_EXPORT void * XSReallocWithInfos( const void * memory, XSUInteger bytes, const char * file, int line, const char * func );

/*!
 * @function    XSRetain
 * @abstract    Retains memory data
 * @param       memory      The memory data to retain
 * @param       file        The file in which the retain occurs
 * @param       line        The line number of the file in which the retain occurs
 * @param       func        The function in which the retain occurs
 * @return      The memory data
 * @discussion  Do not use this function directly. Use the XSRelease macro
 *              instead.
 */
XS_EXPORT void * XSRetainWithInfos( const void * memory, const char * file, int line, const char * func );

/*!
 * @function    XSReleaseWithInfos
 * @abstract    Releases memory data
 * @param       memory      The memory data to release
 * @param       file        The file in which the release occurs
 * @param       line        The line number of the file in which the release occurs
 * @param       func        The function in which the release occurs
 * @discussion  Do not use this function directly. Use the XSRelease macro
 *              instead.
 */
XS_EXPORT void XSReleaseWithInfos( const void * memory, const char * file, int line, const char * func );

/*!
 * @function    XSAutorelease
 * @abstract    Auto-releases memory data
 * @param       memory      The memory data to release
 * @discussion  The memory data will be placed in the instance of the current
 *              auto-release pool, and will be released the next time
 *              the auto-release pool is drained.
 * @return      The memory data
 */
XS_EXPORT void * XSAutorelease( const void * memory );

/*!
 * @function    XSEquals
 * @abstract    Checks whether two memory data objects are equals
 * @param       memory1     The first memory data object to compare
 * @param       memory2     The second memory data object to compare
 * @return      True if both memory data objects are equals, otherwise false
 */
XS_EXPORT bool XSEquals( const void * memory1, const void * memory2 );

/*!
 * @function    XSCopy
 * @abstract    Copies a memory data object
 * @param       memory      The memory data object to copy
 * @param       file        The file in which the copy occurs
 * @param       line        The line number of the file in which the copy occurs
 * @param       func        The function in which the copy occurs
 * @discussion  Do not use this function directly. Use the XSCopy macro
 *              instead.
 * @return      The copy of the memory data object
 */
XS_EXPORT void * XSCopyWithInfos( const void * memory, const char * file, int line, const char * func );

XS_EXTERN_C_END

#endif /* __XS_FUNCTIONS_XS_MEMORY_H__ */

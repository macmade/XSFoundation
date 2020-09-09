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

/* $Id$ */

/*!
 * @header      XSMemory.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSMemory.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_FUNCTIONS_XS_MEMORY_H__
#define __XS___PRIVATE_FUNCTIONS_XS_MEMORY_H__

#include <XS/XSTypes.h>

/*!
 * @typedef     __XS_MEMORY_FENCE_SIZE
 * @abstract    The size of the memory fence to prevent overflows
 */
#ifdef DEBUG
#define __XS_MEMORY_FENCE_SIZE  16
#else
#define __XS_MEMORY_FENCE_SIZE  0
#endif

/*!
 * @typedef     __XSMemoryObject
 * @abstract    Memory object type
 */
typedef struct
{
    volatile XSInteger  retainCount;                        /*! The object's retain count */
    XSUInteger          size;                               /*! The allocated data size */
    XSInteger           allocID;                            /*! The allocation ID */
    XSClassID           classID;                            /*! The class ID (only for allocated instances) */
    #ifdef DEBUG
    unsigned char       fence[ __XS_MEMORY_FENCE_SIZE ];    /*! Memory fence to prevent overflows (DEBUG builds only) */
    #endif
}
__XSMemoryObject;

/*!
 * @typedef     __XSMemoryAllocID
 * @abstract    The current allocation ID
 */
XS_EXTERN volatile XSInteger __XSMemory_AllocID;

#ifdef DEBUG

/*!
 * @typedef     __XSMemoryFenceData
 * @abstract    The memory fence data
 */
XS_EXTERN const char __XSMemory_FenceData[ __XS_MEMORY_FENCE_SIZE ];

#endif


/*!
 * @function    __XSMemory_GetMemoryObject
 * @abstract    Gets the memory object for a pointer
 * @param       ptr     The pointer for which to get the memory object
 * @return      The memory object
 */
__XSMemoryObject * __XSMemory_GetMemoryObject( const void * ptr );

/*!
 * @function    __XSAllocWithInfos
 * @abstract    Allocates memory
 * @param       bytes       The number of bytes to allocate
 * @param       classID     The class ID, if any
 * @param       file        The file in which the allocation occurs
 * @param       line        The line number of the file in which the allocation occurs
 * @param       func        The function in which the allocation occurs
 * @return      The allocated memory, or NULL
 */
void * __XSAllocWithInfos( XSUInteger bytes, XSClassID classID, const char * file, int line, const char * func );

/*!
 * @function    __XSReleaseWithInfos
 * @abstract    Releases memory data
 * @param       memory      The memory data to release
 * @param       file        The file in which the release occurs
 * @param       line        The line number of the file in which the release occurs
 * @param       func        The function in which the release occurs
 */
void __XSReleaseWithInfos( const void * memory, const char * file, int line, const char * func );

#endif /* __XS___PRIVATE_FUNCTIONS_XS_MEMORY_H__ */

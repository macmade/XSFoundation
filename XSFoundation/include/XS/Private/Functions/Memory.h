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
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSMemory.h
 */

#ifndef XS_PRIVATE_FUNCTIONS_MEMORY_H
#define XS_PRIVATE_FUNCTIONS_MEMORY_H

#include <XS/Macros.h>
#include <XS/Types/XSClassID.h>
#include <stddef.h>

XS_EXTERN_C_BEGIN

/*!
 * @typedef     XS_MEMORY_FENCE_SIZE
 * @abstract    The size of the memory fence to prevent overflows
 */
#ifdef DEBUG
#define XS_MEMORY_FENCE_SIZE 16
#else
#define XS_MEMORY_FENCE_SIZE 0
#endif

/*!
 * @typedef     XSMemoryObject
 * @abstract    Memory object type
 */
typedef struct
{
    volatile int64_t retainCount; /*! The object's retain count */
    size_t           size;        /*! The allocated data size */
    int64_t          allocID;     /*! The allocation ID */
    XSClassID        classID;     /*! The class ID (only for allocated instances) */
#ifdef DEBUG
    uint8_t fence[ XS_MEMORY_FENCE_SIZE ]; /*! Memory fence to prevent overflows (DEBUG builds only) */
#endif
} XSMemoryObject;

/*!
 * @typedef     XSMemoryAllocID
 * @abstract    The current allocation ID
 */
XS_EXTERN volatile int64_t XSMemoryAllocID;

#ifdef DEBUG

/*!
 * @typedef     XSMemoryFenceData
 * @abstract    The memory fence data
 */
XS_EXTERN const uint8_t XSMemoryFenceData[ XS_MEMORY_FENCE_SIZE ];

#endif

/*!
 * @function    XSGetMemoryObject
 * @abstract    Gets the memory object for a pointer
 * @param       ptr     The pointer for which to get the memory object
 * @return      The memory object
 */
XSMemoryObject * XSGetMemoryObject( const void * ptr );

XS_EXTERN_C_END

#endif /* XS_PRIVATE_FUNCTIONS_MEMORY_H */

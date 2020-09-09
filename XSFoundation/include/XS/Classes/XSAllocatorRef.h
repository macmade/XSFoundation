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
 * @header      XSAllocatorRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSAllocator class
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_ALLOCATOR_H__
#define __XS_CLASSES_XS_ALLOCATOR_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>
#include <XS/Classes/XSStringRef.h>

/*!
 * @typedef     XSAllocatorRef
 * @abstract    Opaque type for XSAllocator
 */
typedef const struct __XSAllocator * XSAllocatorRef;

/*!
 * @function    XSAllocator_GetClassID
 * @abstract    Gets the class ID for XSAllocator
 * @return      The class ID for XSAllocator
 */
XS_EXPORT XSStatic XSClassID XSAllocator_GetClassID( void );

typedef void * ( * XSAllocator_AllocateCallback )( XSUInteger size, XSClassID classID, XSCompilerContext * context );
typedef void * ( * XSAllocator_ReallocateCallback )( const void * memory, XSUInteger size, XSCompilerContext * context );
typedef void ( * XSAllocator_DeallocateCallback )( const void * memory, XSCompilerContext * context );
typedef void * ( * XSAllocator_RetainCallback )( const void * memory, XSCompilerContext * context );
typedef void ( * XSAllocator_ReleaseCallback )( const void * memory, XSCompilerContext * context );
typedef XSUInteger ( * XSAllocator_PreferredSizeCallback )( XSUInteger size );

typedef struct
{
    XSAllocator_AllocateCallback        alloc;
    XSAllocator_ReallocateCallback      realloc;
    XSAllocator_DeallocateCallback      dealloc;
    XSAllocator_RetainCallback          retain;
    XSAllocator_ReleaseCallback         release;
    XSAllocator_PreferredSizeCallback   size;
}
XSAllocator_Callbacks;

XS_EXPORT XSStatic XSAllocatorRef XSAllocator_Create( XSStringRef name, XSAllocator_Callbacks * callbacks );
XS_EXPORT XSStatic XSAllocatorRef XSAllocator_GetDefault( void );
XS_EXPORT XSStatic void XSAllocator_SetDefault( XSAllocatorRef allocator );

XS_EXPORT void * XSAllocator_Allocate( XSAllocatorRef allocator, XSUInteger size, XSClassID classID, XSCompilerContext * context );
XS_EXPORT void * XSAllocator_Reallocate( XSAllocatorRef allocator, const void * memory, XSUInteger size, XSCompilerContext * context );
XS_EXPORT void XSAllocator_Deallocate( XSAllocatorRef allocator, const void * memory, XSCompilerContext * context );
XS_EXPORT void * XSAllocator_Retain( XSAllocatorRef allocator, const void * memory, XSCompilerContext * context );
XS_EXPORT void XSAllocator_Release( XSAllocatorRef allocator, const void * memory, XSCompilerContext * context );
XS_EXPORT XSUInteger XSAllocator_GetPreferredSizeForSize( XSAllocatorRef allocator, XSUInteger size );
XS_EXPORT XSStringRef XSAllocator_GetName( XSAllocatorRef allocator );

#endif /* __XS_CLASSES_XS_ALLOCATOR_H__ */

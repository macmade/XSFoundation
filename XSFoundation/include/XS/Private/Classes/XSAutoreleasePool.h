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
 * @header      XSAutoreleasePool.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private declarations for the XSAutoreleasePool class
 */

#ifndef XS_PRIVATE_CLASSES_XS_AUTORELEASE_POOL_H
#define XS_PRIVATE_CLASSES_XS_AUTORELEASE_POOL_H

#include <XS/Macros.h>
#include <XS/Types.h>

XS_EXTERN_C_BEGIN

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

/*!
 * @struct      XSAutoreleasePoolStorage
 * @abstract    Internal storage for XSAutoreleasePool
 */
struct XSAutoreleasePoolStorage
{
    const void *                      objects[ 256 ]; /*! Storage for objects */
    size_t                            count;          /*! The number of contained objects */
    struct XSAutoreleasePoolStorage * next;           /*! Next storage */
};

/*!
 * @struct      XSAutoreleasePool
 * @abstract    XSAutoreleasePool instance
 */
struct XSAutoreleasePool
{
    uint64_t                          threadID; /*! The thread ID for the autorelease pool */
    struct XSAutoreleasePoolStorage * storage;  /*! Internal storage for contained objects */
    struct XSAutoreleasePool *        next;     /*! Next autorelease pool in the current thread */
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
XS_EXTERN_C_END

/*!
 * @var         XSAutoreleasePoolTLSKey
 * @abstract    The TLS key for autorelease pools
 */
XS_EXTERN XSTLSKey XSAutoreleasePoolTLSKey;

/*!
 * @var         XSAutoreleasePoolClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID XSAutoreleasePoolClassID;

/*!
 * @var         XSAutoreleasePoolClass
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo XSAutoreleasePoolClass;

/*!
 * @function    XSAutoreleasePoolInitialize
 * @abstract    Class initializer
 */
void XSAutoreleasePoolInitialize( void );

/*!
 * @function    XSAutoreleasePoolFinalize
 * @abstract    Class finalizer
 */
void XSAutoreleasePoolFinalize( void );

/*!
 * @function    XSAutoreleasePoolConstructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The constructed object
 */
XSMutableObjectRef XSAutoreleasePoolConstructor( XSMutableObjectRef object );

/*!
 * @function    XSAutoreleasePoolDestructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void XSAutoreleasePoolDestructor( XSMutableObjectRef object );

#endif /* XS_PRIVATE_CLASSES_XS_AUTORELEASE_POOL_H */

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
 * @header      XSLockRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSLock class
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_LOCK_H__
#define __XS_CLASSES_XS_LOCK_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     XSLockRef
 * @abstract    Opaque type for XSLock
 */
typedef struct __XSLock * XSLockRef;

/*!
 * @function    XSLock_GetClassID
 * @abstract    Gets the class ID for XSLock
 * @return      The class ID for XSLock
 */
XS_EXPORT XSStatic XSClassID XSLock_GetClassID( void );

/*!
 * @function    XSLock_Create
 * @abstract    Creates a lock object
 * @return      The lock object
 */
XS_EXPORT XSStatic XSLockRef XSLock_Create( void );

/*!
 * @function    XSLock_Lock
 * @abstract    Locks a lock object
 * @param       lock    The lock object
 */
XS_EXPORT void XSLock_Lock( XSLockRef lock );

/*!
 * @function    XSLock_TryLock
 * @abstract    Tries to lock a lock object
 * @return      The class ID for XSLock
 * @param       lock    The lock object
 * @discussion  If the lock can't be qcquired, this function will return
 *              immediately, rather than waiting.
 * @return      True if the lock was acquired, otherwise false
 */
XS_EXPORT bool XSLock_TryLock( XSLockRef lock );

/*!
 * @function    XSLock_Unlock
 * @abstract    Unlocks a lock object
 * @param       lock    The lock object
 */
XS_EXPORT void XSLock_Unlock( XSLockRef lock );

#endif /* __XS_CLASSES_XS_LOCK_H__ */

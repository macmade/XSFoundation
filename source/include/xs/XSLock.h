/*******************************************************************************
 * Copyright (c) 2011, Jean-David Gadina <macmade@eosgarden.com>
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/
 
/* $Id$ */

/*!
 * @header      XSLock.h
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    ...
 */

#ifndef _XS_LOCK_H_
#define _XS_LOCK_H_
#pragma once

#include "XSMacros.h"

XS_EXTERN_C_BEGIN

/*!
 * @typedef     XSLock
 * @abstract    Opaque type for the XSLock objects
 */
typedef struct XSLock * XSLock;

/*!
 * @function    XSLock_Alloc
 * @abstract    Object allocator
 * @result      The allocated object
 */
XSStatic XSLock XSLock_Alloc( void );

/*!
 * @function    XSLock_Init
 * @abstract    Creates a lock
 * @param       xsThis  The lock object
 * @result      The lock object
 */
XSLock XSLock_Init( XSLock xsThis );

/*!
 * @function    XSLock_Lock
 * @abstract    Locks the lock object
 * @param       xsThis  The lock object
 * @result      True if the lock was successfully locked, otherwise false
 */
BOOL XSLock_Lock( XSLock xsThis );

/*!
 * @function    XSLock_TryLock
 * @abstract    Tries to acquire a lock
 * @param       xsThis  The lock object
 * @result      True if the lock was successfully locked, otherwise false
 */
BOOL XSLock_TryLock( XSLock xsThis );

/*!
 * @function    XSLock_WaitForLock
 * @abstract    Pause the programs execution until the lock is acquired
 * @param       xsThis  The lock object
 * @result      void
 */
void XSLock_WaitForLock( XSLock xsThis );

/*!
 * @function    XSLock_Unlock
 * @abstract    Unlocks a lock
 * @param       xsThis  The lock object
 * @result      void
 */
void XSLock_Unlock( XSLock xsThis );

/*!
 * @function    XSLock_IsLocked
 * @abstract    Checks if a lock is locked
 * @param       xsThis  The lock object
 * @result      True if the lock is locked, otherwise false
 */
BOOL XSLock_IsLocked( XSLock xsThis );

XS_EXTERN_C_END

#endif /* _XS_LOCK_H_ */

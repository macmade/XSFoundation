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
 * @header      XSThreading.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSFoundation threading functions
 * @discussion  Whenever possible, prefer using the XSFoundation class types
 *              like XSThreaRef, XSLockRef, XSSemaphoreRef, etc over this set
 *              of functions.
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_FUNCTIONS_XS_THREADING_H__
#define __XS_FUNCTIONS_XS_THREADING_H__

XS_EXTERN_C_BEGIN

#include <XS/XSTypes.h>

/*!
 * @function    XSThreading_GetCurrentThreadID
 * @abstract    Gets the ID of the current thread
 * @return      The ID of the current thread
 */
XSUInteger XSThreading_GetCurrentThreadID( void );

/*!
 * @function    XSThreading_SetCurrentThreadName
 * @abstract    Sets the name of the current thread
 * @param       name    The name for the current thread
 */
void XSThreading_SetCurrentThreadName( const char * name );

/*!
 * @function    XSThreading_TLSKeyCreate
 * @abstract    Creates a TLS key
 * @param       key     A pointer to an uninitialized TLS key
 * @return      True if the key was successfully created, otherwise false
 */
bool XSThreading_TLSKeyCreate( XSTLSKey * key );

/*!
 * @function    XSThreading_TLSKeyDelete
 * @abstract    Deletes a TLS key
 * @param       key     A pointer to the TLS key to delete
 */
void XSThreading_TLSKeyDelete( XSTLSKey * key );

/*!
 * @function    XSThreading_TLSGetValue
 * @abstract    Gets a TLS value
 * @param       key     The TLS key
 * @return      The TLS value
 */
void * XSThreading_TLSGetValue( XSTLSKey * key );

/*!
 * @function    XSThreading_TLSSetValue
 * @abstract    Sets a TLS value
 * @param       key     The TLS key
 * @param       data    The TLS value
 */
void XSThreading_TLSSetValue( XSTLSKey * key, void * data );

/*!
 * @function    XSThreading_TLSGetObject
 * @abstract    Gets a TLS object
 * @param       key     The TLS key
 * @return      The TLS object
 */
XSObjectRef XSThreading_TLSGetObject( XSTLSKey * key );

/*!
 * @function    XSThreading_TLSSetObject
 * @abstract    Sets a TLS object
 * @param       key             The TLS key
 * @param       object          The TLS object
 * @param       association     The object association
 * @see         XSTLSObjectAssociation
 */
void XSThreading_TLSSetObject( XSTLSKey * key, XSObjectRef object, XSObjectAssociation association );

/*!
 * @function    XSThreading_MutexCreate
 * @abstract    Creates a mutex
 * @param       mutex   A pointer to an uninitialized mutex
 * @discussion  Mutexes are created recursive.
 * @return      True if the mutex was successfully created, otherwise false
 */
bool XSThreading_MutexCreate( XSMutex * mutex );

/*!
 * @function    XSThreading_MutexDelete
 * @abstract    Deletes a mutex
 * @param       mutex   A pointer to the mutex to delete
 */
void XSThreading_MutexDelete( XSMutex * mutex );

/*!
 * @function    XSThreading_MutexLock
 * @abstract    Locks a mutex
 * @param       mutex   The mutex to lock
 */
void XSThreading_MutexLock( XSMutex * mutex );

/*!
 * @function    XSThreading_MutexTryLock
 * @abstract    Tries to lock a mutex
 * @param       mutex   The mutex to lock, if possible
 * @discussion  If the mutex can't be locked, this function will return
 *              immediately, rather than waiting.
 * @result      True if the mutex was locked, otherwise false
 */
bool XSThreading_MutexTryLock( XSMutex * mutex );

/*!
 * @function    XSThreading_MutexUnlock
 * @abstract    Unlocks a mutex
 * @param       mutex   The mutex to unlock
 */
void XSThreading_MutexUnlock( XSMutex * mutex );

/*!
 * @function    XSThreading_SemaphoreCreate
 * @abstract    Creates a semaphore
 * @param       sem     A pointer to an uninitialized semaphore
 * @param       name    Optional: the name of the semaphore. Pass NULL to create an unnamed semaphore
 * @param       count   The maximum count for the semaphore
 * @return      True if the semaphore was successfully created, otherwise false
 */
bool XSThreading_SemaphoreCreate( XSSemaphore * sem, const char * name, XSUInteger count );

/*!
 * @function    XSThreading_SemaphoreDelete
 * @abstract    Deletes a semaphore
 * @param       sem     A pointer to the semaphore to delete
 */
void XSThreading_SemaphoreDelete( XSSemaphore * sem );

/*!
 * @function    XSThreading_SemaphoreWait
 * @abstract    Locks a semaphore
 * @param       sem     The semaphore to lock
 */
void XSThreading_SemaphoreWait( XSSemaphore * sem );

/*!
 * @function    XSThreading_SemaphoreTryWait
 * @abstract    Tries to lock a semaphore
 * @param       sem     The semaphore to lock, if possible
 * @discussion  If the semaphore can't be locked, this function will return
 *              immediately, rather than waiting.
 * @result      True if the semaphore was locked, otherwise false
 */
bool XSThreading_SemaphoreTryWait( XSSemaphore * sem );

/*!
 * @function    XSThreading_SemaphoreSignal
 * @abstract    Unlocks a semaphore
 * @param       sem     The semaphore to unlock
 */
void XSThreading_SemaphoreSignal( XSSemaphore * sem );

XS_EXTERN_C_END

#endif /* __XS_FUNCTIONS_XS_THREADING_H__ */

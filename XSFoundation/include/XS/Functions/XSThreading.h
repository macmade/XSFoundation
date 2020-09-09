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
 * @header      XSThreading.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSFoundation threading functions
 * @discussion  Whenever possible, prefer using the XSFoundation class types
 *              like XSThreadRef, XSLockRef, XSSemaphoreRef, etc. over this set
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

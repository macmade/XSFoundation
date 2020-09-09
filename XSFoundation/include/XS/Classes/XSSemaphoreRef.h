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
 * @header      XSSemaphoreRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSSemaphore class
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_SEMAPHORE_H__
#define __XS_CLASSES_XS_SEMAPHORE_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     XSSemaphoreRef
 * @abstract    Opaque type for XSSemaphore
 */
typedef struct __XSSemaphore * XSSemaphoreRef;

/*!
 * @function    XSSemaphore_GetClassID
 * @abstract    Gets the class ID for XSSemaphore
 * @return      The class ID for XSSemaphore
 */
XS_EXPORT XSStatic XSClassID XSSemaphore_GetClassID( void );

/*!
 * @function    XSSemaphore_Create
 * @abstract    Creates an unnamed semaphore
 * @param       count   The maximum count for the semaphore
 * @return      The semaphore object
 */
XS_EXPORT XSStatic XSSemaphoreRef XSSemaphore_Create( XSUInteger count );

/*!
 * @function    XSSemaphore_CreateWithName
 * @abstract    Creates a named semaphore
 * @param       name    The semaphore name
 * @param       count   The maximum count for the semaphore
 * @return      The semaphore object
 */
XS_EXPORT XSStatic XSSemaphoreRef XSSemaphore_CreateWithName( const char * name, XSUInteger count );

/*!
 * @function    XSSemaphore_Wait
 * @abstract    Locks a semaphore
 * @param       semaphore   The semaphore object
 */
XS_EXPORT void XSSemaphore_Wait( XSSemaphoreRef semaphore );

/*!
 * @function    XSSemaphore_TryWait
 * @abstract    Tries to lock a semaphore
 * @param       semaphore   The semaphore object
 * @discussion  If the semaphore can't be locked, this function will return
 *              immediately, rather than waiting.
 * @result      True if the semaphore was locked, otherwise false
 */
XS_EXPORT bool XSSemaphore_TryWait( XSSemaphoreRef semaphore );

/*!
 * @function    XSSemaphore_Signal
 * @abstract    Unlocks a semaphore
 * @param       semaphore   The semaphore object
 */
XS_EXPORT void XSSemaphore_Signal( XSSemaphoreRef semaphore );

/*!
 * @function    XSSemaphore_IsNamed
 * @abstract    Checks whether a semaphore is named or not
 * @param       semaphore   The semaphore object
 * @result      True if the semaphore is named, otherwise false
 */
XS_EXPORT bool XSSemaphore_IsNamed( XSSemaphoreRef semaphore );

/*!
 * @function    XSSemaphore_GetName
 * @abstract    Gets the name of a semaphore
 * @param       semaphore   The semaphore object
 * @return      The semaphore name, or NULL if the semaphore is unnamed
 */
XS_EXPORT const char * XSSemaphore_GetName( XSSemaphoreRef semaphore );

#endif /* __XS_CLASSES_XS_SEMAPHORE_H__ */

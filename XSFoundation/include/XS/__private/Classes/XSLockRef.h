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
 * @header      XSLockRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSLockRef.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_LOCK_H__
#define __XS___PRIVATE_CLASSES_XS_LOCK_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @struct      __XSLock
 * @abstract    Structure for XSLock
 */
struct __XSLock
{
    XSMutex     mutex;  /* The mutex */
    XSSemaphore sem;    /* The semaphore */
};

/*!
 * @var         __XSLock_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSLock_ClassID;

/*!
 * @var         __XSLock_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSLock_Class;

/*!
 * @function    __XSLock_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSLock_Initialize( void );

/*!
 * @function    __XSLock_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSLockRef __XSLock_Constructor( XSLockRef object );

/*!
 * @function    __XSLock_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSLock_Destructor( XSLockRef object );

/*!
 * @function    __XSLock_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSLockRef __XSLock_Copy( XSLockRef source, XSLockRef destination );

/*!
 * @function    __XSLock_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSLock_Equals( XSLockRef object1, XSLockRef object2 );

/*!
 * @function    __XSLock_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSLock_ToString( XSLockRef object );

/*!
 * @function    __XSLock_Create
 * @abstract    Creates an XSLock object
 * @return      The XSLock object
 */
XSStatic struct __XSLock * __XSLock_Create( void );

#endif /* __XS___PRIVATE_CLASSES_XS_LOCK_H__ */

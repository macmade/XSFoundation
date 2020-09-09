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
 * @header      XSNotificationRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSNotificationRef.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_NOTIFICATION_H__
#define __XS___PRIVATE_CLASSES_XS_NOTIFICATION_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @struct      __XSNotification
 * @abstract    Structure for XSNotification
 */
struct __XSNotification
{
    XSStringRef     name;       /*! Notification name */
    XSObjectRef     object;     /*! Notification object (sender) */
    XSDictionaryRef userInfo;   /*! Notification user info */
};

/*!
 * @var         __XSNotification_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSNotification_ClassID;

/*!
 * @var         __XSNotification_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSNotification_Class;

/*!
 * @function    __XSNotification_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSNotification_Initialize( void );

/*!
 * @function    __XSNotification_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSNotificationRef __XSNotification_Constructor( XSNotificationRef object );

/*!
 * @function    __XSNotification_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSNotification_Destructor( XSNotificationRef object );

/*!
 * @function    __XSNotification_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSNotificationRef __XSNotification_Copy( XSNotificationRef source, XSNotificationRef destination );

/*!
 * @function    __XSNotification_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSNotification_Equals( XSNotificationRef object1, XSNotificationRef object2 );

/*!
 * @function    __XSNotification_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSNotification_ToString( XSNotificationRef object );

/*!
 * @function    __XSNotification_Create
 * @abstract    Creates an XSNotification object
 * @return      The XSNotification object
 */
XSStatic struct __XSNotification * __XSNotification_Create( void );

#endif /* __XS___PRIVATE_CLASSES_XS_NOTIFICATION_H__ */

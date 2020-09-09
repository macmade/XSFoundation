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
 * @header      XSNotificationCenterRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSNotificationCenterRef.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_NOTIFICATION_CENTER_H__
#define __XS___PRIVATE_CLASSES_XS_NOTIFICATION_CENTER_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>


/*!
 * @typedef     __XSNotificationCenter_NotificationList
 * @abstract    Observer list item
 */
typedef struct __XSNotificationCenter_ObserverListStruct
{
    XSObjectRef                                        observer;    /*! The observer object */
    XSNotificationCenter_NotificationCallback          callback;    /*! The notification callback */
    XSObjectRef                                        sender;      /*! The observed object (sender) */
    struct __XSNotificationCenter_ObserverListStruct * next;        /*! The next observer list item */
}
__XSNotificationCenter_ObserverList;

/*!
 * @typedef     __XSNotificationCenter_NotificationList
 * @abstract    Notification list item
 */
typedef struct __XSNotificationCenter_NotificationListStruct
{
    XSStringRef                                             name;       /*! The notification name */
    __XSNotificationCenter_ObserverList                   * observers;  /*! The observers for the notification */
    struct __XSNotificationCenter_NotificationListStruct  * next;       /*! The next notification list item */
}
__XSNotificationCenter_NotificationList;

/*!
 * @struct      __XSNotificationCenter
 * @abstract    Structure for XSNotificationCenter
 */
struct __XSNotificationCenter
{
    __XSNotificationCenter_NotificationList * notifications;    /*! The notifications */
};

/*!
 * @var         __XSNotificationCenter_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSNotificationCenter_ClassID;

/*!
 * @var         __XSNotificationCenter_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSNotificationCenter_Class;

/*!
 * @function    __XSNotificationCenter_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSNotificationCenter_Initialize( void );

/*!
 * @function    __XSNotificationCenter_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSNotificationCenterRef __XSNotificationCenter_Constructor( XSNotificationCenterRef object );

/*!
 * @function    __XSNotificationCenter_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSNotificationCenter_Destructor( XSNotificationCenterRef object );

/*!
 * @function    __XSNotificationCenter_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSNotificationCenterRef __XSNotificationCenter_Copy( XSNotificationCenterRef source, XSNotificationCenterRef destination );

/*!
 * @function    __XSNotificationCenter_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSNotificationCenter_Equals( XSNotificationCenterRef object1, XSNotificationCenterRef object2 );

/*!
 * @function    __XSNotificationCenter_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSNotificationCenter_ToString( XSNotificationCenterRef object );

/*!
 * @function    __XSNotificationCenter_Create
 * @abstract    Creates an XSNotificationCenter object
 * @return      The XSNotificationCenter object
 */
XSStatic struct __XSNotificationCenter * __XSNotificationCenter_Create( void );

#endif /* __XS___PRIVATE_CLASSES_XS_NOTIFICATION_CENTER_H__ */

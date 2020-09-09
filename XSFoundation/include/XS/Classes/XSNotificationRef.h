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
 * @abstract    XSNotification class
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_NOTIFICATION_H__
#define __XS_CLASSES_XS_NOTIFICATION_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     XSNotificationRef
 * @abstract    Opaque type for XSNotification
 */
typedef const struct __XSNotification * XSNotificationRef;

/*!
 * @function    XSNotification_GetClassID
 * @abstract    Gets the class ID for XSNotification
 * @return      The class ID for XSNotification
 */
XS_EXPORT XSStatic XSClassID XSNotification_GetClassID( void );

/*!
 * @function    XSNotification_Notification
 * @abstract    Gets an XSNotification object
 * @param       name        The notification's name
 * @param       object      The notification's object (sender) - Optional, may be NULL
 * @param       userInfo    The notification's user info - Optional, may be NULL
 * @return      The XSNotification object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSNotificationRef XSNotification_Notification( XSStringRef name, XSObjectRef object, XSDictionaryRef userInfo );

/*!
 * @function    XSNotification_Create
 * @abstract    Creates an XSNotification object
 * @param       name        The notification's name
 * @param       object      The notification's object (sender) - Optional, may be NULL
 * @param       userInfo    The notification's user info - Optional, may be NULL
 * @return      The XSNotification object
 */
XS_EXPORT XSStatic XSNotificationRef XSNotification_Create( XSStringRef name, XSObjectRef object, XSDictionaryRef userInfo );

/*!
 * @function    XSNotification_GetName
 * @abstract    Gets the name of an XSNotification object
 * @param       object      The XSNotification object
 * @return      The notification's name
 */
XS_EXPORT XSStringRef XSNotification_GetName( XSNotificationRef object );

/*!
 * @function    XSNotification_GetObject
 * @abstract    Gets the object (sender) of an XSNotification object
 * @param       object      The XSNotification object
 * @return      The notification's object (sender)
 */
XS_EXPORT XSObjectRef XSNotification_GetObject( XSNotificationRef object );

/*!
 * @function    XSNotification_GetUserInfo
 * @abstract    Gets the user info of an XSNotification object
 * @param       object      The XSNotification object
 * @return      The notification's user info
 */
XS_EXPORT XSDictionaryRef XSNotification_GetUserInfo( XSNotificationRef object );

#endif /* __XS_CLASSES_XS_NOTIFICATION_H__ */

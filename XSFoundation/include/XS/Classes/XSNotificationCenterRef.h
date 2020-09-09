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
 * @abstract    XSNotificationCenter class
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_NOTIFICATION_CENTER_H__
#define __XS_CLASSES_XS_NOTIFICATION_CENTER_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     XSNotificationCenter_NotificationCallback
 * @abstract    Notification callback
 * @param       object          The receiver object
 * @param       notification    The notification
 */
typedef void ( * XSNotificationCenter_NotificationCallback )( XSObjectRef object, XSNotificationRef notification );

/*!
 * @typedef     XSNotificationCenterRef
 * @abstract    Opaque type for XSNotificationCenter
 */
typedef struct __XSNotificationCenter * XSNotificationCenterRef;

/*!
 * @function    XSNotificationCenter_GetClassID
 * @abstract    Gets the class ID for XSNotificationCenter
 * @return      The class ID for XSNotificationCenter
 */
XS_EXPORT XSStatic XSClassID XSNotificationCenter_GetClassID( void );

/*!
 * @function    XSNotificationCenter_DefaultCenter
 * @abstract    Gets the default notification center
 * @return      The default notification center
 */
XS_EXPORT XSStatic XSNotificationCenterRef XSNotificationCenter_DefaultCenter( void );

/*!
 * @function    XSNotificationCenter_Create
 * @abstract    Creates a notification center
 * @return      The notification center
 */
XS_EXPORT XSStatic XSNotificationCenterRef XSNotificationCenter_Create( void );

/*!
 * @function    XSNotificationCenter_AddObserver
 * @abstract    Adds an observer to a notification center
 * @param       center      The notification center (if NULL, the default notification center will be used)
 * @param       observer    The observer object
 * @param       callback    The notification callback
 * @param       name        The name of the notification to observe
 * @param       sender      The sender object (if NULL, the observer will receive the observed notification for all senders)
 */
XS_EXPORT void XSNotificationCenter_AddObserver( XSNotificationCenterRef center, XSObjectRef observer, XSNotificationCenter_NotificationCallback callback, XSStringRef name, XSObjectRef sender );

/*!
 * @function    XSNotificationCenter_RemoveObserver
 * @abstract    Removes an observer from a notification center
 * @param       center      The notification center (if NULL, the default notification center will be used)
 * @param       observer    The observer object
 * @param       name        The notification name (if NULL, the observer will be removed for all notifications)
 * @param       sender      The sender object (may be NULL)
 */
XS_EXPORT void XSNotificationCenter_RemoveObserver( XSNotificationCenterRef center, XSObjectRef observer, XSStringRef name, XSObjectRef sender );

/*!
 * @function    XSNotificationCenter_PostNotification
 * @abstract    Posts a notification to a notification center
 * @param       center          The notification center (if NULL, the default notification center will be used)
 * @param       notification    The notification to post
 */
XS_EXPORT void XSNotificationCenter_PostNotification( XSNotificationCenterRef center, XSNotificationRef notification );

/*!
 * @function    XSNotificationCenter_PostNotificationName
 * @abstract    Posts a notification to a notification center
 * @param       center      The notification center (if NULL, the default notification center will be used)
 * @param       name        The name of the notification to post
 * @param       sender      The sender object (may be NULL)
 * @param       userInfo    The notification's user info (may be NULL)
 */
XS_EXPORT void XSNotificationCenter_PostNotificationName( XSNotificationCenterRef center, XSStringRef name, XSObjectRef sender, XSDictionaryRef userInfo );

#endif /* __XS_CLASSES_XS_NOTIFICATION_CENTER_H__ */

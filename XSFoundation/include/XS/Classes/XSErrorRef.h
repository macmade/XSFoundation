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
 * @header      XSErrorRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSError class
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_ERROR_H__
#define __XS_CLASSES_XS_ERROR_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>
#include <XS/Classes/XSStringRef.h>
#include <XS/Classes/XSDictionaryRef.h>

/*!
 * @typedef     XSErrorRef
 * @abstract    Opaque type for XSError
 */
typedef const struct __XSError * XSErrorRef;

/*!
 * @function    XSError_GetClassID
 * @abstract    Gets the class ID for XSError
 * @return      The class ID for XSError
 */
XS_EXPORT XSStatic XSClassID XSError_GetClassID( void );

/*!
 * @function    XSError_Error
 * @abstract    Gets an error object
 * @param       domain      The error domain
 * @param       code        The error code
 * @param       reason      The error reason
 * @param       userInfo    The error user infos
 * @return      The error object
 */
XS_EXPORT XSStatic XSAutoreleased XSErrorRef XSError_Error( XSStringRef domain, XSInteger code, XSStringRef reason, XSDictionaryRef userInfo );

/*!
 * @function    XSError_Create
 * @abstract    Creates an error object
 * @param       domain      The error domain
 * @param       code        The error code
 * @param       reason      The error reason
 * @param       userInfo    The error user infos
 * @return      The error object
 */
XS_EXPORT XSStatic XSErrorRef XSError_Create( XSStringRef domain, XSInteger code, XSStringRef reason, XSDictionaryRef userInfo );

/*!
 * @function    XSError_GetDomain
 * @abstract    Gets the error domain
 * @param       error       The error object
 * @return      The error domain
 */
XS_EXPORT XSStringRef XSError_GetDomain( XSErrorRef error );

/*!
 * @function    XSError_GetCode
 * @abstract    Gets the error code
 * @param       error       The error object
 * @return      The error code
 */
XS_EXPORT XSInteger XSError_GetCode( XSErrorRef error );

/*!
 * @function    XSError_GetReason
 * @abstract    Gets the error reason
 * @param       error       The error object
 * @return      The error reason
 */
XS_EXPORT XSStringRef XSError_GetReason( XSErrorRef error );

/*!
 * @function    XSError_GetUserInfo
 * @abstract    Gets the error user infos
 * @param       error       The error object
 * @return      The error user infos
 */
XS_EXPORT XSDictionaryRef XSError_GetUserInfo( XSErrorRef error );

#endif /* __XS_CLASSES_XS_ERROR_H__ */

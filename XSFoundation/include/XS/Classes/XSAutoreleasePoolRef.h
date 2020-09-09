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
 * @header      XSAutoreleasePoolRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSAutoreleasePool class
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_AUTORELEASE_POOL_H__
#define __XS_CLASSES_XS_AUTORELEASE_POOL_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     XSAutoreleasePoolRef
 * @abstract    Opaque type for XSAutoreleasePool
 */
typedef struct __XSAutoreleasePool * XSAutoreleasePoolRef;

/*!
 * @function    XSAutoreleasePool_GetClassID
 * @abstract    Gets the class ID for XSAutoreleasePool
 * @return      The class ID for XSAutoreleasePool
 */
XS_EXPORT XSStatic XSClassID XSAutoreleasePool_GetClassID( void );

/*!
 * @function    XSAutoreleasePool_Create
 * @abstract    Creates an autorelease pool
 * @return      The autorelease pool object
 */
XS_EXPORT XSStatic XSAutoreleasePoolRef XSAutoreleasePool_Create( void );

/*!
 * @function    XSAutoreleasePool_AddObject
 * @abstract    Adds an object to an autorelease pool
 * @param       ap      The autorelease pool object
 * @param       object  The object to add to the autorelease pool
 */
XS_EXPORT void XSAutoreleasePool_AddObject( XSAutoreleasePoolRef ap, XSObjectRef object );

/*!
 * @function    XSAutoreleasePool_Drain
 * @abstract    Drains an autorelease pool
 * @param       ap      The autorelease pool object
 */
XS_EXPORT void XSAutoreleasePool_Drain( XSAutoreleasePoolRef ap );

#endif /* __XS_CLASSES_XS_AUTORELEASE_POOL_H__ */

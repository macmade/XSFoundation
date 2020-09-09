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
 * @header      XSStackRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSStack class
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_STACK_H__
#define __XS_CLASSES_XS_STACK_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     XSStackRef
 * @abstract    Opaque type for XSStack
 * @discussion  XSStackRef objects are thread-safe
 */
typedef struct __XSStack * XSStackRef;

/*!
 * @function    XSStack_GetClassID
 * @abstract    Gets the class ID for XSStack
 * @return      The class ID for XSStack
 */
XS_EXPORT XSStatic XSClassID XSStack_GetClassID( void );

/*!
 * @function    XSStack_Create
 * @abstract    Creates a stack object
 * @return      The stack object
 */
XS_EXPORT XSStatic XSStackRef XSStack_Create( void );

/*!
 * @function    XSStack_GetCount
 * @abstract    Gets the number of object in a XSStackRef object
 * @param       stack       The stack object
 * @return      The number of object in the XSStackRef object
 */
XS_EXPORT XSUInteger XSStack_GetCount( XSStackRef stack );

/*!
 * @function    XSStack_Push
 * @abstract    Pushes an object in a XSStackRef object
 * @param       stack       The stack object
 * @param       object      The object to push
 */
XS_EXPORT void XSStack_Push( XSStackRef stack, XSObjectRef object );

/*!
 * @function    XSStack_Pop
 * @abstract    Pops an object from a XSStackRef object
 * @param       stack       The stack object
 * @return      The popped object
 */
XS_EXPORT XSObjectRef XSStack_Pop( XSStackRef stack );

#endif /* __XS_CLASSES_XS_STACK_H__ */

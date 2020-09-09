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
 * @header      XSClassInfo.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSClassInfo type definition
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_TYPES_XS_CLASS_INFO_H__
#define __XS_TYPES_XS_CLASS_INFO_H__

XS_EXTERN_C_BEGIN

#include <XS/XSTypes/XSObjectRef.h>
#include <XS/XSTypes/XSClassType.h>
#include <XS/XSTypes/XSClassCallbackConstructor.h>
#include <XS/XSTypes/XSClassCallbackDestructor.h>
#include <XS/XSTypes/XSClassCallbackCopy.h>
#include <XS/XSTypes/XSClassCallbackEquals.h>
#include <XS/XSTypes/XSClassCallbackToString.h>

/*!
 * @typedef     XSClassInfo
 * @abstract    XSFoundation runtime class structure
 */
typedef struct
{
    const char                * className;      /*! The name of the class */
    XSUInteger                  type;           /*! The class type */
    XSUInteger                  instanceSize;   /*! The size of the class instances */
    XSClassCallbackConstructor  constructor;    /*! The class constructor */
    XSClassCallbackDestructor   destructor;     /*! The class destructor */
    XSClassCallbackCopy         copy;           /*! The object's copy callback */
    XSClassCallbackEquals       equals;         /*! The object's comparison callback */
    XSClassCallbackToString     toString;       /*! The object's description callback */
}
XSClassInfo;

XS_EXTERN_C_END

#endif /* __XS_TYPES_XS_CLASS_INFO_H__ */

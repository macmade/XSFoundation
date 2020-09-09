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
 * @header      XSPrimitiveArrayRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSPrimitiveArray class
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_PRIMITIVE_ARRAY_H__
#define __XS_CLASSES_XS_PRIMITIVE_ARRAY_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     XSPrimitiveArrayRef
 * @abstract    Opaque type for XSPrimitiveArray
 */
typedef const struct __XSPrimitiveArray * XSPrimitiveArrayRef;

/*!
 * @typedef     XSMutablePrimitiveArrayRef
 * @abstract    Opaque type for XSMutablePrimitiveArray
 */
typedef struct __XSPrimitiveArray * XSMutablePrimitiveArrayRef;

/*!
 * @function    XSPrimitiveArray_GetClassID
 * @abstract    Gets the class ID for XSPrimitiveArray
 * @return      The class ID for XSPrimitiveArray
 */
XS_EXPORT XSStatic XSClassID XSPrimitiveArray_GetClassID( void );

#endif /* __XS_CLASSES_XS_PRIMITIVE_ARRAY_H__ */

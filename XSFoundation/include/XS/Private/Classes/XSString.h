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
 * @header      XSString.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private declarations for the XSString class
 */

#ifndef XS_PRIVATE_CLASSES_XS_STRING_H
#define XS_PRIVATE_CLASSES_XS_STRING_H

#include <XS/Macros.h>
#include <XS/Types.h>

XS_EXTERN_C_BEGIN

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

/*!
 * @struct      XSString
 * @abstract    XSString instance
 */
struct XSString
{
    char * cstr;
    size_t length;
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
XS_EXTERN_C_END

/*!
 * @var         XSStringClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID XSStringClassID;

/*!
 * @var         XSStringClass
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo XSStringClass;

/*!
 * @function    XSAutoreleasePoolInitialize
 * @abstract    Class initializer
 */
void XSStringInitialize( void );

/*!
 * @function    XSStringDestructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void XSStringDestructor( XSMutableObjectRef object );

/*!
 * @function    XSStringCopy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSMutableObjectRef XSStringCopy( XSObjectRef source, XSMutableObjectRef destination );

#endif /* XS_PRIVATE_CLASSES_XS_STRING_H */
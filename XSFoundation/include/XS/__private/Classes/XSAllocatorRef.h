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
 * @header      XSAllocatorRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSAllocatorRef.h
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_ALLOCATOR_H__
#define __XS___PRIVATE_CLASSES_XS_ALLOCATOR_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @struct      __XSAllocator
 * @abstract    Structure for XSAllocator
 * @see         XSAllocator_Callbacks
 */
struct __XSAllocator
{
    XSStringRef             name;       /*! The allocator name */
    XSAllocator_Callbacks   callbacks;  /*! The allocator callbacks */
};

/*!
 * @var         __XSAllocator_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSAllocator_ClassID;

/*!
 * @var         __XSAllocator_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSAllocator_Class;

/*!
 * @function    __XSAllocator_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSAllocator_Initialize( void );

/*!
 * @function    __XSAllocator_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSAllocatorRef __XSAllocator_Constructor( XSAllocatorRef object );

/*!
 * @function    __XSAllocator_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSAllocator_Destructor( XSAllocatorRef object );

/*!
 * @function    __XSAllocator_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSAllocatorRef __XSAllocator_Copy( XSAllocatorRef source, XSAllocatorRef destination );

/*!
 * @function    __XSAllocator_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSAllocator_Equals( XSAllocatorRef object1, XSAllocatorRef object2 );

/*!
 * @function    __XSAllocator_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSAllocator_ToString( XSAllocatorRef object );

/*!
 * @function    __XSAllocator_Create
 * @abstract    Creates an XSAllocator object
 * @return      The XSAllocator object
 */
XSStatic struct __XSAllocator * __XSAllocator_Create( void );

/*!
 * @var         __XSAllocator_DefaultAllocator
 * @abstract    The default XSFoundation allocator
 */
XS_EXTERN XSAllocatorRef __XSAllocator_DefaultAllocator;

#endif /* __XS___PRIVATE_CLASSES_XS_ALLOCATOR_H__ */

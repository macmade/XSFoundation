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
 * @abstract    Private definitions for XSStackRef.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_STACK_H__
#define __XS___PRIVATE_CLASSES_XS_STACK_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     __XSStack_Value
 * @abstract    Stack value holder
 */
typedef struct __XSStack_ValueStruct
{
    XSObjectRef                    object;  /*! The contained object */
    struct __XSStack_ValueStruct * next;    /*! The next value */
}
__XSStack_Value;

/*!
 * @struct      __XSStack
 * @abstract    Structure for XSStack
 */
struct __XSStack
{
    __XSStack_Value  * top;   /*! The top element in the stack */
    XSUInteger         count; /*! The number of elements in the stack */
    XSRecursiveLockRef lock;  /*! The lock for thread-safety */
};

/*!
 * @var         __XSStack_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSStack_ClassID;

/*!
 * @var         __XSStack_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSStack_Class;

/*!
 * @function    __XSStack_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSStack_Initialize( void );

/*!
 * @function    __XSStack_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSStackRef __XSStack_Constructor( XSStackRef object );

/*!
 * @function    __XSStack_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSStack_Destructor( XSStackRef object );

/*!
 * @function    __XSStack_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSStackRef __XSStack_Copy( XSStackRef source, XSStackRef destination );

/*!
 * @function    __XSStack_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSStack_Equals( XSStackRef object1, XSStackRef object2 );

/*!
 * @function    __XSStack_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSStack_ToString( XSStackRef object );

/*!
 * @function    __XSStack_Create
 * @abstract    Creates an XSStack object
 * @return      The XSStack object
 */
XSStatic struct __XSStack * __XSStack_Create( void );

#endif /* __XS___PRIVATE_CLASSES_XS_STACK_H__ */

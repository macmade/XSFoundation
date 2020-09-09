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
 * @header      XSOrderedSetRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSOrderedSetRef.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_ORDERED_SET_H__
#define __XS___PRIVATE_CLASSES_XS_ORDERED_SET_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     __XSOrderedSet_Properties
 * @abstract    Ordered set properties
 */
typedef enum
{
    __XSOrderedSet_PropertiesMutable = 0x01  /*! Ordered set is mutable */
}
__XSOrderedSet_Properties;

/*!
 * @struct      __XSOrderedSet_Value
 * @abstract    XSOrderedSet value holder
 */
typedef struct __XSOrderedSet_ValueStruct
{
    XSObjectRef                         object;     /*! The contained object */
    struct __XSOrderedSet_ValueStruct * previous;   /*! The previous value */
    struct __XSOrderedSet_ValueStruct * next;       /*! The next value */
}
__XSOrderedSet_Value;

/*!
 * @struct      __XSOrderedSet
 * @abstract    Structure for XSOrderedSet
 */
struct __XSOrderedSet
{
    XSUInteger              count;          /*! The number of elements in the ordered set */
    XSRecursiveLockRef      lock;           /*! The lock for thread-safety */
    __XSOrderedSet_Value  * first;          /*! First object in the ordered set */
    __XSOrderedSet_Value  * last;           /*! Last object in the ordered set */
    int                     properties;     /*! The ordered set properties */
    char                    _pad_0[ 4 ];    /*! Padding */
};

/*!
 * @var         __XSOrderedSet_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSOrderedSet_ClassID;

/*!
 * @var         __XSOrderedSet_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSOrderedSet_Class;

/*!
 * @function    __XSOrderedSet_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSOrderedSet_Initialize( void );

/*!
 * @function    __XSOrderedSet_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSOrderedSetRef __XSOrderedSet_Constructor( XSOrderedSetRef object );

/*!
 * @function    __XSOrderedSet_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSOrderedSet_Destructor( XSOrderedSetRef object );

/*!
 * @function    __XSOrderedSet_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSOrderedSetRef __XSOrderedSet_Copy( XSOrderedSetRef source, XSOrderedSetRef destination );

/*!
 * @function    __XSOrderedSet_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSOrderedSet_Equals( XSOrderedSetRef object1, XSOrderedSetRef object2 );

/*!
 * @function    __XSOrderedSet_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSOrderedSet_ToString( XSOrderedSetRef object );

/*!
 * @function    __XSOrderedSet_Create
 * @abstract    Creates an XSOrderedSet object
 * @return      The XSOrderedSet object
 */
XSStatic struct __XSOrderedSet * __XSOrderedSet_Create( void );

/*!
 * @function    __XSOrderedSet_CreateWithFirstObjectAndArgs
 * @abstract    Creates an ordered set object with objects from a va_list
 * @param       firstObject The first object
 * @param       args        The other objects, as va_list
 * @return      The ordered set object
 */
XSStatic XSOrderedSetRef __XSOrderedSet_CreateWithFirstObjectAndArgs( XSObjectRef firstObject, va_list args );

#endif /* __XS___PRIVATE_CLASSES_XS_ORDERED_SET_H__ */

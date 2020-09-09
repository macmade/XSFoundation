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
 * @header      XSArrayRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSArrayRef.h
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_ARRAY_H__
#define __XS___PRIVATE_CLASSES_XS_ARRAY_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     __XSArray_Properties
 * @abstract    Array properties
 */
typedef enum
{
    __XSArray_PropertiesMutable = 0x01  /*! Array is mutable */
}
__XSArray_Properties;

/*!
 * @struct      __XSArray_Value
 * @abstract    XSArray value holder
 */
typedef struct __XSArray_ValueStruct
{
    XSObjectRef                    object;      /*! The contained object */
    struct __XSArray_ValueStruct * previous;    /*! The previous value */
    struct __XSArray_ValueStruct * next;        /*! The next value */
}
__XSArray_Value;

/*!
 * @struct      __XSArray
 * @abstract    Structure for XSArray
 */
struct __XSArray
{
    XSUInteger           count;         /*! The number of elements in the array */
    XSRecursiveLockRef   lock;          /*! The lock for thread-safety */
    __XSArray_Value    * first;         /*! First object in the array */
    __XSArray_Value    * last;          /*! Last object in the array */
    int                  properties;    /*! The array properties */
    char                 _pad_0[ 4 ];   /*! Padding */
};

/*!
 * @var         __XSArray_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSArray_ClassID;

/*!
 * @var         __XSArray_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSArray_Class;

/*!
 * @function    __XSArray_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSArray_Initialize( void );

/*!
 * @function    __XSArray_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSArrayRef __XSArray_Constructor( XSArrayRef object );

/*!
 * @function    __XSArray_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSArray_Destructor( XSArrayRef object );

/*!
 * @function    __XSArray_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSArrayRef __XSArray_Copy( XSArrayRef source, XSArrayRef destination );

/*!
 * @function    __XSArray_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSArray_Equals( XSArrayRef object1, XSArrayRef object2 );

/*!
 * @function    __XSArray_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSArray_ToString( XSArrayRef object );

/*!
 * @function    __XSArray_Create
 * @abstract    Creates an XSArray object
 * @return      The XSArray object
 */
XSStatic struct __XSArray * __XSArray_Create( void );

/*!
 * @function    __XSArray_CreateWithFirstObjectAndArgs
 * @abstract    Creates an array object with objects from a va_list
 * @param       firstObject The first object
 * @param       args        The other objects, as va_list
 * @return      The array object
 */
XSStatic XSArrayRef __XSArray_CreateWithFirstObjectAndArgs( XSObjectRef firstObject, va_list args );

/*!
 * @function    __XSArray_Lock
 * @abstract    Locks the internal array lock if necessary
 * @param       array       The array
 * @discussion  Locking will only occure if the array is mutable, as immutable
 *              arrays are de-facto thread-safe. This allows the same code
 *              for both array types, with a performance gain on immutable ones.
 */
void __XSArray_Lock( XSArrayRef array );

/*!
 * @function    __XSArray_Unlock
 * @abstract    Unlocks the internal array lock if necessary
 * @param       array       The array
 * @discussion  Unlocking will only occure if the array is mutable, as immutable
 *              arrays are de-facto thread-safe. This allows the same code
 *              for both array types, with a performance gain on immutable ones.
 */
void __XSArray_Unlock( XSArrayRef array );

/*!
 * @function    __XSArray_SortValuesWithFunction
 * @abstract    Sorts array values using a function
 * @param       values      The array values
 * @param       count       The number of values
 * @param       function    The function used to sort the array
 * @param       stop        If true, stops the iteration
 * @see         XSArray_SortFunction
 */
void __XSArray_SortValuesWithFunction( XSObjectRef * values, XSUInteger count, XSArray_SortFunction function, bool * stop );

/*!
 * @function    __XSArray_SortValuesWithMethod
 * @abstract    Sorts array values using a method
 * @param       values      The array values
 * @param       count       The number of values
 * @param       object      The object on which to call the method
 * @param       method      The method used to sort the array
 * @param       stop        If true, stops the iteration
 * @see         XSArray_SortMethod
 */
void __XSArray_SortValuesWithMethod( XSObjectRef * values, XSUInteger count, XSObjectRef object, XSArray_SortMethod method, bool * stop );

#endif /* __XS___PRIVATE_CLASSES_XS_ARRAY_H__ */

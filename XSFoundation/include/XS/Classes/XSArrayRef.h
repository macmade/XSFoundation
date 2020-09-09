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
 * @abstract    XSArray class
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_ARRAY_H__
#define __XS_CLASSES_XS_ARRAY_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     XSArrayRef
 * @abstract    Opaque type for XSArray
 * @discussion  XSArrayRef objects are thread-safe
 */
typedef const struct __XSArray * XSArrayRef;

/*!
 * @typedef     XSMutableArrayRef
 * @abstract    Opaque type for XSMutableArray
 * @discussion  XSMutableArrayRef objects are thread-safe
 */
typedef struct __XSArray * XSMutableArrayRef;

/*!
 * @typedef     XSArray_ApplierFunction
 * @abstract    A function used to iterate objects in an array
 * @param       value       The array's value
 * @param       index       The index of the array's value
 * @param       stop        If true, stops the iteration
 */
typedef void ( * XSArray_ApplierFunction )( XSObjectRef value, XSUInteger index, bool * stop );

/*!
 * @typedef     XSArray_ApplierMethod
 * @abstract    A method used to iterate objects in an array
 * @param       object      The receiver object
 * @param       value       The array's value
 * @param       index       The index of the array's value
 * @param       stop        If true, stops the iteration
 */
typedef void ( * XSArray_ApplierMethod )( XSObjectRef object, XSObjectRef value, XSUInteger index, bool * stop );

/*!
 * @typedef     XSArray_FilterFunction
 * @abstract    A function used to filter objects in an array
 * @param       value       The array's value
 * @param       index       The index of the array's value
 * @param       stop        If true, stops the iteration
 * @return      True if the object must be kept in the array, otherwise false
 */
typedef bool ( * XSArray_FilterFunction )( XSObjectRef value, XSUInteger index, bool * stop );

/*!
 * @typedef     XSArray_FilterMethod
 * @abstract    A method used to filter objects in an array
 * @param       object      The receiver object
 * @param       value       The array's value
 * @param       index       The index of the array's value
 * @param       stop        If true, stops the iteration
 * @return      True if the object must be kept in the array, otherwise false
 */
typedef bool ( * XSArray_FilterMethod )( XSObjectRef object, XSObjectRef value, XSUInteger index, bool * stop );

/*!
 * @typedef     XSArray_SortFunction
 * @abstract    A function used to sort objects in an array
 * @param       value1      An array's value
 * @param       value2      An array's value
 * @param       stop        If true, stops the iteration
 * @return      The comparison result between the two values
 */
typedef XSComparisonResult ( * XSArray_SortFunction )( XSObjectRef value1, XSObjectRef value2, bool * stop );

/*!
 * @typedef     XSArray_SortMethod
 * @abstract    A method used to sort objects in an array
 * @param       object      The receiver object
 * @param       value1      An array's value
 * @param       value2      An array's value
 * @param       stop        If true, stops the iteration
 * @return      The comparison result between the two values
 */
typedef XSComparisonResult ( * XSArray_SortMethod )( XSObjectRef object, XSObjectRef value1, XSObjectRef value2, bool * stop );

/*!
 * @function    XSArray_GetClassID
 * @abstract    Gets the class ID for XSArray
 * @return      The class ID for XSArray
 */
XS_EXPORT XSStatic XSClassID XSArray_GetClassID( void );

/*!
 * @function    XSArray_Array
 * @abstract    Gets an empty array
 * @return      An empty immutable array
 */
XS_EXPORT XSStatic XSAutoreleased XSArrayRef XSArray_Array( void );

/*!
 * @function    XSArray_MutableArray
 * @abstract    Gets an empty mutable array
 * @return      An empty mutable array
 */
XS_EXPORT XSStatic XSAutoreleased XSMutableArrayRef XSArray_MutableArray( void );

/*!
 * @function    XSArray_ArrayWithArray
 * @abstract    Gets an array from another array
 * @param       array       The array
 * @return      An immutable array based on the given array
 */
XS_EXPORT XSStatic XSAutoreleased XSArrayRef XSArray_ArrayWithArray( XSArrayRef array );

/*!
 * @function    XSArray_ArrayWithObjects
 * @abstract    Gets an array filled with objects
 * @param       firstObject The first object to add
 * @param       ...         Additional objects to add, terminated by NULL
 * @return      An immutable array containing the specified objects
 */
XS_EXPORT XSStatic XSAutoreleased XSArrayRef XSArray_ArrayWithObjects( XSObjectRef firstObject, ... );

/*!
 * @function    XSArray_Create
 * @abstract    Creates an empty array
 * @return      An empty immutable array
 */
XS_EXPORT XSStatic XSArrayRef XSArray_Create( void );

/*!
 * @function    XSArray_CreateMutable
 * @abstract    Creates an empty mutable array
 * @return      An empty mutable array
 */
XS_EXPORT XSStatic XSMutableArrayRef XSArray_CreateMutable( void );

/*!
 * @function    XSArray_CreateWithArray
 * @abstract    Creates an array from another array
 * @param       array       The array
 * @return      An immutable array based on the given array
 */
XS_EXPORT XSStatic XSArrayRef XSArray_CreateWithArray( XSArrayRef array );

/*!
 * @function    XSArray_CreateWithObjects
 * @abstract    Creates an array filled with objects
 * @param       firstObject The first object to add
 * @param       ...         Additional objects to add, terminated by NULL
 * @return      An immutable array containing the specified objects
 */
XS_EXPORT XSStatic XSArrayRef XSArray_CreateWithObjects( XSObjectRef firstObject, ... );

/*!
 * @function    XSArray_CreateMutableCopy
 * @abstract    Creates a mutable copy of an array
 * @param       array       The array
 * @return      The mutable copy of the array
 */
XS_EXPORT XSMutableArrayRef XSArray_CreateMutableCopy( XSArrayRef array );

/*!
 * @function    XSArray_IsMutable
 * @abstract    Checks if an array is mutable
 * @param       array       The array
 * @return      True if the array is mutable, otherwise false
 */
XS_EXPORT bool XSArray_IsMutable( XSArrayRef array );

/*!
 * @function    XSArray_GetCount
 * @abstract    Gets the number of values in an array
 * @param       array       The array
 * @return      The number of values in an array
 */
XS_EXPORT XSUInteger XSArray_GetCount( XSArrayRef array );

/*!
 * @function    XSArray_GetCountOfObject
 * @abstract    Gets the number of time a specific object is present in an array
 * @param       array       The array
 * @param       object      The object
 * @return      The number of time the object is present in the array
 */
XS_EXPORT XSUInteger XSArray_GetCountOfObject( XSArrayRef array, XSObjectRef object );

/*!
 * @function    XSArray_ContainsObject
 * @abstract    Checks if a specific object is present in an array
 * @param       array       The array
 * @return      True if the array contains the object, otherwise false
 */
XS_EXPORT bool XSArray_ContainsObject( XSArrayRef array, XSObjectRef object );

/*!
 * @function    XSArray_GetObjectAtIndex
 * @abstract    Gets an object from an array at a specific index
 * @param       array       The array
 * @param       index       The index
 * @return      The object, or NULL if the index does not exist
 */
XS_EXPORT XSObjectRef XSArray_GetObjectAtIndex( XSArrayRef array, XSUInteger index );

/*!
 * @function    XSArray_GetLastObject
 * @abstract    Gets the last object in the array
 * @param       array       The array
 * @return      The last object, or NULL if the array is empty
 */
XS_EXPORT XSObjectRef XSArray_GetLastObject( XSArrayRef array );

/*!
 * @function    XSArray_GetFirstIndexOfObject
 * @abstract    Gets the first index of an object in an array
 * @param       array       The array
 * @param       object      The object
 * @return      The first index of the object, or XSNotFound
 */
XS_EXPORT XSUInteger XSArray_GetFirstIndexOfObject( XSArrayRef array, XSObjectRef object );

/*!
 * @function    XSArray_GetLastIndexOfObject
 * @abstract    Gets the last index of an object in an array
 * @param       array       The array
 * @param       object      The object
 * @return      The last index of the object, or XSNotFound
 */
XS_EXPORT XSUInteger XSArray_GetLastIndexOfObject( XSArrayRef array, XSObjectRef object );

/*!
 * @function    XSArray_AddObject
 * @abstract    Adds an object in an array
 * @param       array       The array
 * @param       object      The object (cannot be NULL)
 * @discussion  An error will be produced if the array is not mutable
 */
XS_EXPORT void XSArray_AddObject( XSMutableArrayRef array, XSObjectRef object );

/*!
 * @function    XSArray_InsertObjectAtIndex
 * @abstract    Inserts an object at a specific index in an array
 * @param       array       The array
 * @param       index       The index
 * @param       object      The object (cannot be NULL)
 * @discussion  An error will be produced if the array is not mutable
 */
XS_EXPORT void XSArray_InsertObjectAtIndex( XSMutableArrayRef array, XSUInteger index, XSObjectRef object );

/*!
 * @function    XSArray_ReplaceObjectAtIndex
 * @abstract    Replaces an object at a specific index in the array
 * @param       array       The array
 * @param       index       The index
 * @param       newObject   The new object (cannot be NULL)
 * @discussion  An error will be produced if the array is not mutable
 */
XS_EXPORT void XSArray_ReplaceObjectAtIndex( XSMutableArrayRef array, XSUInteger index, XSObjectRef newObject );

/*!
 * @function    XSArray_AppendArray
 * @abstract    Appends values from an array to an array
 * @param       array       The array
 * @param       objects     The array with the objects to append
 * @discussion  An error will be produced if the array is not mutable
 */
XS_EXPORT void XSArray_AppendArray( XSMutableArrayRef array, XSArrayRef objects );

/*!
 * @function    XSArray_RemoveAllObjects
 * @abstract    Removes all objects from an array
 * @param       array       The array
 * @discussion  An error will be produced if the array is not mutable
 */
XS_EXPORT void XSArray_RemoveAllObjects( XSMutableArrayRef array );

/*!
 * @function    XSArray_RemoveLastObject
 * @abstract    Removes the last object in an array
 * @param       array       The array
 * @discussion  An error will be produced if the array is not mutable
 */
XS_EXPORT void XSArray_RemoveLastObject( XSMutableArrayRef array );

/*!
 * @function    XSArray_RemoveObject
 * @abstract    Removes all occurences of a specific object in an array
 * @param       array       The array
 * @param       object      The object to remove
 * @discussion  An error will be produced if the array is not mutable
 */
XS_EXPORT void XSArray_RemoveObject( XSMutableArrayRef array, XSObjectRef object );

/*!
 * @function    XSArray_RemoveObjectAtIndex
 * @abstract    Removes the object at a specific index in an array
 * @param       array       The array
 * @param       index       The index
 * @discussion  An error will be produced if the array is not mutable
 */
XS_EXPORT void XSArray_RemoveObjectAtIndex( XSMutableArrayRef array, XSUInteger index );

/*!
 * @function    XSArray_RemoveObjectsInArray
 * @abstract    Removes all occurences of the objects contained in an array from an array
 * @param       array       The array
 * @param       objects     The array with the objects to remove
 * @discussion  An error will be produced if the array is not mutable
 */
XS_EXPORT void XSArray_RemoveObjectsInArray( XSMutableArrayRef array, XSArrayRef objects );

/*!
 * @function    XSArray_RemoveObjectsInRange
 * @abstract    Removes objects at a specific range from an array
 * @param       array       The array
 * @param       range       The range
 * @discussion  An error will be produced if the array is not mutable
 */
XS_EXPORT void XSArray_RemoveObjectsInRange( XSMutableArrayRef array, XSRange range );

/*!
 * @function    XSArray_ApplyFunction
 * @abstract    Applies a function for each element of an array
 * @param       array       The array
 * @param       function    The function to apply
 * @discussion  The function will be called with each object contained in the array
 * @see         XSArray_ApplierFunction
 */
XS_EXPORT void XSArray_ApplyFunction( XSArrayRef array, XSArray_ApplierFunction function );

/*!
 * @function    XSArray_ApplyMethod
 * @abstract    Applies a method for each element of an array
 * @param       array       The array
 * @param       object      The object on which to call the method
 * @param       method      The function to apply
 * @discussion  The method will be called with each object contained in the array
 * @see         XSArray_ApplierMethod
 */
XS_EXPORT void XSArray_ApplyMethod( XSArrayRef array, XSObjectRef object, XSArray_ApplierMethod method );

/*!
 * @function    XSArray_FilterWithFunction
 * @abstract    Filters an array using a function
 * @param       array       The array
 * @param       function    The function used to filter the array
 * @discussion  The function will be called with each object contained in the array.
 *              An error will be produced if the array is not mutable.
 * @see         XSArray_FilterFunction
 */
XS_EXPORT void XSArray_FilterWithFunction( XSMutableArrayRef array, XSArray_FilterFunction function );

/*!
 * @function    XSArray_FilterWithMethod
 * @abstract    Filters an array using a method
 * @param       array       The array
 * @param       object      The object on which to call the method
 * @param       method      The function used to filter the array
 * @discussion  The method will be called with each object contained in the array.
 *              An error will be produced if the array is not mutable.
 * @see         XSArray_FilterMethod
 */
XS_EXPORT void XSArray_FilterWithMethod( XSMutableArrayRef array, XSObjectRef object, XSArray_FilterMethod method );

/*!
 * @function    XSArray_SortWithFunction
 * @abstract    Sorts an array using a function
 * @param       array       The array
 * @param       function    The function used to sort the array
 * @discussion  The function will be called with each object contained in the array.
 *              An error will be produced if the array is not mutable.
 * @see         XSArray_SortFunction
 */
XS_EXPORT void XSArray_SortWithFunction( XSMutableArrayRef array, XSArray_SortFunction function );

/*!
 * @function    XSArray_SortWithMethod
 * @abstract    Sorts an array using a method
 * @param       array       The array
 * @param       object      The object on which to call the method
 * @param       method      The method used to sort the array
 * @discussion  The method will be called with each object contained in the array.
 *              An error will be produced if the array is not mutable.
 * @see         XSArray_SortMethod
 */
XS_EXPORT void XSArray_SortWithMethod( XSMutableArrayRef array, XSObjectRef object, XSArray_SortMethod method );

#endif /* __XS_CLASSES_XS_ARRAY_H__ */

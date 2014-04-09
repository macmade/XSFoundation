/*******************************************************************************
 * XSFoundation - XEOS C Foundation Library
 * 
 * Copyright (c) 2010-2014, Jean-David Gadina - www.xs-labs.com
 * All rights reserved.
 * 
 * XEOS Software License - Version 1.0 - December 21, 2012
 * 
 * Permission is hereby granted, free of charge, to any person or organisation
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to deal in the Software, with or without
 * modification, without restriction, including without limitation the rights
 * to use, execute, display, copy, reproduce, transmit, publish, distribute,
 * modify, merge, prepare derivative works of the Software, and to permit
 * third-parties to whom the Software is furnished to do so, all subject to the
 * following conditions:
 * 
 *      1.  Redistributions of source code, in whole or in part, must retain the
 *          above copyright notice and this entire statement, including the
 *          above license grant, this restriction and the following disclaimer.
 * 
 *      2.  Redistributions in binary form must reproduce the above copyright
 *          notice and this entire statement, including the above license grant,
 *          this restriction and the following disclaimer in the documentation
 *          and/or other materials provided with the distribution, unless the
 *          Software is distributed by the copyright owner as a library.
 *          A "library" means a collection of software functions and/or data
 *          prepared so as to be conveniently linked with application programs
 *          (which use some of those functions and data) to form executables.
 * 
 *      3.  The Software, or any substancial portion of the Software shall not
 *          be combined, included, derived, or linked (statically or
 *          dynamically) with software or libraries licensed under the terms
 *          of any GNU software license, including, but not limited to, the GNU
 *          General Public License (GNU/GPL) or the GNU Lesser General Public
 *          License (GNU/LGPL).
 * 
 *      4.  All advertising materials mentioning features or use of this
 *          software must display an acknowledgement stating that the product
 *          includes software developed by the copyright owner.
 * 
 *      5.  Neither the name of the copyright owner nor the names of its
 *          contributors may be used to endorse or promote products derived from
 *          this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT OWNER AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE, TITLE AND NON-INFRINGEMENT ARE DISCLAIMED.
 * 
 * IN NO EVENT SHALL THE COPYRIGHT OWNER, CONTRIBUTORS OR ANYONE DISTRIBUTING
 * THE SOFTWARE BE LIABLE FOR ANY CLAIM, DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN ACTION OF CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/* $Id$ */

/*!
 * @header      XSArray.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSArray class
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
typedef struct __XSArray * XSArrayRef;

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
 * @return      An empty array
 */
XS_EXPORT XSStatic XSAutoreleased XSArrayRef XSArray_Array( void );

/*!
 * @function    XSArray_ArrayWithObjects
 * @abstract    Gets an array filled with objects
 * @param       firstObject The first object to add
 * @param       ...         Additional objects to add, terminated by NULL
 * @return      An array containing the specified objects
 */
XS_EXPORT XSStatic XSAutoreleased XSArrayRef XSArray_ArrayWithObjects( XSObjectRef firstObject, ... );

/*!
 * @function    XSArray_Create
 * @abstract    Creates an empty array
 * @return      An empty array
 */
XS_EXPORT XSStatic XSArrayRef XSArray_Create( void );

/*!
 * @function    XSArray_CreateWithObjects
 * @abstract    Creates an array filled with objects
 * @param       firstObject The first object to add
 * @param       ...         Additional objects to add, terminated by NULL
 * @return      An array containing the specified objects
 */
XS_EXPORT XSStatic XSArrayRef XSArray_CreateWithObjects( XSObjectRef firstObject, ... );

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
 */
XS_EXPORT void XSArray_AddObject( XSArrayRef array, XSObjectRef object );

/*!
 * @function    XSArray_InsertObjectAtIndex
 * @abstract    Inserts an object at a specific index in an array
 * @param       array       The array
 * @param       index       The index
 * @param       object      The object (cannot be NULL)
 */
XS_EXPORT void XSArray_InsertObjectAtIndex( XSArrayRef array, XSUInteger index, XSObjectRef object );

/*!
 * @function    XSArray_ReplaceObjectAtIndex
 * @abstract    Replaces an object at a specific index in the array
 * @param       array       The array
 * @param       index       The index
 * @param       newObject   The new object (cannot be NULL)
 */
XS_EXPORT void XSArray_ReplaceObjectAtIndex( XSArrayRef array, XSUInteger index, XSObjectRef newObject );

/*!
 * @function    XSArray_AppendArray
 * @abstract    Appends values from an array to an array
 * @param       array       The array
 * @param       objects     The array with the objects to append
 */
XS_EXPORT void XSArray_AppendArray( XSArrayRef array, XSArrayRef objects );

/*!
 * @function    XSArray_RemoveAllObjects
 * @abstract    Removes all objects from an array
 * @param       array       The array
 */
XS_EXPORT void XSArray_RemoveAllObjects( XSArrayRef array );

/*!
 * @function    XSArray_RemoveLastObject
 * @abstract    Removes the last object in an array
 * @param       array       The array
 */
XS_EXPORT void XSArray_RemoveLastObject( XSArrayRef array );

/*!
 * @function    XSArray_RemoveObject
 * @abstract    Removes all occurences of a specific object in an array
 * @param       array       The array
 * @param       object      The object to remove
 */
XS_EXPORT void XSArray_RemoveObject( XSArrayRef array, XSObjectRef object );

/*!
 * @function    XSArray_RemoveObjectAtIndex
 * @abstract    Removes the object at a specific index in an array
 * @param       array       The array
 * @param       index       The index
 */
XS_EXPORT void XSArray_RemoveObjectAtIndex( XSArrayRef array, XSUInteger index );

/*!
 * @function    XSArray_RemoveObjectsInArray
 * @abstract    Removes all occurences of the objects contained in an array from an array
 * @param       array       The array
 * @param       objects     The array with the objects to remove
 */
XS_EXPORT void XSArray_RemoveObjectsInArray( XSArrayRef array, XSArrayRef objects );

/*!
 * @function    XSArray_RemoveObjectsInRange
 * @abstract    Removes objects at a specific range from an array
 * @param       array       The array
 * @param       range       The range
 */
XS_EXPORT void XSArray_RemoveObjectsInRange( XSArrayRef array, XSRange range );

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
 * @discussion  The function will be called with each object contained in the array
 * @see         XSArray_FilterFunction
 */
XS_EXPORT void XSArray_FilterWithFunction( XSArrayRef array, XSArray_FilterFunction function );

/*!
 * @function    XSArray_FilterWithMethod
 * @abstract    Filters an array using a method
 * @param       array       The array
 * @param       object      The object on which to call the method
 * @param       method      The function used to filter the array
 * @discussion  The method will be called with each object contained in the array
 * @see         XSArray_FilterMethod
 */
XS_EXPORT void XSArray_FilterWithMethod( XSArrayRef array, XSObjectRef object, XSArray_FilterMethod method );

/*!
 * @function    XSArray_SortWithFunction
 * @abstract    Sorts an array using a function
 * @param       array       The array
 * @param       function    The function used to sort the array
 * @discussion  The function will be called with each object contained in the array
 * @see         XSArray_SortFunction
 */
XS_EXPORT void XSArray_SortWithFunction( XSArrayRef array, XSArray_SortFunction function );

/*!
 * @function    XSArray_SortWithMethod
 * @abstract    Sorts an array using a method
 * @param       array       The array
 * @param       object      The object on which to call the method
 * @param       method      The method used to sort the array
 * @discussion  The method will be called with each object contained in the array
 * @see         XSArray_SortFunction
 */
XS_EXPORT void XSArray_SortWithMethod( XSArrayRef array, XSObjectRef object, XSArray_SortMethod method );

#endif /* __XS_CLASSES_XS_ARRAY_H__ */

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
 * @header      XSOrderedSetRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSOrderedSet class
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_ORDERED_SET_H__
#define __XS_CLASSES_XS_ORDERED_SET_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     XSOrderedSetRef
 * @abstract    Opaque type for XSOrderedSet
 */
typedef struct __XSOrderedSet * XSOrderedSetRef;

/*!
 * @typedef     XSOrderedSet_ApplierFunction
 * @abstract    A function used to iterate objects in an ordered set
 * @param       value       The ordered set's value
 * @param       index       The index of the ordered set's value
 * @param       stop        If true, stops the iteration
 */
typedef void ( * XSOrderedSet_ApplierFunction )( XSObjectRef value, XSUInteger index, bool * stop );

/*!
 * @typedef     XSOrderedSet_ApplierMethod
 * @abstract    A method used to iterate objects in an ordered set
 * @param       object      The receiver object
 * @param       value       The ordered set's value
 * @param       index       The index of the ordered set's value
 * @param       stop        If true, stops the iteration
 */
typedef void ( * XSOrderedSet_ApplierMethod )( XSObjectRef object, XSObjectRef value, XSUInteger index, bool * stop );

/*!
 * @typedef     XSOrderedSet_FilterFunction
 * @abstract    A function used to filter objects in an ordered set
 * @param       value       The ordered set's value
 * @param       index       The index of the ordered set's value
 * @param       stop        If true, stops the iteration
 * @return      True if the object must be kept in the ordered set, otherwise false
 */
typedef bool ( * XSOrderedSet_FilterFunction )( XSObjectRef value, XSUInteger index, bool * stop );

/*!
 * @typedef     XSOrderedSet_FilterMethod
 * @abstract    A method used to filter objects in an ordered set
 * @param       object      The receiver object
 * @param       value       The ordered set's value
 * @param       index       The index of the ordered set's value
 * @param       stop        If true, stops the iteration
 * @return      True if the object must be kept in the ordered set, otherwise false
 */
typedef bool ( * XSOrderedSet_FilterMethod )( XSObjectRef object, XSObjectRef value, XSUInteger index, bool * stop );

/*!
 * @typedef     XSOrderedSet_SortFunction
 * @abstract    A function used to sort objects in an ordered set
 * @param       value1      An ordered set's value
 * @param       value2      An ordered set's value
 * @param       stop        If true, stops the iteration
 * @return      The comparison result between the two values
 */
typedef XSComparisonResult ( * XSOrderedSet_SortFunction )( XSObjectRef value1, XSObjectRef value2, bool * stop );

/*!
 * @typedef     XSOrderedSet_SortMethod
 * @abstract    A method used to sort objects in an ordered set
 * @param       object      The receiver object
 * @param       value1      An ordered set's value
 * @param       value2      An ordered set's value
 * @param       stop        If true, stops the iteration
 * @return      The comparison result between the two values
 */
typedef XSComparisonResult ( * XSOrderedSet_SortMethod )( XSObjectRef object, XSObjectRef value1, XSObjectRef value2, bool * stop );

/*!
 * @function    XSOrderedSet_GetClassID
 * @abstract    Gets the class ID for XSOrderedSet
 * @return      The class ID for XSOrderedSet
 */
XS_EXPORT XSStatic XSClassID XSOrderedSet_GetClassID( void );

/*!
 * @function    XSOrderedSet_Array
 * @abstract    Gets an empty ordered set
 * @return      An empty ordered set
 */
XS_EXPORT XSStatic XSAutoreleased XSOrderedSetRef XSOrderedSet_OrderedSet( void );

/*!
 * @function    XSOrderedSet_MutableOrderedSet
 * @abstract    Gets an empty mutable ordered set
 * @return      An empty mutable ordered set
 */
XS_EXPORT XSStatic XSAutoreleased XSOrderedSetRef XSOrderedSet_MutableOrderedSet( void );

/*!
 * @function    XSOrderedSet_OrderedSetWithOrderedSet
 * @abstract    Gets an ordered set from another ordered set
 * @param       set         The ordered set
 * @return      An immutable ordered set based on the given ordered set
 */
XS_EXPORT XSStatic XSAutoreleased XSOrderedSetRef XSOrderedSet_OrderedSetWithOrderedSet( XSOrderedSetRef set );

/*!
 * @function    XSOrderedSet_ArrayWithObjects
 * @abstract    Gets an ordered set filled with objects
 * @param       firstObject The first object to add
 * @param       ...         Additional objects to add, terminated by NULL
 * @return      An ordered set containing the specified objects
 */
XS_EXPORT XSStatic XSAutoreleased XSOrderedSetRef XSOrderedSet_OrderedSetWithObjects( XSObjectRef firstObject, ... );

/*!
 * @function    XSOrderedSet_OrderedSetWithArray
 * @abstract    Gets an ordered set filled with objects contained in an array
 * @param       array       The array with the objects to add
 * @return      An ordered set containing the objects contained in the array
 */
XS_EXPORT XSStatic XSAutoreleased XSOrderedSetRef XSOrderedSet_OrderedSetWithArray( XSArrayRef array );

/*!
 * @function    XSOrderedSet_Create
 * @abstract    Creates an empty ordered set
 * @return      An empty ordered set
 */
XS_EXPORT XSStatic XSOrderedSetRef XSOrderedSet_Create( void );

/*!
 * @function    XSOrderedSet_CreateMutable
 * @abstract    Creates an empty mutable ordered set
 * @return      An empty mutable ordered set
 */
XS_EXPORT XSStatic XSOrderedSetRef XSOrderedSet_CreateMutable( void );

/*!
 * @function    XSOrderedSet_CreateWithOrderedSet
 * @abstract    Creates an ordered set from another ordered set
 * @param       set         The ordered set
 * @return      An immutable ordered set based on the given ordered set
 */
XS_EXPORT XSStatic XSAutoreleased XSOrderedSetRef XSOrderedSet_CreateWithOrderedSet( XSOrderedSetRef set );

/*!
 * @function    XSOrderedSet_CreateWithObjects
 * @abstract    Creates an ordered set filled with objects
 * @param       firstObject The first object to add
 * @param       ...         Additional objects to add, terminated by NULL
 * @return      An ordered set containing the specified objects
 */
XS_EXPORT XSStatic XSOrderedSetRef XSOrderedSet_CreateWithObjects( XSObjectRef firstObject, ... );

/*!
 * @function    XSOrderedSet_CreateWithArray
 * @abstract    Creates an ordered set filled with objects contained in an array
 * @param       array       The array with the objects to add
 * @return      An ordered set containing the objects contained in the array
 */
XS_EXPORT XSStatic XSOrderedSetRef XSOrderedSet_CreateWithArray( XSArrayRef array );

/*!
 * @function    XSOrderedSet_CreateMutableCopy
 * @abstract    Creates a mutable copy of an ordered set
 * @param       set         The ordered set
 * @return      The mutable copy of the ordered set
 */
XS_EXPORT XSOrderedSetRef XSOrderedSet_CreateMutableCopy( XSOrderedSetRef set );

/*!
 * @function    XSOrderedSet_IsMutable
 * @abstract    Checks if an ordered set is mutable
 * @param       set         The ordered set
 * @return      True if the ordered set is mutable, otherwise false
 */
XS_EXPORT bool XSOrderedSet_IsMutable( XSOrderedSetRef set );

/*!
 * @function    XSOrderedSet_GetCount
 * @abstract    Gets the number of values in an ordered set
 * @param       set         The ordered set
 * @return      The number of values in an ordered set
 */
XS_EXPORT XSUInteger XSOrderedSet_GetCount( XSOrderedSetRef set );

/*!
 * @function    XSOrderedSet_ContainsObject
 * @abstract    Checks if a specific object is present in an ordered set
 * @param       set         The ordered set
 * @return      True if the ordered set contains the object, otherwise false
 */
XS_EXPORT bool XSOrderedSet_ContainsObject( XSOrderedSetRef set, XSObjectRef object );

/*!
 * @function    XSOrderedSet_GetAllValues
 * @abstract    Gets all values from an ordered set
 * @param       set         The ordered set
 * @return      An array with all the ordered set's values
 */
XS_EXPORT XSArrayRef XSOrderedSet_GetAllValues( XSOrderedSetRef set );

/*!
 * @function    XSOrderedSet_GetObjectAtIndex
 * @abstract    Gets an object from an ordered set at a specific index
 * @param       set         The ordered set
 * @param       index       The index
 * @return      The object, or NULL if the index does not exist
 */
XS_EXPORT XSObjectRef XSOrderedSet_GetObjectAtIndex( XSOrderedSetRef set, XSUInteger index );

/*!
 * @function    XSOrderedSet_GetLastObject
 * @abstract    Gets the last object in the ordered set
 * @param       set         The ordered set
 * @return      The last object, or NULL if the ordered set is empty
 */
XS_EXPORT XSObjectRef XSOrderedSet_GetLastObject( XSOrderedSetRef set );

/*!
 * @function    XSOrderedSet_GetIndexOfObject
 * @abstract    Gets the index of an object in an ordered set
 * @param       set         The ordered set
 * @param       object      The object
 * @return      The index of the object, or XSNotFound
 */
XS_EXPORT XSUInteger XSOrderedSet_GetIndexOfObject( XSOrderedSetRef set, XSObjectRef object );

/*!
 * @function    XSOrderedSet_AddObject
 * @abstract    Adds an object in an ordered set
 * @param       set         The ordered set
 * @param       object      The object (cannot be NULL)
 * @return      True if the object was added, otherwise false
 */
XS_EXPORT bool XSOrderedSet_AddObject( XSOrderedSetRef set, XSObjectRef object );

/*!
 * @function    XSOrderedSet_InsertObjectAtIndex
 * @abstract    Inserts an object at a specific index in an ordered set
 * @param       set         The ordered set
 * @param       index       The index
 * @param       object      The object (cannot be NULL)
 * @return      True if the object was inserted, otherwise false
 */
XS_EXPORT bool XSOrderedSet_InsertObjectAtIndex( XSOrderedSetRef set, XSUInteger index, XSObjectRef object );

/*!
 * @function    XSOrderedSet_ReplaceObjectAtIndex
 * @abstract    Replaces an object at a specific index in the ordered set
 * @param       set         The ordered set
 * @param       index       The index
 * @param       newObject   The new object (cannot be NULL)
 * @return      True if the object was replaced, otherwise false
 */
XS_EXPORT bool XSOrderedSet_ReplaceObjectAtIndex( XSOrderedSetRef set, XSUInteger index, XSObjectRef newObject );

/*!
 * @function    XSOrderedSet_AppendArray
 * @abstract    Appends values from an array to an ordered set
 * @param       set         The ordered set
 * @param       objects     The ordered set with the objects to append
 */
XS_EXPORT void XSOrderedSet_AppendArray( XSOrderedSetRef set, XSArrayRef objects );

/*!
 * @function    XSOrderedSet_RemoveAllObjects
 * @abstract    Removes all objects from an ordered set
 * @param       set         The ordered set
 */
XS_EXPORT void XSOrderedSet_RemoveAllObjects( XSOrderedSetRef set );

/*!
 * @function    XSOrderedSet_RemoveLastObject
 * @abstract    Removes the last object in an ordered set
 * @param       set         The ordered set
 */
XS_EXPORT void XSOrderedSet_RemoveLastObject( XSOrderedSetRef set );

/*!
 * @function    XSOrderedSet_RemoveObject
 * @abstract    Removes a specific object in an ordered set
 * @param       set         The ordered set
 * @param       object      The object to remove
 */
XS_EXPORT void XSOrderedSet_RemoveObject( XSOrderedSetRef set, XSObjectRef object );

/*!
 * @function    XSOrderedSet_RemoveObjectAtIndex
 * @abstract    Removes the object at a specific index in an ordered set
 * @param       set         The ordered set
 * @param       index       The index
 */
XS_EXPORT void XSOrderedSet_RemoveObjectAtIndex( XSOrderedSetRef set, XSUInteger index );

/*!
 * @function    XSOrderedSet_RemoveObjectsInArray
 * @abstract    Removes all occurences of the objects contained in an array from an ordered set
 * @param       set         The ordered set
 * @param       objects     The ordered set with the objects to remove
 */
XS_EXPORT void XSOrderedSet_RemoveObjectsInArray( XSOrderedSetRef set, XSArrayRef objects );

/*!
 * @function    XSOrderedSet_RemoveObjectsInRange
 * @abstract    Removes objects at a specific range from an ordered set
 * @param       set         The ordered set
 * @param       range       The range
 */
XS_EXPORT void XSOrderedSet_RemoveObjectsInRange( XSOrderedSetRef set, XSRange range );

/*!
 * @function    XSOrderedSet_ApplyFunction
 * @abstract    Applies a function for each element of an ordered set
 * @param       set         The ordered set
 * @param       function    The function to apply
 * @discussion  The function will be called with each object contained in the ordered set
 * @see         XSOrderedSet_ApplierFunction
 */
XS_EXPORT void XSOrderedSet_ApplyFunction( XSOrderedSetRef set, XSOrderedSet_ApplierFunction function );

/*!
 * @function    XSOrderedSet_ApplyMethod
 * @abstract    Applies a method for each element of an ordered set
 * @param       set         The ordered set
 * @param       object      The object on which to call the method
 * @param       method      The function to apply
 * @discussion  The method will be called with each object contained in the ordered set
 * @see         XSOrderedSet_ApplierMethod
 */
XS_EXPORT void XSOrderedSet_ApplyMethod( XSOrderedSetRef set, XSObjectRef object, XSOrderedSet_ApplierMethod method );

/*!
 * @function    XSOrderedSet_FilterWithFunction
 * @abstract    Filters an ordered set using a function
 * @param       set         The ordered set
 * @param       function    The function used to filter the ordered set
 * @discussion  The function will be called with each object contained in the ordered set
 * @see         XSOrderedSet_FilterFunction
 */
XS_EXPORT void XSOrderedSet_FilterWithFunction( XSOrderedSetRef set, XSOrderedSet_FilterFunction function );

/*!
 * @function    XSOrderedSet_FilterWithMethod
 * @abstract    Filters an ordered set using a method
 * @param       set         The ordered set
 * @param       object      The object on which to call the method
 * @param       method      The function used to filter the ordered set
 * @discussion  The method will be called with each object contained in the ordered set
 * @see         XSOrderedSet_FilterMethod
 */
XS_EXPORT void XSOrderedSet_FilterWithMethod( XSOrderedSetRef set, XSObjectRef object, XSOrderedSet_FilterMethod method );

/*!
 * @function    XSOrderedSet_SortWithFunction
 * @abstract    Sorts an ordered set using a function
 * @param       set         The ordered set
 * @param       function    The function used to sort the ordered set
 * @discussion  The function will be called with each object contained in the ordered set
 * @see         XSOrderedSet_SortFunction
 */
XS_EXPORT void XSOrderedSet_SortWithFunction( XSOrderedSetRef set, XSOrderedSet_SortFunction function );

/*!
 * @function    XSOrderedSet_SortWithMethod
 * @abstract    Sorts an ordered set using a method
 * @param       set         The ordered set
 * @param       object      The object on which to call the method
 * @param       method      The method used to sort the ordered set
 * @discussion  The method will be called with each object contained in the ordered set
 * @see         XSOrderedSet_SortFunction
 */
XS_EXPORT void XSOrderedSet_SortWithMethod( XSOrderedSetRef set, XSObjectRef object, XSOrderedSet_SortMethod method );

#endif /* __XS_CLASSES_XS_ORDERED_SET_H__ */

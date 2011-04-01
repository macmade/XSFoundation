/*******************************************************************************
 * Copyright (c) 2011, Jean-David Gadina <macmade@eosgarden.com>
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/
 
/* $Id$ */

/*!
 * @header      XSArray.h
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    ...
 */

#ifndef _XS_ARRAY_H_
#define _XS_ARRAY_H_
#pragma once

#include "XSMacros.h"

XS_EXTERN_C_BEGIN

/*!
 * @typedef     XSArrayRef
 * @abstract    Opaque type for the XSArray objects
 */
typedef struct XSArray * XSArrayRef;

/*!
 * @function    XSArray_Create
 * @abstract    Creates an empty array
 * @result      The array object
 */
XSArrayRef XSArray_Create( void );

/*!
 * @function    XSArray_CreateWithCapacity
 * @abstract    Creates an empty array with an initial capacity
 * @param       capacity    The initial array capacity
 * @result      The array object
 */
XSArrayRef XSArray_CreateWithCapacity( XSUInteger capacity );

/*!
 * @function    XSArray_CreateWithObjects
 * @abstract    Creates an array by inserting objects.
 * @param       array   The array object
 * @param       ...     The objects to insert. Must be terminated by a NULL fence
 * @result      The array object
 */
XSArrayRef XSArray_CreateWithObjects( XSArrayRef array, ... );

/*!
 * @function    XSArray_AppendValue
 * @abstract    Appends a value at the end of the array.
 * @description The appended value will be automatically retained.
 * @param       array   The array object
 * @param       The value to append
 * @result      void
 */
void XSArray_AppendValue( XSArrayRef array, void * value );

/*!
 * @function    XSArray_InsertValueAtIndex
 * @abstract    
 * @description The appended value will be automatically retained.
 * @param       array   The array object
 * @param       value   The value to insert
 * @param       i       The index in the array
 * @result      void
 */
void XSArray_InsertValueAtIndex( XSArrayRef array, void * value, XSUInteger i );

/*!
 * @function    XSArray_ReplaceValueAtIndex
 * @abstract    
 * @description The inserted value will be automatically retained.
 * @param       array   The array object
 * @param       value   The value to insert
 * @param       i       The index in the array
 * @result      void
 */
void XSArray_ReplaceValueAtIndex( XSArrayRef array, void * value, XSUInteger i );

/*!
 * @function    XSArray_GetValueAtIndex
 * @abstract    
 * @description The new value will be automatically retained, and the old value
 *              will be released.
 * @param       array   The array object
 * @param       i       The index in the array
 * @result      The array value
 */
void * XSArray_GetValueAtIndex( XSArrayRef array, XSUInteger i );

/*!
 * @function    XSArray_RemoveValueAtIndex
 * @abstract    Removes a value at a specific index
 * @description The removed value will be released.
 * @param       array   The array object
 * @result      The removed value
 */
void * XSArray_RemoveValueAtIndex( XSArrayRef array, XSUInteger i );

XS_EXTERN_C_END

#endif /* _HEADER_H_ */

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
 * @header      XSDictionary.h
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    XSDictionary class functions
 */

#ifndef _XS_DICTIONARY_H_
#define _XS_DICTIONARY_H_
#pragma once

#include "XSMacros.h"

XS_EXTERN_C_BEGIN

/*!
 * @define      XSDICTIONARY_DEFAULT_CAPACITY
 * @abstract    Default capacity for the empty dictionaries
 */
#define XSDICTIONARY_DEFAULT_CAPACITY    256

/*!
 * @typedef     XSDictionary
 * @abstract    Opaque type for the XSDictionary objects
 */
typedef struct XSDictionary * XSDictionary;

/*!
 * @function    __XSDictionary_Alloc
 * @abstract    Object allocator
 * @result      The allocated object
 */
XSStatic XSDictionary XSDictionary_Alloc( void );

/*!
 * @function    XSDictionary_Create
 * @abstract    Creates an empty dictionary
 * @param       xsThis  The dictionary object
 * @result      The new dictionary object
 */
XSDictionary XSDictionary_Init( XSDictionary xsThis );

/*!
 * @function    XSDictionary_InitWithCapacity
 * @abstract    Creates an empty dictionary with an initial capacity
 * @param       xsThis  The dictionary object
 * @param       capacity    The initial dictionary capacity
 * @result      The new dictionary object
 */
XSDictionary XSDictionary_InitWithCapacity( XSDictionary xsThis, XSUInteger capacity );

/*!
 * @function    XSDictionary_InitWithKeysAndValues
 * @abstract    Creates a dictionary with keys and values
 * @param       xsThis  The dictionary object
 * @param       key1    The first key
 * @param       value1  The first value
 * @param       ...     Other values and keys, terminated by a NULL fence
 * @result      The new dictionary object
 */
XSDictionary XSDictionary_InitWithKeysAndValues( XSDictionary xsThis, XSString key1, void * value1, ... );

/*!
 * @function    XSDictionary_Count
 * @abstract    Gets the number of values in the dictionary
 * @param       xsThis  The dictionary object
 * @result      The number of values in the dictionary
 */
XSUInteger XSDictionary_Count( XSDictionary xsThis );

/*!
 * @function    XSDictionary_Keys
 * @abstract    Gets an array with all the dictionary keys
 * @description You are responsible to release the array returned by this
 *              function.
 * @param       xsThis  The dictionary object
 * @result      An array containing all the dictionary keys
 */
XSAutoreleased XSArray XSDictionary_Keys( XSDictionary xsThis );

/*!
 * @function    XSDictionary_Keys
 * @abstract    Gets an array with all the dictionary values
 * @description You are responsible to release the array returned by this
 *              function.
 * @param       xsThis  The dictionary object
 * @result      An array containing all the dictionary values
 */
XSAutoreleased XSArray XSDictionary_Values( XSDictionary xsThis );

/*!
 * @function    XSDictionary_ValueForKey
 * @abstract    Gets the value associated with a key
 * @param       xsThis  The dictionary object
 * @param       key     The key
 * @result      THe value, or NULL if the key is not present in the dictionary
 */
void * XSDictionary_ValueForKey( XSDictionary xsThis, XSString key );

/*!
 * @function    XSDictionary_SetValueForKey
 * @abstract    Adds a value for a specific key
 * @param       xsThis  The dictionary object
 * @param       value   The value
 * @param       key     The key
 * @result      void
 */
void XSDictionary_SetValueForKey( XSDictionary xsThis, void * value, XSString key );

/*!
 * @function    XSDictionary_RemoveValueForKey
 * @abstract    Remove a value for a specific key
 * @param       xsThis  The dictionary object
 * @param       key     The key
 * @result      The removed value
 */
void XSDictionary_RemoveValueForKey( XSDictionary xsThis, XSString key );

/*!
 * @function    XSDictionary_KeyExists
 * @abstract    Checks if the dictionary contains a specific key
 * @param       xsThis  The dictionary object
 * @param       value   The key to search
 * @result      YES if the dictionary contains the key, otherwise NO
 */
BOOL XSDictionary_KeyExists( XSDictionary xsThis, XSString value );

/*!
 * @function    XSDictionary_ContainsValue
 * @abstract    Checks if the dictionary contains a specific value
 * @param       xsThis  The dictionary object
 * @param       value   The value to search
 * @result      YES if the dictionary contains the value, otherwise NO
 */
BOOL XSDictionary_ContainsValue( XSDictionary xsThis, void * value );

XS_EXTERN_C_END

#endif /* _XS_DICTIONARY_H_ */

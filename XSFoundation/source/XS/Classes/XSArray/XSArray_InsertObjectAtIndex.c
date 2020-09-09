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

/* $Id$ */

/*!
 * @file        XSArray_InsertObjectAtIndex.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSArray_InsertObjectAtIndex
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSArrayRef.h>

void XSArray_InsertObjectAtIndex( XSMutableArrayRef array, XSUInteger index, XSObjectRef object )
{
    XSUInteger        i;
    __XSArray_Value * value;
    __XSArray_Value * newValue;
    
    if( array == NULL )
    {
        return;
    }
    
    if( object == NULL )
    {
        XSFatalError( "Cannot insert NULL in an XSArray" );
    }
    
    __XSArray_Lock( array );
    
    if( XSArray_IsMutable( array ) == false )
    {
        XSFatalError( "Cannot insert an object in an immutable array" );
    }
    
    if( index > array->count )
    {
        XSFatalError( "Cannot insert object in an XSArray - Index %lu out of bounds", ( unsigned long )index );
    }
    else if( index == array->count )
    {
        XSArray_AddObject( array, object );
        __XSArray_Unlock( array );
        
        return;
    }
    
    value = array->first;
    i     = 0;
    
    newValue = XSAlloc( sizeof( __XSArray_Value ) );
    
    if( newValue == NULL )
    {
        XSFatalError( "Error allocating memory for an XSArray value" );
    }
    
    newValue->object = XSRetain( object );
    
    while( value != NULL )
    {
        if( i == index )
        {
            if( value->previous == NULL )
            {
                array->first    = newValue;
                newValue->next  = value;
                value->previous = newValue;
            }
            else
            {
                value->previous->next = newValue;
                newValue->previous    = value->previous;
                newValue->next        = value;
                value->previous       = newValue;
            }
            
            array->count++;
            
            break;
        }
        
        value = value->next;
        
        i++;
    }
    
    __XSArray_Unlock( array );
}

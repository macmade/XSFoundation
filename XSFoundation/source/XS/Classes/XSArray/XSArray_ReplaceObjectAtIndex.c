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
 * @file        XSArray_ReplaceObjectAtIndex.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSArray_ReplaceObjectAtIndex
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSArrayRef.h>

void XSArray_ReplaceObjectAtIndex( XSMutableArrayRef array, XSUInteger index, XSObjectRef newObject )
{
    __XSArray_Value * value;
    XSUInteger        i;
    
    if( array == NULL )
    {
        return;
    }
    
    if( newObject == NULL )
    {
        XSFatalError( "Cannot insert NULL in an XSArray" );
    }
    
    __XSArray_Lock( array );
    
    if( XSArray_IsMutable( array ) == false )
    {
        XSFatalError( "Cannot replace an object from an immutable array" );
    }
    
    if( index >= array->count )
    {
        __XSArray_Unlock( array );
        XSFatalError( "Cannot insert object in an XSArray - Index %lu out of bounds", ( unsigned long )index );
    }
    
    i     = 0;
    value = array->first;
    
    while( value != NULL )
    {
        if( i == index )
        {
            XSRelease( value->object );
            
            value->object = XSRetain( newObject );
            
            break;
        }
        
        value = value->next;
        
        i++;
    }
    
    __XSArray_Unlock( array );
}

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
 * @file        XSArray_RemoveObject.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSArray_RemoveObject
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSArrayRef.h>

void XSArray_RemoveObject( XSMutableArrayRef array, XSObjectRef object )
{
    __XSArray_Value * value;
    __XSArray_Value * removedValue;
    
    if( array == NULL || object == NULL )
    {
        return;
    }
    
    __XSArray_Lock( array );
    
    if( XSArray_IsMutable( array ) == false )
    {
        XSFatalError( "Cannot remove an object from an immutable array" );
    }
    
    value = array->first;
    
    while( value != NULL )
    {
        if( XSEquals( value->object, object ) )
        {
            if( value->previous != NULL )
            {
                value->previous->next = value->next;
            }
            else
            {
                array->first = value->next;
            }
            
            if( value->next != NULL )
            {
                value->next->previous = value->previous;
            }
            else
            {
                array->last = value->previous;
            }
            
            removedValue = value;
            value        = value->next;
            
            XSRelease( removedValue->object );
            XSRelease( removedValue );
            
            array->count--;
        }
        else
        {
            value = value->next;
        }
    }
    
    __XSArray_Unlock( array );
}

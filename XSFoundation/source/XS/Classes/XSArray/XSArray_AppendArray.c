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
 * @file        XSArray_AppendArray.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSArray_AppendArray
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSArrayRef.h>

void XSArray_AppendArray( XSMutableArrayRef array, XSArrayRef objects )
{
    __XSArray_Value * value;
    __XSArray_Value * newValue;
    
    if( array == NULL || objects == NULL )
    {
        return;
    }
    
    __XSArray_Lock( array );
    __XSArray_Lock( objects );
    
    if( XSArray_IsMutable( array ) == false )
    {
        XSFatalError( "Cannot append values to an immutable array" );
    }
    
    if( objects->count == 0 )
    {
        __XSArray_Unlock( objects );
        __XSArray_Unlock( array );
        
        return;
    }
    
    value = array->last;
    
    if( value == NULL )
    {
        value = XSAlloc( sizeof( __XSArray_Value ) );
        
        if( value == NULL )
        {
            XSFatalError( "Error allocating memory for an XSArray value" );
        }
        
        value->object = XSRetain( objects->first->object );
        
        array->first = value;
        array->last  = value;
        
        array->count++;
        
        newValue = objects->first->next;
    }
    else
    {
        newValue = objects->first;
    }
    
    while( newValue != NULL )
    {
        value->next = XSAlloc( sizeof( __XSArray_Value ) );
        
        if( value == NULL )
        {
            XSFatalError( "Error allocating memory for an XSArray value" );
        }
        
        value->next->object = XSRetain( newValue->object );
        array->last         = value->next;
        
        array->count++;
        
        value    = value->next;
        newValue = newValue->next;
    }
    
    __XSArray_Unlock( objects );
    __XSArray_Unlock( array );
}

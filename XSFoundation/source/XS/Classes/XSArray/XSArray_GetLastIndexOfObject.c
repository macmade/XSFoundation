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
 * @file        XSArray_GetLastIndexOfObject.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSArray_GetLastIndexOfObject
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSArrayRef.h>

XSUInteger XSArray_GetLastIndexOfObject( XSArrayRef array, XSObjectRef object )
{
    __XSArray_Value * value;
    XSUInteger        i;
    
    if( array == NULL || object == NULL )
    {
        return XSNotFound;
    }
    
    __XSArray_Lock( array );
    
    if( array->count == 0 )
    {
        __XSArray_Unlock( array );
        
        return XSNotFound;
    }
    
    value = array->last;
    i     = array->count - 1;
    
    while( value != NULL )
    {
        if( XSEquals( value->object, object ) )
        {
            __XSArray_Unlock( array );
            
            return i;
        }
        
        value = value->previous;
        
        i--;
    }
    
    __XSArray_Unlock( array );
    
    return XSNotFound;
}

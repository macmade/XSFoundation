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
 * @file        XSArray_SortWithMethod.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSArray_SortWithMethod
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSArrayRef.h>

void XSArray_SortWithMethod( XSMutableArrayRef array, XSObjectRef object, XSArray_SortMethod method )
{
    XSUInteger        i;
    XSObjectRef     * objects;
    __XSArray_Value * value;
    bool              stop;
    
    if( array == NULL || method == NULL )
    {
        return;
    }
    
    __XSArray_Lock( array );
    
    if( XSArray_IsMutable( array ) )
    {
        XSFatalError( "Cannot sort an immutable array" );
    }
    
    if( array->count < 2 )
    {
        __XSArray_Unlock( array );
        
        return;
    }
    
    objects = XSAlloc( array->count * sizeof( XSObjectRef * ) );
    
    if( objects == NULL )
    {
        XSFatalError( "Error allocating memory for XSArray values" );
    }
    
    value = array->first;
    i     = 0;
    
    while( value != NULL )
    {
        objects[ i++ ] = value->object;
        value          = value->next;
    }
    
    stop = false;
    
    __XSArray_SortValuesWithMethod( objects, array->count, object, method, &stop );
    
    value = array->first;
    i     = 0;
    
    while( value != NULL )
    {
        value->object = objects[ i++ ];
        value         = value->next;
    }
    
    XSRelease( objects );
    __XSArray_Unlock( array );
}

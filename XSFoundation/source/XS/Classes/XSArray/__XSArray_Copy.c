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
 * @file        __XSArray_Copy.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSArray_Copy
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSArrayRef.h>

XSArrayRef __XSArray_Copy( XSArrayRef source, XSArrayRef destination )
{
    __XSArray_Value * value;
    __XSArray_Value * newValue;
    __XSArray_Value * previousValue;
    
    ( ( struct __XSArray * )destination )->lock = XSRecursiveLock_Create();
    
    __XSArray_Lock( source );
    
    value           = source->first;
    previousValue   = NULL;
    
    while( value != NULL )
    {
        newValue = XSAlloc( sizeof( __XSArray_Value ) );
        
        if( newValue == NULL )
        {
            XSFatalError( "Error allocating memory for an XSArray value" );
        }
        
        newValue->object = XSRetain( value->object );
        
        if( previousValue == NULL )
        {
            ( ( struct __XSArray * )destination )->first = newValue;
        }
        else
        {
            previousValue->next = newValue;
            newValue->previous  = previousValue;
        }
        
        ( ( struct __XSArray * )destination )->last = newValue;
        previousValue                               = newValue;
        value                                       = value->next;
        
        ( ( struct __XSArray * )destination )->count++;
    }
    
    ( ( struct __XSArray * )destination )->properties  = source->properties;
    ( ( struct __XSArray * )destination )->properties &= ~__XSArray_PropertiesMutable;
    
    __XSArray_Unlock( source );
    
    return destination;
}

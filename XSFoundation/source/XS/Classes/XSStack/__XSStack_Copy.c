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
 * @file        __XSStack_Copy.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSStack_Copy
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSStackRef.h>

XSStackRef __XSStack_Copy( XSStackRef source, XSStackRef destination )
{
    __XSStack_Value * value;
    __XSStack_Value * newValue;
    __XSStack_Value * previousValue;
    
    destination->lock = XSRecursiveLock_Create();
    
    XSRecursiveLock_Lock( source->lock );
    
    value         = source->top;
    previousValue = NULL;
    
    while( value != NULL )
    {
        newValue = XSAlloc( sizeof( __XSStack_Value ) );
        
        if( newValue == NULL )
        {
            XSFatalError( "Error allocating memory for an XSStack value" );
        }
        
        newValue->object = XSRetain( value->object );
        
        if( previousValue == NULL )
        {
            destination->top = newValue;
        }
        else
        {
            previousValue->next = newValue;
        }
        
        destination->count++;
        
        previousValue = newValue;
        value         = value->next;
    }
    
    XSRecursiveLock_Unlock( source->lock );
    
    return destination;
}

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
 * @file        __XSStack_Equals.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSStack_Equals
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSStackRef.h>

bool __XSStack_Equals( XSStackRef object1, XSStackRef object2 )
{
    bool              equals;
    __XSStack_Value * value1;
    __XSStack_Value * value2;
    
    if( object1 == object2 )
    {
        return true;
    }
    
    equals = false;
    
    XSRecursiveLock_Lock( object1->lock );
    XSRecursiveLock_Lock( object2->lock );
    
    if( object1->count != object2->count )
    {
        goto end;
    }
    
    value1 = object1->top;
    value2 = object2->top;
    
    while( value1 != NULL && value2 != NULL )
    {
        if( XSEquals( value1->object, value2->object ) == false )
        {
            goto end;
        }
        
        value1 = value1->next;
        value2 = value2->next;
    }
    
    equals = true;
    
    end:
    
    XSRecursiveLock_Unlock( object1->lock );
    XSRecursiveLock_Unlock( object2->lock );
    
    return equals;
}

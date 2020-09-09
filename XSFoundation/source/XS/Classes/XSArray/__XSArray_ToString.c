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
 * @file        __XSArray_ToString.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSArray_ToString
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSArrayRef.h>

const char * __XSArray_ToString( XSArrayRef object )
{
    XSStringRef       description;
    __XSArray_Value * value;
    
    __XSArray_Lock( object );
    
    description = XSString_StringWithFormat( "%lu items\n{", ( unsigned long )( object->count ) );
    
    value = object->first;
    
    while( value != NULL )
    {
        description = XSString_StringByAppendingFormat( description, "\n    %s", XSRuntime_GetDescription( value->object ) );
        value       = value->next;
    }
    
    description = XSString_StringByAppendingCString( description, "\n}" );
    
    __XSArray_Unlock( object );
    
    return XSString_GetCString( description );
}

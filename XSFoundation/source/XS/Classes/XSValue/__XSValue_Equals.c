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
 * @file        __XSValue_Equals.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSValue_Equals
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSValueRef.h>

bool __XSValue_Equals( XSValueRef object1, XSValueRef object2 )
{
    if( object1 == object2 )
    {
        return true;
    }
    
    if( object1->type != object2->type )
    {
        return false;
    }
    
    if( object1->type == XSValue_ValueTypePointer )
    {
        return object1->pointer == object2->pointer;
    }
    
    if( object1->type == XSValue_ValueTypePoint )
    {
        return XSPoint_IsEqualToPoint( object1->point, object2->point );
    }
    
    if( object1->type == XSValue_ValueTypeSize )
    {
        return XSSize_IsEqualToSize( object1->size, object2->size );
    }
    
    if( object1->type == XSValue_ValueTypeRect )
    {
        return XSRect_IsEqualToToRect( object1->rect, object2->rect );
    }
    
    if( object1->type == XSValue_ValueTypeEdgeInsets )
    {
        return XSEdgeInsets_IsEqualToEdgeInsets( object1->insets, object2->insets );
    }
    
    if( object1->type == XSValue_ValueTypeRange )
    {
        return XSRange_IsEqualToRange( object1->range, object2->range );
    }
    
    return false;
}

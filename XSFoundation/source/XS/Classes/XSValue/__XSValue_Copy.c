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
 * @file        __XSValue_Copy.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSValue_Copy
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSValueRef.h>

XSValueRef __XSValue_Copy( XSValueRef source, XSValueRef destination )
{
    ( ( struct __XSValue * )destination )->type = source->type;
    
    if( source->type == XSValue_ValueTypePointer )
    {
        ( ( struct __XSValue * )destination )->association = source->association;
        
        if( source->association == XSObjectAssociationRetain )
        {
            ( ( struct __XSValue * )destination )->pointer = XSRetain( destination->pointer );
        }
        else if( source->association == XSObjectAssociationCopy )
        {
            ( ( struct __XSValue * )destination )->pointer = XSCopy( source->pointer );
        }
        else
        {
            ( ( struct __XSValue * )destination )->pointer = source->pointer;
        }
    }
    else if( source->type == XSValue_ValueTypePoint )
    {
        ( ( struct __XSValue * )destination )->point = source->point;
    }
    else if( source->type == XSValue_ValueTypeSize )
    {
        ( ( struct __XSValue * )destination )->size = source->size;
    }
    else if( source->type == XSValue_ValueTypeRect )
    {
        ( ( struct __XSValue * )destination )->rect = source->rect;
    }
    else if( source->type == XSValue_ValueTypeEdgeInsets )
    {
        ( ( struct __XSValue * )destination )->insets = source->insets;
    }
    else if( source->type == XSValue_ValueTypeRange )
    {
        ( ( struct __XSValue * )destination )->range = source->range;
    }
    
    return destination;
}

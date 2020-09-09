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
 * @file        __XSValue_ToString.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSValue_ToString
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSValueRef.h>

const char * __XSValue_ToString( XSValueRef object )
{
    XSStringRef description;
    
    if( object->type == XSValue_ValueTypePointer )
    {
        description = XSString_StringWithFormat( "Pointer value: %p", object->pointer );
    }
    else if( object->type == XSValue_ValueTypePoint )
    {
        description = XSString_StringWithFormat( "XSPoint value: %s", XSString_GetCString( XSString_StringFromXSPoint( object->point ) ) );
    }
    else if( object->type == XSValue_ValueTypeSize )
    {
        description = XSString_StringWithFormat( "XSSize value: %s", XSString_GetCString( XSString_StringFromXSSize( object->size ) ) );
    }
    else if( object->type == XSValue_ValueTypeRect )
    {
        description = XSString_StringWithFormat( "XSRect value: %s", XSString_GetCString( XSString_StringFromXSRect( object->rect ) ) );
    }
    else if( object->type == XSValue_ValueTypeEdgeInsets )
    {
        description = XSString_StringWithFormat( "XSEdgeInsets value: %s", XSString_GetCString( XSString_StringFromXSEdgeInsets( object->insets ) ) );
    }
    else if( object->type == XSValue_ValueTypeRange )
    {
        description = XSString_StringWithFormat( "XSRange value: %s", XSString_GetCString( XSString_StringFromXSRange( object->range ) ) );
    }
    else
    {
        return "Unknown value type";
    }
    
    return XSString_GetCString( description );
}

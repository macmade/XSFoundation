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
 * @file        XSString_SubstringWithRange.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSString_SubstringWithRange
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSStringRef.h>

XSAutoreleased XSStringRef XSString_SubstringWithRange( XSStringRef object, XSRange range )
{
    XSUInteger          length;
    char              * s;
    struct __XSString * str;
    
    if( object == NULL || range.length == 0 )
    {
        return NULL;
    }
    
    length = XSString_GetLength( object );
    
    if( range.location >= length )
    {
        return NULL;
    }
    
    range.length = XS_MIN( range.length, length - range.location );
    s            = XSAlloc( range.length + 1 );
    
    if( s == NULL )
    {
        return NULL;
    }
    
    str          = __XSString_Create();
    str->cString = s;
    str->length  = range.length;
    
    memcpy( s, XSString_GetCString( object ) + range.location, range.length );
    
    return XSAutorelease( str );
}

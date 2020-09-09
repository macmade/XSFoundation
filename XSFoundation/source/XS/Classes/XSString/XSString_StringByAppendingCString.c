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
 * @file        XSString_StringByAppendingCString.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSString_StringByAppendingCString
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSStringRef.h>

XSAutoreleased XSStringRef XSString_StringByAppendingCString( XSStringRef object, const char * s )
{
    XSUInteger          length1;
    XSUInteger          length2;
    char              * s2;
    struct __XSString * str;
    
    if( object == NULL )
    {
        return NULL;
    }
    
    length1 = XSString_GetLength( object );
    
    if( length1 == 0 )
    {
        return XSString_StringWithCString( s );
    }
    
    if( s == NULL || ( length2 = strlen( s ) ) == 0 )
    {
        return XSAutorelease( XSCopy( object ) );
    }
    
    s2 = XSAlloc( length1 + length2 + 1 );
    
    if( s2 == NULL )
    {
        return NULL;
    }
    
    str          = __XSString_Create();
    str->cString = s2;
    str->length  = length1 + length2;
    
    memcpy( s2, XSString_GetCString( object ), length1 );
    memcpy( s2 + length1, s, length2 );
    
    return XSAutorelease( str );
}

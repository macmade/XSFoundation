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
 * @file        XSString_RangeOfCString.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSString_RangeOfCString
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSStringRef.h>

XSRange XSString_RangeOfCString( XSStringRef object, const char * s )
{
    XSRange      range;
    char       * pos;
    const char * s2;
    
    range.location = XSNotFound;
    range.length   = 0;
    
    if( object == NULL || s == NULL )
    {
        return range;
    }
    
    if( XSString_GetLength( object ) == 0 || ( range.length = strlen( s ) ) == 0 )
    {
        return range;
    }
    
    s2  = XSString_GetCString( object );
    pos = strstr( s2, s );
    
    if( pos == NULL )
    {
        return range;
    }
    
    range.location = ( XSUInteger )( pos - s2 );
    
    return range;
}

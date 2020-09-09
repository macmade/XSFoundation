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
 * @file        __XSColor_RGBToHSL.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSColor_RGBToHSL
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSColorRef.h>

void __XSColor_RGBToHSL( XSColorRef object )
{
    XSFloat h;
    XSFloat s;
    XSFloat l;
    XSFloat r;
    XSFloat g;
    XSFloat b;
    XSFloat max;
    XSFloat min;
    XSFloat delta;
    XSFloat r_delta;
    XSFloat g_delta;
    XSFloat b_delta;
    
    if( object == NULL )
    {
        return;
    }
    
    XSRecursiveLock_Lock( object->lock );
    
    h = 0;
    r = object->r;
    g = object->g;
    b = object->b;
    
    max = XS_MAX( r, XS_MAX( g, b ) );
    min = XS_MIN( r, XS_MIN( g, b ) );
    
    delta = max - min;
    l     = ( max + min ) / 2;
    
    if( XSFloat_IsZero( delta ) )
    {
        h = 0;
        s = 0;
    }
    else
    {
        if( l < 0.5 )
        {
            s = delta / ( max + min );
        }
        else
        {
            s = delta / ( 2 - max - min );
        }
        
        r_delta = ( ( ( max - r ) / 6 ) + ( delta / 2 ) ) / delta;
        g_delta = ( ( ( max - g ) / 6 ) + ( delta / 2 ) ) / delta;
        b_delta = ( ( ( max - b ) / 6 ) + ( delta / 2 ) ) / delta;
        
        if( XSFloat_IsEqualToFloat( r_delta, max ) )
        {
            h = b_delta - g_delta;
        }
        else if( XSFloat_IsEqualToFloat( g, max ) )
        {
            h = ( 1 / 3 ) + r_delta - b_delta;
        }
        else if( XSFloat_IsEqualToFloat( b, max ) )
        {
            h = ( 2 / 3 ) + g_delta - r_delta;
        }
        
        if( h < 0 )
        {
            h += 1;
        }
        else if( h > 1 )
        {
            h -= 1;
        }
    }
    
    object->h = h;
    object->s = s;
    object->l = l;
    
    XSRecursiveLock_Unlock( object->lock );
}

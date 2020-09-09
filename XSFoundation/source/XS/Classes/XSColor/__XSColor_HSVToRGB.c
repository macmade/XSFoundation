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
 * @file        __XSColor_HSVToRGB.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSColor_HSVToRGB
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSColorRef.h>

void __XSColor_HSVToRGB( XSColorRef object )
{
    XSFloat   h;
    XSFloat   s;
    XSFloat   v;
    XSFloat   c1;
    XSFloat   c2;
    XSFloat   c3;
    XSFloat   vr;
    XSFloat   vg;
    XSFloat   vb;
    XSFloat   vh;
    XSInteger ih;
    
    if( object == NULL )
    {
        return;
    }
    
    XSRecursiveLock_Lock( object->lock );
    
    h = object->h;
    s = object->s;
    v = object->v;
    
    if( XSFloat_IsZero( s ) )
    {
        object->r = v;
        object->g = v;
        object->b = v;
    }
    else
    {
        vh = h * 6;
        ih = ( XSInteger )vh;
        
        c1 = v * ( 1 - s );
        c2 = v * ( 1 - ( s * ( vh - ih ) ) );
        c3 = v * ( 1 - ( s * ( 1 - ( vh - ih ) ) ) );
        
        if( ih == 0 )
        {
            vr = v;
            vg = c3;
            vb = c1;
        }
        else if( ih == 1 )
        {
            vr = c2;
            vg = v;
            vb = c1;
        }
        else if( ih == 2 )
        {
            vr = c1;
            vg = v;
            vb = c3;
        }
        else if( ih == 3 )
        {
            vr = c1;
            vg = c2;
            vb = v;
        }
        else if( ih == 4 )
        {
            vr = c3;
            vg = c1;
            vb = v;
        }
        else
        {
            vr = v;
            vg = c1;
            vb = c2;
        }
        
        object->r = vr;
        object->g = vg;
        object->b = vb;
    }
    
    XSRecursiveLock_Unlock( object->lock );
}

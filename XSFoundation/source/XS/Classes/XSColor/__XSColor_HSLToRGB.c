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
 * @file        __XSColor_HSLToRGB.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSColor_HSLToRGB
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSColorRef.h>

void __XSColor_HSLToRGB( XSColorRef object )
{
    XSFloat    r;
    XSFloat    g;
    XSFloat    b;
    XSFloat    h;
    XSFloat    s;
    XSFloat    l;
    XSFloat    v;
    XSFloat    c1;
    XSFloat    c2;
    XSFloat    vh;
    XSUInteger i;
    
    if( object == NULL )
    {
        return;
    }
    
    XSRecursiveLock_Lock( object->lock );
    
    r  = 0;
    g  = 0;
    b  = 0;
    vh = 0;
    h  = object->h;
    s  = object->s;
    l  = object->l;
    
    if( XSFloat_IsZero( s ) )
    {
        object->r = l;
        object->g = l;
        object->b = l;
    }
    else
    {
        if( l < 0.5 )
        {
            c2 = l * ( 1 + s );
        }
        else
        {
            c2 = ( l + s ) - ( s * l );
        }
        
        c1 = 2 * l - c2;
        
        for( i = 0; i < 3; i++ )
        {
            switch( i )
            {
                case 0: vh = h + ( 1 / 3 ); break;
                case 1: vh = h;             break;
                case 2: vh = h - ( 1 / 3 ); break;
                default:                    break;
            }
            
            if( vh < 0 )
            {
                vh += 1;
            }
            else if( vh > 1 )
            {
                vh -= 1;
            }
            
            if( ( 6 * vh ) < 1 )
            {
                v = c1 + ( c2 - c1 ) * 6 * vh;
            }
            else if( ( 2 * vh ) < 1 )
            {
                v = c2;
            }
            else if( ( 3 * vh ) < 2 )
            {
                v = c1 + ( c2 - c1 ) * ( ( 2 / 3 ) - vh ) * 6;
            }
            else
            {
                v = c1;
            }
            
            switch( i )
            {
                case 0: r = v; break;
                case 1: g = v; break;
                case 2: b = v; break;
                default:       break;
            }
        }
        
        object->r = r;
        object->g = g;
        object->b = b;
    }
    
    XSRecursiveLock_Unlock( object->lock );
}

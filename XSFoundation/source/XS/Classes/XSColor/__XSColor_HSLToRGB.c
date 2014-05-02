/*******************************************************************************
 * XSFoundation - XEOS C Foundation Library
 * 
 * Copyright (c) 2010-2014, Jean-David Gadina - www.xs-labs.com
 * All rights reserved.
 * 
 * XEOS Software License - Version 1.0 - December 21, 2012
 * 
 * Permission is hereby granted, free of charge, to any person or organisation
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to deal in the Software, with or without
 * modification, without restriction, including without limitation the rights
 * to use, execute, display, copy, reproduce, transmit, publish, distribute,
 * modify, merge, prepare derivative works of the Software, and to permit
 * third-parties to whom the Software is furnished to do so, all subject to the
 * following conditions:
 * 
 *      1.  Redistributions of source code, in whole or in part, must retain the
 *          above copyright notice and this entire statement, including the
 *          above license grant, this restriction and the following disclaimer.
 * 
 *      2.  Redistributions in binary form must reproduce the above copyright
 *          notice and this entire statement, including the above license grant,
 *          this restriction and the following disclaimer in the documentation
 *          and/or other materials provided with the distribution, unless the
 *          Software is distributed by the copyright owner as a library.
 *          A "library" means a collection of software functions and/or data
 *          prepared so as to be conveniently linked with application programs
 *          (which use some of those functions and data) to form executables.
 * 
 *      3.  The Software, or any substancial portion of the Software shall not
 *          be combined, included, derived, or linked (statically or
 *          dynamically) with software or libraries licensed under the terms
 *          of any GNU software license, including, but not limited to, the GNU
 *          General Public License (GNU/GPL) or the GNU Lesser General Public
 *          License (GNU/LGPL).
 * 
 *      4.  All advertising materials mentioning features or use of this
 *          software must display an acknowledgement stating that the product
 *          includes software developed by the copyright owner.
 * 
 *      5.  Neither the name of the copyright owner nor the names of its
 *          contributors may be used to endorse or promote products derived from
 *          this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT OWNER AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE, TITLE AND NON-INFRINGEMENT ARE DISCLAIMED.
 * 
 * IN NO EVENT SHALL THE COPYRIGHT OWNER, CONTRIBUTORS OR ANYONE DISTRIBUTING
 * THE SOFTWARE BE LIABLE FOR ANY CLAIM, DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN ACTION OF CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/* $Id$ */

/*!
 * @file        __XSColor_HSLToRGB.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSColor_HSLToRGB
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSColor.h>

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

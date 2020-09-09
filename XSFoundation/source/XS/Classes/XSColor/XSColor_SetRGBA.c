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
 * @file        XSColor_SetRGBA.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSColor_SetRGBA
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSColorRef.h>

void XSColor_SetRGBA( XSColorRef object, XSFloat r, XSFloat g, XSFloat b, XSFloat a )
{
    if( object == NULL )
    {
        return;
    }
    
    XSRecursiveLock_Lock( object->lock );
    
    object->r = XS_MAX( XS_MIN( r, ( XSFloat )1 ), ( XSFloat )0 );
    object->g = XS_MAX( XS_MIN( g, ( XSFloat )1 ), ( XSFloat )0 );
    object->b = XS_MAX( XS_MIN( b, ( XSFloat )1 ), ( XSFloat )0 );
    object->a = XS_MAX( XS_MIN( a, ( XSFloat )1 ), ( XSFloat )0 );
    
    __XSColor_ConvertFromRGB( object );
    
    XSRecursiveLock_Unlock( object->lock );
}

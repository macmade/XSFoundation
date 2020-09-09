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
 * @file        XSRect_Intersection.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSRect_Intersection
 */

#include <XS/XS.h>

XSRect XSRect_Intersection( XSRect r1, XSRect r2 )
{
    XSRect r;
    
    r1 = XSRect_Standardize( r1 );
    r2 = XSRect_Standardize( r2 );
    
    if
    (
           XSRect_GetMaxX( r1 ) <= r2.origin.x
        || XSRect_GetMaxY( r1 ) <= r2.origin.y
        || XSRect_GetMaxX( r2 ) <= r1.origin.x
        || XSRect_GetMaxY( r2 ) <= r1.origin.y
    )
    {
        return XSRect_Zero();
    }
    
    if( r1.origin.x <= r2.origin.x )
    {
        r.origin.x = r2.origin.x;
    }
    else
    {
        r.origin.x = r1.origin.x;
    }
    
    if( r1.origin.y <= r2.origin.y )
    {
        r.origin.y = r2.origin.y;
    }
    else
    {
        r.origin.y = r1.origin.y;
    }
    
    if( XSRect_GetMaxX( r1 ) >= XSRect_GetMaxX( r2 ) )
    {
        r.size.width = XSRect_GetMaxX( r2 ) - r.origin.x;
    }
    else
    {
        r.size.width = XSRect_GetMaxX( r1 ) - r.origin.x;
    }
    
    if( XSRect_GetMaxY( r1 ) >= XSRect_GetMaxY( r2 ) )
    {
        r.size.height = XSRect_GetMaxY( r2 ) - r.origin.y;
    }
    else
    {
        r.size.height = XSRect_GetMaxY( r1 ) - r.origin.y;
    }
    
    return r;
}

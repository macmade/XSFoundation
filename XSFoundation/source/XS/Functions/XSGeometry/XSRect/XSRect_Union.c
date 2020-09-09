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
 * @file        XSRect_Union.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSRect_Union
 */

#include <XS/XS.h>

XSRect XSRect_Union( XSRect r1, XSRect r2 )
{
    XSRect r;
    bool   empty1;
    bool   empty2;
    
    r1 = XSRect_Standardize( r1 );
    r2 = XSRect_Standardize( r2 );
    
    empty1 = XSRect_IsEmpty( r1 );
    empty2 = XSRect_IsEmpty( r2 );
    
    if( empty1 && empty2 )
    {
        return XSRect_Zero();
    }
    else if( empty1 )
    {
        return r2;
    }
    else if( empty2 )
    {
        return r1;
    }
    
    r.origin.x    = XS_MIN( r1.origin.x, r2.origin.x );
    r.origin.y    = XS_MIN( r1.origin.y, r2.origin.y );
    r.size.width  = XS_MAX( XSRect_GetMaxX( r1 ), XSRect_GetMaxX( r2 ) ) - r.origin.x;
    r.size.height = XS_MAX( XSRect_GetMaxY( r1 ), XSRect_GetMaxY( r2 ) ) - r.origin.y;
    
    return r;
}

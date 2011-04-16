/*******************************************************************************
 * Copyright (c) 2011, Jean-David Gadina <macmade@eosgarden.com>
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/* $Id$ */

/*!
 * @file        XSFunctions.c
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    Implementation of the general functions
 */

#include "XS.h"
#include "__XSFunctions.h"

XSPoint XSMakePoint( XSFloat x, XSFloat y )
{
    XSPoint p;
    
    p.x = x;
    p.y = y;
    
    return p;
}

XSSize XSMakeSize( XSFloat width, XSFloat height )
{
    XSSize s;
    
    s.width  = width;
    s.height = height;
    
    return s;
}

XSRect XSMakeRect( XSFloat x, XSFloat y, XSFloat width, XSFloat height )
{
    XSRect r;
    
    r.origin.x    = x;
    r.origin.y    = y;
    r.size.width  = width;
    r.size.height = height;
    
    return r;
}

XSRect XSRectZero( void )
{
    return XSMakeRect( 0, 0, 0, 0 );
}

XSRange XSMakeRange( XSUInteger location, XSUInteger length )
{
    XSRange r;
    
    r.location = location;
    r.length   = length;
    
    return r;
}

XSEdgeInsets XSMakeEdgeInsets( XSFloat left, XSFloat top, XSFloat right, XSFloat bottom )
{
    XSEdgeInsets e;
    
    e.left   = left;
    e.top    = top;
    e.right  = right;
    e.bottom = bottom;
    
    return e;
}

XSFloat XSAngleBetweenPoints( XSPoint a, XSPoint b )
{
    XSFloat c;
    XSFloat d;
    
    c = b.y - a.y;
    d = a.x - b.x;
    
    return ( XSFloat )atan2( b.y - a.y, b.x - a.x );
}

XSFloat XSDistanceBetweenPoints( XSPoint a, XSPoint b )
{
    XSFloat x;
    XSFloat y;
    
    x = ( XSFloat )fabs( a.x - b.x );
    y = ( XSFloat )fabs( a.y - b.y );
    
    return ( XSFloat )sqrt( ( x * x ) + ( y * y ) );
}

XSFloat XSDegreesToRadians( XSFloat x )
{
    return ( XSFloat )( ( x * M_PI ) / 180 );
}

XSFloat XSRadiansToDegrees( XSFloat x )
{
    return ( XSFloat )( ( x * 180 ) / M_PI );
}

void XSLog( const char * fmt, ... )
{
    va_list args;
    
    va_start( args, fmt );
    
    XSVLog( fmt, args );
    
    va_end( args );
}

void XSVLog( const char * fmt, va_list args )
{
    __XSVLog( fmt, args );
}

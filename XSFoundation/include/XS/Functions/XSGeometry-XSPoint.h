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
 * @header      XSGeometry-XSPoint.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSPoint functions
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_FUNCTIONS_XS_GEOMETRY_XS_POINT_H__
#define __XS_FUNCTIONS_XS_GEOMETRY_XS_POINT_H__

XS_EXTERN_C_BEGIN

#include <XS/XSTypes.h>

/*!
 * @function    XSPoint_Make
 * @abstract    Creates a point with the specified coordinates
 * @param       x       The X coordinate
 * @param       y       The Y coordinate
 * @return      The point
 */
XS_EXPORT XSPoint XSPoint_Make( XSFloat x, XSFloat y );

/*!
 * @function    XSPoint_Zero
 * @abstract    Creates a point with zero coordinates
 * @return      The point
 */
XS_EXPORT XSPoint XSPoint_Zero( void );

/*!
 * @function    XSPoint_IsEqualToPoint
 * @abstract    Checks if two points are equal
 * @param       p1      The first point to compare
 * @param       p2      The second second to compare
 * @return      True if both points are equal, otherwise false
 */
XS_EXPORT bool XSPoint_IsEqualToPoint( XSPoint p1, XSPoint p2 );

XS_EXTERN_C_END

#endif /* __XS_FUNCTIONS_XS_GEOMETRY_XS_POINT_H__ */

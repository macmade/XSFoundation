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
 * @header      XSGeometry.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @abstract    XSFoundation geometry functions
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_FUNCTIONS_XS_GEOMETRY_H__
#define __XS_FUNCTIONS_XS_GEOMETRY_H__

XS_EXTERN_C_BEGIN

#include <XS/XSTypes.h>

/*******************************************************************************
 * XSPoint
 ******************************************************************************/

/*!
 * @function    XSPointMake
 * @abstract    Creates a point with the specified coordinates
 * @param       x       The X coordinate
 * @param       y       The Y coordinate
 * @return      The point
 */
XSPoint XSPointMake( XSFloat x, XSFloat y );

/*!
 * @function    XSPointZero
 * @abstract    Creates a point with zero coordinates
 * @return      The point
 */
XSPoint XSPointZero( void );

/*!
 * @function    XSPointIsEqualToPoint
 * @abstract    Creates a point with zero coordinates
 * @param       p1      The first point to compare
 * @param       p2      The first second to compare
 * @return      True if both points are equal, otherwise false
 */
bool XSPointIsEqualToPoint( XSPoint p1, XSPoint p2 );

/*!
 * @function    XSPointAngleBetweenPoints
 * @abstract    Computes the angle between two points
 * @param       p1      The first point
 * @param       p2      The first second
 * @return      The angle between the two points
 */
XSFloat XSPointAngleBetweenPoints( XSPoint p1, XSPoint p2 );

/*!
 * @function    XSPointDistanceBetweenPoints
 * @abstract    Computes the distance between two points
 * @param       p1      The first point
 * @param       p2      The first second
 * @return      The distance between the two points
 */
XSFloat XSPointDistanceBetweenPoints( XSPoint p1, XSPoint p2 );

/*******************************************************************************
 * XSSize
 ******************************************************************************/

XSSize XSSizeMake( XSFloat width, XSFloat height );
XSSize XSSizeZero( void );
bool XSSizeIsEqualToSize( XSSize s1, XSSize s2 );

/*******************************************************************************
 * XSRect
 ******************************************************************************/

XSRect XSRectMake( XSFloat x, XSFloat y, XSFloat width, XSFloat height );
XSRect XSRectZero( void );
bool XSRectIsEqualToToRect( XSRect r1, XSRect r2 );
bool XSRectIntersectsRect( XSRect rect1, XSRect rect2 );
bool XSRectContainsPoint( XSRect rect, XSPoint point );
bool XSRectContainsRect( XSRect rect1, XSRect rect2 );
bool XSRectIsEmpty( XSRect rect );
bool XSRectIsInfinite( XSRect rect );
void XSRectDivide( XSRect rect, XSRect * slice, XSRect * remainder, XSFloat amount, XSRectEdge edge );
XSRect XSRectInset( XSRect rect, XSFloat dx, XSFloat dy );
XSRect XSRectIntegral( XSRect rect );
XSRect XSRectIntersection( XSRect r1, XSRect r2 );
XSRect XSRectOffset( XSRect rect, XSFloat dx, XSFloat dy );
XSRect XSRectStandardize( XSRect rect );
XSRect XSRectUnion( XSRect r1, XSRect r2 );
XSFloat XSRectGetMinX( XSRect rect );
XSFloat XSRectGetMinY( XSRect rect );
XSFloat XSRectGetMidX( XSRect rect );
XSFloat XSRectGetMidY( XSRect rect );
XSFloat XSRectGetMaxX( XSRect rect );
XSFloat XSRectGetMaxY( XSRect rect );
XSFloat XSRectGetHeight( XSRect rect );
XSFloat XSRectGetWidth( XSRect rect );

/*******************************************************************************
 * XSEdgeInsets
 ******************************************************************************/

XSEdgeInsets XSEdgeInsetsMake( XSFloat left, XSFloat top, XSFloat right, XSFloat bottom );
XSEdgeInsets XSEdgeInsetsZero( void );
bool XSEdgeInsetsIsEqualsToEdgeInsets( XSEdgeInsets e1, XSEdgeInsets e2 );
XSRect XSEdgeInsetsInsetRect( XSRect rect, XSEdgeInsets insets );

/*******************************************************************************
 * XSRange
 ******************************************************************************/

XSRange XSRangeMake( XSUInteger location, XSUInteger length );
XSRange XSRangeZero( void );
XSUInteger XSRangeMax( XSRange range );
bool XSRangeIsEqualToRange( XSRange r1, XSRange r2 );
bool XSRangeLocationInRange( XSUInteger location, XSRange range );
XSRange XSRangeIntersection( XSRange r1, XSRange r2 );
XSRange XSRangeUnion( XSRange r1, XSRange r2 );

XS_EXTERN_C_END

#endif /* __XS_FUNCTIONS_XS_GEOMETRY_H__ */

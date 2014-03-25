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
 * @abstract    Checks if two points are equal
 * @param       p1      The first point to compare
 * @param       p2      The second second to compare
 * @return      True if both points are equal, otherwise false
 */
bool XSPointIsEqualToPoint( XSPoint p1, XSPoint p2 );

/*!
 * @function    XSPointAngleBetweenPoints
 * @abstract    Computes the angle between two points
 * @param       p1      The first point
 * @param       p2      The second second
 * @return      The angle between the two points
 */
XSFloat XSPointAngleBetweenPoints( XSPoint p1, XSPoint p2 );

/*!
 * @function    XSPointDistanceBetweenPoints
 * @abstract    Computes the distance between two points
 * @param       p1      The first point
 * @param       p2      The second second
 * @return      The distance between the two points
 */
XSFloat XSPointDistanceBetweenPoints( XSPoint p1, XSPoint p2 );

/*******************************************************************************
 * XSSize
 ******************************************************************************/

/*!
 * @function    XSSizeMake
 * @abstract    Creates a size with the specified width and height
 * @param       width   The width
 * @param       height  The height
 * @return      The size
 */
XSSize XSSizeMake( XSFloat width, XSFloat height );

/*!
 * @function    XSSizeZero
 * @abstract    Creates a size with zero width and height
 * @return      The size
 */
XSSize XSSizeZero( void );

/*!
 * @function    XSSizeIsEqualToSize
 * @abstract    Checks if two sizes are equal
 * @param       s1      The first size to compare
 * @param       s2      The second size to compare
 * @return      True if both sizes are equal, otherwise false
 */
bool XSSizeIsEqualToSize( XSSize s1, XSSize s2 );

/*******************************************************************************
 * XSRect
 ******************************************************************************/
 
/*!
 * @function    XSRectMake
 * @abstract    Creates a rectangle with the specified coordinates, width and height
 * @param       x       The X coordinate
 * @param       y       The Y coordinate
 * @param       width   The width
 * @param       height  The height
 * @return      The rectangle
 */
XSRect XSRectMake( XSFloat x, XSFloat y, XSFloat width, XSFloat height );

/*!
 * @function    XSRectZero
 * @abstract    Creates a rectangle with zero coordinates, width and height
 * @return      The rectangle
 */
XSRect XSRectZero( void );

/*!
 * @function    XSRectNull
 * @abstract    Creates a null rectangle
 * @return      The null rectangle
 */
XSRect XSRectNull( void );

/*!
 * @function    XSRectIsEqualToToRect
 * @abstract    Checks if two rectangles are equal
 * @param       r1      The first rectangle to compare
 * @param       r2      The second rectangle to compare
 * @return      True if both rectangles are equal, otherwise false
 */
bool XSRectIsEqualToToRect( XSRect r1, XSRect r2 );

/*!
 * @function    XSRectIntersectsRect
 * @abstract    Checks whether two rectangles intersect
 * @param       rect1   The first rectangle
 * @param       rect2   The second rectangle
 * @return      True if the rectangles intersect, otherwise false
 */
bool XSRectIntersectsRect( XSRect rect1, XSRect rect2 );

/*!
 * @function    XSRectContainsPoint
 * @abstract    Checks whether a rectangle contains a specified point
 * @param       rect    The rectangle
 * @param       point   The point
 * @return      True if the rectangle contains the specified point, otherwise false
 */
bool XSRectContainsPoint( XSRect rect, XSPoint point );

/*!
 * @function    XSRectContainsRect
 * @abstract    Checks whether a rectangle contains a second rectangle
 * @param       rect1   The rectangle to examine for containment of the rectangle passed in rect2
 * @param       rect2   The rectangle to examine for being contained in the rectangle passed in rect1
 * @return      True if the first rectangle contains the second rectangle, otherwise false
 */
bool XSRectContainsRect( XSRect rect1, XSRect rect2 );

/*!
 * @function    XSRectIsEmpty
 * @abstract    Checks whether a rectangle has zero width or height
 * @param       rect    The rectangle
 * @return      True if the rectangle has zero width or height, otherwise false
 */
bool XSRectIsEmpty( XSRect rect );

/*!
 * @function    XSRectIsNull
 * @abstract    Checks whether a rectangle is a null rectangle
 * @param       rect    The rectangle
 * @return      True if the rectangle is a null rectangle, otherwise false
 */
bool XSRectIsNull( XSRect rect );

/*!
 * @function    XSRectInset
 * @abstract    Creates a rectangle that is smaller or larger than the source rectangle, with the same center point.
 * @param       rect    The rectangle
 * @param       dx      The X coordinate value to use for adjusting the source rectangle
 * @param       dy      The Y coordinate value to use for adjusting the source rectangle
 * @discussion  The origin value is offset in the X axis by the distance
 *              specified by dx and in the Y axis by the distance specified by
 *              dy, and its size adjusted by ( 2 * dx, 2 * dy ), relative to the
 *              source rectangle.
 *              If dx and dy are positive values, then the rectangle's size is
 *              decreased.
 *              If dx and dy are negative values, the rectangle's size is
 *              increased.
 * @return      The new rectangle
 */
XSRect XSRectInset( XSRect rect, XSFloat dx, XSFloat dy );

/*!
 * @function    XSRectIntegral
 * @abstract    Creates the smallest rectangle that results from converting the source rectangle values to integers
 * @param       rect    The rectangle
 * @discussion  Given a rectangle with fractional origin or size values,
 *              this function rounds the rectangle's origin downward and its
 *              size upward to the nearest whole integers, such that the result
 *              contains the original rectangle.
 * @return      The new rectangle
 */
XSRect XSRectIntegral( XSRect rect );

/*!
 * @function    XSRectIntersection
 * @abstract    Returns the intersection of two rectangles
 * @param       r1      The first rectangle
 * @param       r2      The second rectangle
 * @discussion  Both rectangles are standardized prior to calculating the
 *              intersection.
 * @return      A rectangle that represents the intersection of the two specified rectangles or null rectangle
 * @see         XSRectStandardize
 * @see         XSRectIsNull
 */
XSRect XSRectIntersection( XSRect r1, XSRect r2 );

/*!
 * @function    XSRectOffset
 * @abstract    Creates a rectangle with an origin that is offset from that of the source rectangle
 * @param       rect    The first rectangle
 * @param       dx      The offset value for the X coordinate
 * @param       dy      The offset value for the Y coordinate
 * @return      A rectangle that is the same size as the source, but with its origin offset by dx units along the x-axis and dy units along the y-axis with respect to the source
 */
XSRect XSRectOffset( XSRect rect, XSFloat dx, XSFloat dy );

/*!
 * @function    XSRectStandardize
 * @abstract    Creates a rectangle with a positive width and height
 * @param       rect    The rectangle
 * @return      A rectangle with a positive width and height
 */
XSRect XSRectStandardize( XSRect rect );

/*!
 * @function    XSRectUnion
 * @abstract    Creates the smallest rectangle that contains the two source rectangles
 * @param       r1      The first rectangle
 * @param       r2      The second rectangle
 * @discussion  Both rectangles are standardized prior to calculating the union.
 *              If either of the rectangles is a null rectangle, a copy of the
 *              other rectangle is returned (resulting in a null rectangle if
 *              both rectangles are null).
 *              Otherwise a rectangle that completely contains the source
 *              rectangles is returned.
 * @return      The smallest rectangle that completely contains both of the source rectangles
 * @see         XSRectStandardize
 * @see         XSRectIsNull
 */
XSRect XSRectUnion( XSRect r1, XSRect r2 );

/*!
 * @function    XSRectGetMinX
 * @abstract    Gets the smallest value for the X coordinate of the rectangle
 * @param       rect    The rectangle
 * @return      The smallest value for the X coordinate of the rectangle
 */
XSFloat XSRectGetMinX( XSRect rect );

/*!
 * @function    XSRectGetMinY
 * @abstract    Gets the smallest value for the Y coordinate of the rectangle
 * @param       rect    The rectangle
 * @return      The smallest value for the Y coordinate of the rectangle
 */
XSFloat XSRectGetMinY( XSRect rect );

/*!
 * @function    XSRectGetMidX
 * @abstract    Gets the X coordinate that establishes the center of the rectangle
 * @param       rect    The rectangle
 * @return      The X coordinate of the center of the specified rectangle
 */
XSFloat XSRectGetMidX( XSRect rect );

/*!
 * @function    XSRectGetMidY
 * @abstract    Gets the Y coordinate that establishes the center of the rectangle
 * @param       rect    The rectangle
 * @return      The Y coordinate of the center of the specified rectangle
 */
XSFloat XSRectGetMidY( XSRect rect );

/*!
 * @function    XSRectGetMaxX
 * @abstract    Gets the largest value for the X coordinate of the rectangle
 * @param       rect    The rectangle
 * @return      The largest value for the X coordinate of the rectangle
 */
XSFloat XSRectGetMaxX( XSRect rect );

/*!
 * @function    XSRectGetMaxY
 * @abstract    Gets the largest value for the Y coordinate of the rectangle
 * @param       rect    The rectangle
 * @return      The largest value for the Y coordinate of the rectangle
 */
XSFloat XSRectGetMaxY( XSRect rect );

/*!
 * @function    XSRectGetWidth
 * @abstract    Gets the width of a rectangle
 * @param       rect    The rectangle
 * @discussion  Regardless of whether the width is a positive or negative
 *              number, this function returns the width as if the rectangle
 *              were standardized.
 *              That is, the result is never a negative number.
 * @return      The width of the rectangle
 * @see         XSRectStandardize
 */
XSFloat XSRectGetWidth( XSRect rect );

/*!
 * @function    XSRectGetHeight
 * @abstract    Gets the height of a rectangle
 * @param       rect    The rectangle
 * @discussion  Regardless of whether the height is a positive or negative
 *              number, this function returns the height as if the rectangle
 *              were standardized.
 *              That is, the result is never a negative number.
 * @return      The height of the rectangle
 * @see         XSRectStandardize
 */
XSFloat XSRectGetHeight( XSRect rect );

/*******************************************************************************
 * XSEdgeInsets
 ******************************************************************************/

/*!
 * @function    XSEdgeInsetsMake
 * @abstract    Creates an edge insets with the specified inset values
 * @param       top     The inset at the top
 * @param       left    The inset on the left
 * @param       bottom  The inset on the bottom
 * @param       right   The inset on the right
 * @return      The edge insets
 */
XSEdgeInsets XSEdgeInsetsMake( XSFloat top, XSFloat left, XSFloat bottom, XSFloat right );

/*!
 * @function    XSEdgeInsetsIsEqualsToEdgeInsets
 * @abstract    Checks if two edge insets are equal
 * @param       e1      The first edge insets to compare
 * @param       e2      The second edge insets to compare
 * @return      True if both edge insets are equal, otherwise false
 */
bool XSEdgeInsetsIsEqualsToEdgeInsets( XSEdgeInsets e1, XSEdgeInsets e2 );

/*!
 * @function    XSEdgeInsetsInsetRect
 * @abstract    Adjusts a rectangle by the given edge insets
 * @param       rect    The rectangle to adjust
 * @param       insets  The edge insets
 * @return      The adjusted rectangle
 */
XSRect XSEdgeInsetsInsetRect( XSRect rect, XSEdgeInsets insets );

/*******************************************************************************
 * XSRange
 ******************************************************************************/

/*!
 * @function    XSRangeMake
 * @abstract    Creates an range with the specified location and length
 * @param       location    The range's location
 * @param       length      The range's length
 * @return      The range
 */
XSRange XSRangeMake( XSUInteger location, XSUInteger length );

/*!
 * @function    XSRangeZero
 * @abstract    Creates a range with zero location and length
 * @return      The range
 */
XSRange XSRangeZero( void );

/*!
 * @function    XSRangeMax
 * @abstract    Returns the sum of the location and length of the range
 * @param       range       The range
 * @return      The sum of the location and length of the range
 */
XSUInteger XSRangeMax( XSRange range );

/*!
 * @function    XSRangeIsEqualToRange
 * @abstract    Checks if two ranges are equal
 * @param       r1      The first range to compare
 * @param       r2      The second range to compare
 * @return      True if both ranges are equal, otherwise false
 */
bool XSRangeIsEqualToRange( XSRange r1, XSRange r2 );

/*!
 * @function    XSRangeLocationInRange
 * @abstract    Checks whether a specified position is in a given range
 * @param       location    The location
 * @param       range       The range
 * @return      True if the location is in the given range, otherwise false
 */
bool XSRangeLocationInRange( XSUInteger location, XSRange range );

/*!
 * @function    XSRangeIntersection
 * @abstract    Returns the intersection of the specified ranges
 * @param       r1      The first range
 * @param       r2      The second range
 * @return      A range containing the indices that exist in both ranges
 */
XSRange XSRangeIntersection( XSRange r1, XSRange r2 );

/*!
 * @function    XSRangeUnion
 * @abstract    Returns the union of the specified ranges
 * @param       r1      The first range
 * @param       r2      The second range
 * @discussion  If one range is completely contained in the other, the returned
 *              range is equal to the larger range.
 * @return      A range covering all indices in and between r1 and r2
 */
XSRange XSRangeUnion( XSRange r1, XSRange r2 );

XS_EXTERN_C_END

#endif /* __XS_FUNCTIONS_XS_GEOMETRY_H__ */

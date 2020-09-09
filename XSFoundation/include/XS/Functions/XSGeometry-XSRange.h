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
 * @header      XSGeometry-XSRange.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSRange functions
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_FUNCTIONS_XS_GEOMETRY_XS_RANGE_H__
#define __XS_FUNCTIONS_XS_GEOMETRY_XS_RANGE_H__

XS_EXTERN_C_BEGIN

#include <XS/XSTypes.h>

/*!
 * @function    XSRange_Make
 * @abstract    Creates an range with the specified location and length
 * @param       location    The range's location
 * @param       length      The range's length
 * @return      The range
 */
XS_EXPORT XSRange XSRange_Make( XSUInteger location, XSUInteger length );

/*!
 * @function    XSRange_Zero
 * @abstract    Creates a range with zero location and length
 * @return      The range
 */
XS_EXPORT XSRange XSRange_Zero( void );

/*!
 * @function    XSRange_Max
 * @abstract    Returns the sum of the location and length of the range
 * @param       range       The range
 * @return      The sum of the location and length of the range
 */
XS_EXPORT XSUInteger XSRange_Max( XSRange range );

/*!
 * @function    XSRange_IsEqualToRange
 * @abstract    Checks if two ranges are equal
 * @param       r1      The first range to compare
 * @param       r2      The second range to compare
 * @return      True if both ranges are equal, otherwise false
 */
XS_EXPORT bool XSRange_IsEqualToRange( XSRange r1, XSRange r2 );

/*!
 * @function    XSRange_LocationInRange
 * @abstract    Checks whether a specified position is in a given range
 * @param       location    The location
 * @param       range       The range
 * @return      True if the location is in the given range, otherwise false
 */
XS_EXPORT bool XSRange_LocationInRange( XSUInteger location, XSRange range );

/*!
 * @function    XSRange_Intersection
 * @abstract    Returns the intersection of the specified ranges
 * @param       r1      The first range
 * @param       r2      The second range
 * @return      A range containing the indices that exist in both ranges
 */
XS_EXPORT XSRange XSRange_Intersection( XSRange r1, XSRange r2 );

/*!
 * @function    XSRange_Union
 * @abstract    Returns the union of the specified ranges
 * @param       r1      The first range
 * @param       r2      The second range
 * @discussion  If one range is completely contained in the other, the returned
 *              range is equal to the larger range.
 * @return      A range covering all indices in and between r1 and r2
 */
XS_EXPORT XSRange XSRange_Union( XSRange r1, XSRange r2 );

XS_EXTERN_C_END

#endif /* __XS_FUNCTIONS_XS_GEOMETRY_XS_RANGE_H__ */

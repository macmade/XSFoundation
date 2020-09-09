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
 * @header      XSGeometry-XSEdgeInsets.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSEdgeInsets functions
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_FUNCTIONS_XS_GEOMETRY_XS_EDGE_INSETS_H__
#define __XS_FUNCTIONS_XS_GEOMETRY_XS_EDGE_INSETS_H__

XS_EXTERN_C_BEGIN

#include <XS/XSTypes.h>

/*!
 * @function    XSEdgeInsets_Make
 * @abstract    Creates an edge insets with the specified inset values
 * @param       top     The inset at the top
 * @param       left    The inset on the left
 * @param       bottom  The inset on the bottom
 * @param       right   The inset on the right
 * @return      The edge insets
 */
XS_EXPORT XSEdgeInsets XSEdgeInsets_Make( XSFloat top, XSFloat left, XSFloat bottom, XSFloat right );

/*!
 * @function    XSEdgeInsets_IsEqualToEdgeInsets
 * @abstract    Checks if two edge insets are equal
 * @param       e1      The first edge insets to compare
 * @param       e2      The second edge insets to compare
 * @return      True if both edge insets are equal, otherwise false
 */
XS_EXPORT bool XSEdgeInsets_IsEqualToEdgeInsets( XSEdgeInsets e1, XSEdgeInsets e2 );

/*!
 * @function    XSEdgeInsets_InsetRect
 * @abstract    Adjusts a rectangle by the given edge insets
 * @param       rect    The rectangle to adjust
 * @param       insets  The edge insets
 * @return      The adjusted rectangle
 */
XS_EXPORT XSRect XSEdgeInsets_InsetRect( XSRect rect, XSEdgeInsets insets );

XS_EXTERN_C_END

#endif /* __XS_FUNCTIONS_XS_GEOMETRY_XS_EDGE_INSETS_H__ */

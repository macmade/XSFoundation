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
 * @header      XSMath.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSFoundation math functions
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_FUNCTIONS_XS_MATH_H__
#define __XS_FUNCTIONS_XS_MATH_H__

XS_EXTERN_C_BEGIN

#include <XS/XSTypes.h>

#ifdef M_PI

#define XSMath_PI   ( ( XSFloat )( M_PI ) )

#else

#define XSMath_PI   ( ( XSFloat )( 3.1415926535897932384626433832795 ) )

#endif

/*!
 * @function    XSFloat_IsZero
 * @abstract    Checks if a float value is zero
 * @param       x       The float value to check
 * @return      True if the float value is zero, otherwise false
 */
XS_EXPORT bool XSFloat_IsZero( XSFloat x );

/*!
 * @function    XSFloat_IsInfinity
 * @abstract    Checks if a float value is infinity
 * @param       x       The float value to check
 * @return      True if the float value is infinity, otherwise false
 */
XS_EXPORT bool XSFloat_IsInfinity( XSFloat x );

/*!
 * @function    XSFloat_IsNaN
 * @abstract    Checks if a float value is not a number (NaN)
 * @param       x       The float value to check
 * @return      True if the float value is not a number (NaN), otherwise false
 */
XS_EXPORT bool XSFloat_IsNaN( XSFloat x );

/*!
 * @function    XSFloat_IsEqualToFloat
 * @abstract    Checks if a float value is equal to another
 * @param       x1      The first float value to compare
 * @param       x2      The second float value to compare
 * @return      True if both float values are equal. otherwise false
 */
XS_EXPORT bool XSFloat_IsEqualToFloat( XSFloat x1, XSFloat x2 );

/*!
 * @function    XSFloat_AbsoluteValue
 * @abstract    Gets the absolute value of a float value
 * @param       x       The float value
 * @return      The absolute value of the float value
 */
XS_EXPORT XSFloat XSFloat_AbsoluteValue( XSFloat x );

/*!
 * @function    XSFloat_Ceil
 * @abstract    Computes the nearest integer not less than a float value
 * @param       x       The float value
 * @return      The nearest integer not less than the float value
 */
XS_EXPORT XSFloat XSFloat_Ceil( XSFloat x );

/*!
 * @function    XSFloat_Floor
 * @abstract    Computes the nearest integer not greater than a float value
 * @param       x       The float value
 * @return      The nearest integer not greater than the float value
 */
XS_EXPORT XSFloat XSFloat_Floor( XSFloat x );

/*!
 * @function    XSFloat_Trunc
 * @abstract    Computes the nearest integer not greater in magnitude than a float value
 * @param       x       The float value
 * @return      the nearest integer not greater in magnitude than the float value
 */
XS_EXPORT XSFloat XSFloat_Trunc( XSFloat x );

/*!
 * @function    XSFloat_Round
 * @abstract    Computes the nearest integer to a float value
 * @param       x       The float value
 * @return      The nearest integer to a float value
 */
XS_EXPORT XSFloat XSFloat_Round( XSFloat x );

XS_EXTERN_C_END

#endif /* __XS_FUNCTIONS_XS_MATH_H__ */

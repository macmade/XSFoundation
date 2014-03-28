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
 * @header      XSMath.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSFoundation math functions
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

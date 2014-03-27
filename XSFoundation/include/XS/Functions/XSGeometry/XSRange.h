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
 * @header      XSRange.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @abstract    XSRange functions
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_FUNCTIONS_XS_GEOMETRY_XS_RANGE_H__
#define __XS_FUNCTIONS_XS_GEOMETRY_XS_RANGE_H__

XS_EXTERN_C_BEGIN

#include <XS/XSTypes.h>

/*!
 * @function    XSRangeMake
 * @abstract    Creates an range with the specified location and length
 * @param       location    The range's location
 * @param       length      The range's length
 * @return      The range
 */
XS_EXPORT XSRange XSRangeMake( XSUInteger location, XSUInteger length );

/*!
 * @function    XSRangeZero
 * @abstract    Creates a range with zero location and length
 * @return      The range
 */
XS_EXPORT XSRange XSRangeZero( void );

/*!
 * @function    XSRangeMax
 * @abstract    Returns the sum of the location and length of the range
 * @param       range       The range
 * @return      The sum of the location and length of the range
 */
XS_EXPORT XSUInteger XSRangeMax( XSRange range );

/*!
 * @function    XSRangeIsEqualToRange
 * @abstract    Checks if two ranges are equal
 * @param       r1      The first range to compare
 * @param       r2      The second range to compare
 * @return      True if both ranges are equal, otherwise false
 */
XS_EXPORT bool XSRangeIsEqualToRange( XSRange r1, XSRange r2 );

/*!
 * @function    XSRangeLocationInRange
 * @abstract    Checks whether a specified position is in a given range
 * @param       location    The location
 * @param       range       The range
 * @return      True if the location is in the given range, otherwise false
 */
XS_EXPORT bool XSRangeLocationInRange( XSUInteger location, XSRange range );

/*!
 * @function    XSRangeIntersection
 * @abstract    Returns the intersection of the specified ranges
 * @param       r1      The first range
 * @param       r2      The second range
 * @return      A range containing the indices that exist in both ranges
 */
XS_EXPORT XSRange XSRangeIntersection( XSRange r1, XSRange r2 );

/*!
 * @function    XSRangeUnion
 * @abstract    Returns the union of the specified ranges
 * @param       r1      The first range
 * @param       r2      The second range
 * @discussion  If one range is completely contained in the other, the returned
 *              range is equal to the larger range.
 * @return      A range covering all indices in and between r1 and r2
 */
XS_EXPORT XSRange XSRangeUnion( XSRange r1, XSRange r2 );

XS_EXTERN_C_END

#endif /* __XS_FUNCTIONS_XS_GEOMETRY_XS_RANGE_H__ */

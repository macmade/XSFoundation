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
 * @header      XSSort.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSSort.h
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_FUNCTIONS_XS_SORT_H__
#define __XS___PRIVATE_FUNCTIONS_XS_SORT_H__

#include <XS/XSTypes.h>

/*!
 * @function    __XSSort_QuickSortBool
 * @abstract    Sorts boolean values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortBool( bool * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortChar
 * @abstract    Sorts char values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortChar( char * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortUnsignedChar
 * @abstract    Sorts unsigned char values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortUnsignedChar( unsigned char * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortShort
 * @abstract    Sorts short values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortShort( short * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortUnsignedShort
 * @abstract    Sorts unsigned short values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortUnsignedShort( unsigned short * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortInt
 * @abstract    Sorts int values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortInt( int * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortUnsignedInt
 * @abstract    Sorts unsigned int values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortUnsignedInt( unsigned int * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortLong
 * @abstract    Sorts long values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortLong( long * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortUnsignedLong
 * @abstract    Sorts unsigned long values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortUnsignedLong( unsigned long * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortXSInt8
 * @abstract    Sorts XSInt8 values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortXSInt8( XSInt8 * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortXSUInt8
 * @abstract    Sorts XSUInt8 values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortXSUInt8( XSUInt8 * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortXSInt16
 * @abstract    Sorts XSInt16 values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortXSInt16( XSInt16 * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortXSUInt16
 * @abstract    Sorts XSUInt16 values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortXSUInt16( XSUInt16 * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortXSInt32
 * @abstract    Sorts XSInt32 values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortXSInt32( XSInt32 * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortXSUInt32
 * @abstract    Sorts XSUInt32 values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortXSUInt32( XSUInt32 * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortXSInt64
 * @abstract    Sorts XSInt64 values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortXSInt64( XSInt64 * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortXSUInt64
 * @abstract    Sorts XSUInt64 values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortXSUInt64( XSUInt64 * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortXSInteger
 * @abstract    Sorts XSInteger values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortXSInteger( XSInteger * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortXSUInteger
 * @abstract    Sorts XSUInteger values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortXSUInteger( XSUInteger * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortFloat
 * @abstract    Sorts float values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortFloat( float * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortDouble
 * @abstract    Sorts double values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortDouble( double * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortXSFloat32
 * @abstract    Sorts XSFloat32 values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortXSFloat32( XSFloat32 * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortXSFloat64
 * @abstract    Sorts XSFloat64 values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortXSFloat64( XSFloat64 * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortXSFloat
 * @abstract    Sorts XSFloat values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortXSFloat( XSFloat * values, XSUInteger count );

/*!
 * @function    __XSSort_QuickSortPointer
 * @abstract    Sorts void pointer values using the quick sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_QuickSortPointer( void ** values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortBool
 * @abstract    Sorts boolean values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortBool( bool * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortChar
 * @abstract    Sorts char values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortChar( char * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortUnsignedChar
 * @abstract    Sorts unsigned char values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortUnsignedChar( unsigned char * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortShort
 * @abstract    Sorts short values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortShort( short * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortUnsignedShort
 * @abstract    Sorts unsigned short values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortUnsignedShort( unsigned short * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortInt
 * @abstract    Sorts int values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortInt( int * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortUnsignedInt
 * @abstract    Sorts unsigned int values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortUnsignedInt( unsigned int * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortLong
 * @abstract    Sorts long values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortLong( long * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortUnsignedLong
 * @abstract    Sorts unsigned long values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortUnsignedLong( unsigned long * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortXSInt8
 * @abstract    Sorts XSInt8 values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortXSInt8( XSInt8 * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortXSUInt8
 * @abstract    Sorts XSUInt8 values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortXSUInt8( XSUInt8 * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortXSInt16
 * @abstract    Sorts XSInt16 values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortXSInt16( XSInt16 * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortXSUInt16
 * @abstract    Sorts XSUInt16 values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortXSUInt16( XSUInt16 * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortXSInt32
 * @abstract    Sorts XSInt32 values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortXSInt32( XSInt32 * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortXSUInt32
 * @abstract    Sorts XSUInt32 values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortXSUInt32( XSUInt32 * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortXSInt64
 * @abstract    Sorts XSInt64 values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortXSInt64( XSInt64 * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortXSUInt64
 * @abstract    Sorts XSUInt64 values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortXSUInt64( XSUInt64 * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortXSInteger
 * @abstract    Sorts XSInteger values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortXSInteger( XSInteger * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortXSUInteger
 * @abstract    Sorts XSUInteger values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortXSUInteger( XSUInteger * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortFloat
 * @abstract    Sorts float values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortFloat( float * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortDouble
 * @abstract    Sorts double values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortDouble( double * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortXSFloat32
 * @abstract    Sorts XSFloat32 values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortXSFloat32( XSFloat32 * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortXSFloat64
 * @abstract    Sorts XSFloat64 values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortXSFloat64( XSFloat64 * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortXSFloat
 * @abstract    Sorts XSFloat values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortXSFloat( XSFloat * values, XSUInteger count );

/*!
 * @function    __XSSort_ShellSortPointer
 * @abstract    Sorts void pointer values using the shell sort algorithm
 * @param       values      The values to sort
 * @param       count       The number of values
 */
void __XSSort_ShellSortPointer( void ** values, XSUInteger count );

#endif /* __XS___PRIVATE_FUNCTIONS_XS_SORT_H__ */

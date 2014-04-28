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
 * @file        XSSort_QuickSort.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSSort_QuickSort
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSSort.h>

void XSSort_QuickSort( void * values, XSUInteger count, XSDataType type )
{
    if( values == NULL || count < 2 )
    {
        return;
    }
    
    switch( type )
    {
        case XSDataTypeUnknown:         return;
        case XSDataTypeBool:            __XSSort_QuickSortBool( values, count );
        case XSDataTypeChar:            __XSSort_QuickSortChar( values, count );
        case XSDataTypeUnsignedChar:    __XSSort_QuickSortUnsignedChar( values, count );
        case XSDataTypeShort:           __XSSort_QuickSortShort( values, count );
        case XSDataTypeUnsignedShort:   __XSSort_QuickSortUnsignedShort( values, count );
        case XSDataTypeInt:             __XSSort_QuickSortInt( values, count );
        case XSDataTypeUnsignedInt:     __XSSort_QuickSortUnsignedInt( values, count );
        case XSDataTypeLong:            __XSSort_QuickSortLong( values, count );
        case XSDataTypeUnsignedLong:    __XSSort_QuickSortUnsignedLong( values, count );
        case XSDataTypeXSInt8:          __XSSort_QuickSortXSInt8( values, count );
        case XSDataTypeXSUInt8:         __XSSort_QuickSortXSUInt8( values, count );
        case XSDataTypeXSInt16:         __XSSort_QuickSortXSInt16( values, count );
        case XSDataTypeXSUInt16:        __XSSort_QuickSortXSUInt16( values, count );
        case XSDataTypeXSInt32:         __XSSort_QuickSortXSInt32( values, count );
        case XSDataTypeXSUInt32:        __XSSort_QuickSortXSUInt32( values, count );
        case XSDataTypeXSInt64:         __XSSort_QuickSortXSInt64( values, count );
        case XSDataTypeXSUInt64:        __XSSort_QuickSortXSUInt64( values, count );
        case XSDataTypeXSInteger:       __XSSort_QuickSortXSInteger( values, count );
        case XSDataTypeXSUInteger:      __XSSort_QuickSortXSUInteger( values, count );
        case XSDataTypeFloat:           __XSSort_QuickSortFloat( values, count );
        case XSDataTypeDouble:          __XSSort_QuickSortDouble( values, count );
        case XSDataTypeXSFloat32:       __XSSort_QuickSortXSFloat32( values, count );
        case XSDataTypeXSFloat64:       __XSSort_QuickSortXSFloat64( values, count );
        case XSDataTypeXSFloat:         __XSSort_QuickSortXSFloat( values, count );
        case XSDataTypePointer:         __XSSort_QuickSortPointer( values, count );
    }
}

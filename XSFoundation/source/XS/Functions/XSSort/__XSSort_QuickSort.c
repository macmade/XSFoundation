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
 * @file        __XSSort_QuickSort.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSSort_QuickSort functions
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSSort.h>

#define __XS_SORT_FUNC_QUICK_SORT( _name_, _type_ )                     \
    void _name_ ( _type_ * values, XSUInteger count )                   \
    {                                                                   \
        _type_   value;                                                 \
        _type_   temp;                                                  \
        _type_ * left;                                                  \
        _type_ * right;                                                 \
                                                                        \
        if( count < 2 )                                                 \
        {                                                               \
            return;                                                     \
        }                                                               \
                                                                        \
        value = values[ count / 2 ];                                    \
        left  = values;                                                 \
        right = values + ( count - 1 );                                 \
                                                                        \
        while( left <= right )                                          \
        {                                                               \
            if( *( left ) < value )                                     \
            {                                                           \
                left++;                                                 \
                                                                        \
                continue;                                               \
            }                                                           \
                                                                        \
            if( *( right ) > value )                                    \
            {                                                           \
                right--;                                                \
                                                                        \
                continue;                                               \
            }                                                           \
                                                                        \
            temp       = *( left );                                     \
            *( left )  = *( right );                                    \
            *( right ) = temp;                                          \
                                                                        \
            left++;                                                     \
            right--;                                                    \
        }                                                               \
                                                                        \
        _name_( values, ( XSUInteger )( ( right  - values ) + 1 ) );    \
        _name_( left,   ( XSUInteger )( ( values + count  ) - left ) ); \
    }

__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortBool,          bool )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortChar,          char )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortUnsignedChar,  unsigned char )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortShort,         short )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortUnsignedShort, unsigned short )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortInt,           int )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortUnsignedInt,   unsigned int )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortLong,          long )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortUnsignedLong,  unsigned long )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortXSInt8,        XSInt8 )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortXSUInt8,       XSUInt8 )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortXSInt16,       XSInt16 )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortXSUInt16,      XSUInt16 )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortXSInt32,       XSInt32 )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortXSUInt32,      XSUInt32 )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortXSInt64,       XSInt64 )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortXSUInt64,      XSUInt64 )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortXSInteger,     XSInteger )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortXSUInteger,    XSUInteger )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortFloat,         float )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortDouble,        double )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortXSFloat32,     XSFloat32 )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortXSFloat64,     XSFloat64 )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortXSFloat,       XSFloat )
__XS_SORT_FUNC_QUICK_SORT( __XSSort_QuickSortPointer,       void * )

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
 * @file        __XSSort_ShellSort.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSSort_ShellSort functions
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSSort.h>

#define __XS_SORT_FUNC_SHELL_SORT( _name_, _type_ )                 \
    void _name_ ( _type_ * values, XSUInteger count )               \
    {                                                               \
        size_t h;                                                   \
        size_t i;                                                   \
        size_t j;                                                   \
        _type_ value;                                               \
                                                                    \
        h = 1;                                                      \
                                                                    \
        while( h <= count )                                         \
        {                                                           \
            h = ( 3 * h ) + 1;                                      \
        }                                                           \
                                                                    \
        while( h > 1 )                                              \
        {                                                           \
            h = h / 3;                                              \
                                                                    \
            for( i = h; i < count; i++ )                            \
            {                                                       \
                value = values[ i ];                                \
                                                                    \
                j = i;                                              \
                                                                    \
                while( ( j >= h ) && ( value < values[ j - h ] ) )  \
                {                                                   \
                    values[ j ] = values[ j - h ] ;                 \
                    j          -= h;                                \
                }                                                   \
                                                                    \
                values[ j ] = value;                                \
            }                                                       \
        }                                                           \
    }

__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortBool,          bool )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortChar,          char )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortUnsignedChar,  unsigned char )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortShort,         short )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortUnsignedShort, unsigned short )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortInt,           int )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortUnsignedInt,   unsigned int )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortLong,          long )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortUnsignedLong,  unsigned long )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortXSInt8,        XSInt8 )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortXSUInt8,       XSUInt8 )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortXSInt16,       XSInt16 )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortXSUInt16,      XSUInt16 )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortXSInt32,       XSInt32 )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortXSUInt32,      XSUInt32 )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortXSInt64,       XSInt64 )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortXSUInt64,      XSUInt64 )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortXSInteger,     XSInteger )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortXSUInteger,    XSUInteger )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortFloat,         float )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortDouble,        double )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortXSFloat32,     XSFloat32 )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortXSFloat64,     XSFloat64 )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortXSFloat,       XSFloat )
__XS_SORT_FUNC_SHELL_SORT( __XSSort_ShellSortPointer,       void * )

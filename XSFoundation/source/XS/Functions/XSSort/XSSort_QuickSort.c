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

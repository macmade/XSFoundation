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

/* $Id$ */

/*!
 * @file        XSSort_ShellSort.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSSort_ShellSort
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSSort.h>

void XSSort_ShellSort( void * values, XSUInteger count, XSDataType type )
{
    if( values == NULL || count < 2 )
    {
        return;
    }
    
    switch( type )
    {
        case XSDataTypeUnknown:         return;
        case XSDataTypeBool:            __XSSort_ShellSortBool( values, count );
        case XSDataTypeChar:            __XSSort_ShellSortChar( values, count );
        case XSDataTypeUnsignedChar:    __XSSort_ShellSortUnsignedChar( values, count );
        case XSDataTypeShort:           __XSSort_ShellSortShort( values, count );
        case XSDataTypeUnsignedShort:   __XSSort_ShellSortUnsignedShort( values, count );
        case XSDataTypeInt:             __XSSort_ShellSortInt( values, count );
        case XSDataTypeUnsignedInt:     __XSSort_ShellSortUnsignedInt( values, count );
        case XSDataTypeLong:            __XSSort_ShellSortLong( values, count );
        case XSDataTypeUnsignedLong:    __XSSort_ShellSortUnsignedLong( values, count );
        case XSDataTypeXSInt8:          __XSSort_ShellSortXSInt8( values, count );
        case XSDataTypeXSUInt8:         __XSSort_ShellSortXSUInt8( values, count );
        case XSDataTypeXSInt16:         __XSSort_ShellSortXSInt16( values, count );
        case XSDataTypeXSUInt16:        __XSSort_ShellSortXSUInt16( values, count );
        case XSDataTypeXSInt32:         __XSSort_ShellSortXSInt32( values, count );
        case XSDataTypeXSUInt32:        __XSSort_ShellSortXSUInt32( values, count );
        case XSDataTypeXSInt64:         __XSSort_ShellSortXSInt64( values, count );
        case XSDataTypeXSUInt64:        __XSSort_ShellSortXSUInt64( values, count );
        case XSDataTypeXSInteger:       __XSSort_ShellSortXSInteger( values, count );
        case XSDataTypeXSUInteger:      __XSSort_ShellSortXSUInteger( values, count );
        case XSDataTypeFloat:           __XSSort_ShellSortFloat( values, count );
        case XSDataTypeDouble:          __XSSort_ShellSortDouble( values, count );
        case XSDataTypeXSFloat32:       __XSSort_ShellSortXSFloat32( values, count );
        case XSDataTypeXSFloat64:       __XSSort_ShellSortXSFloat64( values, count );
        case XSDataTypeXSFloat:         __XSSort_ShellSortXSFloat( values, count );
        case XSDataTypePointer:         __XSSort_ShellSortPointer( values, count );
    }
}

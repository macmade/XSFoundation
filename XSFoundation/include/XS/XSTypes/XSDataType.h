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
 * @header      XSDataType.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSDataType type definition
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_TYPES_XS_DATA_TYPE_H__
#define __XS_TYPES_XS_DATA_TYPE_H__

XS_EXTERN_C_BEGIN

#include <XS/XSTypes/XSInteger.h>

/*!
 * @typedef     XSDataType
 * @abstract    Data-types
 */
typedef enum XSDataType
{
    XSDataTypeUnknown       = 0x00,     /*! Unknow data-type */
    
    XSDataTypeBool          = 0x01,     /*! Boolean data-type */
    XSDataTypeChar          = 0x02,     /*! Char data-type */
    XSDataTypeUnsignedChar  = 0x03,     /*! Unsigned char data-type */
    XSDataTypeShort         = 0x04,     /*! Short data-type */
    XSDataTypeUnsignedShort = 0x05,     /*! Unsigned short data-type */
    XSDataTypeInt           = 0x06,     /*! Int data-type */
    XSDataTypeUnsignedInt   = 0x07,     /*! Unsigned int data-type */
    XSDataTypeLong          = 0x08,     /*! Long data-type */
    XSDataTypeUnsignedLong  = 0x09,     /*! Unsigned long data-type */
    
    XSDataTypeXSInt8        = 0x0A,     /*! XSInt8 data-type */
    XSDataTypeXSUInt8       = 0x0B,     /*! XSUInt8 data-type */
    XSDataTypeXSInt16       = 0x0C,     /*! XSInt16 data-type */
    XSDataTypeXSUInt16      = 0x0D,     /*! XSUInt16 data-type */
    XSDataTypeXSInt32       = 0x0E,     /*! XSInt32 data-type */
    XSDataTypeXSUInt32      = 0x0F,     /*! XSUInt32 data-type */
    XSDataTypeXSInt64       = 0x10,     /*! XSInt64 data-type */
    XSDataTypeXSUInt64      = 0x11,     /*! XSUInt64 data-type */
    XSDataTypeXSInteger     = 0x12,     /*! XSInteger data-type */
    XSDataTypeXSUInteger    = 0x13,     /*! XSUInteger data-type */
    
    XSDataTypeFloat         = 0x14,     /*! Float data-type */
    XSDataTypeDouble        = 0x15,     /*! Double data-type */
    
    XSDataTypeXSFloat32     = 0x16,     /*! XSFloat32 data-type */
    XSDataTypeXSFloat64     = 0x17,     /*! XSFloat64 data-type */
    XSDataTypeXSFloat       = 0x18,     /*! XSFloat data-type */
    
    XSDataTypePointer       = 0x19      /*! Pointer data-type */
}
XSDataType;

XS_EXTERN_C_END

#endif /* __XS_TYPES_XS_DATA_TYPE_H__ */

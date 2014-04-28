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
 * @header      XSDataType.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSDataType type definition
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
    
    XSDataTypePointer       = 0x19,     /*! Pointer data-type */
}
XSDataType;

XS_EXTERN_C_END

#endif /* __XS_TYPES_XS_DATA_TYPE_H__ */

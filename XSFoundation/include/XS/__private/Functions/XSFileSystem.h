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
 * @header      XSFileSystem.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSFileSystem.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_FUNCTIONS_XS_FILE_SYSTEM_H__
#define __XS___PRIVATE_FUNCTIONS_XS_FILE_SYSTEM_H__

#include <XS/XSTypes.h>

/*!
 * @typedef     __XSMimeType_Info
 * @abstract    Mime type information
 */
typedef struct __XSFileSystem_MimeTypeInfo_Struct
{
    const char * type;              /*! The mime type */
    const char * extensions[ 15 ];  /*! The possible file extensions for the mime type (no leading '.') */
}
__XSFileSystem_MimeTypeInfo;

/*!
 * @var         __XSMimeType_Types
 * @abstract    The available (recognized) mime types
 */
XS_EXTERN __XSFileSystem_MimeTypeInfo __XSFileSystem_MimeTypes[];

/*!
 * @var         __XSFileSystem_MimeTypeCount
 * @abstract    The number of registered mime types
 */
XS_EXTERN XSUInteger const __XSFileSystem_MimeTypeCount;

/*!
 * @var         __XSFileSystem_DefaultMimeType
 * @abstract    The default mime type for unrecognized types
 */
XS_EXTERN const char * const __XSFileSystem_DefaultMimeType;

#endif /* __XS___PRIVATE_FUNCTIONS_XS_FILE_SYSTEM_H__ */

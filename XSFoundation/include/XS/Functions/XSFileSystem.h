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
 * @header          XSFileSytsem.h
 * @copyright       (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author          Jean-David Gadina - www.xs-labs.com
 * @abstract        XSFoundation filesystem functions
 * @discussion      ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_FUNCTIONS_XS_FILE_SYSTEM_H__
#define __XS_FUNCTIONS_XS_FILE_SYSTEM_H__

XS_EXTERN_C_BEGIN

#include <XS/XSTypes.h>

/*!
 * @function    XSFileSystem_GetMimeTypeForFile
 * @abstract    Gets a mime type for a file
 * @param       file        The file
 * @return      The mime type for the specified file
 * @discussion  The 'file' parameter may be a file name or a file path.
 *              Note that the file doesn't need to exist on the local
 *              filesystem.
 */
const char * XSFileSystem_GetMimeTypeForFile( const char * file );

/*!
 * @function    XSFileSystem_GetMimeTypeForExtension
 * @abstract    Gets a mime type for a file extension
 * @param       extension   The file extension
 * @return      The mime type for the specified file extension
 * @discussion  The extension may have a leading '.'.m 
 */
const char * XSFileSystem_GetMimeTypeForExtension( const char * extension );

XS_EXTERN_C_END

#endif /* __XS_FUNCTIONS_XS_FILE_SYSTEM_H__ */

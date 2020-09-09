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
 * @header      XSLogLevel.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSLogLevel type definition
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_TYPES_XS_LOG_LEVEL_H__
#define __XS_TYPES_XS_LOG_LEVEL_H__

XS_EXTERN_C_BEGIN

/*!
 * @typedef     XSLogLevel
 * @abstract    Log levels
 */
typedef enum
{
    XSLogLevelFatal     = 0x01, /*! Fatal error */
    XSLogLevelError     = 0x02, /*! Error */
    XSLogLevelWarning   = 0x04, /*! Warning */
    XSLogLevelNotice    = 0x08, /*! Notice */
    XSLogLevelInfo      = 0x10, /*! Information */
    XSLogLevelDebug     = 0x20, /*! Debug information */
    XSLogLevelAll       = 0xFF  /*! All possible levels */
}
XSLogLevel;

XS_EXTERN_C_END

#endif /* __XS_TYPES_XS_LOG_LEVEL_H__ */

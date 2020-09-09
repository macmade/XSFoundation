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
 * @header      XSLog.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSLog.h
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_FUNCTIONS_XS_LOG_H__
#define __XS___PRIVATE_FUNCTIONS_XS_LOG_H__

#include <XS/XSTypes.h>

/*!
 * @typedef     __XSLog_Level
 * @abstract    The current log level
 */
XS_EXTERN volatile XSInteger __XSLog_Level;

/*!
 * @typedef     __XSLog_Mutex
 * @abstract    Mutex for log calls
 */
XS_EXTERN XSMutex __XSLog_Mutex;

/*!
 * @typedef     __XSLog_MutexStatus
 * @abstract    Mutex init status
 */
XS_EXTERN volatile XSInteger __XSLog_MutexStatus;

/*!
 * @typedef     __XSLog_IsPaused
 * @abstract    1 if any log call should be hold, otherwise 0
 */
XS_EXTERN volatile XSInteger __XSLog_IsPaused;

/*!
 * @function    __XSLog_StartLog
 * @abstract    Starts a log session
 */
void __XSLog_StartLog( XSLogLevel level, const char * file, int line, const char * func );

/*!
 * @function    __XSLog_EndLog
 * @abstract    Ends a log session
 */
void __XSLog_EndLog( void );

/*!
 * @function    __XSLog_Pause
 * @abstract    Holds any log request
 */
void __XSLog_Pause( void );

/*!
 * @function    __XSLog_Resume
 * @abstract    Resumes all log requests
 */
void __XSLog_Resume( void );

/*!
 * @function    __XSLog_Exit
 * @abstract    XSLog finalizer function
 */
void __XSLog_Exit( void );

#endif /* __XS___PRIVATE_FUNCTIONS_XS_LOG_H__ */

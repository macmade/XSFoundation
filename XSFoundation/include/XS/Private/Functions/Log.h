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
 * @header      Log.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private declarations for logging functions
 */

#ifndef XS_PRIVATE_FUNCTIONS_LOG_H
#define XS_PRIVATE_FUNCTIONS_LOG_H

#include <XS/Macros.h>
#include <XS/Types/XSSpinLock.h>
#include <stdint.h>

XS_EXTERN_C_BEGIN

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

typedef struct
{
    const char * level;
    const char * process;
    uint64_t     processID;
    uint64_t     threadID;
    uint64_t     milliseconds;
    unsigned int line;
    char         date[ 128 ];
    char         file[ 128 ];
    char         func[ 128 ];
} XSLogInfo;

#ifdef __clang__
#pragma clang diagnostic pop
#endif

/*!
 * @var         XSLogCurrentLevel
 * @abstract    The current log level
 */
XS_EXTERN volatile int64_t XSLogCurrentLevel;

/*!
 * @var         XSLogIsPaused
 * @abstract    1 if any log call should be hold, otherwise 0
 */
XS_EXTERN volatile int64_t XSLogIsPaused;

/*!
 * @var         XSLogLock
 * @abstract    Spin lock for log calls
 */
XS_EXTERN XSSpinLock XSLogLock;

/*!
 * @function    XSLogPause
 * @abstract    Holds any log request
 */
void XSLogPause( void );

/*!
 * @function    XSLogResume
 * @abstract    Resumes all log requests
 */
void XSLogResume( void );

/*!
 * @function    XSLogGetInfo
 * @abstract    Gets the necessary info to print a log message
 * @param       level   The level of the log message
 * @param       file    The file in which the log occurs
 * @param       line    The line number of the file in which the log occurs
 * @param       func    The function in which the log occurs
 * @return      A structure with all the necessary info filled
 */
XSLogInfo XSLogGetInfo( XSLogLevel level, const char * file, int line, const char * func );

/*!
 * @function    XSLogGetCurrentTime
 * @abstract    Gets the current date time string
 * @param       buf             The buffer in which to place the result string
 * @param       size            The buffer size
 * @param       milliseconds    On return, contains the number of milliseconds
 */
void XSLogGetCurrentDateTime( char * buf, size_t size, uint64_t * milliseconds );

XS_EXTERN_C_END

#endif /* XS_PRIVATE_FUNCTIONS_LOG_H */

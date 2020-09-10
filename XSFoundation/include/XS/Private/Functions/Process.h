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
 * @header      Process.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private declarations for process-related functions
 */

#ifndef XS_PRIVATE_FUNCTIONS_PROCESS_H
#define XS_PRIVATE_FUNCTIONS_PROCESS_H

#include <XS/Macros.h>
#include <stdint.h>

XS_EXTERN_C_BEGIN

/*!
 * @define      XS_PROCESS_NAME_SIZE
 * @abstract    Size for the process name global buffer
 */
#define XS_PROCESS_NAME_SIZE 256

/*!
 * @typedef     XSProcessName
 * @abstract    Process name
 */
XS_EXTERN char XSProcessName[ XS_PROCESS_NAME_SIZE ];

/*!
 * @typedef     XSProcessNameInitStatus
 * @abstract    Process name initialization status
 */
XS_EXTERN volatile int64_t XSProcessNameInitStatus;

/*!
 * @typedef     XSStoreCurrentProcessName
 * @abstract    Gets and stores the current process name
 * @param       buf     The buffer in which to store the process name
 * @param       max     The max size of the string (not including the termination character)
 */
void XSStoreCurrentProcessName( char * buf, size_t max );

XS_EXTERN_C_END

#endif /* XS_PRIVATE_FUNCTIONS_PROCESS_H */

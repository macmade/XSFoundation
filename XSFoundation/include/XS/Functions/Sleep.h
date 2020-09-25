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
 * @header      Sleep.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Sleep-related functions
 */

#ifndef XS_FUNCTIONS_SLEEP_H
#define XS_FUNCTIONS_SLEEP_H

#include <XS/Macros.h>

XS_EXTERN_C_BEGIN

/*!
 * @function    XSYield
 * @abstract    Asks the implementation to reschedule the execution of threads
 */
XS_EXPORT void XSYield( void );

/*!
 * @function    XSSleepSeconds
 * @abstract    Requests the calling thread to be suspended for a number of seconds
 * @param       secs    The number of seconds to sleep
 */
XS_EXPORT void XSSleepSeconds( unsigned int secs );

/*!
 * @function    XSSleepMilliseconds
 * @abstract    Requests the calling thread to be suspended for a number of milliseconds
 * @param       msecs   The number of milliseconds to sleep
 */
XS_EXPORT void XSSleepMilliseconds( unsigned int msecs );

XS_EXTERN_C_END

#endif /* XS_FUNCTIONS_SLEEP_H */

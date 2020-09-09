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
 * @header      XSSemaphore.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSSemaphore type definition
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_TYPES_XS_SEMAPHORE_H__
#define __XS_TYPES_XS_SEMAPHORE_H__

XS_EXTERN_C_BEGIN

/*!
 * @typedef     XSSemaphore
 * @abstract    Semaphore type
 */
#ifdef _WIN32

typedef struct
{
    HANDLE sem;                 /*! The semaphore */
    bool named;                 /* Whether the semaphore is named or not */
    char __pad_0[ 7 ];          /* Padding */
}
XSSemaphore;

#else
#ifdef __APPLE__

typedef struct
{
    sem_t * semp;               /*! The semaphore pointer, for POSIX named semaphores */
    sem_t   sem;                /*! The semaphore, for POSIX unnamed semaphores */
    semaphore_t semaphore;      /*! The semaphore, for OS X unnamed semaphores */
    bool named;                 /* Whether the semaphore is named or not */
    char __pad_0[ 7 ];          /* Padding */
}
XSSemaphore;

#else

typedef struct
{
    sem_t * semp;               /*! The semaphore pointer, for POSIX named semaphores */
    sem_t   sem;                /*! The semaphore, for POSIX unnamed semaphores */
    bool named;                 /* Whether the semaphore is named or not */
    char __pad_0[ 7 ];          /* Padding */
}
XSSemaphore;

#endif
#endif

XS_EXTERN_C_END

#endif /* __XS_TYPES_XS_SEMAPHORE_H__ */

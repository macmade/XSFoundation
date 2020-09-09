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
 * @file        XSThreading_SemaphoreTryWait.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSThreading_SemaphoreTryWait
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSThreading.h>

#ifdef __APPLE__
#include <mach/mach_init.h>
#include <mach/task.h>
#include <mach/semaphore.h>
#endif

bool XSThreading_SemaphoreTryWait( XSSemaphore * sem )
{
    if( sem == NULL )
    {
        return false;
    }
    
    #if defined( _WIN32 )
    
    return ( WaitForSingleObject( sem->sem, 0 ) == WAIT_OBJECT_0 ) ? true : false;
    
    #else
    
    if( sem->named )
    {
        if( sem->semp != NULL )
        {
            return ( sem_trywait( sem->semp ) == 0 ) ? true : false;
        }
        
        return false;
    }
    else
    {
        #if defined( __APPLE__ )
        
        {
            mach_timespec_t ts;
            
            ts.tv_sec  = 0;
            ts.tv_nsec = 0;
            
            return ( semaphore_timedwait( sem->semaphore, ts ) == KERN_SUCCESS ) ? true : false;
        }
        
        #else
        
        return ( sem_trywait( &( sem->sem ) ) == 0 ) ? true : false;
        
        #endif
    }
    
    #endif
}

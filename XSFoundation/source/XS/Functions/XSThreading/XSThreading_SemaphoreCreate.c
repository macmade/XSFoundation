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
 * @file        XSThreading_SemaphoreCreate.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSThreading_SemaphoreCreate
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSThreading.h>

#ifdef __APPLE__
#include <mach/mach_init.h>
#include <mach/task.h>
#include <mach/semaphore.h>
#endif

bool XSThreading_SemaphoreCreate( XSSemaphore * sem, const char * name, XSUInteger count )
{
    if( sem == NULL || count == 0 )
    {
        return false;
    }
    
    sem->named = ( name == NULL ) ? false : true;
    
    #if defined( _WIN32 )
    
    sem->sem = CreateSemaphore( name, ( LONG )0, ( LONG )count, NULL );
    
    return ( *( sem ) == NULL ) ? false : true;
    
    #else
    
    if( sem->named )
    {
        sem->semp = sem_open( name, O_CREAT, S_IRUSR | S_IWUSR, ( unsigned int )count );
        
        return ( sem->semp == NULL ) ? false : true;
    }
    else
    {
        #if defined( __APPLE__ )
        
        return ( semaphore_create( mach_task_self(), &( sem->semaphore ), SYNC_POLICY_FIFO, ( int )count ) == KERN_SUCCESS ) ? true : false;
        
        #else
        
        return ( sem_init( &( sem->sem ), 0, ( unsigned int )count ) == 0 ) ? true : false;
        
        #endif
    }
    
    #endif
}

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
 * @file        XSThreading_MutexCreate.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSThreading_MutexCreate
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSThreading.h>

bool XSThreading_MutexCreate( XSMutex * mutex )
{
    if( mutex == NULL )
    {
        return false;
    }
    
    #ifdef _WIN32
    
    *( mutex ) = CreateMutex( NULL, FALSE, NULL );
    
    return ( *( mutex ) == NULL ) ? false : true;
    
    #else
    
    {
        pthread_mutexattr_t attr;
        
        if( pthread_mutexattr_init( &attr ) != 0 )
        {
            return false;
        }
        
        if( pthread_mutexattr_settype( &attr, PTHREAD_MUTEX_RECURSIVE ) != 0 )
        {
            pthread_mutexattr_destroy( &attr );
            
            return false;
        }
        
        if( pthread_mutex_init( mutex, &attr ) != 0 )
        {
            pthread_mutexattr_destroy( &attr );
            
            return false;
        }
        
        pthread_mutexattr_destroy( &attr );
        
        return true;
    }
    
    #endif
}

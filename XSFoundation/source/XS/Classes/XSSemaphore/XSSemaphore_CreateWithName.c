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
 * @file        XSSemaphore_CreateWithName.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSSemaphore_CreateWithName
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSSemaphoreRef.h>

XSStatic XSSemaphoreRef XSSemaphore_CreateWithName( const char * name, XSUInteger count )
{
    struct __XSSemaphore * sem;
    XSUInteger             length;
    
    length = strlen( name );
    
    if( length == 0 )
    {
        XSLogWarning( "Error creating an XSemaphore object - No name specified" );
        
        return NULL;
    }
    
    sem        = __XSSemaphore_Create();
    sem->count = count;
    sem->name  = XSAlloc( length + 1 );
    
    if( sem->name == NULL )
    {
        XSFatalError( "Error allocating memory for an XSemaphore name" );
    }
    
    memcpy( &( sem->name ), name, length );
    
    if( XSThreading_SemaphoreCreate( &( sem->sem ), sem->name, count ) == false )
    {
        XSFatalError( "Error creating a semaphore for XSSemaphore" );
    }
    
    return sem;
}

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
 * @file        __XSThread_Detach.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSThread_Detach
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSThreadRef.h>

void __XSThread_Detach( __XSThread_Arguments * args )
{
    if( args == NULL )
    {
        XSFatalError( "No arguments passed to the XSThread proxy" );
    }
    
    #ifdef _WIN32
    
    args->handle = CreateThread( NULL, 0, ( LPTHREAD_START_ROUTINE )__XSThread_Proxy, args, 0, NULL );
    
    #else
    
    {
        pthread_attr_t ta;
        pthread_t      t;
        
        pthread_attr_init( &ta );
        pthread_attr_setdetachstate( &ta, PTHREAD_CREATE_DETACHED );
        pthread_create( &t, &ta, ( void * ( * )( void * ) )__XSThread_Proxy, args );
        pthread_attr_destroy( &ta );
    }
    
    #endif
}

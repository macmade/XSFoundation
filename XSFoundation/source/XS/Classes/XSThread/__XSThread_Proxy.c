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

/* $Id$ */

/*!
 * @file        __XSThread_Proxy.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSThread_Proxy
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSThreadRef.h>

#ifdef _WIN32
DWORD __XSThread_Proxy( __XSThread_Arguments * args )
#else
void * __XSThread_Proxy( __XSThread_Arguments * args )
#endif
{
    struct __XSThread * thread;
    
    thread = __XSThread_Create();
    
    XSThreading_TLSSetObject( &__XSThread_TLSKey, thread, XSObjectAssociationAssign );
    
    if( args == NULL )
    {
        XSFatalError( "No arguments passed to the XSThread proxy" );
    }
    
    if( args->type == __XSThread_TypeMethod )
    {
        args->method( args->object );
        XSRelease( args->object );
    }
    else if( args->type == __XSThread_TypeMethodWithArgument )
    {
        args->methodWithArgument( args->object, args->arg );
        XSRelease( args->object );
    }
    else if( args->type == __XSThread_TypeFunction )
    {
        args->function();
    }
    else if( args->type == __XSThread_TypeFunctionWithArgument )
    {
        args->functionWithArgument( args->arg );
    }
    else
    {
        XSFatalError( "Unknown thread type" );
    }
    
    #ifdef _WIN32
    
    CloseHandle( args->handle );
    
    #endif
    
    XSThreading_TLSSetObject( &__XSThread_TLSKey, NULL, XSObjectAssociationAssign );
    XSRelease( thread );
    XSRelease( args );
    
    return NULL;
}

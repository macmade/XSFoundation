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
 * @file        XSRuntimeRegisterFinalizer.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSRuntimeRegisterFinalizer
 */

#include <XS/XS.h>
#include <XS/Private/Functions/Runtime.h>
#include <stdlib.h>

void XSRuntimeRegisterFinalizer( void ( *func )( void ) )
{
    XSRuntimeFinalizerList * finalizer;
    XSRuntimeFinalizerList * volatile list;

    if( func == NULL )
    {
        return;
    }

    finalizer            = calloc( sizeof( XSRuntimeFinalizerList ), 1 );
    finalizer->finalizer = func;

    if( finalizer == NULL )
    {
        XSFatalError( "Cannot allocate memory for finalizer function %p", ( void * )func );
    }

    if( XSAtomicCompareAndSwapPointer( NULL, finalizer, ( void * volatile * )&XSRuntimeFinalizers ) )
    {
        return;
    }

add:

    list = XSRuntimeFinalizers;

    while( list != NULL )
    {
        finalizer->previous = list;

        if( XSAtomicCompareAndSwapPointer( NULL, finalizer, ( void * volatile * )&( list->next ) ) )
        {
            return;
        }

        list = list->next;
    }

    goto add;
}

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
 * @file        XSRuntimeRegisterClass.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSRuntimeRegisterClass
 */

#include <XS/XS.h>
#include <XS/Private/Functions/Memory.h>
#include <XS/Private/Functions/Runtime.h>
#include <stdlib.h>

XSClassID XSRuntimeRegisterClass( const XSClassInfo * cls )
{
    XSRuntimeClassInfoList * list;
    XSRuntimeClassInfoList * new;
    XSClassID classID;

    if( XS_RUNTIME_IS_FINALIZING || XS_RUNTIME_IS_FINALIZED )
    {
        return 0;
    }

    if( XS_RUNTIME_IS_INITED == false )
    {
        XSFatalError( "XSFoundation runtime has not been inited. Please call XSRuntimeInitialize()" );
    }

    if( cls == NULL )
    {
        XSFatalError( "Cannot register a NULL runtime class info" );
    }

add:

    list = XSRuntimeClasses;

    while( list != NULL )
    {
        if( XSAtomicCompareAndSwapPointer( NULL, ( void * )( ( uintptr_t )cls ), ( void * volatile * )( ( uintptr_t )( ( const void * volatile * )&( list->cls ) ) ) ) )
        {
            classID = XSAtomicIncrement64( &XSRuntimeClassCount );

            goto success;
        }

        if( XSAtomicCompareAndSwapPointer( NULL, NULL, ( void * volatile * )&( list->next ) ) )
        {
            break;
        }

        list = list->next;
    }

    new = calloc( sizeof( XSRuntimeClassInfoList ), 1 );

    new->cls = cls;

    if( new == NULL )
    {
        XSFatalError( "Cannot allocate memory for the runtime class informations" );
    }
    else if( XSAtomicCompareAndSwapPointer( NULL, new, ( void * volatile * )&( list->next ) ) )
    {
        classID = XSAtomicIncrement64( &XSRuntimeClassCount );
        list    = new;

        goto success;
    }

    free( new );

    goto add;

success:

    if( cls->type == XSClassTypeSingleton || cls->type == XSClassTypeSharedInstance )
    {
        list->sharedInstance = XSAllocWithInfos( cls->instanceSize, classID, __FILE__, __LINE__, __func__ );
    }

    return classID;
}

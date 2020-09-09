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
 * @file        XSAllocWithInfos.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSAllocWithInfos
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSMemory.h>
#include <XS/__private/Functions/XSRuntime.h>

XSClassID XSRuntime_RegisterClass( const XSClassInfo * const cls )
{
    __XSRuntime_ClassInfoList * list;
    __XSRuntime_ClassInfoList * new;
    XSClassID                   classID;
    
    if( __XS_RUNTIME_IS_FINALIZING || __XS_RUNTIME_IS_FINALIZED )
    {
        return 0;
    }
    
    if( __XS_RUNTIME_IS_INITED == false )
    {
        XSFatalError( "XSFoundation runtime has not been inited. Please call XSRuntime_Initialize()" );
    }
    
    if( cls == NULL )
    {
        XSFatalError( "Cannot register a NULL runtime class info" );
    }
    
    add:
    
    list = __XSRuntime_Classes;
    
    while( list != NULL )
    {
        if( XSAtomic_CompareAndSwapPointer( NULL, ( void * )cls, ( void * volatile * )&( list->cls ) ) )
        {
            classID = XSAtomic_IncrementInteger( &__XSRuntime_ClassCount );
            
            goto success;
        }
        
        if( XSAtomic_CompareAndSwapPointer( NULL, NULL, ( void * volatile * )&( list->next ) ) )
        {
            break;
        }
        
        list = list->next;
    }
    
    new = calloc( sizeof( __XSRuntime_ClassInfoList ), 1 );
    
    new->cls  = cls;
    
    if( new == NULL )
    {
        XSFatalError( "Cannot allocate memory for the runtime class informations" );
    }
    else if( XSAtomic_CompareAndSwapPointer( NULL, new, ( void * volatile * )&( list->next ) ) )
    {
        classID = XSAtomic_IncrementInteger( &__XSRuntime_ClassCount );
        list    = new;
        
        goto success;
    }
    
    free( new );
    
    goto add;
    
    success:
    
    if( cls->type == XSClassTypeSingleton || cls->type == XSClassTypeSharedInstance )
    {
        list->sharedInstance = __XSAllocWithInfos( cls->instanceSize, classID, __FILE__, __LINE__, __func__ );
    }
    
    return classID;
}

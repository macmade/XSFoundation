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
 * @file        __XSRuntime_Finalize.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSRuntime_Finalize
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSRuntime.h>
#include <XS/__private/Functions/XSMemory.h>

void __XSRuntime_Finalize( void )
{
    __XSRuntime_ClassInfoList * classList;
    __XSRuntime_ClassInfoList * nextClass;
    __XSRuntime_FinalizerList * finalizerList;
    __XSRuntime_FinalizerList * finalizer;
    
    if( XSAtomic_CompareAndSwapInteger( 0, 1, &__XSRuntime_IsFinalizing ) == false )
    {
        return;
    }
    
    classList = __XSRuntime_Classes;
    
    while( classList != NULL )
    {
        if( classList->sharedInstance != NULL )
        {
            __XSReleaseWithInfos( classList->sharedInstance, __FILE__, __LINE__, __func__ );
        }
        
        classList = classList->next;
    }
    
    finalizerList = __XSRuntime_Finalizers;
    finalizer     = finalizerList;
    
    while( finalizer != NULL )
    {
        finalizerList = finalizer;
        finalizer     = finalizer->next;
    }
    
    finalizer = finalizerList;
    
    while( finalizer != NULL )
    {
        if( finalizer->finalizer != NULL )
        {
            finalizer->finalizer();
        }
        
        finalizerList = finalizer;
        finalizer     = finalizerList->previous;
        
        free( finalizerList );
    }
    
    if( XSAtomic_CompareAndSwapInteger( XSInitStatusInited, XSInitStatusFinalizing, &__XSRuntime_InitStatus ) == false )
    {
        return;
    }
    
    classList               = __XSRuntime_Classes;
    nextClass               = classList;
    __XSRuntime_ClassCount  = 0;
    __XSRuntime_Classes     = NULL;
    
    while( nextClass != NULL )
    {
        classList = nextClass;
        nextClass = classList->next;
        
        free( classList );
    }
    
    while( XSAtomic_CompareAndSwapInteger( XSInitStatusFinalizing, XSInitStatusFinalized, &__XSRuntime_InitStatus ) == false );
}

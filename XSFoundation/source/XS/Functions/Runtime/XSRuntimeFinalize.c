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
 * @file        XSRuntimeFinalize.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSRuntimeFinalize
 */

#include <XS/XS.h>
#include <XS/Private/Functions/Runtime.h>
#include <XS/Private/Functions/Memory.h>
#include <stdlib.h>

void XSRuntimeFinalize( void )
{
    XSRuntimeClassInfoList * classList;
    XSRuntimeClassInfoList * nextClass;
    XSRuntimeFinalizerList * finalizerList;
    XSRuntimeFinalizerList * finalizer;

    if( XS_RUNTIME_IS_FINALIZING )
    {
        return;
    }

    if( XSAtomicCompareAndSwap64( XSInitStatusInited, XSInitStatusFinalizing, &XSRuntimeInitStatus ) == false )
    {
        return;
    }

    classList = XSRuntimeClasses;

    while( classList != NULL )
    {
        if( classList->sharedInstance != NULL )
        {
            XSReleaseWithInfos( classList->sharedInstance, __FILE__, __LINE__, __func__ );
        }

        classList = classList->next;
    }

    finalizerList = XSRuntimeFinalizers;
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

    classList           = XSRuntimeClasses;
    nextClass           = classList;
    XSRuntimeClassCount = 0;
    XSRuntimeClasses    = NULL;

    while( nextClass != NULL )
    {
        classList = nextClass;
        nextClass = classList->next;

        free( classList );
    }

    XSAtomicWrite64( XSInitStatusFinalized, &XSRuntimeInitStatus );
}

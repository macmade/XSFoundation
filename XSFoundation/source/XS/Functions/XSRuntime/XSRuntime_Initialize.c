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
 * @file        XSRuntime_Initialize.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSRuntime_Initialize
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSRuntime.h>

/* Private initializers */
void __XSDebugger_Initialize( void );

/* Private class initializers */
XSStatic void __XSAllocator_Initialize( void );
XSStatic void __XSArray_Initialize( void );
XSStatic void __XSAutoreleasePool_Initialize( void );
XSStatic void __XSBag_Initialize( void );
XSStatic void __XSBinaryTree_Initialize( void );
XSStatic void __XSBoolean_Initialize( void );
XSStatic void __XSColor_Initialize( void );
XSStatic void __XSData_Initialize( void );
XSStatic void __XSDate_Initialize( void );
XSStatic void __XSDictionary_Initialize( void );
XSStatic void __XSError_Initialize( void );
XSStatic void __XSFile_Initialize( void );
XSStatic void __XSFileManager_Initialize( void );
XSStatic void __XSLock_Initialize( void );
XSStatic void __XSNode_Initialize( void );
XSStatic void __XSNotification_Initialize( void );
XSStatic void __XSNotificationCenter_Initialize( void );
XSStatic void __XSNull_Initialize( void );
XSStatic void __XSNumber_Initialize( void );
XSStatic void __XSPrimitiveArray_Initialize( void );
XSStatic void __XSRecursiveLock_Initialize( void );
XSStatic void __XSSemaphore_Initialize( void );
XSStatic void __XSSet_Initialize( void );
XSStatic void __XSStack_Initialize( void );
XSStatic void __XSString_Initialize( void );
XSStatic void __XSThread_Initialize( void );
XSStatic void __XSURL_Initialize( void );
XSStatic void __XSValue_Initialize( void );
XSStatic void __XSXMLParser_Initialize( void );

void XSRuntime_Initialize( void )
{
    __XSRuntime_ClassInfoList * classes;
    
    if( XSAtomic_CompareAndSwapInteger( XSInitStatusNotInited, XSInitStatusInitializing, &__XSRuntime_InitStatus ) == false )
    {
        return;
    }
    
    classes = calloc( sizeof( __XSRuntime_ClassInfoList ), 1 );
    
    if( classes == NULL )
    {
        XSFatalError( "Cannot allocate memory for the runtime class informations" );
    }
    
    if( atexit( __XSRuntime_Finalize ) != 0 )
    {
        XSFatalError( "Cannot register the XSFoundation finalizier function" );
    }
    
    __XSRuntime_Classes     = classes;
    __XSRuntime_ClassCount  = 0;
    
    while( XSAtomic_CompareAndSwapInteger( XSInitStatusInitializing, XSInitStatusInited, &__XSRuntime_InitStatus ) == false );
    
    __XSDebugger_Initialize();
    
    __XSAllocator_Initialize();
    __XSArray_Initialize();
    __XSAutoreleasePool_Initialize();
    __XSBag_Initialize();
    __XSBinaryTree_Initialize();
    __XSBoolean_Initialize();
    __XSColor_Initialize();
    __XSData_Initialize();
    __XSDate_Initialize();
    __XSDictionary_Initialize();
    __XSError_Initialize();
    __XSFile_Initialize();
    __XSFileManager_Initialize();
    __XSLock_Initialize();
    __XSNode_Initialize();
    __XSNotification_Initialize();
    __XSNotificationCenter_Initialize();
    __XSNull_Initialize();
    __XSNumber_Initialize();
    __XSPrimitiveArray_Initialize();
    __XSRecursiveLock_Initialize();
    __XSSemaphore_Initialize();
    __XSSet_Initialize();
    __XSStack_Initialize();
    __XSString_Initialize();
    __XSThread_Initialize();
    __XSURL_Initialize();
    __XSValue_Initialize();
    __XSXMLParser_Initialize();
}

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
 * @file        __XSDebugger_Initialize.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSDebugger_Initialize
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSDebugger.h>

void __XSDebugger_Initialize( void )
{
    #ifndef DEBUG
    
    return;
    
    #else
    
    XSRuntime_RegisterFinalizer( __XSDebugger_Exit );
    
    #ifdef _WIN32
    
    __XSDebugger_SEH = AddVectoredExceptionHandler( 0, __XSDebugger_ErrorHandler );
    
    #else
    
    {
        struct sigaction sa1;
        struct sigaction sa2;
        
        sa1.sa_handler = __XSDebugger_ErrorHandler;
        sa1.sa_flags   = 0;
        
        sigemptyset( &sa1.sa_mask );
        
        if( sigaction( SIGSEGV, &sa1, &sa2 ) != 0 )
        {
            XSFatalError( "Error setting a signal handler for SIGSEGV" );
        }
        
        if( sigaction( SIGBUS, &sa1, &sa2 ) != 0 )
        {
            XSFatalError( "Error setting a signal handler for SIGBUS" );
        }
        
        if( sigaction( SIGABRT, &sa1, &sa2 ) != 0 )
        {
            XSFatalError( "Error setting a signal handler for SIGABRT" );
        }
    }
    
    #endif
    
    #endif
}

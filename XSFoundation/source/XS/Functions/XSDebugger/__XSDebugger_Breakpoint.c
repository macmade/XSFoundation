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
 * @file        __XSDebugger_Breakpoint.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSDebugger_Breakpoint
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSDebugger.h>
#include <XS/__private/Functions/XSLog.h>

void __XSDebugger_Breakpoint( const char * message, __XSDebugger_MemoryRecord * record )
{
    int c;
    
    if( __XSDebugger_ExitRequested )
    {
        return;
    }
    
    #ifndef DEBUG
    
    ( void )message;
    ( void )record;
    ( void )c;
    
    return;
    
    #else
    
    __XSLog_Pause();
    
    fprintf( stderr, "\n" );
    
    start:
    
    fprintf
    (
        stderr,
        "#-------------------------------------------------------------------------------\n"
        "# XSFOUNDATION - BREAKPOINT\n"
        "#-------------------------------------------------------------------------------\n"
        "# \n"
        "# The XSFoundation debugger triggered a breakpoint.\n"
        "# Reason:\n"
        "# \n"
        "#     %s\n"
        "# \n",
        message
    );
    
    if( record != NULL )
    {
        
    }
    
    fprintf
    (
        stderr,
        "#-------------------------------------------------------------------------------\n"
        "# \n"
        "# Available commands:\n"
        "# \n"
        "#     c:    Continues the program's execution (default)\n"
        "#     q:    Aborts the program's execution\n"
        "#     b:    Displays the current backtrace\n"
    );
    
    if( record != NULL )
    {
        fprintf
        (
            stderr,
            "#     p:    Prints information about the memory record involved\n"
            "#     d:    Dumps the memory record's data\n"
        );
    }
    
    fprintf
    (
        stderr,
        "# \n"
        "#-------------------------------------------------------------------------------\n"
        "\n"
        "Choice: "
    );
    
    fflush( stderr );
    
    c = getchar();
    
    if( c == '\n' )
    {
        c = 'c';
    }
    else
    {
        while( getchar() != '\n' );
    }
    
    switch( c )
    {
        case '\n':
        case 'c':
            
            goto end;
            
        case 'q':
            
            __XSDebugger_ExitRequested = true;
            
            exit( EXIT_SUCCESS );
            
            break;
            
        case 'b':
            
            __XSDebugger_PrintBacktrace();
            break;
            
        case 'p':
            
            if( record == NULL )
            {
                fprintf( stderr, "\nError: unknown command\n\n" );
                
                break;
            }
            
            if( record != NULL )
            {
                __XSDebugger_PrintMemoryRecord( record );
            }
            
            break;
            
        case 'd':
            
            if( record == NULL )
            {
                fprintf( stderr, "\nError: unknown command\n\n" );
                
                break;
            }
            
            if( record->freed )
            {
                fprintf( stderr, "\nError: cannot dump a freed memory record\n\n" );
                
                break;
            }
            
            __XSDebugger_DumpMemoryRecord( record );
            
            break;
            
        default:
            
            fprintf( stderr, "\nError: unknown command\n\n" );
            
            break;
    }
    
    goto start;
    
    end:
    
    fprintf( stderr, "\n" );
    
    __XSLog_Resume();
    
    #endif
}

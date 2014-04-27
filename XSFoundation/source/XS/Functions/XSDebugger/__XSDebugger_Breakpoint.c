/*******************************************************************************
 * XSFoundation - XEOS C Foundation Library
 * 
 * Copyright (c) 2010-2014, Jean-David Gadina - www.xs-labs.com
 * All rights reserved.
 * 
 * XEOS Software License - Version 1.0 - December 21, 2012
 * 
 * Permission is hereby granted, free of charge, to any person or organisation
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to deal in the Software, with or without
 * modification, without restriction, including without limitation the rights
 * to use, execute, display, copy, reproduce, transmit, publish, distribute,
 * modify, merge, prepare derivative works of the Software, and to permit
 * third-parties to whom the Software is furnished to do so, all subject to the
 * following conditions:
 * 
 *      1.  Redistributions of source code, in whole or in part, must retain the
 *          above copyright notice and this entire statement, including the
 *          above license grant, this restriction and the following disclaimer.
 * 
 *      2.  Redistributions in binary form must reproduce the above copyright
 *          notice and this entire statement, including the above license grant,
 *          this restriction and the following disclaimer in the documentation
 *          and/or other materials provided with the distribution, unless the
 *          Software is distributed by the copyright owner as a library.
 *          A "library" means a collection of software functions and/or data
 *          prepared so as to be conveniently linked with application programs
 *          (which use some of those functions and data) to form executables.
 * 
 *      3.  The Software, or any substancial portion of the Software shall not
 *          be combined, included, derived, or linked (statically or
 *          dynamically) with software or libraries licensed under the terms
 *          of any GNU software license, including, but not limited to, the GNU
 *          General Public License (GNU/GPL) or the GNU Lesser General Public
 *          License (GNU/LGPL).
 * 
 *      4.  All advertising materials mentioning features or use of this
 *          software must display an acknowledgement stating that the product
 *          includes software developed by the copyright owner.
 * 
 *      5.  Neither the name of the copyright owner nor the names of its
 *          contributors may be used to endorse or promote products derived from
 *          this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT OWNER AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE, TITLE AND NON-INFRINGEMENT ARE DISCLAIMED.
 * 
 * IN NO EVENT SHALL THE COPYRIGHT OWNER, CONTRIBUTORS OR ANYONE DISTRIBUTING
 * THE SOFTWARE BE LIABLE FOR ANY CLAIM, DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN ACTION OF CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
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
        "# The XSFoundation memory debugger triggered a breakpoint.\n"
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

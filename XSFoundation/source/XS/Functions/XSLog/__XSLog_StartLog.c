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
 * @file        __XSLog_StartLog.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definitions for __XSLog_StartLog
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSLog.h>
#include <XS/__private/Functions/XSRuntime.h>

void __XSLog_StartLog( XSLogLevel level, const char * file, int line, const char * func )
{
    
    const char * levelName;
    const char * filename;
    char         date[ 255 ];
    XSUInt64     milliseconds;
    
    if( XSAtomic_CompareAndSwapInteger( XSInitStatusFinalized, XSInitStatusFinalized, &__XSLog_MutexStatus ) )
    {
        return;
    }
    
    if( XSAtomic_CompareAndSwapInteger( XSInitStatusNotInited, XSInitStatusInitializing, &__XSLog_MutexStatus ) )
    {
        XSThreading_MutexCreate( &__XSLog_Mutex );
        
        while( XSAtomic_CompareAndSwapInteger( XSInitStatusInitializing, XSInitStatusInited, &__XSLog_MutexStatus ) == false );
        
        XSRuntime_RegisterFinalizer( __XSLog_Exit );
    }
    
    while( XSAtomic_CompareAndSwapInteger( XSInitStatusInited, XSInitStatusInited, &__XSLog_MutexStatus ) == false );
    
    levelName = "Info";
    
    if( level == XSLogLevelFatal     ) { levelName = "Fatal";   }
    if( level == XSLogLevelError     ) { levelName = "Error";   }
    if( level == XSLogLevelWarning   ) { levelName = "Warning"; }
    if( level == XSLogLevelNotice    ) { levelName = "Notice";  }
    if( level == XSLogLevelInfo      ) { levelName = "Info";    }
    if( level == XSLogLevelDebug     ) { levelName = "Debug";   }
    
    XSThreading_MutexLock( &__XSLog_Mutex );
    
    #ifdef _WIN32
    
    {
        time_t     t;
        struct tm  now;
        SYSTEMTIME time;
        
        time( &t );
        GetSystemTime( &time );
        localtime_s( &now, &t );
        strftime( ( char * )date, 255, "%Y-%m-%d %H:%M:%S", &now );
        
        milliseconds = time.wMilliseconds;
    }
    
    #else
    
    {
        time_t         t;
        struct tm    * now;
        struct timeval tv;
        
        t   = time( NULL );
        now = localtime( &t );
        
        gettimeofday( &tv, NULL );
        strftime( ( char * )date, 255, "%Y-%m-%d %H:%M:%S", now );
        
        milliseconds = ( XSUInt64 )( tv.tv_usec / 1000 );
    }
    
    #endif
    
    #ifdef DEBUG
    
    #ifdef _WIN32
    filename = strrchr( file, '\' );
    #else
    filename = strrchr( file, '/' );
    #endif
    
    filename = ( filename == NULL ) ? file : filename + 1;
    
    if( strlen( filename ) == 0 )
    {
        filename = "unknown";
    }
    
    if( strlen( func ) == 0 )
    {
        func = "unknown";
    }
    
    fprintf
    (
        stderr,
        "%s.%lu %s[%lu:%lX] <%s:%s:%i> %s: ",
        date,
        ( unsigned long )milliseconds,
        XSProcess_GetProcessName(),
        ( unsigned long )XSProcess_GetProcessID(),
        ( unsigned long )XSThreading_GetCurrentThreadID(),
        func,
        filename,
        line,
        levelName
    );
    
    #else
    
    ( void )file;
    ( void )filename;
    ( void )line;
    ( void )func;
    
    fprintf
    (
        stderr,
        "%s.%lu %s[%lu:%lX] %s: ",
        date,
        ( unsigned long )milliseconds,
        XSProcess_GetProcessName(),
        ( unsigned long )XSProcess_GetProcessID(),
        ( unsigned long )XSThreading_GetCurrentThreadID(),
        levelName
    );
    
    #endif
}

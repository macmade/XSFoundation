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
 * @file        XSProcess_GetProcessName.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSProcess_GetProcessName
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSProcess.h>

#ifdef __APPLE__
#include <mach-o/dyld.h>
#endif

const char * XSProcess_GetProcessName( void )
{
    if( XSAtomic_CompareAndSwapInteger( XSInitStatusNotInited, XSInitStatusInitializing, &__XSProcess_ProcessNameStatus ) )
    {
        memset( __XSProcess_ProcessName, 0, XS_PATH_MAX );
        
        #if defined( _WIN32 )
        
        {
            TCHAR  name[ XS_PATH_MAX ];
            char * pos;
            
            memset( name, 0, XS_PATH_MAX );
            
            GetModuleFileName( NULL, ( LPTSTR )name, XS_PATH_MAX );
            
            pos = strrchr( name, '\\' );
            
            if( pos != NULL )
            {
                strcpy_s( __XSProcess_ProcessName, XS_PATH_MAX, pos + 1 );
            }
            else
            {
                strcpy_s( __XSProcess_ProcessName, XS_PATH_MAX, name );
            }
            
            if( strlen( __XSProcess_ProcessName ) == 0 )
            {
                strcpy_s( __XSProcess_ProcessName, XS_PATH_MAX, "unknown" );
            }
        }
        
        #elif defined( __APPLE__ )
        
        {
            char     name[ XS_PATH_MAX ];
            XSUInt32 size;
            char   * pos;
            
            size = XS_PATH_MAX;
            
            _NSGetExecutablePath( name, &size );
            
            pos = strrchr( name, '/' );
            
            if( pos != NULL )
            {
                strlcpy( __XSProcess_ProcessName, pos + 1, XS_PATH_MAX );
            }
            else
            {
                strlcpy( __XSProcess_ProcessName, name, XS_PATH_MAX );
            }
            
            if( strlen( __XSProcess_ProcessName ) == 0 )
            {
                strlcpy( __XSProcess_ProcessName, "unknown", XS_PATH_MAX );
            }
        }
        
        #elif defined( __linux )
        
        strcpy( __XSProcess_ProcessName, getenv( "_" ) );
        
        #elif defined( __unix__ )
        
        strcpy( __XSProcess_ProcessName, getprogname() );
        
        #elif defined( __XEOS__ )
        
        strcpy( __XSProcess_ProcessName, "unknown" );
        
        #else
        
        strcpy( __XSProcess_ProcessName, "unknown" );
        
        #endif
        
        while( XSAtomic_CompareAndSwapInteger( XSInitStatusInitializing, XSInitStatusInited, &__XSProcess_ProcessNameStatus ) == false );
    }
    
    while( XSAtomic_CompareAndSwapInteger( XSInitStatusInited, XSInitStatusInited, &__XSProcess_ProcessNameStatus ) == false );
    
    return __XSProcess_ProcessName;
}

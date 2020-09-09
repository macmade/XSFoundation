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
 * @file        XSThreading_SetCurrentThreadName.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSThreading_SetCurrentThreadName
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSThreading.h>

#ifdef _WIN32

/*!
 * @define      __MS_VC_EXCEPTION
 * @abstract    Exception number to set the thread name
 */
#define __MS_VC_EXCEPTION   0x406D1388

#pragma pack( push, 8 )

/*!
 * @typedef     THREADNAME_INFO
 * @abstract    Thread name info structure
 */
typedef struct tagTHREADNAME_INFO
{
   DWORD  dwType;       /*! Must be 0x1000 */
   LPCSTR szName;       /*! Pointer to name (in user addr space) */
   DWORD  dwThreadID;   /*! Thread ID (-1=caller thread) */
   DWORD  dwFlags;      /*! Reserved for future use, must be zero */
}
THREADNAME_INFO;

#pragma pack( pop )

#endif

void XSThreading_SetCurrentThreadName( const char * name )
{
    #if defined( _WIN32 )
    
    THREADNAME_INFO info;
    
    info.dwType     = ( DWORD )0x1000;
    info.szName     = ( LPCSTR )name;
    info.dwThreadID = ( DWORD )-1;
    info.dwFlags    = ( DWORD )0;
    
    /* See: http://msdn.microsoft.com/en-us/library/xcb2z8hs.aspx */
    __try
    {
        RaiseException( __MS_VC_EXCEPTION, 0, sizeof( info ) / sizeof( ULONG_PTR ), ( ULONG_PTR * )&info );
    }
    __except( EXCEPTION_EXECUTE_HANDLER )
    {}
    
    #elif defined( __APPLE__ )
    
    pthread_setname_np( name );
    
    #elif defined( __linux )
    
    pthread_setname_np( pthread_self(), name );
    
    #elif defined( __unix__ )
    
    pthread_set_name_np( pthread_self(), name );
    
    #elif defined( __XEOS__ )
    
    ( void )name;
    
    #else
    
    ( void )name;
    
    #endif
}

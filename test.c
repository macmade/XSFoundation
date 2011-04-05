/*******************************************************************************
 * Copyright (c) 2011, Jean-David Gadina <macmade@eosgarden.com>
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/
 
/* $Id$ */

/*!
 * @header      test.c
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    ...
 */

#include <stdlib.h>
#include <stdio.h>
#include "XS.h"

void thread_test( XSThreadRef thread, void * arg );
void thread_test( XSThreadRef thread, void * arg )
{
    XSStringRef str;
    
    str = ( XSStringRef )arg;
    
    XSLog( "Log message from thread #%X: %@", XSThread_GetID( thread ), str );
}

void timer_test( XSTimerRef timer );
void timer_test( XSTimerRef timer )
{
    static XSUInteger i = 0;
    
    XSLog( "Timer called: %i", ++i );
    
    if( i == 5 )
    {
        XSTimer_Invalidate( timer );
    }
}

int main( int argc, char * argv[] )
{
    unsigned int         i;
    char              ** test;
    XSApplicationRef     app;
    XSStringRef          str1;
    XSStringRef          str2;
    XSStringRef          str3;
    XSArrayRef           arr;
    XSDictionaryRef      dict;
    XSTimerRef           timer;
    
    app  = XSApplication_Start( argc, ( const char ** )argv );
    test = XSAutoAlloc( 5 * sizeof( char * ) );
    
    for( i = 0; i < 5; i++ )
    {
        test[ i ] = XSAutoAlloc( 2 );
    }
    
    str1 = XSSTR( "hello, world" );
    str2 = XSString_SubstringFromIndex( str1, 5 );
    str3 = XSCopy( str2 );
    arr  = XSArray_CreateWithValues( str1, str2, str3, NULL );
    dict = XSAutorelease( XSDictionary_CreateWithValuesAndKeys( str1, str1, str2, str2, NULL ) );
    
    printf( "%s%s%s\n", XSString_CString( str1 ), XSString_CString( str2 ), XSString_CString( str3 ) );
    
    XSLog( "hello, universe: %i %@ %i %@ %i", 42, str1, 43, app, 44 );
    XSLog( "Array value 0: %@", XSArray_ValueAtIndex( arr, 0 ) );
    
    XSLog( "%@", XSAutorelease( XSString_StringByAppendingString( str1, str2 ) ) );
    XSLog( "%@", arr );
    XSLog( "%@", dict );
    
    XSThread_Detach( thread_test, NULL );
    XSThread_Detach( thread_test, str1 );
    
    timer = XSTimer_Create( timer_test, 1000 );
    
    XSTimer_RunOnce( timer );
    XSTimer_RunAndRepeat( timer );
    
    XSRelease( timer );
    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( str3 );
    XSRelease( arr );
    
    XSApplication_Exit();
}

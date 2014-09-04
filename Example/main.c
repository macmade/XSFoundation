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

#include <XS/XS.h>

XSComparisonResult __ArraySort( XSObjectRef value1, XSObjectRef value2, bool * stop );
XSComparisonResult __ArraySort( XSObjectRef value1, XSObjectRef value2, bool * stop )
{
    ( void )stop;
    
    return XSNumber_CompareWithNumber( value1, value2 );
}

void __threadedFunc( XSBooleanRef boolean );
void __threadedFunc( XSBooleanRef boolean )
{
    XSShow( boolean );
    XSShow( XSThread_GetCurrentThread() );
    XSShow( XSThread_GetMainThread() );
    
    sleep( 1 );
}

bool __filterArray( XSObjectRef object, XSUInteger index, bool * stop );
bool __filterArray( XSObjectRef object, XSUInteger index, bool * stop )
{
    ( void )index;
    ( void )stop;
    
    return XSEquals( object, XSSTR( "str5" ) );
}

int main( int argc, const char * argv[] )
{
    XSAutoreleasePoolRef ap1;
    XSAutoreleasePoolRef ap2;
    
    ( void )argc;
    ( void )argv;
    
    XSRuntime_Initialize();
    
    ap1 = XSAutoreleasePool_Create();
    
    XSAutoAlloc( 1024 );
    XSAutoAlloc( 1024 );
    
    ap2 = XSAutoreleasePool_Create();
    
    XSArray_Array();
    
    XSRelease( ap2 );
    XSRelease( ap1 );
    
    ap1 = XSAutoreleasePool_Create();
    
    {
        void * x1;
        void * x2;
        
        x1 = XSAlloc( 10 );
        x2 = XSAlloc( 100 );
        
        XSRelease( x1 );
        XSRelease( x2 );
    }
    
    {
        XSBooleanRef bool1;
        XSBooleanRef bool2;
        XSBooleanRef bool3;
        
        bool1 = XSBoolean_Create( true );
        bool2 = XSCopy( bool1 );
        bool3 = XSBoolean_Create( false );
        
        XSLog( "bool1: %p", bool1 );
        XSLog( "bool2: %p", bool2 );
        XSLog( "bool3: %p", bool3 );
        
        XSLog( "bool1: %s", XSRuntime_GetDescription( bool1 ) );
        XSLog( "bool2: %s", XSRuntime_GetDescription( bool2 ) );
        XSLog( "bool3: %s", XSRuntime_GetDescription( bool3 ) );
        
        if( XSEquals( bool1, bool2 ) )
        {
            XSLog( "bool1 == bool2" );
        }
        else
        {
            XSLog( "bool1 != bool2" );
        }
        
        if( XSEquals( bool1, bool3 ) )
        {
            XSLog( "bool1 == bool3" );
        }
        else
        {
            XSLog( "bool1 != bool3" );
        }
        
        XSRelease( bool1 );
        XSRelease( bool2 );
        XSRelease( bool3 );
    }
    
    XSInteger x;
    
    x = 42;
    
    XSAtomic_IncrementInteger( &x );
    
    XSLog( "%li", ( long )x );
    
    XSAtomic_AddInteger( 42, &x );
    
    XSLog( "%li", ( long )x );
    XSLog( "%li", ( long )XSAtomic_ReadInteger( &x ) );
    
    XSLog( "%lu", ( unsigned long )XSProcess_GetProcessID() );
    XSLog( "%s", XSProcess_GetProcessName() );
    
    {
        XSBooleanRef b;
        XSTLSKey     k;
        
        b = XSBoolean_Create( true );
        
        XSShow( b );
        XSShow( NULL );
        
        XSLog( "%p", b );
        XSThreading_TLSKeyCreate( &k );
        XSThreading_TLSSetObject( &k, b, XSObjectAssociationRetain );
        XSRelease( b );
        XSLog( "%p", XSThreading_TLSGetObject( &k ) );
        XSLog( "%s", XSRuntime_GetDescription( XSThreading_TLSGetObject( &k ) ) );
        XSThreading_TLSSetObject( &k, NULL, XSObjectAssociationRetain );
        XSLog( "%p", XSThreading_TLSGetObject( &k ) );
    }
    
    {
        char * s;
        
        s       = XSAlloc( 2 );
        s[ 0 ]  = 'a';
        
        XSLog( "%s", s );
        XSShow( s );
        
        s       = XSRealloc( s, 3 );
        s[ 1 ]  = 'b';
        
        XSLog( "%s", s );
        XSRelease( s );
    }
    
    {
        XSStringRef str1;
        XSStringRef str2;
        XSRange     r;
        
        str1 = XSString_StringWithCString( "Abcdefg" );
        
        XSShow( str1 );
        XSShow( XSString_LowercaseString( str1 ) );
        XSShow( XSString_UppercaseString( str1 ) );
        
        XSShow( XSString_SubstringWithRange( str1, XSRange_Make( 2, 2 ) ) );
        
        str2 = XSCopy( str1 );
        
        XSShow( XSString_StringByAppendingString( XSSTR( "hello" ), XSSTR( ", world" ) ) );
        
        r = XSString_RangeOfString( str1, XSSTR( "cdefg" ) );
        
        if( r.location == XSNotFound )
        {
            XSLog( "Not found..." );
        }
        else
        {
            XSLog( "%lu %lu", ( unsigned long )( r.location ), ( unsigned long )( r.length ) );
        }
        
        XSLog
        (
            "%i %i",
            XSString_ContainsString( XSSTR( "abc" ), XSSTR( "bc" ) ),
            XSString_ContainsString( XSSTR( "abc" ), XSSTR( "def" ) )
        );
        
        XSShow( XSString_StringWithFormat( "%s %i %p %f", "ok", 42, str1, ( XSFloat )42 ) );
        XSShow( XSString_StringByAppendingFormat( XSSTR( "test" ), " %i", 42 ) );
        
        XSRelease( str2 );
    }
    
    {
        XSStackRef   s1;
        XSStackRef   s2;
        XSBooleanRef b1;
        XSBooleanRef b2;
        XSBooleanRef b3;
        
        s1    = XSStack_Create();
        b1    = XSBoolean_Create( true );
        b2    = XSBoolean_Create( true );
        b3    = XSBoolean_Create( true );
        
        XSStack_Push( s1, b1 );
        XSStack_Push( s1, b2 );
        XSStack_Push( s1, b3 );
        
        s2 = XSCopy( s1 );
        
        XSShow( s2 );
        
        XSLog( "B1: %p",        b1 );
        XSLog( "B2: %p",        b2 );
        XSLog( "B3: %p",        b3 );
        XSLog( "Stack pop: %p", XSStack_Pop( s1 ) );
        XSLog( "Stack pop: %p", XSStack_Pop( s1 ) );
        XSLog( "Stack pop: %p", XSStack_Pop( s1 ) );
        XSLog( "Stack pop: %p", XSStack_Pop( s1 ) );
        XSLog( "Stack pop: %p", XSStack_Pop( s2 ) );
        XSLog( "Stack pop: %p", XSStack_Pop( s2 ) );
        XSLog( "Stack pop: %p", XSStack_Pop( s2 ) );
        XSLog( "Stack pop: %p", XSStack_Pop( s2 ) );
        
        XSRelease( b1 );
        XSRelease( b2 );
        XSRelease( b3 );
        XSRelease( s1 );
        XSRelease( s2 );
    }
    
    {
        XSArrayRef        a1;
        XSMutableArrayRef a2;
        
        a1 = XSArray_ArrayWithObjects( XSSTR( "str1" ), XSSTR( "str2" ), XSSTR( "str3" ), XSSTR( "str4" ), XSSTR( "str5" ), NULL );
        a2 = XSArray_CreateMutableCopy( a1 );
        
        XSArray_AddObject( a2 , XSSTR( "str6" ) );
        XSArray_AddObject( a2 , a1 );
        XSArray_AppendArray( a2, a1 );
        
        XSLog( "Count:       %lu", ( unsigned long )XSArray_GetCount( a2 ) );
        XSLog( "First index: %lu", ( unsigned long )XSArray_GetFirstIndexOfObject( a2, XSSTR( "str2" ) ) );
        XSLog( "Last index:  %lu", ( unsigned long )XSArray_GetLastIndexOfObject( a2, XSSTR( "str2" ) ) );
        
        XSShow( a1 );
        XSShow( a2 );
        
        XSArray_FilterWithFunction( a2, __filterArray );
        XSShow( a2 );
        
        XSArray_InsertObjectAtIndex( a2, 1, XSSTR( "hello, world" ) );
        XSShow( a2 );
        
        XSArray_ReplaceObjectAtIndex( a2, 2, XSSTR( "hello, universe" ) );
        XSShow( a2 );
        
        XSArray_RemoveObjectsInRange( a2, XSRange_Make( 0, 1 ) );
        XSShow( a2 );
        
        XSArray_RemoveAllObjects( a2 );
        XSShow( a2 );
        
        XSRelease( a2 );
        
        a1 = XSArray_ArrayWithObjects( XSSTR( "1" ), XSSTR( "2" ), XSSTR( "3" ), NULL );
        a2 = XSArray_MutableArray();
        
        XSArray_AppendArray( a2, a1 );
        XSShow( a2 );
        XSArray_AppendArray( a2, a1 );
        XSShow( a2 );
    }
    
    {
        XSShow( XSNull_Null() );
        XSShow( XSNull_Null() );
        XSRelease( XSNull_Null() );
    }
    
    {
        XSArrayRef        a1;
        XSMutableArrayRef a2;
        
        a1 = XSArray_ArrayWithObjects
        (
            XSNumber_NumberWithInt( 6 ),
            XSNumber_NumberWithInt( 0 ),
            XSNumber_NumberWithInt( 3 ),
            XSNumber_NumberWithInt( 2 ),
            XSNumber_NumberWithInt( 1 ),
            XSNumber_NumberWithInt( 4 ),
            XSNumber_NumberWithInt( 8 ),
            XSNumber_NumberWithInt( 5 ),
            XSNumber_NumberWithInt( 9 ),
            XSNumber_NumberWithInt( 7 ),
            NULL
        );
        
        a2 = XSArray_CreateMutableCopy( a1 );
        
        XSShow( a2 );
        XSArray_SortWithFunction( a2, &__ArraySort );
        XSShow( a2 );
        XSRelease( a2 );
    }
    
    {
        XSValueRef v1;
        XSValueRef v2;
        XSValueRef v3;
        XSRect     r;
        XSSize     s;
        
        r = XSRect_Make( 0, 0, 42, 42 );
        s = XSSize_Make( 21, 21 );
        
        v1 = XSValue_ValueWithRect( r );
        v2 = XSValue_ValueWithSize( s );
        v3 = XSValue_ValueWithPointer( v1, XSObjectAssociationAssign );
        
        XSShow( v1 );
        XSShow( v2 );
        XSShow( v3 );
    }
    
    {
        XSBooleanRef b;
        int          i;
        
        i = 10;
        b = XSBoolean_Create( true );
        
        while( i-- )
        {
            XSThread_DetachFunctionWithArgument( ( XSThread_FunctionWithArgument )__threadedFunc, b );
        }
        
        XSRelease( b );
    }
    
    XSShow( ap1 );
    XSRelease( ap1 );
    
    sleep( 1 );
    
    return 0;
}


#include "stdafx.h"

int _tmain( int argc, _TCHAR * argv[] )
{
    unsigned int  i;
    XSInteger     arg_int;
    XSUInteger    arg_uint;
    XSString      arg_str;
    XSFloat       arg_float;
    char       ** test;
    XSApplication app;
    XSString      str1;
    XSString      str2;
    XSString      str3;
    XSNumber      num;
    
    app  = XSApplication_Start( argc, ( const char ** )argv );
    
    XSApplication_RegisterArgument( app, "--test",    XSApplicationArgumentTypeFlag,    "A test flag" );
    XSApplication_RegisterArgument( app, "--int",     XSApplicationArgumentTypeInteger, "A test integer" );
    XSApplication_RegisterArgument( app, "--string",  XSApplicationArgumentTypeString,  "A test string" );
    XSApplication_RegisterArgument( app, "--float",   XSApplicationArgumentTypeFloat,   "A test float" );
    XSApplication_RegisterArgument( app, "--uint",    XSApplicationArgumentTypeUnsignedInteger, NULL );
    
    XSApplication_PrintHelp( app, "A test application for the XSFoundation" );
    
    if( XSApplication_GetFlag( app, "--test" ) )
    {
        XSLog( "Has flag argument: test" );
    }
    
    if( ( arg_int = XSApplication_GetInteger( app, "--int" ) ) )
    {
        XSLog( "Has int argument: %i", arg_int );
    }
    
    if( ( arg_uint = XSApplication_GetUnsignedInteger( app, "--uint" ) ) )
    {
        XSLog( "Has uint argument: %u", arg_uint );
    }
    
    if( ( arg_str = XSApplication_GetString( app, "--string" ) ) )
    {
        XSLog( "Has string argument: $@", arg_str );
    }
    
    if( ( arg_float = XSApplication_GetFloat( app, "--float" ) ) )
    {
        XSLog( "Has float argument: %f", arg_float );
    }
    
    test = XSAutoAlloc( 5 * sizeof( char * ) );
    
    for( i = 0; i < 5; i++ )
    {
        test[ i ] = XSAutoAlloc( 2 );
    }
    
    str1 = XSSTR( "hello, world" );
    str2 = XSString_SubstringFromIndex( str1, 5 );
    str3 = XSCopy( str2 );
    num  = XSNumber_InitWithShort( XSNumber_Alloc(), 0x0303 );

    XSLog( "Memory hash: %s", XSHash( test ) );
    XSLog( "Object hash: %s", XSHash( str1 ) );
    XSLog( "%s%s%s", XSString_CString( str1 ), XSString_CString( str2 ), XSString_CString( str3 ) );
    XSLog( "hello, universe: %i $@ %i $@ %i", 42, str1, 43, app, 44 );
    XSLog( "$@", XSAutorelease( XSRuntime_CreateInstanceOfClassWithName( "XSString" ) ) );
    XSLog( "$@", num );
    XSLog( "0x%02x", XSNumber_GetChar( num ) );
    
    XSRelease( str3 );
    XSRelease( num );

    return EXIT_SUCCESS;
}

#include "XS.h"

/*******************************************************************************
 * MyClass.h
 ******************************************************************************/

#undef  XSCurrentClass
#define XSCurrentClass MyClass

XSClassDeclare

XSMethodPrototype( void, SayHelloWorld,     { char * text; }, { text }, char * text );
XSMethodPrototype( void, SayHelloUniverse,  { char * text; }, { text }, char * text );

#undef XSCurrentClass

/*******************************************************************************
 * MyClass.c
 ******************************************************************************/
 
#undef  XSCurrentClass
#define XSCurrentClass MyClass

XSClassDefine

XSPropertiesStart
    
    int x;
    int y;
    
XSPropertiesEnd

XSBinding( void, SayHelloWorld );
XSBinding( void, SayHelloUniverse );

XSClassDefinitions
(
    XSClassConstructor,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
);

XSConstructorStart
    
    XSLog( "MyClass object constructed" );
    
    self->x = 42;
    
XSConstructorEnd

XSMethodImplementationStart
    
    XSMethodDefine( void, SayHelloWorld );

    XSLog( "hello, the world %s", arguments.text );
    XSLog( "x has the value: %u", self->x );

XSMethodImplementationEnd

XSMethodImplementationStart

    XSMethodDefine( void, SayHelloUniverse );

    XSLog( "hello, the universe %s", arguments.text );
    XSLog( "x has the value: %u", self->x );

XSMethodImplementationEnd

#undef XSCurrentClass

/*******************************************************************************
 * main.c
 ******************************************************************************/

XSMainStart( argc, argv )
{
    MyClass o;
    
    RegisterClass( MyClass );
    
    o = XSNew( MyClass );
    
    XSCall_Void( XSRuntime_GetMethod( o, ( char * )"SayHelloWorld" ), MyClass_SayHelloWorld_MakeArgs( o, "is open" ) );
    XSCall_Void( XSRuntime_GetMethod( o, ( char * )"SayHelloUniverse" ), MyClass_SayHelloWorld_MakeArgs( o, "is open" ) );
    
    XSRelease( o );
}
XSMainEnd( EXIT_SUCCESS );

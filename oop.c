#include "XS.h"

/*!
 * @def     __XSConcatName2
 * @brief   ...
 * @param   a   ...
 * @param   b   ...
 */
#define __XSConcatName2( a, b )       a ## b

/*!
 * @def     __XSConcatName3
 * @brief   ...
 * @param   a   ...
 * @param   b   ...
 * @param   c   ...
 */
#define __XSConcatName3( a, b, c )    a ## b ## c

/*!
 * @def     __XSConcatName4
 * @brief   ...
 * @param   a   ...
 * @param   b   ...
 * @param   c   ...
 * @param   d   ...
 */
#define __XSConcatName4( a, b, c, d ) a ## b ## c ## d

#define __XSClassStructName( name )                     __XSConcatName3( __, name, _Struct )
#define __XSClassTypeName( name )                       __XSConcatName2( __, name )
#define __XSClassInfosName( name )                      __XSConcatName3( __, name, Class )
#define __XSClassPropertyName( class )                  __XSConcatName3( __, class, _Properties )
#define __XSClassPropertyStructName( class )            __XSConcatName3( __, class, _Properties_Struct )
#define __XSMethodName( class, name )                   __XSConcatName3( class, _, name )
#define __XSMethodContextName( class, name )            __XSConcatName4( class, _, name, _Context )
#define __XSMethodContextStructName( class, name )      __XSConcatName4( class, _, name, _Context_Struct )
#define __XSMethodArgumentsName( class, name )          __XSConcatName4( class, _, name, _Arguments )
#define __XSMethodArgumentsStructName( class, name )    __XSConcatName4( class, _, name, _Arguments_Struct )
#define __XSMethodMakeArgsName( class, name )           __XSConcatName4( class, _, name, _MakeArgs )
#define __XSMethodMakeArgsLinkName( name )              __XSConcatName2( name, _MakeArgs )
#define __XSMethodLinkerName( class )                   __XSConcatName2( class, _RT_Init )
#define __XSClassAlloc( class )                         __XSConcatName2( class, _Alloc )
#define __XSClassInitialize( class )                    __XSConcatName3( __, class, _Initialize )
#define __XSClassConstructor( class )                   __XSConcatName3( __, class, _Construct )
#define __XSClassDestructor( class )                    __XSConcatName3( __, class, _Destruct )
#define __XSClassInit( class )                          __XSConcatName3( __, class, _Init )
#define __XSClassCopy( class )                          __XSConcatName3( __, class, _Copy )
#define __XSClassToString( class )                      __XSConcatName3( __, class, _ToString )
#define __XSClassEquals( class )                        __XSConcatName3( __, class, _Equals )

/*******************************************************************************
 * Class definition macros
 ******************************************************************************/

#define XSClassDeclare                                                      \
    typedef struct __XSClassStructName( XSCurrentClass ) * XSCurrentClass;

#define XSClassDefine                                                               \
    static XSClassID __classID;                                                     \
                                                                                    \
    void __XSClassConstructor( XSCurrentClass )( XSObject object );                 \
    void __XSClassDestructor( XSCurrentClass )( XSObject object );                  \
    void __XSClassInit( XSCurrentClass )( XSObject object );                        \
    void __XSClassCopy( XSCurrentClass )( XSObject source, XSObject destination );  \
    XSString __XSClassToString( XSCurrentClass )( XSObject object );                \
    BOOL __XSClassEquals( XSCurrentClass )( XSObject object1, XSObject object2 );   \
                                                                                    \
    XSObject __XSClassAlloc( XSCurrentClass )( void );                              \
    XSObject __XSClassAlloc( XSCurrentClass )( void )                               \
    {                                                                               \
        return XSRuntime_CreateInstance( __classID );                               \
    }

#define XSClassCallbacks( construct, destruct, init, copy, toString, equals )   \
    }                                                                           \
    const XSClassInfos __XSClassInfosName( XSCurrentClass ) =                   \
    {                                                                           \
        "",                                                                     \
        sizeof( __XSClassTypeName( XSCurrentClass ) ),                          \
        construct,                                                              \
        destruct,                                                               \
        init,                                                                   \
        copy,                                                                   \
        toString,                                                               \
        equals                                                                  \
    }

#define XSPropertiesStart                                   \
    struct __XSClassStructName( XSCurrentClass )            \
    {                                                       \
        XSRuntimeClass  * __class;

#define XSPropertiesEnd                                                                         \
    };                                                                                          \
    typedef struct __XSClassStructName( XSCurrentClass ) __XSClassTypeName( XSCurrentClass );   \
    extern const XSClassInfos __XSClassInfosName( XSCurrentClass );                             \
    void __XSClassInitialize( XSCurrentClass )( void );                                         \
    void __XSClassInitialize( XSCurrentClass )( void )                                          \
    {                                                                                           \
        __classID = XSRuntime_RegisterClass( &__XSClassInfosName( XSCurrentClass ) );

#define XSBinding( name )

#define XSMethodImplementation( ret, mName )                                                                                        \
    ret __XSMethodName( XSCurrentClass, mName )( void * _context )                                                                  \
    {                                                                                                                               \
        __XSMethodContextName( XSCurrentClass, mName ) * context = ( __XSMethodContextName( XSCurrentClass, mName ) * )_context;    \
        XSCurrentClass self                                      = context->self;

#define XSMethodImplementationEnd }

#define XSClassConstructor  __XSClassConstructor( XSCurrentClass )
#define XSClassDestructor   __XSClassDestructor( XSCurrentClass )
#define XSClassInit         __XSClassInit( XSCurrentClass )
#define XSClassCopy         __XSClassCopy( XSCurrentClass )
#define XSClassToString     __XSClassToString( XSCurrentClass )
#define XSClassEquals       __XSClassEquals( XSCurrentClass )


#define XSNew( class ) 0

/* Adds a member method (and its arguments caster) to a class declaration.
 * It must be placed between XSClassBegin and XSClassEnd.
 */
#define XSClassMember( ret, mName, ... )                                                            \
    void * ( * __XSMethodMakeArgsLinkName( mName ) )( XSCurrentClass, __VA_ARGS__ );                \
    ret ( * mName )( void * )

/* Defines a method prototype for the current class declaration.
 */
#define XSMethodPrototype( ret, mName, mArgs, argNames, ... )                                       \
    typedef struct __XSMethodArgumentsStructName( XSCurrentClass, mName )                           \
    mArgs                                                                                           \
    __XSMethodArgumentsName( XSCurrentClass, mName );                                               \
    typedef struct __XSMethodContextStructName( XSCurrentClass, mName )                             \
    {                                                                                               \
        XSCurrentClass    self;                                                                     \
        __XSMethodArgumentsName( XSCurrentClass, mName ) arguments;                                 \
    }                                                                                               \
    __XSMethodContextName( XSCurrentClass, mName );                                                 \
    void * __XSMethodMakeArgsName( XSCurrentClass, mName )( XSCurrentClass self, __VA_ARGS__ );     \
    void * __XSMethodMakeArgsName( XSCurrentClass, mName )( XSCurrentClass self, __VA_ARGS__ )      \
    {                                                                                               \
        __XSMethodContextName( XSCurrentClass, mName ) * s =                                        \
        ( __XSMethodContextName( XSCurrentClass, mName ) * )                                        \
        calloc( 1, sizeof( __XSMethodContextName( XSCurrentClass, mName ) ) );                      \
        s->self         = self;                                                                     \
        s->arguments    = ( __XSMethodArgumentsName( XSCurrentClass, mName ) )argNames;             \
        return ( void * )s;                                                                         \
    }                                                                                               \
    ret __XSMethodName( XSCurrentClass, mName )( void * _context )

/*******************************************************************************
 * MyClass.h
 ******************************************************************************/

#undef  XSCurrentClass
#define XSCurrentClass MyClass

XSClassDeclare

XSMethodPrototype( void, SayHelloWorld,     { char * text; }, { text }, char * text );
XSMethodPrototype( void, SayHelloUniverse,  { char * text; }, { text }, char * text );

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

XSBinding( SayHelloWorld );
XSBinding( SayHelloUniverse );

XSClassCallbacks
(
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
);

XSMethodImplementation( void, SayHelloWorld )
{
    printf( "hello, the world %s\n", context->arguments.text );
    printf( "x has the value: %u\n", self->x );
}
XSMethodImplementationEnd

XSMethodImplementation( void, SayHelloUniverse )
{
    printf( "hello, the universe %s\n", context->arguments.text );
    printf( "x has the value: %u\n", self->x );
}
XSMethodImplementationEnd

#undef XSCurrentClass

/*******************************************************************************
 * main.c
 ******************************************************************************/

XSMainStart( argc, argv )
{
    MyClass o;
    
    __MyClass_Initialize();
    
    o = XSNew( MyClass );
    
    //XSCall( o, SayHelloUniverse, ( char * )"is open !" );
}
XSMainEnd( EXIT_SUCCESS );

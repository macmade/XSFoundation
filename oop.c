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
#define __XSClassConstructor( class )                   __XSConcatName2( class, _Construct )
#define __XSClassDestructor( class )                    __XSConcatName2( class, _Destruct )
#define __XSClassInit( class )                          __XSConcatName2( class, _Init )
#define __XSClassCopy( class )                          __XSConcatName2( class, _Copy )
#define __XSClassToString( class )                      __XSConcatName2( class, _ToString )
#define __XSClassEquals( class )                        __XSConcatName2( class, _Equals )

#define __XSStringify( x )                              #x
#define __XSExpendStringify( x )                        __XSStringify( x )

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

#define XSClassDefinitions( construct, destruct, init, copy, toString, equals )   \
    }                                                                           \
    const XSClassInfos __XSClassInfosName( XSCurrentClass ) =                   \
    {                                                                           \
        __XSExpendStringify( XSCurrentClass ),                                  \
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

#define XSBinding( name ) XSRuntime_BindMethodToClassID( __classID, ( void ( * )( void ) )__XSMethodName( XSCurrentClass, name ), #name )

#define XSMethodImplementationStart

#define XSMethodDefine( ret, mName )                                                                                                \
    ret __XSMethodName( XSCurrentClass, mName )( void * __context )                                                                 \
    {                                                                                                                               \
        __XSMethodContextName( XSCurrentClass, mName ) * context   = ( __XSMethodContextName( XSCurrentClass, mName ) * )__context; \
        __XSClassTypeName( XSCurrentClass ) * self                 = context->self;                                                 \
        __XSMethodArgumentsName( XSCurrentClass, mName ) arguments = context->arguments;                                            \
        __context                                                  = NULL;                                                          \
        ( void )self;                                                                                                               \
        ( void )arguments;                                                                                                          \
        {

#define XSMethodImplementationEnd }}

#define XSClassConstructor  __XSClassConstructor( XSCurrentClass )
#define XSClassDestructor   __XSClassDestructor( XSCurrentClass )
#define XSClassInit         __XSClassInit( XSCurrentClass )
#define XSClassCopy         __XSClassCopy( XSCurrentClass )
#define XSClassToString     __XSClassToString( XSCurrentClass )
#define XSClassEquals       __XSClassEquals( XSCurrentClass )

#define XSConstructorStart \
    void __XSClassConstructor( XSCurrentClass )( XSObject __self )                                      \
    {                                                                                                   \
        __XSClassTypeName( XSCurrentClass ) * self = ( __XSClassTypeName( XSCurrentClass ) * )__self;   \
        __self                                     = NULL;                                              \
        ( void )self;

#define XSConstructorEnd }

#define XSNew( class ) __XSClassAlloc( class )()

#define RegisterClass( class ) __XSClassInitialize( class )()

#define XSMethodPrototype( ret, mName, mArgs, argNames, ... )                                           \
    typedef struct __XSMethodArgumentsStructName( XSCurrentClass, mName )                               \
    mArgs                                                                                               \
    __XSMethodArgumentsName( XSCurrentClass, mName );                                                   \
    typedef struct __XSMethodContextStructName( XSCurrentClass, mName )                                 \
    {                                                                                                   \
        XSCurrentClass    self;                                                                         \
        __XSMethodArgumentsName( XSCurrentClass, mName ) arguments;                                     \
    }                                                                                                   \
    __XSMethodContextName( XSCurrentClass, mName );                                                     \
    void * __XSMethodMakeArgsName( XSCurrentClass, mName )( XSCurrentClass self, __VA_ARGS__ );         \
    void * __XSMethodMakeArgsName( XSCurrentClass, mName )( XSCurrentClass self, __VA_ARGS__ )          \
    {                                                                                                   \
        __XSMethodArgumentsName( XSCurrentClass, mName ) args = argNames;                               \
        __XSMethodContextName( XSCurrentClass, mName ) * s =                                            \
        ( __XSMethodContextName( XSCurrentClass, mName ) * )                                            \
        XSAlloc( sizeof( __XSMethodContextName( XSCurrentClass, mName ) ) );                            \
        s->self = self;                                                                         \
        memcpy( &( s->arguments ), &args, sizeof( __XSMethodArgumentsName( XSCurrentClass, mName ) ) ); \
        return ( void * )s;                                                                             \
    }                                                                                                   \
    ret __XSMethodName( XSCurrentClass, mName )( void * _context )

/*******************************************************************************
 * Calling functions
 ******************************************************************************/

void __XSCall_Void( XSMethod * method, void * context );
char __XSCall_Char( XSMethod * method, void * context );
short __XSCall_Short( XSMethod * method, void * context );
int __XSCall_Int( XSMethod * method, void * context );
long __XSCall_Long( XSMethod * method, void * context );
long long __XSCall_LongLong( XSMethod * method, void * context );
float __XSCall_Float( XSMethod * method, void * context );
double __XSCall_Double( XSMethod * method, void * context );
void * __XSCall_Pointer( XSMethod * method, void * context );

void __XSCall_Void( XSMethod * method, void * context )
{
    int ( * f )( void * ) = ( int ( * )( void * ) )( method->func );
    
    f( context );
    XSRelease( context );
}

char __XSCall_Char( XSMethod * method, void * context )
{
    char ( * f )( void * ) = ( char ( * )( void * ) )( method->func );
    char result            = f( context );
    
    XSRelease( context );
    
    return result;
}

short __XSCall_Short( XSMethod * method, void * context )
{
    short ( * f )( void * ) = ( short ( * )( void * ) )( method->func );
    short result            = f( context );
    
    XSRelease( context );
    
    return result;
}

int __XSCall_Int( XSMethod * method, void * context )
{
    int ( * f )( void * ) = ( int ( * )( void * ) )( method->func );
    int result            = f( context );
    
    XSRelease( context );
    
    return result;
}

long __XSCall_Long( XSMethod * method, void * context )
{
    long ( * f )( void * ) = ( long ( * )( void * ) )( method->func );
    long result            = f( context );
    
    XSRelease( context );
    
    return result;
}

long long __XSCall_LongLong( XSMethod * method, void * context )
{
    long long ( * f )( void * ) = ( long long ( * )( void * ) )( method->func );
    long long result            = f( context );
    
    XSRelease( context );
    
    return result;
}

float __XSCall_Float( XSMethod * method, void * context )
{
    float ( * f )( void * ) = ( float ( * )( void * ) )( method->func );
    float result            = f( context );
    
    XSRelease( context );
    
    return result;
}

double __XSCall_Double( XSMethod * method, void * context )
{
    double ( * f )( void * ) = ( double ( * )( void * ) )( method->func );
    double result            = f( context );
    
    XSRelease( context );
    
    return result;
}

void * __XSCall_Pointer( XSMethod * method, void * context )
{
    void * ( * f )( void * ) = ( void * ( * )( void * ) )( method->func );
    void * result            = f( context );
    
    XSRelease( context );
    
    return result;
}

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

XSBinding( SayHelloWorld );
XSBinding( SayHelloUniverse );

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

    printf( "hello, the world %s\n", arguments.text );
    printf( "x has the value: %u\n", self->x );

XSMethodImplementationEnd

XSMethodImplementationStart

    XSMethodDefine( void, SayHelloUniverse );

    printf( "hello, the universe %s\n", arguments.text );
    printf( "x has the value: %u\n", self->x );

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
    
    __XSCall_Void( XSRuntime_GetMethod( o, ( char * )"SayHelloWorld" ), MyClass_SayHelloWorld_MakeArgs( o, "is open" ) );
    __XSCall_Void( XSRuntime_GetMethod( o, ( char * )"SayHelloUniverse" ), MyClass_SayHelloWorld_MakeArgs( o, "is open" ) );
    
    XSRelease( o );
    
    //XSCall( o, SayHelloUniverse, ( char * )"is open !" );
}
XSMainEnd( EXIT_SUCCESS );

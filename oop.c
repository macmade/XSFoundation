#include "XS.h"

#include <stdlib.h>

/* Names concatenation macros
 */
#define __XSConcatName2( x, y )                         x ## y
#define __XSConcatName3( x, y, z )                      x ## y ## z
#define __XSConcatName4( x, y, z, s )                   x ## y ## z ## s

/* Macros used to "generate" the names of everything which is in relation with classes.
 */
#define __XSClassStructName( name )                     __XSConcatName3( __, name, _Struct )
#define __XSClassPropName( class )                      __XSConcatName3( __, class, _properties )
#define __XSClassPropStructName( class )                __XSConcatName3( __, class, _properties_Struct )
#define __XSMethodName( class, name )                   __XSConcatName3( class, _, name )
#define __XSMethodContextName( class, name )            __XSConcatName4( class, _, name, _context )
#define __XSMethodContextStructName( class, name )      __XSConcatName4( class, _, name, _context_Struct )
#define __XSMethodArgumentsName( class, name )          __XSConcatName4( class, _, name, _arguments )
#define __XSMethodArgumentsStructName( class, name )    __XSConcatName4( class, _, name, _arguments_Struct )
#define __XSMethodMakeArgsName( class, name )           __XSConcatName4( class, _, name, _makeArgs )
#define __XSMethodMakeArgsLinkName( name )              __XSConcatName2( name, _makeArgs )
#define __XSMethodLinkerName( class )                   __XSConcatName2( class, _RT_Init )

/* The following two are used for nothing at the moment,
 * but I kept them here as a reminder ... ;)
 */
//#define __XSStringify( x )                              #x
//#define __XSExpendStringify( x )                        __XSStringify( x )


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Start of macros for the class definitions
 */

/* Starts a class properties structure.
 * Note: one CANNOT put a ; at the end of XSClassPropBegin.
 */
#define XSClassPropBegin \
     \
    struct __XSClassPropStructName( XSCurrentClass ) {

/* Ends a class properties structure.
 * Note: one should not put a ; at the end of XSClassPropEnd.
 */
#define XSClassPropEnd };


/* Starts a class declaration.
 * Note: one should not put a ; at the end of XSClassBegin.
 */
#define XSClassBegin                                                                                \
    typedef struct __XSClassPropStructName( XSCurrentClass ) * __XSClassPropName( XSCurrentClass ); \
    typedef struct __XSClassStructName( XSCurrentClass ) * XSCurrentClass;                          \
    struct __XSClassStructName( XSCurrentClass )                                                    \
    {                                                                                               \
        __XSClassPropName( XSCurrentClass ) properties;

/* Adds a member method (and its arguments caster) to a class declaration.
 * It must be placed between XSClassBegin and XSClassEnd.
 */
#define XSClassMember( ret, mName, ... )                                                            \
    void * ( * __XSMethodMakeArgsLinkName( mName ) )( XSCurrentClass, __VA_ARGS__ );                \
    ret ( * mName )( void * )

/* Ends a class declaration.
 * Note: one should not put a ; at the end of XSClassEnd.
 */
#define XSClassEnd };


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


/* Defines a method implementation for the current class declaration.
 */
#define XSMethodImplementation( ret, mName )                                                        \
    ret __XSMethodName( XSCurrentClass, mName )( void * _context ) \
    {   \
    __XSMethodContextName( XSCurrentClass, mName ) * context =                                      \
    ( __XSMethodContextName( XSCurrentClass, mName ) * )_context; \
        XSCurrentClass self = context->self;
        
#define XSMethodImplementationEnd free( context ); }
/* Destroys the method context and returns the value.
* (used within a method implementation)
 */
#define XSReturn( val ) \
    XSContextDestroy() \
    return val                                                                 \

/* Gets a property of the objet.
 * (used within a method implementation)
 */
#define XSSelfGet( pName )                                                                          \
    context->self->properties->pName

/* Gets an argument of the method.
 * (used within a method implementation)
 */
#define XSSGetArguments( name )                                                                     \
    context->arguments.name


/* Declares the methods linker for the current class.
 */
#define XSMethodLinker()                                                                            \
    void __XSMethodLinkerName( XSCurrentClass )( XSCurrentClass o );                                \
    void __XSMethodLinkerName( XSCurrentClass )( XSCurrentClass o )

/* Allocates the memory for the properties of the current class.
 * (used within the XSMethodLinker declaration and only if properties have been declared for the class)
 */
#define XSPropAlloc()                                                                               \
    o->properties = ( struct __XSClassPropStructName( XSCurrentClass ) * )                          \
    calloc( 1, sizeof( struct __XSClassPropStructName( XSCurrentClass ) ) )

/* Inits a default value for a property of the class.
 * (used within the XSMethodLinker declaration, only after XSPropAlloc and only if properties have been declared for the class)
 */
#define XSPropInit( pName, val )                                                                    \
    o->properties->pName = val

/* 
 */
#define XSMethodLink( mName )                                                                       \
    o->__XSMethodMakeArgsLinkName( mName )  = __XSMethodMakeArgsName( XSCurrentClass, mName );      \
    o->mName                                = __XSMethodName( XSCurrentClass, mName );

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Start of the macro to be used in the "main" program.
 * Note that these macro makes no check of if something goes wrong ...
 */

#define XSNew( cName, o )                                                                           \
    o = ( cName )calloc( 1, sizeof( struct __XSClassStructName( cName ) ) );                        \
    __XSMethodLinkerName( cName )( o )

#define XSGet( o, pName )                                                                           \
    o->properties->pName

#define XSCall( o, mName, ... )                                                                     \
    o->mName( o->__XSMethodMakeArgsLinkName( mName )( o, __VA_ARGS__ ) )




/* ------------------------------------------------------------------------------------------------------------------ */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Start of a class definition (user code)
 */

/* Defines the name of the Class.
 */
#undef XSCurrentClass
#define XSCurrentClass MyClass

/* Declares of the properties (can be any where in the class definition).
 */
XSClassPropBegin

    /* Here, any type of property could be declared.
     * Note that we are within a structure, so every line MUST be terminated with a ;
     */
    unsigned int x;
    unsigned int y;

XSClassPropEnd

/* Declares the class.
 */
XSClassBegin

    XSClassMember( void, SayHelloUniverse,  char * text );

XSClassEnd

/* Declares the method prototypes and their arguments caster (struct & back-caster)
 */
XSMethodPrototype( void, SayHelloUniverse,  { char * text; }, { text }, char * text );

// Done for the header ... ;)


/* ------------------------------------------------------------------------------------------------------------------ */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Start of a class implementation (user code)
 */

/* User include(s)
 */
#include <stdio.h>

/* Defines the name of the Class.
 */
#undef XSCurrentClass
#define XSCurrentClass MyClass

/* Implements the method SayHelloUniverse with it's body.
 */
XSMethodImplementation( void, SayHelloUniverse )
{
    /* Gets an argument of the method, and a property of the object
     */
    printf( "hello, the universe %s\n", XSSGetArguments( text ) );
    printf( "x has the value: %u\n", XSSelfGet( x ) );
    
    /* The user can do that but it's quite unintuitive.
     */
    printf( "hello, the universe %s\n", context->arguments.text );
    printf( "x has the value: %u\n", context->self->properties->x );
    printf( "x has the value: %u\n", self->properties->x );
    
    //XSReturn( val );  // and this otherwize
}
XSMethodImplementationEnd

/* Declares the methods linker for this the current class.
 */
XSMethodLinker()
{
    XSMethodLink( SayHelloUniverse );
    
    /* This can be placed anywhere in XSMethodLinker, but MUST be placed before XSPropInit()
     * and if can be here only if properties have been declared for the class ...
     * (between XSClassPropBegin and XSClassPropEnd)
     */
    XSPropAlloc();
    
    /* inits the default values of the properties.
     * Note: They can be here only if properties have been declared for the class ...
     */
    XSPropInit( x, 42 );
    XSPropInit( y, 27 );
}

// Done for the implementation ... ;)

/* ------------------------------------------------------------------------------------------------------------------ */

/* This is placed here just to demonstrate that,
 * from this point, XSCurrentClass is no more needed ... ;)
 */
#undef XSCurrentClass


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Start of the "main" program (user code)
 */

#include <stdint.h>

int main( void )
{
    MyClass o;
    
    intptr_t a;
    
    XSNew( MyClass, o );
    
    a = ( intptr_t )o;
    
    /* Calls the method SayHelloUniverse on the object o.
     */
    XSCall( o, SayHelloUniverse, ( char * )"is open !" );
    
    /* (for now)
     * If a user wants to call his method "manually", he can do the following.
     * (which is quite unintuitive)
     */
    o->SayHelloUniverse( o->SayHelloUniverse_makeArgs( o, ( char * )"is open !" ) );
    
    //printf( "%i\n", o->properties.x );
    
    XSCall( ( ( MyClass )a ), SayHelloUniverse, ( char * )"is open !" );
    
    return 0;
}





















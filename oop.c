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


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Start of macros for the class definitions
 */

/* Starts a class properties structure.
 * Note: one CANNOT put a ; at the end of XSClassPropertyBegin.
 */
#define XSClassPropertyBegin                                \
    struct __XSClassPropertyStructName( XSCurrentClass )    \
    {

/* Ends a class properties structure.
 * Note: one should not put a ; at the end of XSClassPropertyEnd.
 */
#define XSClassPropertyEnd };

#define XSClassDefine( XSCurrentClass )                                                                     \
    typedef struct __XSClassPropertyStructName( XSCurrentClass ) * __XSClassPropertyName( XSCurrentClass ); \
    typedef struct __XSClassStructName( XSCurrentClass )         * XSCurrentClass;                          \

/* Starts a class declaration.
 * Note: one should not put a ; at the end of XSClassBegin.
 */
#define XSClassBegin                                        \
    struct __XSClassStructName( XSCurrentClass )            \
    {                                                       \
        __XSClassPropertyName( XSCurrentClass ) properties;
        
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
#define XSMethodImplementation( ret, mName, code )                                                                                  \
    ret __XSMethodName( XSCurrentClass, mName )( void * _context )                                                                  \
    {                                                                                                                               \
        __XSMethodContextName( XSCurrentClass, mName ) * context = ( __XSMethodContextName( XSCurrentClass, mName ) * )_context;    \
        XSCurrentClass self                                      = context->self;                                                   \
        code                                                                                                                        \
    }

/* Declares the methods linker for the current class.
 */
#define XSMethodLinker()                                                                            \
    void __XSMethodLinkerName( XSCurrentClass )( XSCurrentClass o );                                \
    void __XSMethodLinkerName( XSCurrentClass )( XSCurrentClass o )

/* Allocates the memory for the properties of the current class.
 * (used within the XSMethodLinker declaration and only if properties have been declared for the class)
 */
#define XSPropAlloc()                                                                               \
    o->properties = ( struct __XSClassPropertyStructName( XSCurrentClass ) * )                          \
    calloc( 1, sizeof( struct __XSClassPropertyStructName( XSCurrentClass ) ) )

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




/*******************************************************************************
 * MyClass.h
 ******************************************************************************/

#undef  XSCurrentClass
#define XSCurrentClass MyClass

XSClassDefine( XSCurrentClass );

XSMethodPrototype( void, SayHelloUniverse,  { char * text; }, { text }, char * text );

/*******************************************************************************
 * MyClass.c
 ******************************************************************************/
 
#undef  XSCurrentClass
#define XSCurrentClass MyClass

XSClassPropertyBegin

    unsigned int x;
    unsigned int y;

XSClassPropertyEnd

XSClassBegin

    XSClassMember( void, SayHelloUniverse,  char * text );

XSClassEnd

XSMethodImplementation
(
    void,
    SayHelloUniverse,
    {
        printf( "hello, the universe %s\n", context->arguments.text );
        printf( "x has the value: %u\n", self->properties->x );
    }
)

/* Declares the methods linker for this the current class.
 */
XSMethodLinker()
{
    XSMethodLink( SayHelloUniverse );
    
    /* This can be placed anywhere in XSMethodLinker, but MUST be placed before XSPropInit()
     * and if can be here only if properties have been declared for the class ...
     * (between XSClassPropertyBegin and XSClassPropertyEnd)
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

int main( void )
{
    MyClass o;
    
    XSNew( MyClass, o );
    
    XSCall( o, SayHelloUniverse, ( char * )"is open !" );
    
    return 0;
}





















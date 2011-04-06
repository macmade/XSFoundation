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
 * @header      XSRuntime.c
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    ...
 */

#include "XS.h"
#include "__XSMemory.h"

/*!
 * define       __XS_RUNTIME_CLASS_TABLE_SIZE
 * @abstract    Default allocation size for the runtime class table
 */
#define __XS_RUNTIME_CLASS_TABLE_SIZE   1024

/*!
 * define       __XS_RUNTINE_INIT_CHECK
 * @abstract    Checks if the runtime has been initialized
 * @description This macro will produce a fatal error if the runtime has not been initialized.
 */
#define __XS_RUNTINE_INIT_CHECK         if( __inited == NO ) { XSFatalError( "Error: the runtime has not been initialized\n" ) }

/*!
 * @var         __inited
 * @abstract    Whether the XSFoundation runtime has been initialized
 */
static BOOL              __inited = NO;

/*!
 * @var         __class_table
 * @abstract    The runtime class table
 */
static XSRuntimeClass ** __class_table;

/*!
 * @var         __class_size
 * @abstract    The allocated size of the runtime class table
 */
static size_t            __class_size;

/*!
 * @var         __class_count
 * @abstract    The number of registered classes in the runtime class table
 */
static size_t            __class_count;

/* Prototypes for the initialization of the core runtime classes */
void __XSMemoryObject_Initialize( void );
void __XSAutoreleasePool_Initialize( void );
void __XSApplication_Initialize( void );
void __XSApplicationArgument_Initialize( void );
void __XSArray_Initialize( void );
void __XSBag_Initialize( void );
void __XSColor_Initialize( void );
void __XSData_Initialize( void );
void __XSDate_Initialize( void );
void __XSDictionary_Initialize( void );
void __XSError_Initialize( void );
void __XSFile_Initialize( void );
void __XSLock_Initialize( void );
void __XSNumber_Initialize( void );
void __XSSet_Initialize( void );
void __XSString_Initialize( void );
void __XSThread_Initialize( void );
void __XSTimer_Initialize( void );
void __XSTree_Initialize( void );
void __XSURL_Initialize( void );

/*!
 * @function    XSRuntime_Initialize
 * @abstract    Initialize the XSFoundation runtime.
 * @description Do not call this function. Use the XSFOUNDATION_START()
 *              macro instead.
 * @result      void
 */
void XSRuntime_Initialize( void )
{
    __inited = YES;
    
    atexit( XSRuntime_Finalize );
    
    __XSAutoreleasePool_Initialize();
    __XSArray_Initialize();
    __XSApplication_Initialize();
    __XSApplicationArgument_Initialize();
    __XSBag_Initialize();
    __XSColor_Initialize();
    __XSData_Initialize();
    __XSDate_Initialize();
    __XSDictionary_Initialize();
    __XSError_Initialize();
    __XSFile_Initialize();
    __XSLock_Initialize();
    __XSNumber_Initialize();
    __XSSet_Initialize();
    __XSString_Initialize();
    __XSThread_Initialize();
    __XSTimer_Initialize();
    __XSTree_Initialize();
    __XSURL_Initialize();
}

/*!
 * @function    XSRuntime_Finalize
 * @abstract    Finilization the XSFoundation runtime.
 * @description Do not call this function. Use the XSFOUNDATION_END()
 *              macro instead.
 * @result      void
 */
void XSRuntime_Finalize( void )
{
    __inited = NO;
    
    free( __class_table );
}

/*!
 * @function    XSRuntime_RegisterClass
 * @abstract    Registers a class for the runtime
 * @description All runtime classes needs to be registered before the runtime
 *              can use them and create instances.
 *              This function needs to be called once per class,
 *              ie using pthread_once().
 * @param       cls     The class structure to register
 * @result      The runtime type ID for the class
 */
XSTypeID XSRuntime_RegisterClass( const XSRuntimeClass * const cls )
{
    __XS_RUNTINE_INIT_CHECK
    
    if( __class_size == 0 )
    {
        if( NULL == ( __class_table = ( XSRuntimeClass ** )calloc( sizeof( XSRuntimeClass * ), __XS_RUNTIME_CLASS_TABLE_SIZE ) ) )
        {
            fprintf( stderr, "Error: unable to allocate the runtime class table!\n" );
            exit( EXIT_FAILURE );
        }
        
        __class_size += __XS_RUNTIME_CLASS_TABLE_SIZE;
    }
    
    if( __class_count == __class_size )
    {
        if( NULL == ( __class_table = ( XSRuntimeClass ** )realloc( __class_table, sizeof( XSRuntimeClass * ) * ( __XS_RUNTIME_CLASS_TABLE_SIZE + __class_size ) ) ) )
        {
            fprintf( stderr, "Error: unable to re-allocate the runtime class table!\n" );
            exit( EXIT_FAILURE );
        }
        
        __class_size += __XS_RUNTIME_CLASS_TABLE_SIZE;
    }
    
    __class_table[ __class_count ] = ( XSRuntimeClass * )cls;
    
    return ++__class_count;
}

/*!
 * @function    XSRuntime_CreateInstance
 * @abstract    Creates a new instance of a registered class
 * @param       The type ID of the class
 * @param       The size of the object structure for the class
 * @result      The allocated instance
 */
XSTypeRef XSRuntime_CreateInstance( XSTypeID typeID, size_t extraBytes )
{
    XSRuntimeBase  * b;
    XSRuntimeClass * cls;
    size_t           size;
    XSTypeRef      * o;
    
    __XS_RUNTINE_INIT_CHECK
    
    if( typeID > __class_count )
    {
        return NULL;
    }
    
    cls    = __class_table[ typeID - 1 ];
    size   = sizeof( cls ) + extraBytes;
    o      = XSAlloc( size, typeID );
    b      = ( XSRuntimeBase * )o;
    b->isa = cls;
    
    return o;
}

/*!
 * @function    XSRuntime_IsInstance
 * @abstract    Checks whether a pointer is an object instance
 * @param       ptr     The pointer to check
 * @result      True if the pointer represents an instance, otherwise false
 */
BOOL XSRuntime_IsInstance( void * ptr )
{
    __XSMemoryObject * o;
    
    o = __XSMemory_GetMemoryObject( ptr );
    
    if( o->typeID > 0 && XSRuntime_GetClassForTypeID( o->typeID ) != NULL )
    {
        return YES;
    }
    
    return NO;
}

/*!
 * @function    XSRuntime_GetClassForTypeID
 * @abstract    Gets the class structure for a specific type ID
 * @param       The type ID of the class
 * @result      The class corresponding to the type ID
 */
Class XSRuntime_GetClassForTypeID( XSTypeID typeID )
{
    if( typeID > __class_count )
    {
        return NULL;
    }
    
    return ( Class )__class_table[ typeID - 1 ];
}

/*!
 * @function    XSRuntime_GetClassForTypeID
 * @abstract    Gets the type ID for a specific class
 * @param       The class
 * @result      The type ID of the class
 */
XSTypeID XSRuntime_GetTypeIDForClass( Class cls )
{
    XSUInteger       i;
    XSRuntimeClass * _cls;
    
    _cls = ( XSRuntimeClass * )cls;
    
    for( i = 0; i < __class_count; i++ )
    {
        if( __class_table[ i ] == _cls )
        {
            return i + 1;
        }
    }
    
    return 0;
}

/*!
 * @function    XSRuntime_GetClassForObject
 * @abstract    Gets the class for an object
 * @param       object  The object
 * @result      The object's class
 */
Class XSRuntime_GetClassForObject( id object )
{
    if( XSRuntime_IsInstance( object ) == NO )
    {
        return NULL;
    }
    
    return ( ( XSRuntimeBase * )object )->isa;
}

/*!
 * @function    XSRuntime_GetTypeIDForObject
 * @abstract    Gets the class type ID for an object
 * @param       object  The object
 * @result      The class type ID for the object
 */
XSTypeID XSRuntime_GetTypeIDForObject( id object )
{
    if( XSRuntime_IsInstance( object ) == NO )
    {
        return 0;
    }
    
    return XSRuntime_GetTypeIDForClass( XSRuntime_GetClassForObject( object ) );
}

/*!
 * @function    XSRuntime_GetClassNameForObject
 * @abstract    Gets the class name for an object
 * @param       object  The object
 * @result      The name of the class
 */
const char * XSRuntime_GetClassNameForObject( id object )
{
    if( XSRuntime_IsInstance( object ) == NO )
    {
        return NULL;
    }
    
    return ( ( XSRuntimeBase * )object )->isa->className;
}

/*!
 * @function    XSRuntime_IsInstanceOfClass
 * @abstract    Checks whether an object is an instance of a class
 * @param       object  The object
 * @param       cls     The class
 * @result      True if the object is an instance of the class, otherwise false
 */
BOOL XSRuntime_IsInstanceOfClass( id object, Class cls )
{
    if( XSRuntime_IsInstance( object ) == NO )
    {
        return NO;
    }
    
    if( ( ( XSRuntimeBase * )object )->isa == cls )
    {
        return YES;
    }
    
    return NO;
}

/*!
 * @function    XSRuntime_IsInstanceOfClassName
 * @abstract    Checks whether an object is an instance of a class name
 * @param       object  The object
 * @param       name    The name of the class
 * @result      True if the object is an instance of the class name, otherwise false
 */
BOOL XSRuntime_IsInstanceOfClassName( id object, const char * name )
{
    if( XSRuntime_IsInstance( object ) == NO )
    {
        return NO;
    }
    
    if( strcmp( ( ( XSRuntimeBase * )object )->isa->className, name ) == 0 )
    {
        return YES;
    }
    
    return NO;
}
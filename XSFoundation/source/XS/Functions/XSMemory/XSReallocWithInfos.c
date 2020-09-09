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

/*!
 * @file        XSReleaseWithInfos.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSReleaseWithInfos
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSMemory.h>
#include <XS/__private/Functions/XSDebugger.h>
#include <XS/__private/Functions/XSRuntime.h>

XS_EXPORT void * XSReallocWithInfos( const void * memory, XSUInteger bytes, const char * file, int line, const char * func )
{
    XSUInteger         size;
    XSUInteger         oldSize;
    __XSMemoryObject * object;
    __XSMemoryObject * newObject;
    __XSMemoryObject * oldObject;
    
    if( memory == NULL )
    {
        return NULL;
    }
    
    if( bytes == 0 )
    {
        XSRelease( memory );
        
        return NULL;
    }
    
    object    = __XSMemory_GetMemoryObject( memory );
    oldObject = __XSMemory_GetMemoryObject( memory ); /* So the static analyzer doesn't complain about using memory which has been freed... */
    
    __XSDebugger_CheckObjectIntegrity( object );
    
    if( XSRuntime_IsRegisteredClass( object->classID ) )
    {
        XSFatalError( "Trying to reallocate an instance of class %s", XSRuntime_GetClassName( object->classID ) );
    }
    
    oldSize = object->size;
    
    if( oldSize == bytes )
    {
        return ( void * )memory;
    }
    
    size        = bytes + sizeof( __XSMemoryObject ) + __XS_MEMORY_FENCE_SIZE;
    newObject   = realloc( object, size );
    
    if( newObject == NULL )
    {
        XSLogWarning( "Cannot reallocate memory (%lu bytes)", ( unsigned long )bytes );
        
        return NULL;
    }
    
    newObject->size = bytes;
    
    if( bytes > oldSize )
    {
        memset( ( char * )newObject + sizeof( __XSMemoryObject ) + oldSize, 0, bytes - oldSize );
    }
    
    #ifdef DEBUG
    memcpy( &( newObject->fence ), __XSMemory_FenceData, __XS_MEMORY_FENCE_SIZE );
    memcpy( ( char * )newObject + ( size - __XS_MEMORY_FENCE_SIZE ), __XSMemory_FenceData, __XS_MEMORY_FENCE_SIZE );
    #endif
    
    __XSDebugger_UpdateMemoryRecord( oldObject, newObject, file, line, func );
    
    return ( char * )newObject + sizeof( __XSMemoryObject );
}

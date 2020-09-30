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
 * @file        XSReallocWithInfos.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSReallocWithInfos
 */

#include <XS/XS.h>
#include <XS/Private/Functions/Memory.h>
#include <XS/Private/Functions/Runtime.h>
#include <string.h>
#include <stdlib.h>

void * XSReallocWithInfos( const void * memory, size_t bytes, const char * file, int line, const char * func )
{
    size_t           size;
    size_t           oldSize;
    XSMemoryObject * object;
    XSMemoryObject * newObject;

    if( memory == NULL )
    {
        return NULL;
    }

    if( bytes == 0 )
    {
        XSRelease( memory );

        return NULL;
    }

    object = XSGetMemoryObject( memory );

    // TODO
    ( void )file;
    ( void )line;
    ( void )func;
    //__XSDebugger_CheckObjectIntegrity( object );

    if( XSRuntimeIsRegisteredClass( object->classID ) )
    {
        XSFatalError( "Trying to reallocate an instance of class %s", XSRuntimeGetClassName( object->classID ) );
    }

    if( XSAtomicRead64( &( object->retainCount ) ) == -1 )
    {
        XSFatalError( "Trying to reallocate a constant object of class %s", XSRuntimeGetClassName( object->classID ) );
    }

    oldSize = object->size;

    if( oldSize == bytes )
    {
        return ( void * )( ( uintptr_t )memory );
    }

    size      = bytes + sizeof( XSMemoryObject ) + XS_MEMORY_FENCE_SIZE;
    newObject = realloc( object, size );

    if( newObject == NULL )
    {
        XSLogWarning( "Cannot reallocate memory (%llu bytes)", ( unsigned long long )bytes );

        return NULL;
    }

    newObject->size = bytes;

    if( bytes > oldSize )
    {
        memset( ( char * )newObject + sizeof( XSMemoryObject ) + oldSize, 0, bytes - oldSize );
    }

#ifdef DEBUG
    memcpy( &( newObject->fence ), XSMemoryFenceData, XS_MEMORY_FENCE_SIZE );
    memcpy( ( char * )newObject + ( size - XS_MEMORY_FENCE_SIZE ), XSMemoryFenceData, XS_MEMORY_FENCE_SIZE );
#endif

    // TODO
    //__XSDebugger_UpdateMemoryRecord( oldObject, newObject, file, line, func );

    return ( char * )newObject + sizeof( XSMemoryObject );
}

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
 * @file        XSAllocWithInfos.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSAllocWithInfos
 */

#include <XS/XS.h>
#include <XS/Private/Functions/Memory.h>
#include <XS/Private/Functions/Runtime.h>
#include <stdlib.h>
#include <string.h>

void * XSAllocWithInfos( size_t bytes, XSClassID classID, const char * file, int line, const char * func )
{
    if( XSRuntimeIsRegisteredClass( classID ) && XSRuntimeGetInstanceSize( classID ) != bytes )
    {
        XSFatalError(
            "Cannot allocate memory for class ID %lli (%s): requested bytes do not match the class instance size",
            ( long long )classID,
            XSRuntimeGetClassName( classID ) );
    }

    if( XSRuntimeIsRegisteredClass( classID ) && XSRuntimeGetClassType( classID ) == XSClassTypeSingleton )
    {
        XSFatalError(
            "Cannot allocate memory for class ID %lli (%s): class is declared as a singleton",
            ( long long )classID,
            XSRuntimeGetClassName( classID ) );
    }

    {
        size_t           size;
        XSMemoryObject * object;

        size   = bytes + sizeof( XSMemoryObject ) + XS_MEMORY_FENCE_SIZE;
        object = calloc( size, 1 );

        if( object == NULL )
        {
            XSLogWarning( "Cannot allocate memory (%llu bytes)", ( unsigned long long )bytes );

            return NULL;
        }

        object->retainCount = 1;
        object->size        = bytes;
        object->classID     = classID;
        object->allocID     = XSAtomicIncrement64( &XSMemoryAllocID );

#ifdef DEBUG
        memcpy( &( object->fence ), XSMemoryFenceData, XS_MEMORY_FENCE_SIZE );
        memcpy( ( char * )object + ( size - XS_MEMORY_FENCE_SIZE ), XSMemoryFenceData, XS_MEMORY_FENCE_SIZE );
#endif

        // TODO
        ( void )file;
        ( void )line;
        ( void )func;
        //__XSDebugger_NewMemoryRecord( object, file, line, func );

        return ( char * )object + sizeof( XSMemoryObject );
    }
}

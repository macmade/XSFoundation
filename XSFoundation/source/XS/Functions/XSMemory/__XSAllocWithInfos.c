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

/* $Id$ */

/*!
 * @file        __XSAllocWithInfos.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSAllocWithInfos
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSMemory.h>
#include <XS/__private/Functions/XSDebugger.h>
#include <XS/__private/Functions/XSRuntime.h>

void * __XSAllocWithInfos( XSUInteger bytes, XSClassID classID, const char * file, int line, const char * func )
{
    XSUInteger         size;
    __XSMemoryObject * object;
    
    size    = bytes + sizeof( __XSMemoryObject ) + __XS_MEMORY_FENCE_SIZE;
    object  = calloc( size, 1 );
    
    if( object == NULL )
    {
        XSLogWarning( "Cannot allocate memory (%lu bytes)", ( unsigned long )bytes );
        
        return NULL;
    }
    
    object->retainCount = 1;
    object->size        = bytes;
    object->classID     = classID;
    object->allocID     = XSAtomic_IncrementInteger( &__XSMemory_AllocID );
    
    #ifdef DEBUG
    memcpy( &( object->fence ), __XSMemory_FenceData, __XS_MEMORY_FENCE_SIZE );
    memcpy( ( char * )object + ( size - __XS_MEMORY_FENCE_SIZE ), __XSMemory_FenceData, __XS_MEMORY_FENCE_SIZE );
    #endif
    
    __XSDebugger_NewMemoryRecord( object, file, line, func );
    
    return ( char * )object + sizeof( __XSMemoryObject );
}

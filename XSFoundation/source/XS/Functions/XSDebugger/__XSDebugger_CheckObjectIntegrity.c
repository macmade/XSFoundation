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
 * @file        __XSDebugger_CheckObjectIntegrity.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSDebugger_CheckObjectIntegrity
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSDebugger.h>

void __XSDebugger_CheckObjectIntegrity( __XSMemoryObject * object )
{
    #ifndef DEBUG
    
    ( void )object;
    
    return;
    
    #else
    
    if( object == NULL )
    {
        return;
    }
    
    if
    (
           memcmp( object->fence, __XSMemory_FenceData, __XS_MEMORY_FENCE_SIZE ) != 0
        || memcmp( ( char * )object + sizeof( __XSMemoryObject ) + object->size, __XSMemory_FenceData, __XS_MEMORY_FENCE_SIZE ) != 0
    )
    {
        __XSDebugger_Breakpoint( "Heap corruption detected - Invalid checksum for memory object", __XSDebugger_GetMemoryRecord( object ) );
    }
    
    #endif
}

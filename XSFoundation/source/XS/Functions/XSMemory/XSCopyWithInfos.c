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
 * @file        XSCopyWithInfos.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSCopyWithInfos
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSMemory.h>
#include <XS/__private/Functions/XSDebugger.h>
#include <XS/__private/Functions/XSRuntime.h>

void * XSCopyWithInfos( const void * memory, const char * file, int line, const char * func )
{
    __XSMemoryObject      * object;
    void                  * data;
    void                  * copiedData;
    XSClassCallbackCopy     copy;
    
    if( memory == NULL )
    {
        return NULL;
    }
    
    object = __XSMemory_GetMemoryObject( memory );
    
    __XSDebugger_CheckObjectIntegrity( object );
    
    data = XSAllocWithInfos( object->size, object->classID, file, line, func );
    
    if( XSRuntime_IsRegisteredClass( object->classID ) == false )
    {
        memcpy( data, memory, object->size );
        
        return data;
    }
    
    copy = __XSRuntime_GetCopyCallback( object->classID );
    
    if( copy != NULL )
    {
        copiedData = ( void * )copy( memory, data );
        
        if( copiedData == NULL )
        {
            XSRelease( data );
            
            data = NULL;
        }
        else
        {
            data = copiedData;
        }
    }
    else
    {
        memcpy( data, memory, object->size );
    }
    
    return data;
}

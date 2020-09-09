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
 * @file        __XSDebugger_NewMemoryRecord.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSDebugger_NewMemoryRecord
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSDebugger.h>

void __XSDebugger_NewMemoryRecord( __XSMemoryObject * object, const char * file, int line, const char * func )
{
    __XSDebugger_MemoryRecord *          rec;
    __XSDebugger_MemoryRecord *          previous;
    __XSDebugger_MemoryRecord * volatile list;
    
    #ifndef DEBUG
    
    ( void )object;
    ( void )file;
    ( void )line;
    ( void )func;
    ( void )rec;
    ( void )previous;
    ( void )list;
    
    return;
    
    #else
    
    if( object == NULL )
    {
        return;
    }
    
    rec = calloc( sizeof( __XSDebugger_MemoryRecord ), 1 );
    
    if( rec == NULL )
    {
        XSFatalError( "Cannot allocate memory for a memory record" );
    }
    
    previous = __XSDebugger_GetMemoryRecord( object );
    
    if( previous != NULL )
    {
        memcpy( rec, previous, sizeof( __XSDebugger_MemoryRecord ) );
        
        rec->next                = NULL;
        previous->archived       = rec;
        
        previous->freed          = false;
        previous->freeFile       = NULL;
        previous->freeLine       = 0;
        previous->freeFunc       = NULL;
        previous->freeThreadID   = 0;
        
        previous->object         = object;
        previous->data           = object + sizeof( __XSMemoryObject );
        previous->size           = object->size;
        previous->allocID        = object->allocID;
        previous->classID        = object->classID;
        previous->allocFile      = file;
        previous->allocLine      = line;
        previous->allocFunc      = func;
        previous->allocThreadID  = XSThreading_GetCurrentThreadID();
    }
    else
    {
        rec->object         = object;
        rec->data           = object + sizeof( __XSMemoryObject );
        rec->size           = object->size;
        rec->allocID        = object->allocID;
        rec->classID        = object->classID;
        rec->allocFile      = file;
        rec->allocLine      = line;
        rec->allocFunc      = func;
        rec->allocThreadID  = XSThreading_GetCurrentThreadID();
        
        if( XSAtomic_CompareAndSwapPointer( NULL, rec, ( void * volatile * )&__XSDebugger_MemoryRecords ) )
        {
            return;
        }
        
        add:
        
        list = __XSDebugger_MemoryRecords;
        
        while( list != NULL )
        {
            if( XSAtomic_CompareAndSwapPointer( NULL, rec, ( void * volatile * )&( list->next ) ) )
            {
                return;
            }
            
            list = list->next;
        }
        
        goto add;
    }
    
    #endif
}

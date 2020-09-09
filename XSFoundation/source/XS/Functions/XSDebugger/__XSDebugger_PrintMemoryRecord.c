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
 * @file        __XSDebugger_PrintMemoryRecord.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSDebugger_PrintMemoryRecord
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSDebugger.h>

void __XSDebugger_PrintMemoryRecord( __XSDebugger_MemoryRecord * record )
{
    const char * allocFile;
    const char * allocFunc;
    const char * freeFile;
    const char * freeFunc;
    const char * pos1;
    const char * pos2;
    const char * classname;
    
    #ifndef DEBUG
    
    ( void )record;
    ( void )allocFile;
    ( void )allocFunc;
    ( void )freeFile;
    ( void )freeFunc;
    ( void )pos1;
    ( void )pos2;
    ( void )classname;
    
    return;
    
    #else
    
    if( record == NULL || record->object == NULL )
    {
        return;
    }
    
    allocFile = record->allocFile;
    allocFunc = record->allocFunc;
    freeFile  = record->freeFile;
    freeFunc  = record->freeFunc;
    classname = XSRuntime_GetClassName( record->classID );
    
    #ifdef _WIN32
    pos1 = ( allocFile != NULL ) ? strrchr( allocFile, '\\' ) : NULL;
    pos2 = ( freeFile  != NULL ) ? strrchr( freeFile,  '\\' ) : NULL;
    #else
    pos1 = ( allocFile != NULL ) ? strrchr( allocFile, '/' ) : NULL;
    pos2 = ( freeFile  != NULL ) ? strrchr( freeFile, '/' )  : NULL;
    #endif
    
    if( pos1 != NULL ) { allocFile = pos1 + 1; }
    if( pos2 != NULL ) { freeFile  = pos2 + 1; }
    
    fprintf
    (
        stderr,
        "\n"
        "#-------------------------------------------------------------------------------\n"
        "# Memory object ID:      %lu\n"
        "# Class ID:              %lu - %s\n"
        "# Allocation size:       %lu bytes\n"
        "# Data pointer:          %p\n",
        ( unsigned long )( record->allocID ),
        ( unsigned long )( record->classID ),
        ( classname == NULL ) ? "N/A" : classname,
        ( unsigned long )( record->size ),
        record->data
    );
    
    if( allocFile != NULL )
    {
        fprintf
        (
            stderr,
            "# Allocated in file:     %s:%i\n",
            allocFile,
            record->allocLine
        );
    }
    else
    {
        fprintf
        (
            stderr,
            "# Allocated in file:     N/A\n"
        );
    }
    
    fprintf
    (
        stderr,
        "# Allocated in function: %s\n"
        "# Allocated in thread:   %lX\n",
        ( allocFunc == NULL ) ? "N/A" : allocFunc,
        ( unsigned long )( record->allocThreadID )
    );
    
    if( record->freed )
    {
        fprintf
        (
            stderr,
            "# Freed in file:         %s:%i\n"
            "# Freed in function:     %s\n"
            "# Freed in thread:       %lX\n",
            freeFile,
            record->freeLine,
            freeFunc,
            ( unsigned long )( record->freeThreadID )
        );
    }
    else
    {
        fprintf
        (
            stderr,
            "# Freed in file:         N/A\n"
            "# Freed in function:     N/A\n"
            "# Freed in thread:       N/A\n"
        );
    }
    
    fprintf
    (
        stderr,
        "#-------------------------------------------------------------------------------\n"
        "\n"
    );
    
    #endif
}

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
 * @header      XSDebugger.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSDebugger.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_FUNCTIONS_XS_DEBUGGER_H__
#define __XS___PRIVATE_FUNCTIONS_XS_DEBUGGER_H__

#include <XS/XSTypes.h>
#include <XS/__private/Functions/XSMemory.h>

#if defined( __APPLE__ )

#include <execinfo.h>

/*!
 * @define  __XS_DEBUGGER_HAVE_EXECINFO_H
 * @brief   execinfo.h header file is available
 */
#define __XS_DEBUGGER_HAVE_EXECINFO_H

#elif defined( __GLIBC__ ) && defined( HAVE_EXECINFO_H )

#include <execinfo.h>

/*!
 * @define  __XS_DEBUGGER_HAVE_EXECINFO_H
 * @brief   execinfo.h header file is available
 */
#define __XS_DEBUGGER_HAVE_EXECINFO_H

#endif

/*!
 * @typedef     __XSDebugger_MemoryRecord
 * @abstract    Memory record for the debugger
 */
typedef struct __XSDebugger_MemoryRecord_struct
{
    struct __XSDebugger_MemoryRecord_struct * next;            /*! The next record, if any */
    struct __XSDebugger_MemoryRecord_struct * archived;        /*! Archived records which had the same address, if any */
    __XSMemoryObject                        * object;          /*! The memory object */
    void                                    * data;            /*! The user data pointer */
    XSUInteger                                size;            /*! The allocated data size */
    XSInteger                                 allocID;         /*! The allocation ID */
    XSClassID                                 classID;         /*! The class ID (only for allocated instances) */
    XSUInteger                                allocThreadID;   /*! The ID of the thread in which the object was allocated */
    XSUInteger                                freeThreadID;    /*! The ID of the thread in which the object was freed */
    const char                              * allocFile;       /*! The file in which the object was allocated */
    const char                              * freeFile;        /*! The file in which the object was freed */
    const char                              * allocFunc;       /*! The function in which the object was allocated */
    const char                              * freeFunc;        /*! The function in which the object was freed */
    int                                       allocLine;       /*! The line of the file in which the object was allocated */
    int                                       freeLine;        /*! The line of the file in which the object was freed */
    bool                                      freed;           /*! Whether the object has been freed */
    char                                      __pad_0[ 7 ];    /*! Padding */
    
}
__XSDebugger_MemoryRecord;

/*!
 * @var         __XSDebugger_MemoryRecords
 * @abstract    The list of the memory records
 */
XS_EXTERN __XSDebugger_MemoryRecord * volatile __XSDebugger_MemoryRecords;

/*!
 * @var         __XSDebugger_ExitRequested
 * @abstract    Whether exit was requested through the debugger
 */
XS_EXTERN bool __XSDebugger_ExitRequested;

#ifdef _WIN32

/*!
 * @var         __XSDebugger_SEH
 * @abstract    Vectored exception handler
 */
XS_EXTERN PVOID __XSDebugger_SEH;

#endif

/*!
 * @function    __XSDebugger_Initialize
 * @abstract    Initialize the debug system
 */
void __XSDebugger_Initialize( void );

/*!
 * @function    __XSDebugger_NewMemoryRecord
 * @abstract    Creates a new memory record
 * @param       object  The memory object for which to create a record
 * @param       file    The file in which the allocation occured
 * @param       line    The line of the file in which the allocation occured
 * @param       func    The function in which the allocation occured
 */
void __XSDebugger_NewMemoryRecord( __XSMemoryObject * object, const char * file, int line, const char * func );

/*!
 * @function    __XSDebugger_UpdateMemoryRecord
 * @abstract    Updates a memory record (eg. after a reallocation)
 * @param       oldObject   The address of the old memory object
 * @param       newObject   The new memory object
 * @param       file        The file in which the reallocation occured
 * @param       line        The line of the file in which the reallocation occured
 * @param       func        The function in which the reallocation occured
 */
void __XSDebugger_UpdateMemoryRecord( void * oldObject, __XSMemoryObject * newObject, const char * file, int line, const char * func );

/*!
 * @function    __XSDebugger_ReleaseMemoryRecord
 * @abstract    Informs the debugger that an memory object has been released
 * @param       object      The memory object that has been released
 * @param       markAsFreed Whether the memory object has been freed
 * @param       file        The file in which the release occured
 * @param       line        The line of the file in which the release occured
 * @param       func        The function in which the release occured
 */
void __XSDebugger_ReleaseMemoryRecord( __XSMemoryObject * object, bool markAsFreed, const char * file, int line, const char * func );

/*!
 * @function    __XSDebugger_GetMemoryRecord
 * @abstract    Gets the memory record associated to a memory object
 * @param       object      The memory object
 * @return      The memory record
 */
__XSDebugger_MemoryRecord * __XSDebugger_GetMemoryRecord( __XSMemoryObject * object );

/*!
 * @function    __XSDebugger_CheckObjectIntegrity
 * @abstract    Checks for buffer overflows/underflows
 * @param       object      The memory object to check
 */
void __XSDebugger_CheckObjectIntegrity( __XSMemoryObject * object );

#ifdef _WIN32

/*!
 * @function    __XSDebugger_ErrorHandler
 * @abstract    Vectored exception handler
 * @param       exceptionInfo   The vectored exception info pointer
 */
LONG CALLBACK __XSDebugger_ErrorHandler( _In_ PEXCEPTION_POINTERS exceptionInfo );

#else

/*!
 * @function    __XSDebugger_ErrorHandler
 * @abstract    Signal handler
 * @param       sig         The signal number
 */
void __XSDebugger_ErrorHandler( int sig );

#endif

/*!
 * @function    __XSDebugger_Breakpoint
 * @abstract    Issues a debugger breakpoint
 * @param       message     The warning message
 * @param       record      The memory record involved, if any
 * @discussion  In debug mode, this will show the debug console.
 *              In release mode, the program will just continue normal execution.
 */
void __XSDebugger_Breakpoint( const char * message, __XSDebugger_MemoryRecord * record );

/*!
 * @function    __XSDebugger_PrintMemoryRecord
 * @abstract    Prints a memory record
 * @param       record      The memory record to print
 */
void __XSDebugger_PrintMemoryRecord( __XSDebugger_MemoryRecord * record );

/*!
 * @function    __XSDebugger_DumpMemoryRecord
 * @abstract    Dumps a memory record
 * @param       record      The memory record to dump
 */
void __XSDebugger_DumpMemoryRecord( __XSDebugger_MemoryRecord * record );

/*!
 * @function    __XSDebugger_PrintBacktrace
 * @abstract    Prints the current backtrace
 */
void __XSDebugger_PrintBacktrace( void );

/*!
 * @function    __XSDebugger_Exit
 * @abstract    XSDebugger finalizer function
 */
void __XSDebugger_Exit( void );

#endif /* __XS___PRIVATE_FUNCTIONS_XS_DEBUGGER_H__ */

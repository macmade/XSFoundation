/*******************************************************************************
 * XSFoundation - XEOS C Foundation Library
 * 
 * Copyright (c) 2010-2014, Jean-David Gadina - www.xs-labs.com
 * All rights reserved.
 * 
 * XEOS Software License - Version 1.0 - December 21, 2012
 * 
 * Permission is hereby granted, free of charge, to any person or organisation
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to deal in the Software, with or without
 * modification, without restriction, including without limitation the rights
 * to use, execute, display, copy, reproduce, transmit, publish, distribute,
 * modify, merge, prepare derivative works of the Software, and to permit
 * third-parties to whom the Software is furnished to do so, all subject to the
 * following conditions:
 * 
 *      1.  Redistributions of source code, in whole or in part, must retain the
 *          above copyright notice and this entire statement, including the
 *          above license grant, this restriction and the following disclaimer.
 * 
 *      2.  Redistributions in binary form must reproduce the above copyright
 *          notice and this entire statement, including the above license grant,
 *          this restriction and the following disclaimer in the documentation
 *          and/or other materials provided with the distribution, unless the
 *          Software is distributed by the copyright owner as a library.
 *          A "library" means a collection of software functions and/or data
 *          prepared so as to be conveniently linked with application programs
 *          (which use some of those functions and data) to form executables.
 * 
 *      3.  The Software, or any substancial portion of the Software shall not
 *          be combined, included, derived, or linked (statically or
 *          dynamically) with software or libraries licensed under the terms
 *          of any GNU software license, including, but not limited to, the GNU
 *          General Public License (GNU/GPL) or the GNU Lesser General Public
 *          License (GNU/LGPL).
 * 
 *      4.  All advertising materials mentioning features or use of this
 *          software must display an acknowledgement stating that the product
 *          includes software developed by the copyright owner.
 * 
 *      5.  Neither the name of the copyright owner nor the names of its
 *          contributors may be used to endorse or promote products derived from
 *          this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT OWNER AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE, TITLE AND NON-INFRINGEMENT ARE DISCLAIMED.
 * 
 * IN NO EVENT SHALL THE COPYRIGHT OWNER, CONTRIBUTORS OR ANYONE DISTRIBUTING
 * THE SOFTWARE BE LIABLE FOR ANY CLAIM, DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN ACTION OF CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/* $Id$ */

/*!
 * @header      XSDebugger.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSDebugger.h
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
 * @def     __XS_DEBUGGER_HAVE_EXECINFO_H
 * @brief   execinfo.h header file is available
 */
#define __XS_DEBUGGER_HAVE_EXECINFO_H

#elif defined( __GLIBC__ ) && defined( HAVE_EXECINFO_H )

#include <execinfo.h>

/*!
 * @def     __XS_DEBUGGER_HAVE_EXECINFO_H
 * @brief   execinfo.h header file is available
 */
#define __XS_DEBUGGER_HAVE_EXECINFO_H

#endif

/*!
 * @typedef     __XSDebugger_MemoryRecord
 * @abstract    Memory record for the memory debugger
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

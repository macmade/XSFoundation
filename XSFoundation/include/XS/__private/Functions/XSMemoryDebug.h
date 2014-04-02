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
 * @header      XSMemoryDebug.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSMemoryDebug.h
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_FUNCTIONS_XS_MEMORY_DEBUG_H__
#define __XS___PRIVATE_FUNCTIONS_XS_MEMORY_DEBUG_H__

#include <XS/XSTypes.h>
#include <XS/__private/Functions/XSMemory.h>

/*!
 * @typedef     __XSMemoryDebug_Record
 * @abstract    Memory record for the memory debugger
 */
typedef struct __XSMemoryDebug_Record_Struct
{
    struct __XSMemoryDebug_Record_Struct * next;            /*! The next record, if any */
    __XSMemoryObject                     * object;          /*! The memory object */
    void                                 * data;            /*! The user data pointer */
    const char                           * allocFile;       /*! The file in which the object was allocated */
    const char                           * freeFile;        /*! The file in which the object was freed */
    const char                           * allocFunc;       /*! The function in which the object was allocated */
    const char                           * freeFunc;        /*! The function in which the object was freed */
    int                                    allocLine;       /*! The line of the file in which the object was allocated */
    int                                    freeLine;        /*! The line of the file in which the object was freed */
    bool                                   freed;           /*! Whether the object has been freed */
    char                                   __pad_0[ 7 ];    /*! Padding */
    
}
__XSMemoryDebug_Record;

/*!
 * @var         __XSMemoryDebug_Records
 * @abstract    The list of the memory records
 */
XS_EXTERN __XSMemoryDebug_Record * volatile __XSMemoryDebug_Records;

/*!
 * @function    __XSMemoryDebug_NewRecord
 * @abstract    Creates a new memory record
 * @param       object  The memory object for which to create a record
 * @param       file    The file in which the allocation occured
 * @param       line    The line of the file in which the allocation occured
 * @param       func    The function in which the allocation occured
 */
void __XSMemoryDebug_NewRecord( __XSMemoryObject * object, const char * file, int line, const char * func );

/*!
 * @function    __XSMemoryDebug_UpdateRecord
 * @abstract    Updates a memory record (eg. after a reallocation)
 * @param       oldObject   The address of the old memory object
 * @param       newObject   The new memory object
 * @param       file        The file in which the reallocation occured
 * @param       line        The line of the file in which the reallocation occured
 * @param       func        The function in which the reallocation occured
 */
void __XSMemoryDebug_UpdateRecord( void * oldObject, __XSMemoryObject * newObject, const char * file, int line, const char * func );

/*!
 * @function    __XSMemoryDebug_ReleaseRecord
 * @abstract    Informs the debugger that an memory object has been released
 * @param       object      The memory object that has been released
 * @param       markAsFreed Whether the memory object has been freed
 * @param       file        The file in which the release occured
 * @param       line        The line of the file in which the release occured
 * @param       func        The function in which the release occured
 */
void __XSMemoryDebug_ReleaseRecord( __XSMemoryObject * object, bool markAsFreed, const char * file, int line, const char * func );

/*!
 * @function    __XSMemoryDebug_GetRecord
 * @abstract    Gets the memory record associated to a memory object
 * @param       object      The memory object
 * @return      The memory record
 */
__XSMemoryDebug_Record * __XSMemoryDebug_GetRecord( __XSMemoryObject * object );

/*!
 * @function    __XSMemoryDebug_CheckObjectIntegrity
 * @abstract    Checks for buffer overflows/underflows
 * @param       object      The memory object to check
 */
void __XSMemoryDebug_CheckObjectIntegrity( __XSMemoryObject * object );

/*!
 * @function    __XSMemoryDebug_Exit
 * @abstract    XSMemoryDebug finalizer function
 */
void __XSMemoryDebug_Exit( void );

#endif /* __XS___PRIVATE_FUNCTIONS_XS_MEMORY_DEBUG_H__ */

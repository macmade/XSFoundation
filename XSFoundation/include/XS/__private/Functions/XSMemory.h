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
 * @header      XSMemory.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSMemory.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_FUNCTIONS_XS_MEMORY_H__
#define __XS___PRIVATE_FUNCTIONS_XS_MEMORY_H__

#include <XS/XSTypes.h>

/*!
 * @typedef     __XS_MEMORY_FENCE_SIZE
 * @abstract    The size of the memory fence to prevent overflows
 */
#ifdef DEBUG
#define __XS_MEMORY_FENCE_SIZE  16
#else
#define __XS_MEMORY_FENCE_SIZE  0
#endif

/*!
 * @typedef     __XSMemoryObject
 * @abstract    Memory object type
 */
typedef struct
{
    volatile XSInteger  retainCount;                        /*! The object's retain count */
    XSUInteger          size;                               /*! The allocated data size */
    XSInteger           allocID;                            /*! The allocation ID */
    XSClassID           classID;                            /*! The class ID (only for allocated instances) */
    #ifdef DEBUG
    unsigned char       fence[ __XS_MEMORY_FENCE_SIZE ];    /*! Memory fence to prevent overflows (DEBUG builds only) */
    #endif
}
__XSMemoryObject;

/*!
 * @typedef     __XSMemoryAllocID
 * @abstract    The current allocation ID
 */
XS_EXTERN volatile XSInteger __XSMemory_AllocID;

#ifdef DEBUG

/*!
 * @typedef     __XSMemoryFenceData
 * @abstract    The memory fence data
 */
XS_EXTERN const char __XSMemory_FenceData[ __XS_MEMORY_FENCE_SIZE ];

#endif


/*!
 * @function    __XSMemory_GetMemoryObject
 * @abstract    Gets the memory object for a pointer
 * @param       ptr     The pointer for which to get the memory object
 * @return      The memory object
 */
__XSMemoryObject * __XSMemory_GetMemoryObject( void * ptr );

/*!
 * @function    __XSAllocWithInfos
 * @abstract    Allocates memory
 * @param       bytes       The number of bytes to allocate
 * @param       classID     The class ID, if any
 * @param       file        The file in which the allocation occurs
 * @param       line        The line number of the file in which the allocation occurs
 * @param       func        The function in which the allocation occurs
 * @return      The allocated memory, or NULL
 */
void * __XSAllocWithInfos( XSUInteger bytes, XSClassID classID, const char * file, int line, const char * func );

/*!
 * @function    __XSReleaseWithInfos
 * @abstract    Releases memory data
 * @param       memory      The memory data to release
 * @param       file        The file in which the release occurs
 * @param       line        The line number of the file in which the release occurs
 * @param       func        The function in which the release occurs
 */
void __XSReleaseWithInfos( void * memory, const char * file, int line, const char * func );

#endif /* __XS___PRIVATE_FUNCTIONS_XS_MEMORY_H__ */

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
 * @abstract    XSFoundation memory allocation functions
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_FUNCTIONS_XS_MEMORY_H__
#define __XS_FUNCTIONS_XS_MEMORY_H__

XS_EXTERN_C_BEGIN

#include <XS/XSTypes.h>

/*!
 * @def         XSAlloc
 * @abstract    Allocates memory
 * @param       _bytes_     The number of bytes to allocate
 * @return      The allocated memory, or NULL
 */
#define XSAlloc( _bytes_ )      XSAllocWithInfos( _bytes_, 0, __FILE__, __LINE__, __func__ )

/*!
 * @def         XSAutoAlloc
 * @abstract    Allocates memory which will be automatically released
 * @param       _bytes_     The number of bytes to allocate
 * @discussion  The memory data will be placed in the instance of the current
 *              auto-release pool, and will be released the next time
 *              the auto-release pool is drained.
 * @return      The allocated memory, or NULL
 */
#define XSAutoAlloc( _bytes_ )  XSAutoAllocWithInfos( _bytes_, 0, __FILE__, __LINE__, __func__ )

/*!
 * @def         XSRelease
 * @abstract    Releases memory data
 * @param       _memory_    The memory data to release
 * @discussion  Memory may be freed if the retain count for the memory
 *              data reaches 0.
 */
#define XSRelease( _memory_ )   XSReleaseWithInfos( _memory_, __FILE__, __LINE__, __func__ )

/*!
 * @def         XSCopy
 * @abstract    Copies an object
 * @param       _memory_    The object to copy 
 * @return      The copy of the object
 */
#define XSCopy( _memory_ )      XSCopyWithInfos( _memory_, __FILE__, __LINE__, __func__ )

/*!
 * @function    XSAllocWithInfos
 * @abstract    Allocates memory
 * @param       bytes       The number of bytes to allocate
 * @param       classID     The class ID, if any
 * @param       file        The file in which the allocation occurs
 * @param       line        The line number of the file in which the allocation occurs
 * @param       func        The function in which the allocation occurs
 * @discussion  Do not use this function directly. Use the XSAlloc macro
 *              instead.
 * @return      The allocated memory, or NULL
 */
XS_EXPORT void * XSAllocWithInfos( XSSize bytes, XSClassID classID, const char * file, int line, const char * func );

/*!
 * @function    XSAutoAllocWithInfos
 * @abstract    Allocates memory which will be automatically released
 * @param       bytes       The number of bytes to allocate
 * @param       classID     The class ID, if any
 * @param       file        The file in which the allocation occurs
 * @param       line        The line number of the file in which the allocation occurs
 * @param       func        The function in which the allocation occurs
 * @discussion  Do not use this function directly. Use the XSAutoAlloc macro
 *              instead.
 * @return      The allocated memory, or NULL
 */
XS_EXPORT void * XSAutoAllocWithInfos( XSSize bytes, XSClassID classID, const char * file, int line, const char * func );

/*!
 * @function    XSRetainWithInfos
 * @abstract    Retains memory data
 * @param       memory      The memory data to retain
 * @return      The memory data
 */
XS_EXPORT void * XSRetain( void * memory );

/*!
 * @function    XSReleaseWithInfos
 * @abstract    Releases memory data
 * @param       memory      The memory data to release
 * @param       file        The file in which the allocation occurs
 * @param       line        The line number of the file in which the allocation occurs
 * @param       func        The function in which the allocation occurs
 * @discussion  Do not use this function directly. Use the XSRelease macro
 *              instead.
 */
XS_EXPORT void XSReleaseWithInfos( void * memory, const char * file, int line, const char * func );

/*!
 * @function    XSAutorelease
 * @abstract    Auto-releases memory data
 * @param       memory      The memory data to release
 * @discussion  The memory data will be placed in the instance of the current
 *              auto-release pool, and will be released the next time
 *              the auto-release pool is drained.
 * @return      The memory data
 */
XS_EXPORT void * XSAutorelease( void * memory );

/*!
 * @function    XSEquals
 * @abstract    Checks whether two objects are equals
 * @param       memory1     The first object to compare
 * @param       memory2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
XS_EXPORT bool XSEquals( void * memory1, void * memory2 );

/*!
 * @function    XSCopy
 * @abstract    Copies an object
 * @param       memory      The object to copy
 * @param       file        The file in which the allocation occurs
 * @param       line        The line number of the file in which the allocation occurs
 * @param       func        The function in which the allocation occurs
 * @discussion  Do not use this function directly. Use the XSCopy macro
 *              instead.
 * @return      The copy of the object
 */
XS_EXPORT XSObjectRef XSCopyWithInfos( void * memory, const char * file, int line, const char * func );

XS_EXTERN_C_END

#endif /* __XS_FUNCTIONS_XS_MEMORY_H__ */

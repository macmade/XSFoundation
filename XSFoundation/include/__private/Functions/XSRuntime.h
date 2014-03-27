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
 * @header      XSRuntime.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSRuntime.h
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_FUNCTIONS_XS_RUNTIME_H__
#define __XS___PRIVATE_FUNCTIONS_XS_RUNTIME_H__

#include <XS/XSTypes.h>

/*!
 * @typedef     __XSRuntime_InitStatus
 * @abstract    Initialization status of the XSFoundation runtime
 */
typedef enum
{
    __XSRuntime_InitStatusNotInited     = 0x00, /*! XSFoundation runtime not inited */
    __XSRuntime_InitStatusInited        = 0x01, /*! XSFoundation runtime inited */
    __XSRuntime_InitStatusInitializing  = 0x02, /*! XSFoundation runtime initializing */
    __XSRuntime_InitStatusFinalizing    = 0x03  /*! XSFoundation runtime finalizing */
}
__XSRuntime_InitStatus;

/*!
 * @typedef     __XSRuntime_ClassInfoList
 * @abstract    Linked list for the XSFoundation class infos
 */
typedef struct __XSRuntime_ClassInfoList_Struct
{
    const XSClassInfo                       * info;
    struct __XSRuntime_ClassInfoList_Struct * next;
}
__XSRuntime_ClassInfoList;

/*!
 * @def         __XS_RUNTIME_IS_INITED
 * @abstract    Checks whether the XSFoundation runtime is inited
 */
#define __XS_RUNTIME_IS_INITED      XSAtomic_CompareAndSwap32( __XSRuntime_InitStatusInited,     __XSRuntime_InitStatusInited,     ( volatile XSInt32 * )&__XSRuntime_Inited )

/*!
 * @def         __XS_RUNTIME_IS_INITED
 * @abstract    Checks whether the XSFoundation runtime is finalizing
 */
#define __XS_RUNTIME_IS_FINALIZING  XSAtomic_CompareAndSwap32( __XSRuntime_InitStatusFinalizing, __XSRuntime_InitStatusFinalizing, ( volatile XSInt32 * )&__XSRuntime_Inited )

/*!
 * @var         __XSRuntime_Inited
 * @abstract    XSFoundation runtime initialization status
 * @see         __XSRuntime_InitStatus
 */
XS_EXTERN volatile XSUInt32 __XSRuntime_Inited;

/*!
 * @var         __XSRuntime_ClassInfoList
 * @abstract    Registered XSFoundation runtime class infos
 */
XS_EXTERN __XSRuntime_ClassInfoList * __XSRuntime_Classes;

/*!
 * @var         __XSRuntime_Inited
 * @abstract    Number of registered XSFoundation runtime class infos
 */
XS_EXTERN volatile XSUInt32 __XSRuntime_ClassCount;

/*!
 * @var         __XSRuntime_GetClassInfo
 * @abstract    Gets the class info for a class ID
 * @param       classID     The class ID
 * @return      The class info
 */
const XSClassInfo * __XSRuntime_GetClassInfo( XSClassID classID );

/*!
 * @var         __XSRuntime_GetInstanceSize
 * @abstract    Gets the instance site for a class ID
 * @param       classID     The class ID
 * @return      The instance size
 */
XSUInteger __XSRuntime_GetInstanceSize( XSClassID classID );

/*!
 * @var         __XSRuntime_GetConstructorCallback
 * @abstract    Gets the constructor callback for a class ID
 * @param       classID     The class ID
 * @return      The copy callback
 */
XSClassInfoConstructorCallback __XSRuntime_GetConstructorCallback( XSClassID classID );

/*!
 * @var         __XSRuntime_GetDestructorCallback
 * @abstract    Gets the destructor callback for a class ID
 * @param       classID     The class ID
 * @return      The destructor callback
 */
XSClassInfoDestructorCallback __XSRuntime_GetDestructorCallback( XSClassID classID );

/*!
 * @var         __XSRuntime_GetCopyCallback
 * @abstract    Gets the copy callback for a class ID
 * @param       classID     The class ID
 * @return      The copy callback
 */
XSClassInfoCopyCallback __XSRuntime_GetCopyCallback( XSClassID classID );

/*!
 * @var         __XSRuntime_GetEqualsCallback
 * @abstract    Gets the equals callback for a class ID
 * @param       classID     The class ID
 * @return      The equals callback
 */
XSClassInfoEqualsCallback __XSRuntime_GetEqualsCallback( XSClassID classID );

/*!
 * @var         __XSRuntime_GetToStringCallback
 * @abstract    Gets the to-string callback for a class ID
 * @param       classID     The class ID
 * @return      The to-string callback
 */
XSClassInfoToStringCallback __XSRuntime_GetToStringCallback( XSClassID classID );

void __XSRuntime_Finalize( void );

#endif /* __XS___PRIVATE_FUNCTIONS_XS_RUNTIME_H__ */

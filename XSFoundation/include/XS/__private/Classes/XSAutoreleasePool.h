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
 * @header      XSAutoreleasePool.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSAutoreleasePool.h
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_AUTORELEASE_POOL_H__
#define __XS___PRIVATE_CLASSES_XS_AUTORELEASE_POOL_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @struct      __XSAutoreleasePool_List
 * @abstract    Autorelease pool list
 */
typedef struct __XSAutoreleasePool_ListStruct
{
    XSAutoreleasePoolRef                    ap;
    struct __XSAutoreleasePool_ListStruct * next;
}
__XSAutoreleasePool_List;

/*!
 * @typedef     __XSAutoreleasePool_Value
 * @abstract    Autorelease pool value holder
 */
typedef struct __XSAutoreleasePool_ValueStruct
{
    XSObjectRef                              object;    /*! The contained object */
    struct __XSAutoreleasePool_ValueStruct * next;      /*! The next value */
}
__XSAutoreleasePool_Value;

/*!
 * @struct      __XSAutoreleasePool
 * @abstract    Structure for XSAutoreleasePool
 */
struct __XSAutoreleasePool
{
    __XSAutoreleasePool_Value * first;    /* The first value */
    XSUInteger                  threadID; /*! The ID of the thread the autorelease pool belongs to */
};

/*!
 * @var         __XSAutoreleasePool_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSAutoreleasePool_ClassID;

/*!
 * @var         __XSAutoreleasePool_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSAutoreleasePool_Class;

/*!
 * @var         __XSAutoreleasePool_TLSKey
 * @abstract    The TLS key for autorelease pools
 */
XS_EXTERN XSTLSKey __XSAutoreleasePool_TLSKey;

/*!
 * @function    __XSAutoreleasePool_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSAutoreleasePool_Initialize( void );

/*!
 * @function    __XSAutoreleasePool_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSAutoreleasePoolRef __XSAutoreleasePool_Constructor( XSAutoreleasePoolRef object );

/*!
 * @function    __XSAutoreleasePool_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSAutoreleasePool_Destructor( XSAutoreleasePoolRef object );

/*!
 * @function    __XSAutoreleasePool_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSAutoreleasePoolRef __XSAutoreleasePool_Copy( XSAutoreleasePoolRef source, XSAutoreleasePoolRef destination );

/*!
 * @function    __XSAutoreleasePool_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSAutoreleasePool_Equals( XSAutoreleasePoolRef object1, XSAutoreleasePoolRef object2 );

/*!
 * @function    __XSAutoreleasePool_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSAutoreleasePool_ToString( XSAutoreleasePoolRef object );

/*!
 * @function    __XSAutoreleasePool_Create
 * @abstract    Creates an XSAutoreleasePool object
 * @return      The XSAutoreleasePool object
 */
XSStatic XSAutoreleasePoolRef __XSAutoreleasePool_Create( void );

/*!
 * @function    __XSAutoreleasePool_Exit
 * @abstract    Class finalizer
 */
void __XSAutoreleasePool_Exit( void );

/*!
 * @function    __XSAutoreleasePool_Register
 * @abstract    Registers an autorelease pool in the current thread
 * @param       ap          The autorelease pool
 */
void __XSAutoreleasePool_Register( XSAutoreleasePoolRef ap );

/*!
 * @function    __XSAutoreleasePool_Unregister
 * @abstract    Unregisters an autorelease pool in the current thread
 * @param       ap          The autorelease pool
 */
void __XSAutoreleasePool_Unregister( XSAutoreleasePoolRef ap );

/*!
 * @function    __XSAutoreleasePool_GetCurrent
 * @abstract    Gets the current autorepease pool for the current thread
 * @return      The current autorelease pool, if one exists
 */
XSAutoreleasePoolRef __XSAutoreleasePool_GetCurrent( void );

#endif /* __XS___PRIVATE_CLASSES_XS_AUTORELEASE_POOL_H__ */

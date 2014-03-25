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
 * @header      XSError.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSError.h
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_ERROR_H__
#define __XS___PRIVATE_CLASSES_XS_ERROR_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @struct      __XSError
 * @abstract    Structure for XSError
 */
struct __XSError
{
    void * temp; /*! Not yet implemented... */
};

/*!
 * @var         __XSError_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSError_ClassID;

/*!
 * @var         __XSError_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSError_Class;

/*!
 * @function    __XSError_Initialize
 * @abstract    Class initializer
 */
void XSStatic __XSError_Initialize( void );

/*!
 * @function    __XSError_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 */
void __XSError_Constructor( XSErrorRef object );

/*!
 * @function    __XSError_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSError_Destructor( XSErrorRef object );

/*!
 * @function    __XSError_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 */
void __XSError_Copy( XSErrorRef source, XSErrorRef destination );

/*!
 * @function    __XSError_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @result      True if both objects are equals, otherwise false
 */
bool __XSError_Equals( XSErrorRef object1, XSErrorRef object2 );

/*!
 * @function    __XSError_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSError_ToString( XSErrorRef object );

#endif /* __XS___PRIVATE_CLASSES_XS_ERROR_H__ */

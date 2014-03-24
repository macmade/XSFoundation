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
 * @file        XSRuntime_Initialize.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSRuntime_Initialize
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSRuntime.h>

/* Private class initializers */
void XSStatic __XSApplication_Initialize( void );
void XSStatic __XSApplicationArgument_Initialize( void );
void XSStatic __XSArray_Initialize( void );
void XSStatic __XSAutoreleasePool_Initialize( void );
void XSStatic __XSBag_Initialize( void );
void XSStatic __XSBinaryTree_Initialize( void );
void XSStatic __XSBoolean_Initialize( void );
void XSStatic __XSColor_Initialize( void );
void XSStatic __XSData_Initialize( void );
void XSStatic __XSDictionary_Initialize( void );
void XSStatic __XSError_Initialize( void );
void XSStatic __XSException_Initialize( void );
void XSStatic __XSFile_Initialize( void );
void XSStatic __XSLock_Initialize( void );
void XSStatic __XSNode_Initialize( void );
void XSStatic __XSNotification_Initialize( void );
void XSStatic __XSNotificationCenter_Initialize( void );
void XSStatic __XSNull_Initialize( void );
void XSStatic __XSNumber_Initialize( void );
void XSStatic __XSSet_Initialize( void );
void XSStatic __XSString_Initialize( void );
void XSStatic __XSThread_Initialize( void );
void XSStatic __XSTimer_Initialize( void );
void XSStatic __XSURL_Initialize( void );

void XSRuntime_Initialize( void )
{
    __XSRuntime_ClassInfoList * classes;
    
    if( XSAtomic_CompareAndSwap32( __XSRuntime_InitStatusNotInited, __XSRuntime_InitStatusInitializing, ( volatile XSInt32 * )&__XSRuntime_Inited ) == false )
    {
        return;
    }
    
    classes = ( __XSRuntime_ClassInfoList * )calloc( sizeof( __XSRuntime_ClassInfoList ), 1 );
    
    if( classes == NULL )
    {
        XSFatalError( "Cannot allocate memory for the runtime class informations" );
    }
    
    if( atexit( __XSRuntime_Finalize ) != 0 )
    {
        XSFatalError( "Cannot register the XSFoundation finalizier function" );
    }
    
    __XSRuntime_Classes     = classes;
    __XSRuntime_ClassCount  = 0;
    
    while( XSAtomic_CompareAndSwap32( __XSRuntime_InitStatusInitializing, __XSRuntime_InitStatusInited, ( volatile XSInt32 * )&__XSRuntime_Inited ) == false );
    
    __XSApplication_Initialize();
    __XSApplicationArgument_Initialize();
    __XSArray_Initialize();
    __XSAutoreleasePool_Initialize();
    __XSBag_Initialize();
    __XSBinaryTree_Initialize();
    __XSBoolean_Initialize();
    __XSColor_Initialize();
    __XSData_Initialize();
    __XSDictionary_Initialize();
    __XSError_Initialize();
    __XSException_Initialize();
    __XSFile_Initialize();
    __XSLock_Initialize();
    __XSNode_Initialize();
    __XSNotification_Initialize();
    __XSNotificationCenter_Initialize();
    __XSNull_Initialize();
    __XSNumber_Initialize();
    __XSSet_Initialize();
    __XSString_Initialize();
    __XSThread_Initialize();
    __XSTimer_Initialize();
    __XSURL_Initialize();
}

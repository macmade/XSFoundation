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
 * @header      XS.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSFoundation main include file
 * @discussion  This file should be included on projects using the XEOS C
 *              Foundation Library. Other header files should never be included
 *              directly.
 */

#ifndef __XS_H__
#define __XS_H__

/* Internal build only - Adds extra warning flags */
#ifdef __XS_BUILD__
#include <XS/__private/XSWarnings.h>
#endif

/* Standard includes */
#include <XS/XS-STD.h>

/* Core */
#include <XS/XSMacros.h>
#include <XS/XSMacros-X.h>
#include <XS/XSTypes.h>

/* Functions */
#include <XS/Functions/XSAtomic.h>
#include <XS/Functions/XSMemory.h>
#include <XS/Functions/XSRuntime.h>
#include <XS/Functions/XSMemoryDebug.h>
#include <XS/Functions/XSProcess.h>
#include <XS/Functions/XSThreading.h>
#include <XS/Functions/XSLog.h>
#include <XS/Functions/XSMath.h>
#include <XS/Functions/XSGeometry.h>
#include <XS/Functions/XSSort.h>

/* Classes */
#include <XS/Classes/XSApplication.h>
#include <XS/Classes/XSApplicationArgument.h>
#include <XS/Classes/XSArray.h>
#include <XS/Classes/XSAutoreleasePool.h>
#include <XS/Classes/XSBag.h>
#include <XS/Classes/XSBinaryTree.h>
#include <XS/Classes/XSBoolean.h>
#include <XS/Classes/XSColor.h>
#include <XS/Classes/XSData.h>
#include <XS/Classes/XSDate.h>
#include <XS/Classes/XSDictionary.h>
#include <XS/Classes/XSError.h>
#include <XS/Classes/XSFile.h>
#include <XS/Classes/XSLock.h>
#include <XS/Classes/XSNode.h>
#include <XS/Classes/XSNotification.h>
#include <XS/Classes/XSNotificationCenter.h>
#include <XS/Classes/XSNull.h>
#include <XS/Classes/XSNumber.h>
#include <XS/Classes/XSPrimitiveArray.h>
#include <XS/Classes/XSRecursiveLock.h>
#include <XS/Classes/XSSemaphore.h>
#include <XS/Classes/XSSet.h>
#include <XS/Classes/XSString.h>
#include <XS/Classes/XSThread.h>
#include <XS/Classes/XSTimer.h>
#include <XS/Classes/XSURL.h>
#include <XS/Classes/XSValue.h>

#endif /* __XS_H__ */

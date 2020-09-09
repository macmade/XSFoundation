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
#include <XS/Functions/XSProcess.h>
#include <XS/Functions/XSThreading.h>
#include <XS/Functions/XSLog.h>
#include <XS/Functions/XSMath.h>
#include <XS/Functions/XSGeometry.h>
#include <XS/Functions/XSSort.h>
#include <XS/Functions/XSFileSystem.h>

/* Classes */
#include <XS/Classes/XSArrayRef.h>
#include <XS/Classes/XSAutoreleasePoolRef.h>
#include <XS/Classes/XSBagRef.h>
#include <XS/Classes/XSBinaryTreeRef.h>
#include <XS/Classes/XSBooleanRef.h>
#include <XS/Classes/XSColorRef.h>
#include <XS/Classes/XSDataRef.h>
#include <XS/Classes/XSDateRef.h>
#include <XS/Classes/XSDictionaryRef.h>
#include <XS/Classes/XSErrorRef.h>
#include <XS/Classes/XSFileRef.h>
#include <XS/Classes/XSFileManagerRef.h>
#include <XS/Classes/XSLockRef.h>
#include <XS/Classes/XSNodeRef.h>
#include <XS/Classes/XSNotificationRef.h>
#include <XS/Classes/XSNotificationCenterRef.h>
#include <XS/Classes/XSNullRef.h>
#include <XS/Classes/XSNumberRef.h>
#include <XS/Classes/XSOrderedSetRef.h>
#include <XS/Classes/XSPrimitiveArrayRef.h>
#include <XS/Classes/XSRecursiveLockRef.h>
#include <XS/Classes/XSSemaphoreRef.h>
#include <XS/Classes/XSSetRef.h>
#include <XS/Classes/XSStackRef.h>
#include <XS/Classes/XSStringRef.h>
#include <XS/Classes/XSThreadRef.h>
#include <XS/Classes/XSURLRef.h>
#include <XS/Classes/XSValueRef.h>

#endif /* __XS_H__ */

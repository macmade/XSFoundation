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
 * @header      XSTypes.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSFoundation types
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_TYPES_H__
#define __XS_TYPES_H__

XS_EXTERN_C_BEGIN

#include <XS/XSTypes/XSUInt8.h>
#include <XS/XSTypes/XSUInt16.h>
#include <XS/XSTypes/XSUInt32.h>
#include <XS/XSTypes/XSUInt64.h>
#include <XS/XSTypes/XSInt8.h>
#include <XS/XSTypes/XSInt16.h>
#include <XS/XSTypes/XSInt32.h>
#include <XS/XSTypes/XSInt64.h>
#include <XS/XSTypes/XSFloat32.h>
#include <XS/XSTypes/XSFloat64.h>
#include <XS/XSTypes/XSUInteger.h>
#include <XS/XSTypes/XSInteger.h>
#include <XS/XSTypes/XSFloat.h>

#include <XS/XSTypes/XSMutex.h>
#include <XS/XSTypes/XSSemaphore.h>
#include <XS/XSTypes/XSTLSKey.h>
#include <XS/XSTypes/XSObjectAssociation.h>

#include <XS/XSTypes/XSPoint.h>
#include <XS/XSTypes/XSSize.h>
#include <XS/XSTypes/XSRect.h>
#include <XS/XSTypes/XSRectEdge.h>
#include <XS/XSTypes/XSEdgeInsets.h>

#include <XS/XSTypes/XSInitStatus.h>
#include <XS/XSTypes/XSLogLevel.h>

#include <XS/XSTypes/XSRange.h>
#include <XS/XSTypes/XSComparisonResult.h>

#include <XS/XSTypes/XSClassID.h>
#include <XS/XSTypes/XSClassType.h>
#include <XS/XSTypes/XSObjectRef.h>
#include <XS/XSTypes/XSClassCallbackConstructor.h>
#include <XS/XSTypes/XSClassCallbackDestructor.h>
#include <XS/XSTypes/XSClassCallbackCopy.h>
#include <XS/XSTypes/XSClassCallbackEquals.h>
#include <XS/XSTypes/XSClassCallbackToString.h>
#include <XS/XSTypes/XSClassInfo.h>

#include <XS/XSTypes/XSCompilerContext.h>

XS_EXTERN_C_END

#endif /* __XS_RUNTIME_H__ */

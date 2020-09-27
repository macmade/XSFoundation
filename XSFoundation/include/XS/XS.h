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
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSFoundation main include file
 * @discussion  This file should be included on projects using the XEOS C
 *              Foundation Library. Other header files should never be included
 *              directly.
 */

#ifndef XS_H
#define XS_H

/* Base */
#include <XS/Macros.h>
#include <XS/Types.h>

/* Functions */
#include <XS/Functions/Atomic.h>
#include <XS/Functions/Memory.h>
#include <XS/Functions/Runtime.h>
#include <XS/Functions/Log.h>
#include <XS/Functions/Sleep.h>
#include <XS/Functions/SpinLock.h>
#include <XS/Functions/Threading.h>
#include <XS/Functions/Process.h>
#include <XS/Functions/CString.h>

/* Classes */
#include <XS/Classes/XSAutoreleasePool.h>
#include <XS/Classes/XSString.h>

#endif /* XS_H */

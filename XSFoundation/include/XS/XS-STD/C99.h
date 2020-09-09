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
 * @header      STD-C99.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    C99 include files
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_STD_C99_H__
#define __XS_STD_C99_H__

#include <assert.h>     /* Diagnostics. */
#include <ctype.h>      /* Character class tests. */
#include <errno.h>      /* Error codes reported by (some) library functions. */
#include <float.h>      /* Implementation-defined floating-point limits. */
#include <iso646.h>     /* Programming in ISO 646 variant character sets. */
#include <limits.h>     /* Implementation-defined limits. */
#include <locale.h>     /* Locale-specific information. */
#include <math.h>       /* Mathematical functions. */
#include <setjmp.h>     /* Non-local jumps. */
#include <signal.h>     /* Signals. */
#include <stdarg.h>     /* Variable argument lists. */
#include <stddef.h>     /* Definitions of general use. */
#include <stdint.h>     /* Definition of various integer types. */
#include <stdio.h>      /* Input and output. */
#include <stdlib.h>     /* Utility functions. */
#include <string.h>     /* String functions. */
#include <time.h>       /* Time and date functions. */
#include <wchar.h>      /* Manipulation of wide streams and several kinds of strings using wide characters. */
#include <wctype.h>     /* Wide characters classification. */

#ifndef _WIN32

#include <complex.h>    /* Complex numbers manupilations. */
#include <fenv.h>       /* Control of floating-point environment. */
#include <inttypes.h>   /* Precise conversion between integer types. */
#include <stdbool.h>    /* Boolean data type. */
#include <tgmath.h>     /* Type-generic mathematical functions. */

#endif

#endif /* __XS_STD_C99_H__ */

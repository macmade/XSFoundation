/*******************************************************************************
 * Copyright (c) 2010, Jean-David Gadina <macmade@eosgarden.com>
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/* $Id$ */

/*!
 * @header      
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    
 */

#ifndef _XS_TYPES_H_
#define _XS_TYPES_H_
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "XSConstants.h"
#include "../std/std.h"

#ifndef OBJC_BOOL_DEFINED
    
    typedef signed char BOOL;
    #define YES ( BOOL )1
    #define NO  ( BOOL )0
    #define OBJC_BOOL_DEFINED
    
#endif

typedef unsigned char           Boolean;
typedef unsigned char           UInt8;
typedef signed char             SInt8;
typedef unsigned short          UInt16;
typedef signed short            SInt16;
typedef unsigned int            UInt32;
typedef signed int              SInt32;
typedef uint64_t                UInt64;
typedef int64_t                 SInt64;
typedef float                   Float32;
typedef double                  Float64;
typedef UInt8                   Byte;
typedef SInt8                   SignedByte;
typedef unsigned short          UniChar;
typedef unsigned long           UniCharCount;
typedef unsigned char         * StringPtr;
typedef const unsigned char   * ConstStringPtr;
typedef unsigned char           Str255[ 256 ];
typedef const unsigned char   * ConstStr255Param;
typedef SInt16                  RegionCode;
typedef SInt16                  LangCode;
typedef SInt16                  ScriptCode;
typedef UInt32                  FourCharCode;
typedef FourCharCode            OSType;
typedef SInt32                  OSStatus;
typedef SInt16                  OSErr;
typedef UInt8                   UTF8Char;
typedef UInt16                  UTF16Char;
typedef UInt32                  UTF32Char;

#if __LP64__
    
    typedef long          XSInteger;
    typedef unsigned long XSUInteger;
    typedef double        XSFloat;
    
#else
    
    typedef int          XSInteger;
    typedef unsigned int XSUInteger;
    typedef float        XSFloat;
    
#endif

typedef struct _XSRuntimeClass
{
    const char * className;
    void ( * init        )( void * object );
    void ( * dealloc     )( void * object );
    void ( * copy        )( void * source, void * destination );
    void ( * description )( void * object );
}
XSRuntimeClass;

typedef struct _XSRuntimeBase
{
    XSRuntimeClass isa;
}
XSRuntimeBase;

typedef unsigned long XSTypeID;
typedef const void  * XSTypeRef;

typedef struct _XSPoint
{
    XSFloat x;
    XSFloat y;
}
XSPoint;

typedef struct _XSSize
{
    XSFloat width;
    XSFloat height;
}
XSSize;

typedef struct _XSRect
{
    XSPoint origin;
    XSSize  size;
}
XSRect;

typedef struct _XSRange
{
    XSUInteger location;
    XSUInteger length;
}
XSRange;

typedef enum _XSByteOrder
{
   XS_UnknownByteOrder = 0,
   XS_LittleEndian     = 1,
   XS_BigEndian        = 2
}
XSByteOdrer;

enum
{
   XSOrderedAscending  = -1,
   XSOrderedSame       = 0,
   XSOrderedDescending = 1
};

typedef XSInteger XSComparisonResult;

typedef struct _XSDecimal
{
    signed int     exponent   : 8;
    unsigned int   length     : 4;
    unsigned int   isNegative : 1;
    unsigned int   isCompact  : 1;
    unsigned int   reserved   : 18;
    unsigned short mantissa[ XSDecimalMaxSize ];
}
XSDecimal;

#ifdef __cplusplus
}
#endif

#endif /* _XS_TYPES_H_ */

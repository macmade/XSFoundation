/*******************************************************************************
 * Copyright (c) 2011, Jean-David Gadina <macmade@eosgarden.com>
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
 * @header      XSData.c
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    ...
 */

#include "XS.h"
#include "__XSData.h"

#define __XSDATA_DEFAULT_CAPACITY 4096

extern XSClassID __XSDataClassID;

XSStatic XSData XSData_Alloc( void )
{
    return ( XSData )XSRuntime_CreateInstance( __XSDataClassID );
}

XSData XSData_Init( XSData xsThis )
{
    return XSData_InitWithCapacity( xsThis, __XSDATA_DEFAULT_CAPACITY );
}

XSData XSData_InitWithCapacity( XSData xsThis, XSUInteger capacity )
{
    __XSData * data;
    UInt8    * bytes;
    
    data                  = ( __XSData * )xsThis;
    data->capacity        = capacity;
    data->initialCapacity = capacity;
    data->length          = 0;
    
    if( NULL == ( bytes = ( UInt8 * )XSAlloc( capacity * sizeof( UInt8 ) ) ) )
    {
        return NULL;
    }
    
    data->bytes = bytes;
    
    return xsThis;
}

XSData XSData_InitWithBytes( XSData xsThis, UInt8 * bytes, XSUInteger length )
{
    __XSData * data;
    
    if( NULL == XSData_InitWithCapacity( xsThis, length ) )
    {
        return NULL;
    }
    
    data         = ( __XSData * )xsThis;
    data->length = length;
    
    memcpy( data->bytes, bytes, length );
    
    return xsThis;
}

XSUInteger XSData_GetLength( XSData xsThis )
{
    return ( ( __XSData * )xsThis )->length;
}

XSAutoreleased UInt8 * XSData_GetBytes( XSData xsThis, XSRange range )
{
    ( void )xsThis;
    ( void )range;
    
    return NULL;
}

void XSData_SetBytes( XSData xsThis, XSRange range )
{
    ( void )xsThis;
    ( void )range;
}

void XSData_AppendBytes( XSData xsThis, UInt8 * bytes )
{
    ( void )xsThis;
    ( void )bytes;
}

void XSData_DeleteBytes( XSData xsThis, XSRange range )
{
    ( void )xsThis;
    ( void )range;
}

UInt8 * XSData_GetBytesPointer( XSData xsThis )
{
    ( void )xsThis;
    
    return NULL;
}
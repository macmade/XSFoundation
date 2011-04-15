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
 * @file        __XSString.c
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    Private implementation for the XSString class
 */

#include "XS.h"
#include "__XSString.h"

/*!
 * @var         __XSStringClass
 * @abstract    Runtime class definition
 */
static const XSClassInfos __XSStringClass =
{
    "XSString",             /* Class name */
    sizeof( __XSString ),   /* Object size */
    NULL,                   /* Constructor */
    __XSString_Destruct,    /* Destructor */
    __XSString_Copy,        /* Object copy */
    __XSString_ToString,    /* Object description */
    __XSString_Equals       /* Object comparison */
};

/*!
 * @var         __XSStringClassID
 * @abstract    Type ID for the runtine class
 */
XSClassID __XSStringClassID;

void __XSString_Initialize( void )
{
    __XSStringClassID = XSRuntime_RegisterClass( &__XSStringClass );
}

void __XSString_Destruct( void * object )
{
    __XSString * str;
    
    str = ( __XSString * )object;
    
    XSRelease( str->str );
}

void __XSString_Copy( void * source, void * destination )
{
    __XSString * str1 = ( __XSString * )source;
    __XSString * str2 = ( __XSString * )destination;
    
    if( NULL == ( str2->str = XSAlloc( str1->length + 1 ) ) )
    {
        str2->str = NULL;
    }
    
    memcpy( str2->str, str1->str, str1->length );
}

XSString __XSString_ToString( void * object )
{
    return ( XSString )object;
}

BOOL __XSString_Equals( void * object1, void * object2 )
{
    __XSString * s1;
    __XSString * s2;
    
    s1 = ( __XSString * )object1;
    s2 = ( __XSString * )object2;
    
    return ( strcmp( s1->str, s2->str ) == 0 ) ? YES : NO;
}

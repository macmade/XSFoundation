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

/* $Id */

/*!
 * @file        XSString.c
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    ...
 */

#include "XS.h"
#include "__XSString.h"

extern XSClassID __XSStringClassID;

#define __XSSTRING_DEFAULT_CAPACITY 256

XSString XSString_Alloc( void )
{
    return ( XSString )XSRuntime_CreateInstance( __XSStringClassID );
}

XSString XSString_Init( XSString xsThis )
{
    return XSString_InitWithCapacity( xsThis, __XSSTRING_DEFAULT_CAPACITY );
}

XSString XSString_InitWithCapacity( XSString xsThis, XSUInteger capacity )
{
    __XSString * string;
    
    string = ( __XSString * )xsThis;
    
    if( capacity == 0 )
    {
        capacity = __XSSTRING_DEFAULT_CAPACITY;
    }
    
    string->str = XSAlloc( ( sizeof( char ) * capacity ) + 1 );
    
    return ( XSString )string;
}

XSString XSString_InitWithCString( XSString xsThis, char * str )
{
    size_t       length;
    __XSString * string;
    
    if( str == NULL )
    {
        return xsThis;
    }
    
    length = strlen( str );
    string = ( __XSString * )XSString_InitWithCapacity( xsThis, length );
    
    memcpy( string->str, str, length );
    
    string->length = length;
    
    return ( XSString )string;
}

XSString XSString_InitWithContentOfFile( XSString xsThis, char * path )
{
    ( void )path;
    ( void )xsThis;
    
    return NULL;
}

XSString XSString_SubstringFromIndex( XSString xsThis, size_t i )
{
    __XSString * _str;
    
    if( xsThis == NULL )
    {
        return NULL;
    }
    
    _str = ( __XSString * )xsThis;
    
    if( i >= _str->length )
    {
        return NULL;
    }
    
    return XSString_InitWithCString( XSString_Alloc(), _str->str + i );
}

XSString XSString_SubstringToIndex( XSString xsThis, size_t i )
{
    __XSString * _str;
    __XSString * str2;
    
    if( xsThis == NULL )
    {
        return NULL;
    }
    
    _str = ( __XSString * )xsThis;
    
    if( i >= _str->length )
    {
        return XSCopy( xsThis );
    }
    
    str2 = ( __XSString * )XSString_InitWithCapacity( XSString_Alloc(), i + 1 );
    
    memcpy( str2->str, _str->str, i );
    
    return ( XSString )str2;
}

XSString XSString_SubstringWithRange( XSString xsThis, XSRange range )
{
    __XSString * _str1;
    __XSString * _str2;
    
    if( xsThis == NULL )
    {
        return NULL;
    }
    
    _str1 = ( __XSString * )xsThis;
    
    if( range.location > _str1->length )
    {
        return NULL;
    }
    
    if( range.length > _str1->length - range.location )
    {
        range.length = _str1->length - range.location;
    }
    
    _str2 = ( __XSString * )XSString_InitWithCapacity( XSString_Alloc(), range.length + 1 );
    
    memset( _str2->str, 0, range.length + 1 );
    memcpy( _str2->str, ( _str1->str ) + range.location, range.length );
    
    return ( XSString )_str2;
}

XSString XSString_LowercaseString( XSString xsThis )
{
    __XSString * _str;
    size_t       i;
    char         c;
    
    if( xsThis == NULL )
    {
        return NULL;
    }
    
    _str = XSCopy( xsThis );
    
    for( i = 0; i < _str->length; i++ )
    {
        c = _str->str[ i ];
        
        if( c >= 0x41 && c <= 0x5A )
        {
            _str->str[ i ] = _str->str[ i ] + 0x20;
        }
    }
    
    return ( XSString)_str;
}

XSString XSString_UppercaseString( XSString xsThis )
{
    __XSString * _str;
    size_t       i;
    char         c;
    
    if( xsThis == NULL )
    {
        return NULL;
    }
    
    _str = XSCopy( xsThis );
    
    for( i = 0; i < _str->length; i++ )
    {
        c = _str->str[ i ];
        
        if( c >= 0x61 && c <= 0x7A )
        {
            _str->str[ i ] = _str->str[ i ] - 0x20;
        }
    }
    
    return ( XSString)_str;
}

XSString XSString_StringByAppendingString( XSString xsThis, XSString str )
{
    __XSString * newStr;
    size_t       length1;
    size_t       length2;
    
    if( xsThis == NULL )
    {
        return NULL;
    }
    
    if( str == NULL )
    {
        return XSCopy( xsThis );
    }
    
    length1 = XSString_Length( xsThis );
    length2 = XSString_Length( str );
    
    newStr         = ( __XSString * )XSString_InitWithCapacity( XSString_Alloc(), length1 + length2 + 1 );
    newStr->length = length1 + length2;
    
    memset( newStr->str, 0, newStr->length + 1 );
    memcpy( newStr->str, ( ( __XSString * )xsThis )->str, length1 );
    strcat( newStr->str, ( ( __XSString * )str )->str );
    
    return ( XSString )newStr;
}

XSString XSString_StringByAppendingCString( XSString xsThis, char * str )
{
    __XSString * newStr;
    size_t       length1;
    size_t       length2;
    
    if( xsThis == NULL )
    {
        return NULL;
    }
    
    if( str == NULL )
    {
        return XSCopy( xsThis );
    }
    
    length1 = XSString_Length( xsThis );
    length2 = strlen( str );
    
    newStr         = ( __XSString * )XSString_InitWithCapacity( XSString_Alloc(), length1 + length2 + 1 );
    newStr->length = length1 + length2;
    
    memset( newStr->str, 0, newStr->length + 1 );
    memcpy( newStr->str, ( ( __XSString * )xsThis )->str, length1 );
    strcat( newStr->str, str );
    
    return ( XSString )str;
}

size_t XSString_Length( XSString xsThis )
{
    if( xsThis == NULL )
    {
        return 0;
    }
    
    return ( ( __XSString * )xsThis )->length;
}

char XSString_CharacterAtIndex( XSString xsThis, size_t i )
{
    __XSString * _str;
    
    if( xsThis == NULL )
    {
        return 0;
    }
    
    _str = ( __XSString * )xsThis;
    
    if( i >= _str->length )
    {
        return 0;
    }
    
    return _str->str[ i ];
}

const char * XSString_CString( XSString xsThis )
{
    if( xsThis == NULL )
    {
        return NULL;
    }
    
    return ( ( __XSString * )xsThis )->str;
}

XSRange XSString_RangeOfString( XSString xsThis, XSString str )
{
    XSString * _str1;
    XSString * _str2;
    XSRange    range;
    
    if( xsThis == NULL || str == NULL )
    {
        return XSMakeRange( XSNotFound, 0 );
    }
    
    _str1 = ( XSString * )xsThis;
    _str2 = ( XSString * )str;
    range = XSMakeRange( 0, 0 );
    
    return range;
}

XSRange XSString_RangeOfCString( XSString xsThis, char * str )
{
    XSString * _str;
    XSRange    range;
    
    if( xsThis == NULL || str == NULL )
    {
        return XSMakeRange( XSNotFound, 0 );
    }
    
    _str  = ( XSString * )str;
    range = XSMakeRange( 0, 0 );
    
    return range;
}

BOOL XSString_IsEqualToString( XSString xsThis, XSString str )
{
    __XSString * _str1;
    __XSString * _str2;
    
    if( xsThis == NULL || str == NULL )
    {
        return NO;
    }
    
    _str1 = ( __XSString * )xsThis;
    _str2 = ( __XSString * )str;
    
    if( strcmp( _str1->str, _str2->str ) == 0 )
    {
        return YES;
    }
    
    return NO;
}

XSString XSString_StringByReplacingStringWithString( XSString xsThis, XSString str1, XSString str2 )
{
    XSString * _str1;
    XSString * _str2;
    XSString * _str3;
    
    _str1 = ( XSString * )xsThis;
    _str2 = ( XSString * )str1;
    _str3 = ( XSString * )str2;
    
    return NULL;
}

XSInteger XSString_IntegerValue( XSString xsThis )
{
    XSString * _str;
    
    _str = ( XSString * )xsThis;
    
    return 0;
}

XSFloat XSString_FloatValue( XSString xsThis )
{
    XSString * _str;
    
    _str = ( XSString * )xsThis;
    
    return 0;
}

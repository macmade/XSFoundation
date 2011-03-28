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

/* $Id */

/*!
 * @file        
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    
 */

#include "XS.h"
#include "private/__XSString.h"

XSStringRef XSString_Create( void )
{
    return NULL;
}

XSStringRef XSString_CreateWithCapacity( XSUInteger capacity )
{
    ( void )capacity;
    
    return NULL;
}

XSStringRef XSString_CreateWithCString( char * str, ... )
{
    ( void )str;
    
    return NULL;
}

XSStringRef XSString_CreateWithContentOfFile( char * path )
{
    ( void )path;
    
    return NULL;
}

XSStringRef XSString_Copy( XSStringRef str )
{
    ( void )str;
    
    return NULL;
}

XSStringRef XSString_SubstringFromIndex( XSStringRef str, size_t i )
{
    ( void )str;
    ( void )i;
    
    return NULL;
}

XSStringRef XSString_SubstringToIndex( XSStringRef str, size_t i )
{
    ( void )str;
    ( void )i;
    
    return NULL;
}

XSStringRef XSString_SubstringWithRange( XSStringRef str, XSRange range )
{
    ( void )str;
    ( void )range;
    
    return NULL;
}

XSStringRef XSString_LowercaseString( XSStringRef str )
{
    ( void )str;
    
    return NULL;
}

XSStringRef XSString_UppercaseString( XSStringRef str )
{
    ( void )str;
    
    return NULL;
}

XSStringRef XSString_StringByAppendingString( XSStringRef str, ... )
{
    ( void )str;
    
    return NULL;
}

XSStringRef XSString_StringByAppendingCString( char * str, ... )
{
    ( void )str;
    
    return NULL;
}

BOOL XSString_WriteToFile( XSStringRef str )
{
    ( void )str;
    
    return NO;
}

size_t XSString_Length( XSStringRef str )
{
    ( void )str;
    
    return 0;
}

char XSString_CharacterAtIndex( XSStringRef str, size_t i )
{
    ( void )str;
    ( void )i;
    
    return 0;
}

const char * XSString_CString( XSStringRef str )
{
    ( void )str;
    
    return NULL;
}

XSRange XSString_RangeOfString( XSStringRef str1, XSStringRef str2 )
{
    XSRange range = XSMakeRange( 0, 0 );
    
    ( void )str1;
    ( void )str2;
    
    return range;
}

XSRange XSString_RangeOfCString( XSStringRef str1, char * str2 )
{
    XSRange range = XSMakeRange( 0, 0 );
    
    ( void )str1;
    ( void )str2;
    
    return range;
}

BOOL XSString_IsEqualToString( XSStringRef str1, XSStringRef str2 )
{
    ( void )str1;
    ( void )str2;
    
    return NO;
}

XSStringRef XSString_StringByReplacingStringWithString( XSStringRef str1, XSStringRef str2, XSStringRef str3 )
{
    ( void )str1;
    ( void )str2;
    ( void )str3;
    
    return NULL;
}

XSUInteger XSString_UnsignedIntValue( XSStringRef str1 )
{
    ( void )str1;
    
    return 0;
}

XSInteger XSString_IntValue( XSStringRef str1 )
{
    ( void )str1;
    
    return 0;
}

XSFloat XSString_FloatValue( XSStringRef str1 )
{
    ( void )str1;
    
    return 0;
}

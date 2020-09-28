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
 * @file        XSStringAppendFormatAndArguments.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSStringAppendFormatAndArguments
 */

#include <XS/XS.h>
#include <XS/Private/Classes/XSString.h>
#include <string.h>
#include <stdio.h>

void XSStringAppendFormatAndArguments( XSMutableStringRef str, const char * fmt, va_list ap )
{
    va_list ap2;
    int     length;
    char *  cstr;

    if( str == NULL )
    {
        return;
    }

    if( ( str->flags & XSStringFlagsMutable ) == 0 )
    {
        XSFatalError( "Cannot modify an immutable XSString" );
    }

    if( fmt == NULL || strlen( fmt ) == 0 )
    {
        return;
    }

    va_copy( ap2, ap );

    length = vsnprintf( NULL, 0, fmt, ap );

    if( length < 0 )
    {
        va_end( ap2 );

        return;
    }

    cstr = XSAlloc( ( size_t )length + 1 );

    if( cstr == NULL )
    {
        va_end( ap2 );
        XSBadAlloc();
    }

    vsnprintf( cstr, ( size_t )length + 1, fmt, ap2 );
    va_end( ap2 );
    XSStringAppendCString( str, cstr );
    XSRelease( cstr );
}

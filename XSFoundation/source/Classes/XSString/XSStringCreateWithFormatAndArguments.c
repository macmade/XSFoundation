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
 * @file        XSStringCreateWithFormatAndArguments.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSStringCreateWithFormatAndArguments
 */

#include <XS/XS.h>
#include <XS/Private/Classes/XSString.h>
#include <string.h>
#include <stdio.h>

XSStringRef XSStringCreateWithFormatAndArguments( const char * fmt, va_list ap )
{
    va_list           ap2;
    struct XSString * instance;
    int               length;

    if( fmt == NULL || strlen( fmt ) == 0 )
    {
        return XSStringCreateWithCString( "" );
    }

    va_copy( ap2, ap );

    length = vsnprintf( NULL, 0, fmt, ap );

    if( length < 0 )
    {
        va_end( ap2 );

        return XSStringCreateWithCString( "" );
    }

    instance = XSRuntimeCreateInstance( XSStringClassID );

    if( instance == NULL )
    {
        va_end( ap2 );
        XSBadAlloc();
    }

    instance->length = ( size_t )length;

    if( instance->length < sizeof( instance->storage.cstr ) )
    {
        vsnprintf( instance->storage.cstr, sizeof( instance->storage.cstr ), fmt, ap2 );
    }
    else
    {
        instance->capacity     = instance->length + 1;
        instance->storage.cptr = XSAlloc( instance->capacity );

        if( instance->storage.cptr == NULL )
        {
            va_end( ap2 );
            XSRelease( instance );
            XSBadAlloc();
        }

        vsnprintf( instance->storage.cptr, instance->capacity, fmt, ap2 );
    }

    va_end( ap2 );

    return instance;
}

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
 * @file        XSStringAppendBytes.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSStringAppendBytes
 */

#include <XS/XS.h>
#include <XS/Private/Classes/XSString.h>
#include <string.h>

void XSStringAppendBytes( XSMutableStringRef str, const uint8_t * bytes, size_t length )
{
    const uint8_t * end;

    if( str == NULL )
    {
        return;
    }

    if( ( str->flags & XSStringFlagsMutable ) == 0 )
    {
        XSFatalError( "Cannot modify an immutable XSString" );
    }

    if( bytes == NULL || length == 0 )
    {
        return;
    }

    end = memchr( bytes, 0, length );

    if( end != NULL )
    {
        length = ( size_t )( end - bytes );
    }

    if( str->capacity == 0 )
    {
        if( str->length + length < sizeof( str->storage.cstr ) )
        {
            memcpy( str->storage.cstr + str->length, bytes, length );
        }
        else
        {
            char * cptr;
            size_t capacity;

            capacity = str->length + length + 1;
            cptr     = XSAlloc( capacity );

            if( cptr == NULL )
            {
                XSBadAlloc();
            }

            memcpy( cptr, str->storage.cstr, str->length );
            memcpy( cptr + str->length, bytes, length );

            str->capacity     = capacity;
            str->storage.cptr = cptr;
        }
    }
    else if( str->length + length < str->capacity )
    {
        memcpy( str->storage.cptr + str->length, bytes, length );
    }
    else
    {
        char * cptr;
        size_t capacity;

        capacity = str->length + length + 1;
        cptr     = XSRealloc( str->storage.cptr, capacity );

        if( cptr == NULL )
        {
            XSBadAlloc();
        }

        memcpy( cptr + str->length, bytes, length );

        str->capacity     = capacity;
        str->storage.cptr = cptr;
    }

    str->length += length;
}

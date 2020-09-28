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
 * @file        XSStringCopy.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSStringCopy
 */

#include <XS/XS.h>
#include <XS/Private/Classes/XSString.h>
#include <string.h>

XSMutableObjectRef XSStringCopy( XSObjectRef source, XSMutableObjectRef destination )
{
    const struct XSString * str1 = source;
    struct XSString *       str2 = destination;

    if( str1->capacity == 0 )
    {
        memcpy( str2->cstr, str1->cstr, str1->length );
    }
    else
    {
        str2->cptr = XSAlloc( str1->capacity );

        if( str2->cptr == NULL )
        {
            XSBadAlloc();
        }

        memcpy( str2->cptr, str1->cptr, str1->length );
    }

    str2->length   = str1->length;
    str2->capacity = str1->capacity;
    str2->flags    = str1->flags & ( uint64_t )( ~XSStringFlagsMutable );

    return destination;
}

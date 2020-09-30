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
 * @file        XSAutoreleasePoolDrain.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSAutoreleasePoolDrain
 */

#include <XS/XS.h>
#include <XS/Private/Classes/XSAutoreleasePool.h>
#include <string.h>

void XSAutoreleasePoolDrain( XSAutoreleasePoolRef ap )
{
    struct XSAutoreleasePoolStorage * storage;

    if( ap == NULL )
    {
        return;
    }

    if( XSGetCurrentThreadID() != ap->threadID )
    {
        XSFatalError( "An autorelease pool object can only be used on the same thread it was created" );
    }

    storage = ap->storage;

    while( storage != NULL )
    {
        for( size_t i = 0; i < storage->count; i++ )
        {
            XSRelease( storage->objects[ i ] );
        }

        {
            struct XSAutoreleasePoolStorage * temp = storage;

            storage = storage->next;

            if( temp != ap->storage )
            {
                XSRelease( temp );
            }
        }
    }

    if( ap->storage != NULL )
    {
        memset( ap->storage, 0, sizeof( struct XSAutoreleasePoolStorage ) );
    }
}

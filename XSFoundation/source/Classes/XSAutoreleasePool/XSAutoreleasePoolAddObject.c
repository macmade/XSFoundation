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
 * @file        XSAutoreleasePoolAddObject.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSAutoreleasePoolAddObject
 */

#include <XS/XS.h>
#include <XS/Private/Classes/XSAutoreleasePool.h>

void XSAutoreleasePoolAddObject( XSAutoreleasePoolRef ap, const void * object )
{
    struct XSAutoreleasePoolStorage * storage;

    if( ap == NULL || object == NULL || XSRuntimeIsConstantObject( object ) )
    {
        return;
    }

    storage = ap->storage;

    while( storage != NULL )
    {
        if( storage->count < sizeof( storage->objects ) / sizeof( const void * ) )
        {
            storage->objects[ storage->count++ ] = object;

            return;
        }

        if( storage->next == NULL )
        {
            storage->next = XSAlloc( sizeof( struct XSAutoreleasePoolStorage ) );

            if( storage->next == NULL )
            {
                XSBadAlloc();
            }

            storage->next->objects[ storage->next->count++ ] = object;

            return;
        }
        else
        {
            storage = storage->next;
        }
    }
}

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
 * @file        XSRuntimeCreateInstance.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSRuntimeCreateInstance
 */

#include <XS/XS.h>
#include <XS/Private/Functions/Runtime.h>

void * XSRuntimeCreateInstance( XSClassID classID )
{
    void *                     object;
    void *                     newObject;
    size_t                     instanceSize;
    XSClassCallbackConstructor constructor;

    if( XSRuntimeIsRegisteredClass( classID ) == false )
    {
        return NULL;
    }

    instanceSize = XSRuntimeGetInstanceSize( classID );

    if( instanceSize == 0 )
    {
        XSFatalError( "Cannot create an instance for a class with zero as instance size (class ID: %lli)", ( long long )classID );
    }

    object = XSAllocWithInfos( instanceSize, classID, NULL, 0, NULL );

    if( object == NULL )
    {
        XSBadAlloc();
    }

    constructor = XSRuntimeGetConstructorCallback( classID );

    if( constructor != NULL )
    {
        newObject = constructor( object );

        if( newObject == NULL )
        {
            XSRelease( object );

            object = NULL;
        }
        else
        {
            object = newObject;
        }
    }

    return object;
}

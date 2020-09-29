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
 * @file        XSRuntimeGetDescription.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSRuntimeGetDescription
 */

#include <XS/XS.h>
#include <XS/Private/Functions/Runtime.h>

XSStringRef XSRuntimeGetDescription( XSObjectRef object )
{
    XSClassID               classID;
    XSClassCallbackToString toString;
    XSStringRef             description;
    XSStringRef             objectDescription;
    const char *            className;

    if( object == NULL )
    {
        return XSStringWithCString( "(null)" );
    }
    else
    {
        classID           = XSRuntimeGetClassID( object );
        className         = XSRuntimeGetClassName( classID );
        toString          = XSRuntimeGetToStringCallback( classID );
        objectDescription = NULL;

        if( XSRuntimeIsRegisteredClass( classID ) == false || className == NULL )
        {
            description = XSStringWithFormat( "<%p>", object );
        }
        else
        {
            if( toString != NULL )
            {
                objectDescription = toString( object );
            }

            if( objectDescription != NULL && XSStringGetLength( objectDescription ) > 0 )
            {
                description = XSStringWithFormat( "<%s %p> %s", className, object, XSStringGetCString( objectDescription ) );
            }
            else
            {
                description = XSStringWithFormat( "<%s %p>", className, object );
            }
        }
    }

    return description;
}

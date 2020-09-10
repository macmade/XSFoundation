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
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSRuntimeGetDescription
 */

#include <XS/XS.h>
#include <XS/Private/Functions/Runtime.h>

const char * XSRuntimeGetDescription( XSObjectRef object )
{
    ( void )object;

    return "<object>";

    // TODO
    /*
    XSClassID               classID;
    XSClassCallbackToString toString;
    XSStringRef             description;
    const char *            className;
    const char *            objectDescription;

    if( object == NULL )
    {
        return "(null)";
    }
    else
    {
        classID           = XSRuntime_GetClassID( object );
        className         = XSRuntime_GetClassName( classID );
        toString          = __XSRuntime_GetToStringCallback( classID );
        objectDescription = NULL;

        if( className == NULL )
        {
            description = XSString_StringWithFormat( "<%p>", object );
        }
        else
        {
            if( toString != NULL )
            {
                objectDescription = toString( object );
            }

            if( objectDescription != NULL )
            {
                description = XSString_StringWithFormat( "<%s %p> %s", className, object, objectDescription );
            }
            else
            {
                description = XSString_StringWithFormat( "<%s %p>", className, object );
            }
        }
    }

    return XSString_GetCString( description );
    */
}

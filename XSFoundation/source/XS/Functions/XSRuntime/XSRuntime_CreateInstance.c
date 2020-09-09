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

/* $Id$ */

/*!
 * @file        XSAllocWithInfos.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSAllocWithInfos
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSRuntime.h>

XSObjectRef XSRuntime_CreateInstance( XSClassID classID )
{
    XSObjectRef                 object;
    XSObjectRef                 newObject;
    XSUInteger                  instanceSize;
    XSClassCallbackConstructor  constructor;
    
    if( XSRuntime_IsRegisteredClass( classID ) == false )
    {
        XSFatalError( "Cannot create an instance for an unregistered class (class ID: %li)", ( long )classID );
    }
    
    instanceSize = __XSRuntime_GetInstanceSize( classID );
    
    if( instanceSize == 0 )
    {
        XSFatalError( "Cannot create an instance for a class with zero as instance size (class ID: %li)", ( long )classID );
    }
    
    object = ( XSObjectRef )XSAllocWithInfos( instanceSize, classID, NULL, 0, NULL );
    
    if( object == NULL )
    {
        return NULL;
    }
    
    constructor = __XSRuntime_GetConstructorCallback( classID );
    
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

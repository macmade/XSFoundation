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
 * @file        __XSData_Copy.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSData_Copy
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSDataRef.h>

XSDataRef __XSData_Copy( XSDataRef source, XSDataRef destination )
{
    ( ( struct __XSData * )destination )->lock          = XSRecursiveLock_Create();
    ( ( struct __XSData * )destination )->properties    = source->properties;
    ( ( struct __XSData * )destination )->length        = source->length;
    ( ( struct __XSData * )destination )->capacity      = source->capacity;
    ( ( struct __XSData * )destination )->releaseType   = source->releaseType;
    
    __XSData_Lock( source );
    
    if( source->buffer != NULL )
    {
        if( source->releaseType == XSData_BufferReleaseTypeRelease && ( source->properties & __XSData_PropertiesMutable ) == 0 )
        {
            ( ( struct __XSData * )destination )->buffer        = XSRetain( source->buffer );
        }
        else
        {
            ( ( struct __XSData * )destination )->releaseType   = XSData_BufferReleaseTypeRelease;
            ( ( struct __XSData * )destination )->buffer        = XSAlloc( source->capacity );
            
            if( destination->buffer == NULL )
            {
                XSFatalError( "Error allocating memory for the XSData buffer" );
            }
            
            memcpy( ( ( struct __XSData * )destination )->buffer, source->buffer, source->length );
        }
    }
    
    __XSData_Unlock( source );
    
    return destination;
}

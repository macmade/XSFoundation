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
 * @file        XSString_CreateWithFormatAndArgs.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSString_CreateWithFormatAndArgs
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSStringRef.h>

XSStatic XSStringRef XSString_CreateWithFormatAndArgs( const char * format, va_list args )
{
    XSInteger           length;
    char              * s;
    struct __XSString * str;
    va_list             ap;
    
    if( format == NULL || strlen( format ) == 0 )
    {
        XSLogWarning( "Error creating an XSString object - No format specified" );
        
        return NULL;
    }
    
    va_copy( ap, args );
    
    length = vsnprintf( NULL, 0, format, args );
    
    if( length <= 0 )
    {
        va_end( ap );
        XSLogWarning( "Error creating an XSString object - Invalid format" );
        
        return NULL;
    }
    
    s = XSAlloc( ( XSUInteger )length + 1 );
    
    if( s == NULL )
    {
        XSFatalError( "Error allocating memory for XSString C format string" );
    }
    
    str = __XSString_Create();
    
    vsnprintf( s, length + 1, format, ap );
    va_end( ap );
    
    str->cString = s;
    str->length  = ( XSUInteger )length;
    
    return str;
}

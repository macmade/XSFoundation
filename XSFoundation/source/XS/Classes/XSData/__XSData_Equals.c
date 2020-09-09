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
 * @file        __XSData_Equals.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSData_Equals
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSDataRef.h>

bool __XSData_Equals( XSDataRef object1, XSDataRef object2 )
{
    bool equals;
    
    if( object1 == object2 )
    {
        return true;
    }
    
    equals = false;
    
    __XSData_Lock( object1 );
    __XSData_Lock( object2 );
    
    if( object1->length != object2->length )
    {
        goto end;
    }
    
    if( object1->buffer == object2->buffer )
    {
        equals = true;
        
        goto end;
    }
    
    if( memcmp( object1->buffer, object2->buffer, object1->length ) == 0 )
    {
        equals = true;
        
        goto end;
    }
    
    end:
    
    __XSData_Unlock( object1 );
    __XSData_Unlock( object2 );
    
    return equals;
}

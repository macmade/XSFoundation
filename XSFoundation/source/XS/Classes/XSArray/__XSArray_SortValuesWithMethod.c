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
 * @file        __XSArray_SortValuesWithMethod.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSArray_SortValuesWithMethod
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSArrayRef.h>

void __XSArray_SortValuesWithMethod( XSObjectRef * values, XSUInteger count, XSObjectRef object, XSArray_SortMethod method, bool * stop )
{
    XSObjectRef   value;
    XSObjectRef   temp;
    XSObjectRef * left;
    XSObjectRef * right;
    
    if( count < 2 )
    {
        return;
    }
        
    if( stop != NULL && *( stop ) == true )
    {
        return;
    }
    
    value = values[ count / 2 ];
    left  = values;
    right = values + ( count - 1 );
    
    while( left <= right )
    {
        if( method( object, *( left ), value, stop ) == XSComparisonResultOrderAscending )
        {
            left++;
            
            continue;
        }
        
        if( stop != NULL && *( stop ) == true )
        {
            return;
        }
        
        if( method( object, *( right ), value, stop ) == XSComparisonResultOrderDescending )
        {
            right--;
            
            continue;
        }
        
        if( stop != NULL && *( stop ) == true )
        {
            return;
        }
        
        temp       = *( left );
        *( left )  = *( right );
        *( right ) = temp;
        
        left++;
        right--;
    }
    
    __XSArray_SortValuesWithMethod( values, ( XSUInteger )( ( right  - values ) + 1 ),    object, method, stop );
    __XSArray_SortValuesWithMethod( left,   ( XSUInteger )( ( values + count  ) - left ), object, method, stop );
}

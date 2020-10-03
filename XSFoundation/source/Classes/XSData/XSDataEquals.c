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
 * @file        XSDataEquals.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSDataEquals
 */

#include <XS/XS.h>
#include <XS/Private/Classes/XSData.h>
#include <string.h>

bool XSDataEquals( XSObjectRef object1, XSObjectRef object2 )
{
    XSDataRef       data1;
    XSDataRef       data2;
    const uint8_t * bytes1;
    const uint8_t * bytes2;

    if( object1 == NULL || object1 == NULL )
    {
        return false;
    }

    data1 = object1;
    data2 = object2;

    if( data1->length != data2->length )
    {
        return false;
    }

    bytes1 = XSDataGetBytesPointer( data1 );
    bytes2 = XSDataGetBytesPointer( data2 );

    return memcmp( bytes1, bytes2, data1->length ) == 0;
}

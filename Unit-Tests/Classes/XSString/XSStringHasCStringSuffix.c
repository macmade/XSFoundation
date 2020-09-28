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
 * @file        XSStringHasCStringSuffix.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSString, XSStringHasCStringSuffix )
{
    XSStringRef  str1  = XSStringCreateWithCString( "" );
    XSStringRef  str2  = XSStringCreateWithCString( "hello, world" );
    const char * pref1 = "";
    const char * pref2 = "hello";
    const char * pref3 = "world";

    AssertFalse( XSStringHasCStringSuffix( NULL, NULL ) );
    AssertFalse( XSStringHasCStringSuffix( str1, NULL ) );
    AssertFalse( XSStringHasCStringSuffix( NULL, pref1 ) );

    AssertFalse( XSStringHasCStringSuffix( str1, pref1 ) );
    AssertFalse( XSStringHasCStringSuffix( str2, pref1 ) );

    AssertFalse( XSStringHasCStringSuffix( str2, pref2 ) );
    AssertTrue( XSStringHasCStringSuffix( str2, pref3 ) );

    XSRelease( str1 );
    XSRelease( str2 );
}

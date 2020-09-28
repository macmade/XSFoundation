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
 * @file        XSStringContainsCString.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSString, XSStringContainsCString )
{
    XSStringRef  str1    = XSStringCreateWithCString( "" );
    XSStringRef  str2    = XSStringCreateWithCString( "hello, world" );
    const char * search1 = "";
    const char * search2 = "hello";
    const char * search3 = "world";
    const char * search4 = "lo, wo";
    const char * search5 = ",";
    const char * search6 = "universe";
    const char * search7 = "hello, world & universe";

    AssertFalse( XSStringContainsCString( NULL, NULL ) );
    AssertFalse( XSStringContainsCString( str1, NULL ) );
    AssertFalse( XSStringContainsCString( NULL, search1 ) );

    AssertFalse( XSStringContainsCString( str1, search1 ) );
    AssertFalse( XSStringContainsCString( str2, search1 ) );

    AssertTrue( XSStringContainsCString( str2, search2 ) );
    AssertTrue( XSStringContainsCString( str2, search3 ) );
    AssertTrue( XSStringContainsCString( str2, search4 ) );
    AssertTrue( XSStringContainsCString( str2, search5 ) );
    AssertFalse( XSStringContainsCString( str2, search6 ) );
    AssertFalse( XSStringContainsCString( str2, search7 ) );

    XSRelease( str1 );
    XSRelease( str2 );
}

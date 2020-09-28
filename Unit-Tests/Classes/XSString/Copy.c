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
 * @file        Copy.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSString, Copy )
{
    XSStringRef        str1;
    XSMutableStringRef str2;
    XSStringRef        copy1;
    XSStringRef        copy2;

    str1 = XSStringCreateWithCString( "hello, world" );
    str2 = XSStringCreateMutable();

    XSStringAppendCString( str2, "hello, universe" );

    copy1 = XSCopy( str1 );
    copy2 = XSCopy( str2 );

    AssertTrue( copy1 != NULL );
    AssertTrue( copy2 != NULL );

    AssertTrue( copy1 != str1 );
    AssertTrue( copy2 != str2 );

    AssertFalse( XSStringIsMutable( copy1 ) );
    AssertFalse( XSStringIsMutable( copy2 ) );

    AssertTrue( XSEquals( str1, copy1 ) );
    AssertTrue( XSEquals( str2, copy2 ) );

    AssertStringEqual( XSStringGetCString( str1 ), "hello, world" );
    AssertStringEqual( XSStringGetCString( str2 ), "hello, universe" );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( copy1 );
    XSRelease( copy2 );
}

Test( XSString, Copy_LongString )
{
    XSStringRef        str1;
    XSMutableStringRef str2;
    XSStringRef        copy1;
    XSStringRef        copy2;

    str1 = XSStringCreateWithCString( "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );
    str2 = XSStringCreateMutable();

    XSStringAppendCString( str2, "Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat." );

    copy1 = XSCopy( str1 );
    copy2 = XSCopy( str2 );

    AssertTrue( copy1 != NULL );
    AssertTrue( copy2 != NULL );

    AssertTrue( copy1 != str1 );
    AssertTrue( copy2 != str2 );

    AssertFalse( XSStringIsMutable( copy1 ) );
    AssertFalse( XSStringIsMutable( copy2 ) );

    AssertTrue( XSEquals( str1, copy1 ) );
    AssertTrue( XSEquals( str2, copy2 ) );

    AssertStringEqual( XSStringGetCString( str1 ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );
    AssertStringEqual( XSStringGetCString( str2 ), "Ut wisi enim ad minim veniam, quis nostrud exerci tation ullamcorper suscipit lobortis nisl ut aliquip ex ea commodo consequat." );

    XSRelease( str1 );
    XSRelease( str2 );
    XSRelease( copy1 );
    XSRelease( copy2 );
}

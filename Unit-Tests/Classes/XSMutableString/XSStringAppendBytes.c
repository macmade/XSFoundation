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
 * @file        XSStringAppendBytes.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSMutableString, XSStringAppendBytes )
{
    XSMutableStringRef mutable = XSStringCreateMutable();
    const uint8_t * str1       = ( const uint8_t * )"hello";
    const uint8_t * str2       = ( const uint8_t * )"";
    const uint8_t * str3       = ( const uint8_t * )", world";
    const uint8_t * str4       = ( const uint8_t * )".";

    XSStringAppendBytes( mutable, str1, 5 );
    AssertEqual( XSStringGetLength( mutable ), 5 );
    AssertStringEqual( XSStringGetCString( mutable ), "hello" );

    XSStringAppendBytes( mutable, NULL, 0 );
    AssertEqual( XSStringGetLength( mutable ), 5 );
    AssertStringEqual( XSStringGetCString( mutable ), "hello" );

    XSStringAppendBytes( mutable, NULL, 42 );
    AssertEqual( XSStringGetLength( mutable ), 5 );
    AssertStringEqual( XSStringGetCString( mutable ), "hello" );

    XSStringAppendBytes( mutable, str2, 0 );
    AssertEqual( XSStringGetLength( mutable ), 5 );
    AssertStringEqual( XSStringGetCString( mutable ), "hello" );

    XSStringAppendBytes( mutable, str2, 1 );
    AssertEqual( XSStringGetLength( mutable ), 5 );
    AssertStringEqual( XSStringGetCString( mutable ), "hello" );

    XSStringAppendBytes( mutable, str3, 7 );
    AssertEqual( XSStringGetLength( mutable ), 12 );
    AssertStringEqual( XSStringGetCString( mutable ), "hello, world" );

    XSStringAppendBytes( mutable, str3, 3 );
    AssertEqual( XSStringGetLength( mutable ), 15 );
    AssertStringEqual( XSStringGetCString( mutable ), "hello, world, w" );

    {
        size_t expected = XSStringGetLength( mutable );

        for( size_t i = 0; i < 1024; i++ )
        {
            expected++;

            XSStringAppendBytes( mutable, str4, 1 );
            AssertEqual( XSStringGetLength( mutable ), expected );
        }
    }

    XSRelease( mutable );
}

Test( XSMutableString, XSStringAppendBytes_LongString )
{
    XSMutableStringRef mutable = XSStringCreateMutable();
    const uint8_t * str1       = ( const uint8_t * )"Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.";
    const uint8_t * str2       = ( const uint8_t * )"";
    const uint8_t * str3       = ( const uint8_t * )"Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.";
    const uint8_t * str4       = ( const uint8_t * )".";

    XSStringAppendBytes( mutable, str1, 144 );
    AssertEqual( XSStringGetLength( mutable ), 144 );
    AssertStringEqual( XSStringGetCString( mutable ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );

    XSStringAppendBytes( mutable, NULL, 0 );
    AssertEqual( XSStringGetLength( mutable ), 144 );
    AssertStringEqual( XSStringGetCString( mutable ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );

    XSStringAppendBytes( mutable, NULL, 42 );
    AssertEqual( XSStringGetLength( mutable ), 144 );
    AssertStringEqual( XSStringGetCString( mutable ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );

    XSStringAppendBytes( mutable, str2, 0 );
    AssertEqual( XSStringGetLength( mutable ), 144 );
    AssertStringEqual( XSStringGetCString( mutable ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );

    XSStringAppendBytes( mutable, str2, 1 );
    AssertEqual( XSStringGetLength( mutable ), 144 );
    AssertStringEqual( XSStringGetCString( mutable ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );

    XSStringAppendBytes( mutable, str3, 144 );
    AssertEqual( XSStringGetLength( mutable ), 288 );
    AssertStringEqual( XSStringGetCString( mutable ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );

    XSStringAppendBytes( mutable, str3, 3 );
    AssertEqual( XSStringGetLength( mutable ), 291 );
    AssertStringEqual( XSStringGetCString( mutable ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.Lor" );

    {
        size_t expected = XSStringGetLength( mutable );

        for( size_t i = 0; i < 1024; i++ )
        {
            expected++;

            XSStringAppendBytes( mutable, str4, 1 );
            AssertEqual( XSStringGetLength( mutable ), expected );
        }
    }

    XSRelease( mutable );
}

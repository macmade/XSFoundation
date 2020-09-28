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
 * @file        XSStringAppendFormatAndArguments.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

static void Append( XSMutableStringRef str, const char * fmt, ... )
{
    va_list ap;

    va_start( ap, fmt );

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-nonliteral"
#endif

    XSStringAppendFormatAndArguments( str, fmt, ap );

#ifdef __clang__
#pragma clang diagnostic pop
#endif

    va_end( ap );
}

Test( XSMutableString, XSStringAppendFormatAndArguments )
{
    XSMutableStringRef mutable = XSStringCreateMutable();
    const char * str1          = "hello";
    const char * str2          = "";
    const char * str3          = ", world";
    const char * str4          = ".";

    Append( mutable, "%s", str1 );
    AssertEqual( XSStringGetLength( mutable ), 5 );
    AssertStringEqual( XSStringGetCString( mutable ), "hello" );

    Append( mutable, NULL );
    AssertEqual( XSStringGetLength( mutable ), 5 );
    AssertStringEqual( XSStringGetCString( mutable ), "hello" );

    Append( mutable, "%s", str2 );
    AssertEqual( XSStringGetLength( mutable ), 5 );
    AssertStringEqual( XSStringGetCString( mutable ), "hello" );

    Append( mutable, "%s", str3 );
    AssertEqual( XSStringGetLength( mutable ), 12 );
    AssertStringEqual( XSStringGetCString( mutable ), "hello, world" );

    {
        size_t expected = XSStringGetLength( mutable );

        for( size_t i = 0; i < 1024; i++ )
        {
            expected++;

            Append( mutable, "%s", str4 );
            AssertEqual( XSStringGetLength( mutable ), expected );
        }
    }

    XSRelease( mutable );
}

Test( XSMutableString, XSStringAppendFormatAndArguments_LongString )
{
    XSMutableStringRef mutable = XSStringCreateMutable();
    const char * str1          = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.";
    const char * str2          = "";
    const char * str3          = "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.";
    const char * str4          = ".";

    Append( mutable, "%s", str1 );
    AssertEqual( XSStringGetLength( mutable ), 144 );
    AssertStringEqual( XSStringGetCString( mutable ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );

    Append( mutable, NULL );
    AssertEqual( XSStringGetLength( mutable ), 144 );
    AssertStringEqual( XSStringGetCString( mutable ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );

    Append( mutable, "%s", str2 );
    AssertEqual( XSStringGetLength( mutable ), 144 );
    AssertStringEqual( XSStringGetCString( mutable ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );

    Append( mutable, "%s", str3 );
    AssertEqual( XSStringGetLength( mutable ), 288 );
    AssertStringEqual( XSStringGetCString( mutable ), "Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat.Lorem ipsum dolor sit amet, consectetuer adipiscing elit, sed diam nonummy nibh euismod tincidunt ut laoreet dolore magna aliquam erat volutpat." );

    {
        size_t expected = XSStringGetLength( mutable );

        for( size_t i = 0; i < 1024; i++ )
        {
            expected++;

            Append( mutable, "%s", str4 );
            AssertEqual( XSStringGetLength( mutable ), expected );
        }
    }

    XSRelease( mutable );
}

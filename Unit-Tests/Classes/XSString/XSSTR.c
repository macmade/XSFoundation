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
 * @file        XSSTR.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

Test( XSString, XSSTR )
{
    XSStringRef str1 = XSSTR( "hello, world" );
    XSStringRef str2 = XSSTR( "hello, world" );
    XSStringRef str3 = XSSTR( "hello, universe" );
    XSStringRef str4 = XSSTR( "" );

    AssertTrue( str1 != NULL );
    AssertTrue( str2 != NULL );
    AssertTrue( str3 != NULL );
    AssertTrue( str4 != NULL );

    AssertTrue( XSRuntimeIsConstantObject( str1 ) );
    AssertTrue( XSRuntimeIsConstantObject( str2 ) );
    AssertTrue( XSRuntimeIsConstantObject( str3 ) );
    AssertTrue( XSRuntimeIsConstantObject( str4 ) );

    AssertEqual( XSStringGetLength( str1 ), 12 );
    AssertEqual( XSStringGetLength( str2 ), 12 );
    AssertEqual( XSStringGetLength( str3 ), 15 );
    AssertEqual( XSStringGetLength( str4 ), 0 );

    AssertStringEqual( XSStringGetCString( str1 ), "hello, world" );
    AssertStringEqual( XSStringGetCString( str2 ), "hello, world" );
    AssertStringEqual( XSStringGetCString( str3 ), "hello, universe" );
    AssertStringEqual( XSStringGetCString( str4 ), "" );

    AssertTrue( str1 == str2 );
}

Test( XSString, XSSTR_Multiple )
{
    XSSTR( "hello, world: #1" );
    XSSTR( "hello, world: #2" );
    XSSTR( "hello, world: #3" );
    XSSTR( "hello, world: #4" );
    XSSTR( "hello, world: #5" );
    XSSTR( "hello, world: #6" );
    XSSTR( "hello, world: #7" );
    XSSTR( "hello, world: #8" );
    XSSTR( "hello, world: #9" );
    XSSTR( "hello, world: #10" );
    XSSTR( "hello, world: #11" );
    XSSTR( "hello, world: #12" );
    XSSTR( "hello, world: #13" );
    XSSTR( "hello, world: #14" );
    XSSTR( "hello, world: #15" );
    XSSTR( "hello, world: #16" );
    XSSTR( "hello, world: #17" );
    XSSTR( "hello, world: #18" );
    XSSTR( "hello, world: #19" );
    XSSTR( "hello, world: #20" );
    XSSTR( "hello, world: #21" );
    XSSTR( "hello, world: #22" );
    XSSTR( "hello, world: #23" );
    XSSTR( "hello, world: #24" );
    XSSTR( "hello, world: #25" );
    XSSTR( "hello, world: #26" );
    XSSTR( "hello, world: #27" );
    XSSTR( "hello, world: #28" );
    XSSTR( "hello, world: #29" );
    XSSTR( "hello, world: #30" );
    XSSTR( "hello, world: #31" );
    XSSTR( "hello, world: #32" );
    XSSTR( "hello, world: #33" );
    XSSTR( "hello, world: #34" );
    XSSTR( "hello, world: #35" );
    XSSTR( "hello, world: #36" );
    XSSTR( "hello, world: #37" );
    XSSTR( "hello, world: #38" );
    XSSTR( "hello, world: #39" );
    XSSTR( "hello, world: #40" );
    XSSTR( "hello, world: #41" );
    XSSTR( "hello, world: #42" );
    XSSTR( "hello, world: #43" );
    XSSTR( "hello, world: #44" );
    XSSTR( "hello, world: #45" );
    XSSTR( "hello, world: #46" );
    XSSTR( "hello, world: #47" );
    XSSTR( "hello, world: #48" );
    XSSTR( "hello, world: #49" );
    XSSTR( "hello, world: #50" );
    XSSTR( "hello, world: #51" );
    XSSTR( "hello, world: #52" );
    XSSTR( "hello, world: #53" );
    XSSTR( "hello, world: #54" );
    XSSTR( "hello, world: #55" );
    XSSTR( "hello, world: #56" );
    XSSTR( "hello, world: #57" );
    XSSTR( "hello, world: #58" );
    XSSTR( "hello, world: #59" );
    XSSTR( "hello, world: #60" );
    XSSTR( "hello, world: #61" );
    XSSTR( "hello, world: #62" );
    XSSTR( "hello, world: #63" );
    XSSTR( "hello, world: #64" );
    XSSTR( "hello, world: #65" );
    XSSTR( "hello, world: #66" );
    XSSTR( "hello, world: #67" );
    XSSTR( "hello, world: #68" );
    XSSTR( "hello, world: #69" );
    XSSTR( "hello, world: #70" );
    XSSTR( "hello, world: #71" );
    XSSTR( "hello, world: #72" );
    XSSTR( "hello, world: #73" );
    XSSTR( "hello, world: #74" );
    XSSTR( "hello, world: #75" );
    XSSTR( "hello, world: #76" );
    XSSTR( "hello, world: #77" );
    XSSTR( "hello, world: #78" );
    XSSTR( "hello, world: #79" );
    XSSTR( "hello, world: #80" );
    XSSTR( "hello, world: #81" );
    XSSTR( "hello, world: #82" );
    XSSTR( "hello, world: #83" );
    XSSTR( "hello, world: #84" );
    XSSTR( "hello, world: #85" );
    XSSTR( "hello, world: #86" );
    XSSTR( "hello, world: #87" );
    XSSTR( "hello, world: #88" );
    XSSTR( "hello, world: #89" );
    XSSTR( "hello, world: #90" );
    XSSTR( "hello, world: #91" );
    XSSTR( "hello, world: #92" );
    XSSTR( "hello, world: #93" );
    XSSTR( "hello, world: #94" );
    XSSTR( "hello, world: #95" );
    XSSTR( "hello, world: #96" );
    XSSTR( "hello, world: #97" );
    XSSTR( "hello, world: #98" );
    XSSTR( "hello, world: #99" );
    XSSTR( "hello, world: #100" );
    XSSTR( "hello, world: #101" );
    XSSTR( "hello, world: #102" );
    XSSTR( "hello, world: #103" );
    XSSTR( "hello, world: #104" );
    XSSTR( "hello, world: #105" );
    XSSTR( "hello, world: #106" );
    XSSTR( "hello, world: #107" );
    XSSTR( "hello, world: #108" );
    XSSTR( "hello, world: #109" );
    XSSTR( "hello, world: #110" );
    XSSTR( "hello, world: #111" );
    XSSTR( "hello, world: #112" );
    XSSTR( "hello, world: #113" );
    XSSTR( "hello, world: #114" );
    XSSTR( "hello, world: #115" );
    XSSTR( "hello, world: #116" );
    XSSTR( "hello, world: #117" );
    XSSTR( "hello, world: #118" );
    XSSTR( "hello, world: #119" );
    XSSTR( "hello, world: #120" );
    XSSTR( "hello, world: #121" );
    XSSTR( "hello, world: #122" );
    XSSTR( "hello, world: #123" );
    XSSTR( "hello, world: #124" );
    XSSTR( "hello, world: #125" );
    XSSTR( "hello, world: #126" );
    XSSTR( "hello, world: #127" );
    XSSTR( "hello, world: #128" );
    XSSTR( "hello, world: #129" );
    XSSTR( "hello, world: #130" );
    XSSTR( "hello, world: #131" );
    XSSTR( "hello, world: #132" );
    XSSTR( "hello, world: #133" );
    XSSTR( "hello, world: #134" );
    XSSTR( "hello, world: #135" );
    XSSTR( "hello, world: #136" );
    XSSTR( "hello, world: #137" );
    XSSTR( "hello, world: #138" );
    XSSTR( "hello, world: #139" );
    XSSTR( "hello, world: #140" );
    XSSTR( "hello, world: #141" );
    XSSTR( "hello, world: #142" );
    XSSTR( "hello, world: #143" );
    XSSTR( "hello, world: #144" );
    XSSTR( "hello, world: #145" );
    XSSTR( "hello, world: #146" );
    XSSTR( "hello, world: #147" );
    XSSTR( "hello, world: #148" );
    XSSTR( "hello, world: #149" );
    XSSTR( "hello, world: #150" );
    XSSTR( "hello, world: #151" );
    XSSTR( "hello, world: #152" );
    XSSTR( "hello, world: #153" );
    XSSTR( "hello, world: #154" );
    XSSTR( "hello, world: #155" );
    XSSTR( "hello, world: #156" );
    XSSTR( "hello, world: #157" );
    XSSTR( "hello, world: #158" );
    XSSTR( "hello, world: #159" );
    XSSTR( "hello, world: #160" );
    XSSTR( "hello, world: #161" );
    XSSTR( "hello, world: #162" );
    XSSTR( "hello, world: #163" );
    XSSTR( "hello, world: #164" );
    XSSTR( "hello, world: #165" );
    XSSTR( "hello, world: #166" );
    XSSTR( "hello, world: #167" );
    XSSTR( "hello, world: #168" );
    XSSTR( "hello, world: #169" );
    XSSTR( "hello, world: #170" );
    XSSTR( "hello, world: #171" );
    XSSTR( "hello, world: #172" );
    XSSTR( "hello, world: #173" );
    XSSTR( "hello, world: #174" );
    XSSTR( "hello, world: #175" );
    XSSTR( "hello, world: #176" );
    XSSTR( "hello, world: #177" );
    XSSTR( "hello, world: #178" );
    XSSTR( "hello, world: #179" );
    XSSTR( "hello, world: #180" );
    XSSTR( "hello, world: #181" );
    XSSTR( "hello, world: #182" );
    XSSTR( "hello, world: #183" );
    XSSTR( "hello, world: #184" );
    XSSTR( "hello, world: #185" );
    XSSTR( "hello, world: #186" );
    XSSTR( "hello, world: #187" );
    XSSTR( "hello, world: #188" );
    XSSTR( "hello, world: #189" );
    XSSTR( "hello, world: #190" );
    XSSTR( "hello, world: #191" );
    XSSTR( "hello, world: #192" );
    XSSTR( "hello, world: #193" );
    XSSTR( "hello, world: #194" );
    XSSTR( "hello, world: #195" );
    XSSTR( "hello, world: #196" );
    XSSTR( "hello, world: #197" );
    XSSTR( "hello, world: #198" );
    XSSTR( "hello, world: #199" );
    XSSTR( "hello, world: #200" );
    XSSTR( "hello, world: #201" );
    XSSTR( "hello, world: #202" );
    XSSTR( "hello, world: #203" );
    XSSTR( "hello, world: #204" );
    XSSTR( "hello, world: #205" );
    XSSTR( "hello, world: #206" );
    XSSTR( "hello, world: #207" );
    XSSTR( "hello, world: #208" );
    XSSTR( "hello, world: #209" );
    XSSTR( "hello, world: #210" );
    XSSTR( "hello, world: #211" );
    XSSTR( "hello, world: #212" );
    XSSTR( "hello, world: #213" );
    XSSTR( "hello, world: #214" );
    XSSTR( "hello, world: #215" );
    XSSTR( "hello, world: #216" );
    XSSTR( "hello, world: #217" );
    XSSTR( "hello, world: #218" );
    XSSTR( "hello, world: #219" );
    XSSTR( "hello, world: #220" );
    XSSTR( "hello, world: #221" );
    XSSTR( "hello, world: #222" );
    XSSTR( "hello, world: #223" );
    XSSTR( "hello, world: #224" );
    XSSTR( "hello, world: #225" );
    XSSTR( "hello, world: #226" );
    XSSTR( "hello, world: #227" );
    XSSTR( "hello, world: #228" );
    XSSTR( "hello, world: #229" );
    XSSTR( "hello, world: #230" );
    XSSTR( "hello, world: #231" );
    XSSTR( "hello, world: #232" );
    XSSTR( "hello, world: #233" );
    XSSTR( "hello, world: #234" );
    XSSTR( "hello, world: #235" );
    XSSTR( "hello, world: #236" );
    XSSTR( "hello, world: #237" );
    XSSTR( "hello, world: #238" );
    XSSTR( "hello, world: #239" );
    XSSTR( "hello, world: #240" );
    XSSTR( "hello, world: #241" );
    XSSTR( "hello, world: #242" );
    XSSTR( "hello, world: #243" );
    XSSTR( "hello, world: #244" );
    XSSTR( "hello, world: #245" );
    XSSTR( "hello, world: #246" );
    XSSTR( "hello, world: #247" );
    XSSTR( "hello, world: #248" );
    XSSTR( "hello, world: #249" );
    XSSTR( "hello, world: #250" );
    XSSTR( "hello, world: #251" );
    XSSTR( "hello, world: #252" );
    XSSTR( "hello, world: #253" );
    XSSTR( "hello, world: #254" );
    XSSTR( "hello, world: #255" );
    XSSTR( "hello, world: #256" );
    XSSTR( "hello, world: #257" );
    XSSTR( "hello, world: #258" );
    XSSTR( "hello, world: #259" );
    XSSTR( "hello, world: #260" );

    AssertTrue( true );
}

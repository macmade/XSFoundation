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
 * @file        XSVLogWithInfos.c
 * @copyright   (c) 202o - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definitions for XSVLogWithInfos
 */

#include <XS/XS.h>
#include <XS/Private/Functions/Log.h>

void XSVLogWithInfos( XSLogLevel level, const char * file, int line, const char * func, const char * fmt, va_list args )
{
    ( void )level;
    ( void )file;
    ( void )line;
    ( void )func;
    ( void )fmt;
    ( void )args;

    /*
    while( XSAtomic_CompareAndSwapInteger( 0, 0, &__XSLog_IsPaused ) == false )
        ;

    if( ( XSGetLogLevel() & level ) != 0 )
    {
        __XSLog_StartLog( level, file, line, func );
        vfprintf( stderr, fmt, args );
        __XSLog_EndLog();
    }*/
}
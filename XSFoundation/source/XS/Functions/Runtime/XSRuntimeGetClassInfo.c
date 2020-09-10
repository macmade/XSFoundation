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
 * @file        XSRuntimeGetClassInfo.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSRuntimeGetClassInfo
 */

#include <XS/XS.h>
#include <XS/Private/Functions/Runtime.h>

const XSRuntimeClassInfoList * XSRuntimeGetClassInfo( XSClassID classID )
{
    XSRuntimeClassInfoList * info;

    if( XS_RUNTIME_IS_FINALIZING || XS_RUNTIME_IS_FINALIZED )
    {
        return NULL;
    }

    if( XS_RUNTIME_IS_INITED == false )
    {
        XSFatalError( "XSFoundation runtime has not been inited. Please call XSRuntimeInitialize()" );
    }

    if( XSRuntimeIsRegisteredClass( classID ) == false )
    {
        return NULL;
    }

    info = XSRuntimeClasses;

    while( --classID && info != NULL )
    {
        info = info->next;
    }

    return info;
}

/*******************************************************************************
 * Copyright (c) 2011, Jean-David Gadina <macmade@eosgarden.com>
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/
 
/* $Id$ */

/*!
 * @file        __XSURLRequest.c
 * @brief       Private implementation for the XSURLRequest class
 * @author      Jean-David Gadina <macmade@eosgarden.com>
 */

#include "XS.h"
#include "__XSURLRequest.h"

/*!
 * @var         __XSURLRequestClass
 * @brief       Runtime class definition
 */
static const XSClassInfos __XSURLRequestClass =
{
    "XSURLRequest",             /* Class name */
    sizeof( __XSURLRequest ),   /* Object size */
    __XSURLRequest_Construct,   /* Constructor */
    __XSURLRequest_Destruct,    /* Destructor */
    NULL,                       /* Default initializer */
    __XSURLRequest_Copy,        /* Object copy */
    NULL,                       /* Object description */
    NULL                        /* Object comparison */
};

/*!
 * @var         __XSURLRequestClassID
 * @brief       Type ID for the runtime class
 */
XSClassID __XSURLRequestClassID;

void __XSURLRequest_Initialize( void )
{
    __XSURLRequestClassID = XSRuntime_RegisterClass( &__XSURLRequestClass );
    
    XSRuntime_BindMethodToClassID( __XSURLRequestClassID, ( void ( * )( void ) )XSURLRequest_InitWithURL, "InitWithURL", "XSString" );
    XSRuntime_BindMethodToClassID( __XSURLRequestClassID, ( void ( * )( void ) )XSURLRequest_GetURL, "GetURL", "XSURL" );
    XSRuntime_BindMethodToClassID( __XSURLRequestClassID, ( void ( * )( void ) )XSURLRequest_GetHTTPHeaders, "GetHTTPHeaders", "XSDictionary" );
    XSRuntime_BindMethodToClassID( __XSURLRequestClassID, ( void ( * )( void ) )XSURLRequest_GetRawBody, "GetRawBody", "XSData" );
    XSRuntime_BindMethodToClassID( __XSURLRequestClassID, ( void ( * )( void ) )XSURLRequest_Start, "Start", "void" );
}

void __XSURLRequest_Construct( XSObject object )
{
    __XSURLRequest * req;
    
    req = ( __XSURLRequest * )object;
    
    req->headers = XSDictionary_Init( XSDictionary_Alloc() );
    req->data    = XSData_InitWithCapacity( XSData_Alloc(), 20000 );
}

void __XSURLRequest_Destruct( XSObject object )
{
    __XSURLRequest * req;
    
    req = ( __XSURLRequest * )object;
    
    XSRelease( req->url );
    XSRelease( req->host );
    XSRelease( req->status );
    XSRelease( req->headers );
    XSRelease( req->data );
}

void __XSURLRequest_Copy( XSObject source, XSObject destination )
{
    __XSURLRequest * req1;
    __XSURLRequest * req2;
    
    req1 = ( __XSURLRequest * )source;
    req2 = ( __XSURLRequest * )destination;
    
    req2->url     = XSCopy( req2->url );
    req1->host    = XSCopy( req1->host );
    req1->status  = XSCopy( req1->status );
    req1->headers = XSCopy( req1->headers );
    req1->data    = XSCopy( req1->data );
}

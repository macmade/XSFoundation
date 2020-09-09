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

/* $Id$ */

/*!
 * @header      XSXMLParserRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSXMLParserRef.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_XML_PARSER_H__
#define __XS___PRIVATE_CLASSES_XS_XML_PARSER_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @struct      __XSXMLParser
 * @abstract    Structure for XSXMLParser
 */
struct __XSXMLParser
{
    void * dummy;  /*! Dummy... */
};

/*!
 * @var         __XSXMLParser_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSXMLParser_ClassID;

/*!
 * @var         __XSXMLParser_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSXMLParser_Class;

/*!
 * @function    __XSXMLParser_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSXMLParser_Initialize( void );

/*!
 * @function    __XSXMLParser_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSXMLParserRef __XSXMLParser_Constructor( XSXMLParserRef object );

/*!
 * @function    __XSXMLParser_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSXMLParser_Destructor( XSXMLParserRef object );

/*!
 * @function    __XSXMLParser_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSXMLParserRef __XSXMLParser_Copy( XSXMLParserRef source, XSXMLParserRef destination );

/*!
 * @function    __XSXMLParser_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSXMLParser_Equals( XSXMLParserRef object1, XSXMLParserRef object2 );

/*!
 * @function    __XSXMLParser_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSXMLParser_ToString( XSXMLParserRef object );

/*!
 * @function    __XSXMLParser_Create
 * @abstract    Creates an XSXMLParser object
 * @return      The XSXMLParser object
 */
XSStatic struct __XSXMLParser * __XSXMLParser_Create( void );

#endif /* __XS___PRIVATE_CLASSES_XS_XML_PARSER_H__ */

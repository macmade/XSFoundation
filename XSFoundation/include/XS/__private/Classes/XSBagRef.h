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
 * @header      XSBagRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSBagRef.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_BAG_H__
#define __XS___PRIVATE_CLASSES_XS_BAG_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @struct      __XSBag
 * @abstract    Structure for XSBag
 */
struct __XSBag
{
    void * temp; /*! Not yet implemented... */
};

/*!
 * @var         __XSBag_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSBag_ClassID;

/*!
 * @var         __XSBag_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSBag_Class;

/*!
 * @function    __XSBag_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSBag_Initialize( void );

/*!
 * @function    __XSBag_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSBagRef __XSBag_Constructor( XSBagRef object );

/*!
 * @function    __XSBag_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSBag_Destructor( XSBagRef object );

/*!
 * @function    __XSBag_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSBagRef __XSBag_Copy( XSBagRef source, XSBagRef destination );

/*!
 * @function    __XSBag_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSBag_Equals( XSBagRef object1, XSBagRef object2 );

/*!
 * @function    __XSBag_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSBag_ToString( XSBagRef object );

/*!
 * @function    __XSAutoreleasePool_Create
 * @abstract    Creates an XSBag object
 * @return      The XSBag object
 */
XSStatic struct __XSBag * __XSBag_Create( void );

#endif /* __XS___PRIVATE_CLASSES_XS_BAG_H__ */

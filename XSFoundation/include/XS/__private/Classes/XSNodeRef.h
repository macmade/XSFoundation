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
 * @header      XSNodeRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSNodeRef.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_NODE_H__
#define __XS___PRIVATE_CLASSES_XS_NODE_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @struct      __XSNode
 * @abstract    Structure for XSNode
 */
struct __XSNode
{
    void * temp; /*! Not yet implemented... */
};

/*!
 * @var         __XSNode_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSNode_ClassID;

/*!
 * @var         __XSNode_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSNode_Class;

/*!
 * @function    __XSNode_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSNode_Initialize( void );

/*!
 * @function    __XSNode_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSNodeRef __XSNode_Constructor( XSNodeRef object );

/*!
 * @function    __XSNode_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSNode_Destructor( XSNodeRef object );

/*!
 * @function    __XSNode_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSNodeRef __XSNode_Copy( XSNodeRef source, XSNodeRef destination );

/*!
 * @function    __XSNode_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSNode_Equals( XSNodeRef object1, XSNodeRef object2 );

/*!
 * @function    __XSNode_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSNode_ToString( XSNodeRef object );

/*!
 * @function    __XSNode_Create
 * @abstract    Creates an XSNode object
 * @return      The XSNode object
 */
XSStatic struct __XSNode * __XSNode_Create( void );

#endif /* __XS___PRIVATE_CLASSES_XS_NODE_H__ */

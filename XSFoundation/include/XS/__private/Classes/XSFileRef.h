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
 * @header      XSFileRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSFileRef.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_FILE_H__
#define __XS___PRIVATE_CLASSES_XS_FILE_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @struct      __XSFile
 * @abstract    Structure for XSFile
 */
struct __XSFile
{
    void * temp; /*! Not yet implemented... */
};

/*!
 * @var         __XSFile_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSFile_ClassID;

/*!
 * @var         __XSFile_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSFile_Class;

/*!
 * @function    __XSFile_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSFile_Initialize( void );

/*!
 * @function    __XSFile_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSFileRef __XSFile_Constructor( XSFileRef object );

/*!
 * @function    __XSFile_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSFile_Destructor( XSFileRef object );

/*!
 * @function    __XSFile_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSFileRef __XSFile_Copy( XSFileRef source, XSFileRef destination );

/*!
 * @function    __XSFile_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSFile_Equals( XSFileRef object1, XSFileRef object2 );

/*!
 * @function    __XSFile_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSFile_ToString( XSFileRef object );

/*!
 * @function    __XSFile_Create
 * @abstract    Creates an XSFile object
 * @return      The XSFile object
 */
XSStatic struct __XSFile * __XSFile_Create( void );

#endif /* __XS___PRIVATE_CLASSES_XS_FILE_H__ */

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
 * @header      XSBoolean.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private declarations for the XSBoolean class
 */

#ifndef XS_PRIVATE_CLASSES_XS_BOOLEAN_H
#define XS_PRIVATE_CLASSES_XS_BOOLEAN_H

#include <XS/Macros.h>
#include <XS/Types.h>
#include <stdbool.h>

XS_EXTERN_C_BEGIN

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

/*!
 * @struct      XSBoolean
 * @abstract    XSBoolean instance
 */
struct XSBoolean
{
    bool value;
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
XS_EXTERN_C_END

/*!
 * @var         XSBooleanClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID XSBooleanClassID;

/*!
 * @var         XSBooleanClass
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo XSBooleanClass;

/*!
 * @var         XSBooleanTrueInstance
 * @abstract    Shared instance for the `true` value
 */
XS_EXTERN struct XSBoolean * XSBooleanTrueInstance;

/*!
 * @var         XSBooleanFalseInstance
 * @abstract    Shared instance for the `false` value
 */
XS_EXTERN struct XSBoolean * XSBooleanFalseInstance;

/*!
 * @function    XSBooleanInitialize
 * @abstract    Class initializer
 */
void XSBooleanInitialize( void );

/*!
 * @function    XSBooleanFinalize
 * @abstract    Class finalizer
 */
void XSBooleanFinalize( void );

/*!
 * @function    XSBooleanCopy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSMutableObjectRef XSBooleanCopy( XSObjectRef source, XSMutableObjectRef destination );

/*!
 * @function    XSBooleanEquals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool XSBooleanEquals( XSObjectRef object1, XSObjectRef object2 );

/*!
 * @typedef     XSBooleanToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
XSStringRef XSBooleanToString( XSObjectRef object );

#endif /* XS_PRIVATE_CLASSES_XS_BOOLEAN_H */

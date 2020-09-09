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
 * @header      XSStringRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSStringRef.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_STRING_H__
#define __XS___PRIVATE_CLASSES_XS_STRING_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     __XSString_Properties
 * @abstract    String properties
 */
typedef enum
{
    __XSString_PropertiesMutable = 0x01  /*! String is mutable */
}
__XSString_Properties;

/*!
 * @struct      __XSString
 * @abstract    Structure for XSString
 */
struct __XSString
{
    char              * cString;        /*! The C string */
    XSRecursiveLockRef  lock;           /*! The lock for thread-safety */
    XSUInteger          length;         /* The length */
    XSUInteger          capacity;       /*! The string capacity */
    int                 properties;     /*! The string properties */
    char                 _pad_0[ 4 ];   /*! Padding */
};

/*!
 * @var         __XSString_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSString_ClassID;

/*!
 * @var         __XSString_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSString_Class;

/*!
 * @function    __XSString_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSString_Initialize( void );

/*!
 * @function    __XSString_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSStringRef __XSString_Constructor( XSStringRef object );

/*!
 * @function    __XSString_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSString_Destructor( XSStringRef object );

/*!
 * @function    __XSString_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSStringRef __XSString_Copy( XSStringRef source, XSStringRef destination );

/*!
 * @function    __XSString_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSString_Equals( XSStringRef object1, XSStringRef object2 );

/*!
 * @function    __XSString_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSString_ToString( XSStringRef object );

/*!
 * @function    __XSString_Create
 * @abstract    Creates an XSString object
 * @return      The XSString object
 */
XSStatic struct __XSString * __XSString_Create( void );

/*!
 * @function    __XSString_Lock
 * @abstract    Locks the internal string lock if necessary
 * @param       object      The string object
 * @discussion  Locking will only occure if the string is mutable, as immutable
 *              strings are de-facto thread-safe. This allows the same code
 *              for both string types, with a performance gain on immutable ones.
 */
void __XSString_Lock( XSStringRef object );

/*!
 * @function    __XSString_Unlock
 * @abstract    Unlocks the internal string lock if necessary
 * @param       object      The string object
 * @discussion  Unlocking will only occure if the string is mutable, as immutable
 *              strings are de-facto thread-safe. This allows the same code
 *              for both string types, with a performance gain on immutable ones.
 */
void __XSString_Unlock( XSStringRef object );

#endif /* __XS___PRIVATE_CLASSES_XS_STRING_H__ */

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
 * @header      XSDataRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSDataRef.h
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_DATA_H__
#define __XS___PRIVATE_CLASSES_XS_DATA_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @typedef     __XSData_Properties
 * @abstract    Data object properties
 */
typedef enum
{
    __XSData_PropertiesMutable = 0x01   /*! Data object is mutable */
}
__XSData_Properties;

/*!
 * @struct      __XSData
 * @abstract    Structure for XSData
 */
struct __XSData
{
    XSUInt8                   * buffer;         /*! The byte buffer */
    XSRecursiveLockRef          lock;           /*! The lock for thread-safety */
    XSUInteger                  length;         /*! The length of the byte buffer */
    XSUInteger                  capacity;       /*! The capacity of the byte buffer */
    XSData_BufferReleaseType    releaseType;    /*! The release type for the byte buffer */
    int                         properties;     /*! The data object properties */
};

/*!
 * @var         __XSData_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSData_ClassID;

/*!
 * @var         __XSData_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSData_Class;

/*!
 * @function    __XSData_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSData_Initialize( void );

/*!
 * @function    __XSData_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSDataRef __XSData_Constructor( XSDataRef object );

/*!
 * @function    __XSData_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSData_Destructor( XSDataRef object );

/*!
 * @function    __XSData_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSDataRef __XSData_Copy( XSDataRef source, XSDataRef destination );

/*!
 * @function    __XSData_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSData_Equals( XSDataRef object1, XSDataRef object2 );

/*!
 * @function    __XSData_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSData_ToString( XSDataRef object );

/*!
 * @function    __XSData_Create
 * @abstract    Creates an XSData object
 * @return      The XSData object
 */
XSStatic struct __XSData * __XSData_Create( void );

/*!
 * @function    __XSData_Lock
 * @abstract    Locks the internal data lock if necessary
 * @param       data        The data
 * @discussion  Locking will only occure if the data is mutable, as immutable
 *              datas are de-facto thread-safe. This allows the same code
 *              for both data types, with a performance gain on immutable ones.
 */
void __XSData_Lock( XSDataRef data );

/*!
 * @function    __XSData_Lock
 * @abstract    Unlocks the internal array lock if necessary
 * @param       data        The data
 * @discussion  Unlocking will only occure if the data is mutable, as immutable
 *              datas are de-facto thread-safe. This allows the same code
 *              for both data types, with a performance gain on immutable ones.
 */
void __XSData_Unlock( XSDataRef data );

#endif /* __XS___PRIVATE_CLASSES_XS_DATA_H__ */

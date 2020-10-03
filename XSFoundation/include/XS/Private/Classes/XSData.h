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
 * @header      XSData.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private declarations for the XSData class
 */

#ifndef XS_PRIVATE_CLASSES_XS_DATA_H
#define XS_PRIVATE_CLASSES_XS_DATA_H

#include <XS/Macros.h>
#include <XS/Types.h>
#include <stddef.h>
#include <stdint.h>

XS_EXTERN_C_BEGIN

/*!
 * @enum        XSDataFlags
 * @abstract    Flags for XSData instances
 */
enum XSDataFlags
{
    XSDataFlagsMutable = 1 << 1,
    XSDataFlagsNoCopy  = 1 << 2
};

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

/*!
 * @union       XSDataStorage
 * @abstract    Storage for XSData bytes
 */
union XSDataStorage
{
    const uint8_t * ptr;         /*! The data bytes (external storage) */
    uint8_t         bytes[ 32 ]; /*! The data bytes (internal storage) */
};

/*!
 * @struct      XSData
 * @abstract    XSData instance
 */
struct XSData
{
    union XSDataStorage storage;
    size_t              length;   /*! Length of the data bytes */
    size_t              capacity; /*! Capacity of the data bytes storage - 0 for internal storage */
    uint64_t            flags;    /*! Instance flags */
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
XS_EXTERN_C_END

/*!
 * @var         XSDataClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID XSDataClassID;

/*!
 * @var         XSDataClass
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo XSDataClass;

/*!
 * @var         XSDataEmpty
 * @abstract    Empty data shared instance
 */
XS_EXTERN struct XSData * XSDataEmpty;

/*!
 * @function    XSDataInitialize
 * @abstract    Class initializer
 */
void XSDataInitialize( void );

/*!
 * @function    XSDataDestructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void XSDataDestructor( XSMutableObjectRef object );

/*!
 * @function    XSDataCopy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSMutableObjectRef XSDataCopy( XSObjectRef source, XSMutableObjectRef destination );

/*!
 * @function    XSDataEquals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool XSDataEquals( XSObjectRef object1, XSObjectRef object2 );

/*!
 * @function    XSDataHash
 * @abstract    Class hash callback
 * @param       object      The object to hash
 * @return      The object's hash
 */
uint64_t XSDataHash( XSObjectRef object );

/*!
 * @typedef     XSDataToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
XSStringRef XSDataToString( XSObjectRef object );

#endif /* XS_PRIVATE_CLASSES_XS_DATA_H */

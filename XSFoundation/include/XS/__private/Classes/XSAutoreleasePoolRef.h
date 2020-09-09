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
 * @header      XSAutoreleasePoolRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSAutoreleasePoolRef.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_AUTORELEASE_POOL_H__
#define __XS___PRIVATE_CLASSES_XS_AUTORELEASE_POOL_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @struct      __XSAutoreleasePool_List
 * @abstract    Autorelease pool list
 */
typedef struct __XSAutoreleasePool_ListStruct
{
    XSAutoreleasePoolRef                    ap;
    struct __XSAutoreleasePool_ListStruct * next;
}
__XSAutoreleasePool_List;

/*!
 * @typedef     __XSAutoreleasePool_Value
 * @abstract    Autorelease pool value holder
 */
typedef struct __XSAutoreleasePool_ValueStruct
{
    XSObjectRef                              object;    /*! The contained object */
    struct __XSAutoreleasePool_ValueStruct * next;      /*! The next value */
}
__XSAutoreleasePool_Value;

/*!
 * @struct      __XSAutoreleasePool
 * @abstract    Structure for XSAutoreleasePool
 */
struct __XSAutoreleasePool
{
    __XSAutoreleasePool_Value * first;    /* The first value */
    XSUInteger                  threadID; /*! The ID of the thread the autorelease pool belongs to */
};

/*!
 * @var         __XSAutoreleasePool_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSAutoreleasePool_ClassID;

/*!
 * @var         __XSAutoreleasePool_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSAutoreleasePool_Class;

/*!
 * @var         __XSAutoreleasePool_TLSKey
 * @abstract    The TLS key for autorelease pools
 */
XS_EXTERN XSTLSKey __XSAutoreleasePool_TLSKey;

/*!
 * @function    __XSAutoreleasePool_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSAutoreleasePool_Initialize( void );

/*!
 * @function    __XSAutoreleasePool_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSAutoreleasePoolRef __XSAutoreleasePool_Constructor( XSAutoreleasePoolRef object );

/*!
 * @function    __XSAutoreleasePool_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSAutoreleasePool_Destructor( XSAutoreleasePoolRef object );

/*!
 * @function    __XSAutoreleasePool_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSAutoreleasePoolRef __XSAutoreleasePool_Copy( XSAutoreleasePoolRef source, XSAutoreleasePoolRef destination );

/*!
 * @function    __XSAutoreleasePool_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSAutoreleasePool_Equals( XSAutoreleasePoolRef object1, XSAutoreleasePoolRef object2 );

/*!
 * @function    __XSAutoreleasePool_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSAutoreleasePool_ToString( XSAutoreleasePoolRef object );

/*!
 * @function    __XSAutoreleasePool_Create
 * @abstract    Creates an XSAutoreleasePool object
 * @return      The XSAutoreleasePool object
 */
XSStatic struct __XSAutoreleasePool * __XSAutoreleasePool_Create( void );

/*!
 * @function    __XSAutoreleasePool_Exit
 * @abstract    Class finalizer
 */
void __XSAutoreleasePool_Exit( void );

/*!
 * @function    __XSAutoreleasePool_Register
 * @abstract    Registers an autorelease pool in the current thread
 * @param       ap          The autorelease pool
 */
void __XSAutoreleasePool_Register( XSAutoreleasePoolRef ap );

/*!
 * @function    __XSAutoreleasePool_Unregister
 * @abstract    Unregisters an autorelease pool in the current thread
 * @param       ap          The autorelease pool
 */
void __XSAutoreleasePool_Unregister( XSAutoreleasePoolRef ap );

/*!
 * @function    __XSAutoreleasePool_GetCurrent
 * @abstract    Gets the current autorepease pool for the current thread
 * @return      The current autorelease pool, if one exists
 */
XSAutoreleasePoolRef __XSAutoreleasePool_GetCurrent( void );

#endif /* __XS___PRIVATE_CLASSES_XS_AUTORELEASE_POOL_H__ */

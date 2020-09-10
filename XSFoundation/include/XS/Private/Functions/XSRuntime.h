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
 * @header      XSRuntime.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSRuntime.h
 */

#ifndef XS_PRIVATE_FUNCTIONS_XS_RUNTIME_H
#define XS_PRIVATE_FUNCTIONS_XS_RUNTIME_H

#include <XS/Macros.h>
#include <XS/Types/XSClassID.h>
#include <XS/Types/XSClassInfo.h>
#include <XS/Types/XSObjectRef.h>
#include <XS/Types/XSInitStatus.h>
#include <XS/Types/XSClassCallbackConstructor.h>
#include <XS/Types/XSClassCallbackDestructor.h>
#include <XS/Types/XSClassCallbackCopy.h>
#include <XS/Types/XSClassCallbackEquals.h>
#include <XS/Types/XSClassCallbackToString.h>
#include <stdint.h>
#include <stddef.h>

XS_EXTERN_C_BEGIN

/*!
 * @typedef     XSRuntimeClassInfoList
 * @abstract    Linked list for the XSFoundation class infos
 */
typedef struct XSRuntimeClassInfoListStruct
{
    const XSClassInfo *                   cls;            /*! The class info */
    XSObjectRef *                         sharedInstance; /*! The shared instance, if any */
    struct XSRuntimeClassInfoListStruct * next;           /*! The next entry, if any */
} XSRuntimeClassInfoList;

/*!
 * @define      XS_RUNTIME_IS_INITED
 * @abstract    Checks whether the XSFoundation runtime is inited
 */
#define XS_RUNTIME_IS_INITED XSAtomicCompareAndSwap64( XSInitStatusInited, XSInitStatusInited, &XSRuntimeInitStatus )

/*!
 * @define      XS_RUNTIME_IS_FINALIZING
 * @abstract    Checks whether the XSFoundation runtime is finalizing
 */
#define XS_RUNTIME_IS_FINALIZING XSAtomicCompareAndSwap64( XSInitStatusFinalizing, XSInitStatusFinalizing, &XSRuntimeInitStatus )

/*!
 * @define      XS_RUNTIME_IS_FINALIZED
 * @abstract    Checks whether the XSFoundation runtime is finalized
 */
#define XS_RUNTIME_IS_FINALIZED XSAtomicCompareAndSwap64( XSInitStatusFinalized, XSInitStatusFinalized, &XSRuntimeInitStatus )

/*!
 * @var         XSRuntimeInitStatus
 * @abstract    XSFoundation runtime initialization status
 */
XS_EXTERN volatile int64_t XSRuntimeInitStatus;

/*!
 * @var         XSRuntimeClasses
 * @abstract    Registered XSFoundation runtime class infos
 */
XS_EXTERN XSRuntimeClassInfoList * volatile XSRuntimeClasses;

/*!
 * @var         XSRuntimeClassCount
 * @abstract    Number of registered XSFoundation runtime class infos
 */
XS_EXTERN volatile size_t XSRuntimeClassCount;

/*!
 * @typedef     XSRuntimeFinalizerList
 * @abstract    List of finalizer functions
 */
typedef struct XSRuntimeFinalizerListStruct
{
    void ( *finalizer )( void );                    /*! The finalizer function */
    struct XSRuntimeFinalizerListStruct * next;     /*! The next entry */
    struct XSRuntimeFinalizerListStruct * previous; /*! The previous entry */
} XSRuntimeFinalizerList;

/*!
 * @var         XSRuntimeFinalizers
 * @abstract    Registered finalizer functions
 */
XS_EXTERN XSRuntimeFinalizerList * volatile XSRuntimeFinalizers;

/*!
 * @function    XSRuntimeGetClassInfo
 * @abstract    Gets the class info for a class ID
 * @param       classID     The class ID
 * @return      The class info
 */
const XSRuntimeClassInfoList * XSRuntimeGetClassInfo( XSClassID classID );

/*!
 * @function    XSRuntimeGetInstanceSize
 * @abstract    Gets the instance site for a class ID
 * @param       classID     The class ID
 * @return      The instance size
 */
size_t XSRuntimeGetInstanceSize( XSClassID classID );

/*!
 * @function    XSRuntimeGetConstructorCallback
 * @abstract    Gets the constructor callback for a class ID
 * @param       classID     The class ID
 * @return      The copy callback
 */
XSClassCallbackConstructor XSRuntimeGetConstructorCallback( XSClassID classID );

/*!
 * @function    XSRuntimeGetDestructorCallback
 * @abstract    Gets the destructor callback for a class ID
 * @param       classID     The class ID
 * @return      The destructor callback
 */
XSClassCallbackDestructor XSRuntimeGetDestructorCallback( XSClassID classID );

/*!
 * @function    XSRuntimeGetCopyCallback
 * @abstract    Gets the copy callback for a class ID
 * @param       classID     The class ID
 * @return      The copy callback
 */
XSClassCallbackCopy XSRuntimeGetCopyCallback( XSClassID classID );

/*!
 * @function    XSRuntimeGetEqualsCallback
 * @abstract    Gets the equals callback for a class ID
 * @param       classID     The class ID
 * @return      The equals callback
 */
XSClassCallbackEquals XSRuntimeGetEqualsCallback( XSClassID classID );

/*!
 * @function    XSRuntimeGetToStringCallback
 * @abstract    Gets the to-string callback for a class ID
 * @param       classID     The class ID
 * @return      The to-string callback
 */
XSClassCallbackToString XSRuntimeGetToStringCallback( XSClassID classID );

/*!
 * @function    XSRuntimeFinalize
 * @abstract    XSFoundation runtime finalizer function
 * @discussion  Never call this function directly. It will be automatically
 *              called when the program exits.
 */
void XSRuntimeFinalize( void );

XS_EXTERN_C_END

#endif /* XS_PRIVATE_FUNCTIONS_XS_RUNTIME_H */

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
 * @header      XSRuntime.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSRuntime.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_FUNCTIONS_XS_RUNTIME_H__
#define __XS___PRIVATE_FUNCTIONS_XS_RUNTIME_H__

#include <XS/XSTypes.h>

/*!
 * @typedef     __XSRuntime_ClassInfoList
 * @abstract    Linked list for the XSFoundation class infos
 */
typedef struct __XSRuntime_ClassInfoList_Struct
{
    const XSClassInfo                       * cls;              /*! The class info */
    XSObjectRef                             * sharedInstance;   /*! The shared instance, if any */
    struct __XSRuntime_ClassInfoList_Struct * next;             /*! The next entry, if any */
}
__XSRuntime_ClassInfoList;

/*!
 * @define      __XS_RUNTIME_IS_INITED
 * @abstract    Checks whether the XSFoundation runtime is inited
 */
#define __XS_RUNTIME_IS_INITED      XSAtomic_CompareAndSwapInteger( XSInitStatusInited, XSInitStatusInited, &__XSRuntime_InitStatus )

/*!
 * @define      __XS_RUNTIME_IS_FINALIZING
 * @abstract    Checks whether the XSFoundation runtime is finalizing
 */
#define __XS_RUNTIME_IS_FINALIZING  XSAtomic_CompareAndSwapInteger( XSInitStatusFinalizing, XSInitStatusFinalizing, &__XSRuntime_InitStatus )

/*!
 * @define      __XS_RUNTIME_IS_FINALIZED
 * @abstract    Checks whether the XSFoundation runtime is finalized
 */
#define __XS_RUNTIME_IS_FINALIZED   XSAtomic_CompareAndSwapInteger( XSInitStatusFinalized, XSInitStatusFinalized, &__XSRuntime_InitStatus )

/*!
 * @var         __XSRuntime_InitStatus
 * @abstract    XSFoundation runtime initialization status
 */
XS_EXTERN volatile XSInteger __XSRuntime_InitStatus;

/*!
 * @var         __XSRuntime_IsFinalizing
 * @abstract    1 if the runtime is finalizing, otherwise 0
 */
XS_EXTERN volatile XSInteger __XSRuntime_IsFinalizing;

/*!
 * @var         __XSRuntime_ClassInfoList
 * @abstract    Registered XSFoundation runtime class infos
 */
XS_EXTERN __XSRuntime_ClassInfoList * volatile __XSRuntime_Classes;

/*!
 * @var         __XSRuntime_Inited
 * @abstract    Number of registered XSFoundation runtime class infos
 */
XS_EXTERN volatile XSInteger __XSRuntime_ClassCount;

/*!
 * @typedef     __XSRuntime_FinalizerList
 * @abstract    List of finalizer functions
 */
typedef struct __XSRuntime_FinalizerList_Struct
{
    void ( * finalizer )( void );                       /*! The finalizer function */
    struct __XSRuntime_FinalizerList_Struct * next;     /*! The next entry */
    struct __XSRuntime_FinalizerList_Struct * previous; /*! The previous entry */
}
__XSRuntime_FinalizerList;

/*!
 * @var         __XSRuntime_Finalizers
 * @abstract    Registered finalizer functions
 */
XS_EXTERN __XSRuntime_FinalizerList * volatile __XSRuntime_Finalizers;

/*!
 * @function    __XSRuntime_GetClassInfo
 * @abstract    Gets the class info for a class ID
 * @param       classID     The class ID
 * @return      The class info
 */
const __XSRuntime_ClassInfoList * __XSRuntime_GetClassInfo( XSClassID classID );

/*!
 * @function    __XSRuntime_GetInstanceSize
 * @abstract    Gets the instance site for a class ID
 * @param       classID     The class ID
 * @return      The instance size
 */
XSUInteger __XSRuntime_GetInstanceSize( XSClassID classID );

/*!
 * @function    __XSRuntime_GetConstructorCallback
 * @abstract    Gets the constructor callback for a class ID
 * @param       classID     The class ID
 * @return      The copy callback
 */
XSClassCallbackConstructor __XSRuntime_GetConstructorCallback( XSClassID classID );

/*!
 * @function    __XSRuntime_GetDestructorCallback
 * @abstract    Gets the destructor callback for a class ID
 * @param       classID     The class ID
 * @return      The destructor callback
 */
XSClassCallbackDestructor __XSRuntime_GetDestructorCallback( XSClassID classID );

/*!
 * @function    __XSRuntime_GetCopyCallback
 * @abstract    Gets the copy callback for a class ID
 * @param       classID     The class ID
 * @return      The copy callback
 */
XSClassCallbackCopy __XSRuntime_GetCopyCallback( XSClassID classID );

/*!
 * @function    __XSRuntime_GetEqualsCallback
 * @abstract    Gets the equals callback for a class ID
 * @param       classID     The class ID
 * @return      The equals callback
 */
XSClassCallbackEquals __XSRuntime_GetEqualsCallback( XSClassID classID );

/*!
 * @function    __XSRuntime_GetToStringCallback
 * @abstract    Gets the to-string callback for a class ID
 * @param       classID     The class ID
 * @return      The to-string callback
 */
XSClassCallbackToString __XSRuntime_GetToStringCallback( XSClassID classID );

/*!
 * @function    __XSRuntime_Finalize
 * @abstract    XSFoundation runtime finalizer function
 * @discussion  Never call this function directly. It will be automatically
 *              called when the program exits.
 */
void __XSRuntime_Finalize( void );

#endif /* __XS___PRIVATE_FUNCTIONS_XS_RUNTIME_H__ */

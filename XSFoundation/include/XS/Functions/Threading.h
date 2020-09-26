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
 * @header      Threading.h
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Threading-related functions
 */

#ifndef XS_FUNCTIONS_THREADING_H
#define XS_FUNCTIONS_THREADING_H

#include <XS/Macros.h>
#include <stdint.h>

XS_EXTERN_C_BEGIN

/*!
 * @function    XSGetCurrentThreadID
 * @abstract    Gets the ID of the current thread
 * @return      The ID of the current thread
 */
XS_EXPORT uint64_t XSGetCurrentThreadID( void );

/*!
 * @function    XSTLSKeyCreate
 * @abstract    Creates a TLS key
 * @param       key     A pointer to an uninitialized TLS key
 * @return      True if the key was successfully created, otherwise false
 */
bool XSTLSKeyCreate( XSTLSKey * key );

/*!
 * @function    XSTLSKeyDelete
 * @abstract    Deletes a TLS key
 * @param       key     A pointer to the TLS key to delete
 */
void XSTLSKeyDelete( XSTLSKey * key );

/*!
 * @function    XSTLSGetValue
 * @abstract    Gets the value associated with a TLS key
 * @param       key     The TLS key
 * @return      The associated value
 */
void * XSTLSGetValue( XSTLSKey * key );

/*!
 * @function    XSTLSSetValue
 * @abstract    Sets the value associated with a TLS key
 * @param       key             The TLS key
 * @param       value           The value to set
 * @param       association     The association type to use
 * @see         XSObjectAssociation
 */
void XSTLSSetValue( XSTLSKey * key, void * value, XSObjectAssociation association );

XS_EXTERN_C_END

#endif /* XS_FUNCTIONS_THREADING_H */

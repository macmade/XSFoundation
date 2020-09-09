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
 * @file        XSAllocator_Create.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSAllocator_Create
 */

#include <XS/XS.h>
#include <XS/__private/Classes/XSAllocatorRef.h>

XSStatic XSAllocatorRef XSAllocator_Create( XSStringRef name, XSAllocator_Callbacks * callbacks )
{
    struct __XSAllocator * object;
    
    if( callbacks == NULL )
    {
        XSFatalError( "Cannot create an instance of XSAllocator without callbacks" );
    }
    
    object = __XSAllocator_Create();
    
    object->name                = XSRetain( name );
    object->callbacks.alloc     = callbacks->alloc;
    object->callbacks.dealloc   = callbacks->dealloc;
    object->callbacks.realloc   = callbacks->realloc;
    object->callbacks.retain    = callbacks->retain;
    object->callbacks.release   = callbacks->release;
    object->callbacks.size      = callbacks->size;
    
    return object;
}

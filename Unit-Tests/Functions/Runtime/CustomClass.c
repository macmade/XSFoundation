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
 * @file        CustomClass.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 */

#include <XSCTest/XSCTest.h>
#include <XS/XS.h>

static XSClassID   classID;
static XSClassInfo classInfo;

static XSMutableObjectRef FooConstructor( XSMutableObjectRef object );
static void               FooDestructor( XSMutableObjectRef object );
static XSMutableObjectRef FooCopy( XSObjectRef object1, XSMutableObjectRef object2 );
static bool               FooEquals( XSObjectRef object1, XSObjectRef object2 );
static const char *       FooToString( XSObjectRef object );

struct Foo
{
    int x;
    int y;
};

Test( Runtime, CustomClass )
{
    classInfo.className    = "Foo";
    classInfo.type         = XSClassTypeNormal;
    classInfo.instanceSize = sizeof( struct Foo );
    classInfo.constructor  = FooConstructor;
    classInfo.destructor   = FooDestructor;
    classInfo.copy         = FooCopy;
    classInfo.equals       = FooEquals;
    classInfo.toString     = FooToString;

    classID = XSRuntimeRegisterClass( &classInfo );

    AssertGreater( classID, 0 );
}

static XSMutableObjectRef FooConstructor( XSMutableObjectRef object )
{
    return object;
}

static void FooDestructor( XSMutableObjectRef object )
{
    ( void )object;
}

static XSMutableObjectRef FooCopy( XSObjectRef object1, XSMutableObjectRef object2 )
{
    ( void )object1;

    return object2;
}

static bool FooEquals( XSObjectRef object1, XSObjectRef object2 )
{
    ( void )object1;
    ( void )object2;

    return false;
}

static const char * FooToString( XSObjectRef object )
{
    ( void )object;

    return "Foo";
}

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
static XSStringRef        FooToString( XSObjectRef object );

struct Foo
{
    int x;
    int y;
};

typedef struct Foo * FooRef;

static bool constructorCalled;
static bool destructorCalled;
static bool copyCalled;
static bool equalsCalled;
static bool toStringCalled;

Test( Runtime, CustomClass )
{
    XSAutoreleasePoolRef ap;

    ap = XSAutoreleasePoolCreate();

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
    AssertEqual( XSRuntimeGetClassIDOfClassNamed( "Foo" ), classID );
    AssertTrue( XSRuntimeGetClassType( classID ) == XSClassTypeNormal );
    AssertStringEqual( XSRuntimeGetClassName( classID ), "Foo" );

    {
        constructorCalled = false;
        FooRef foo        = XSRuntimeCreateInstance( classID );

        AssertTrue( foo != NULL );
        AssertTrue( constructorCalled );
        AssertEqual( foo->x, 42 );
        AssertEqual( foo->y, 43 );
        AssertTrue( XSRuntimeGetClassID( foo ) == classID );
        AssertTrue( XSRuntimeIsInstance( foo ) );
        AssertEqual( XSGetRetainCount( foo ), 1 );

        foo->x = 1;
        foo->y = 2;

        toStringCalled = false;
        AssertTrue( XSStringContainsCString( XSRuntimeGetDescription( foo ), "hello, world" ) );
        AssertTrue( toStringCalled );

        {
            FooRef copy;

            constructorCalled = false;
            copyCalled        = false;
            copy              = XSCopy( foo );

            AssertFalse( constructorCalled );
            AssertTrue( copyCalled );
            AssertEqual( foo->x, 1 );
            AssertEqual( foo->y, 2 );
            AssertEqual( copy->x, 1 );
            AssertEqual( copy->y, 2 );

            equalsCalled = false;

            AssertTrue( XSEquals( foo, copy ) );
            AssertTrue( equalsCalled );

            copy->x = 0;
            copy->y = 0;

            equalsCalled = false;

            AssertFalse( XSEquals( foo, copy ) );
            AssertTrue( equalsCalled );

            destructorCalled = false;

            XSRelease( copy );
            AssertTrue( destructorCalled );
        }

        XSRelease( foo );
    }

    {
        FooRef instance;

        constructorCalled = false;

        instance = XSRuntimeCreateInstanceOfClassNamed( "Foo" );

        AssertTrue( constructorCalled );
        AssertTrue( instance != NULL );
        AssertTrue( XSRuntimeGetClassID( instance ) == classID );

        destructorCalled = false;

        XSRelease( instance );
        AssertTrue( destructorCalled );
    }

    XSRelease( ap );
}

static XSMutableObjectRef FooConstructor( XSMutableObjectRef object )
{
    FooRef foo;

    foo               = object;
    constructorCalled = true;

    foo->x = 42;
    foo->y = 43;

    return foo;
}

static void FooDestructor( XSMutableObjectRef object )
{
    ( void )object;

    destructorCalled = true;
}

static XSMutableObjectRef FooCopy( XSObjectRef object1, XSMutableObjectRef object2 )
{
    const struct Foo * foo1;
    FooRef             foo2;

    foo1 = object1;
    foo2 = object2;

    foo2->x = foo1->x;
    foo2->y = foo1->y;

    copyCalled = true;

    return foo2;
}

static bool FooEquals( XSObjectRef object1, XSObjectRef object2 )
{
    const struct Foo * foo1;
    const struct Foo * foo2;

    foo1 = object1;
    foo2 = object2;

    equalsCalled = true;

    return foo1->x == foo2->x && foo1->y == foo2->y;
}

static XSStringRef FooToString( XSObjectRef object )
{
    ( void )object;

    toStringCalled = true;

    return XSSTR( "hello, world" );
}

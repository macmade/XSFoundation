<div class="xsdoc-file">
    <?php
        if( !isset( $_GET[ 'xsdoc-print' ] ) )
        {
    ?>
    <div class="xsdoc-file-toc">
        <h2>Table of contents</h2>
        <h3><a href="#opaque">Opaque types</a></h3>
        <h3><a href="#public">Public declarations</a></h3>
        <ul>
            <li><a href="#public-opaque">Opaque type</a></li>
            <li><a href="#public-clsid">Class ID getter</a></li>
        </ul>
        <h3><a href="#private">Private declarations and definitions</a></h3>
        <ul>
            <li><a href="#private-instdef">Class instance definition</a></li>
            <li><a href="#private-clsdecl">Class declaration</a></li>
            <li><a href="#private-clsdef">Class definition</a></li>
            <li><a href="#private-clsid">Class ID declaration/definition</a></li>
        </ul>
        <h3><a href="#example">Example</a></h3>
        <ul>
            <li><a href="#example-public">Public header - PointObject.h</a></li>
            <li><a href="#example-private">Private header - PointObjectPrivate.h</a></li>
            <li><a href="#example-implementation">Implementation - PointObject.c</a></li>
        </ul>
        <h3><a href="#registration">Class registration</a></h3>
        <h3><a href="#callbacks">Class callbacks</a></h3>
        <ul>
            <li><a href="#callbacks-constructor">Constructor</a></li>
            <li><a href="#callbacks-destructor">Destructor</a></li>
            <li><a href="#callbacks-copy">Copy constructor</a></li>
            <li><a href="#callbacks-equals">Equality</a></li>
            <li><a href="#callbacks-tostring">String representation</a></li>
        </ul>
    </div>
    <?php
        }
    ?>
    <div class="xsdoc-file-content">
        <h2>Custom class creation</h2>
        <p>
            XSFoundation lets you create custom classes for your projects.<br />
            Custom classes can be used the exact same way as XSFoundation's core classes.
        </p>
        <a name="opaque"></a>
        <h3>Opaque types</h3>
        <p>
            XSFoundation uses the concept of <a href="http://en.wikipedia.org/wiki/Opaque_data_type">opaque types</a> for its classes, as it provides a better abstraction level and higher flexibility.<br />
            It means that the concrete implementation of a class is completely hidden to the user.
        </p>
        <p>
            In order to achieve this, declarations must be splitted into <strong>public</strong> and <strong>private</strong> declarations.<br />
            Typically, all <strong>private</strong> declarations will go in specific header files, not distributed with binary builds, while public declarations will be made available through specific public header files.
        </p>
        <a name="public"></a>
        <h3>Public declarations</h3>
        <a name="public-opaque"></a>
        <h4>Opaque type</h4>
        <p>
            The first thing is obviously to declare a type for the custom class:
        </p>
        <p class="xsdoc-code-block">
            <code>typedef struct MyCustomClassStruct * MyCustomClassRef;</code>
        </p>
        <p>
            This is the opaque type. The <span class="xsdoc-code">struct MyCustomClassStruct</span> structure definition is is hidden here, and instances of the custom class will only be referred with the <span class="xsdoc-code">MyCustomClassRef</span> type.
        </p>
        <a name="public-clsid"></a>
        <h4>Class ID getter</h4>
        <p>
            A getter for the class ID also needs to be declared:
        </p>
        <p class="xsdoc-code-block">
            <code>XS_EXPORT XSStatic XSClassID MyCustomClass_GetClassID( void );</code>
        </p>
        <p>
            All XSFoundation classes receive a unique ID when they are registered within the XSFoundation runtime.<br />
            This unique ID can be used to create instances of a specific class or to compare different instances.
        </p>
        <a name="private"></a>
        <h3>Private declarations and definitions</h3>
        <a name="private-instdef"></a>
        <h4>Class instance definition</h4>
        <p>
            This is the concrete implementation of a class instance.<br />
            There is no specific member related to XSFoundation, so the structure layout is completely up to you:
        </p>
        <p class="xsdoc-code-block">
            <code>struct MyCustomClassStruct</code><br />
            <code>{</code><br />
            <code>    /* Your instance variables here... */</code><br />
            <code>};</code>
        </p>
        <a name="private-clsdecl"></a>
        <h4>Class declaration</h4>
        <p>
            As all XSFoundation classes need to be registered in the XSFoundation runtime, a variable of type <span class="xsdoc-code">XSClassInfo</span> is needed:
        </p>
        <p class="xsdoc-code-block">
            <code>XS_EXTERN XSClassInfo MyCustomClass;</code>
        </p>
        <a name="private-clsdef"></a>
        <h4>Class definition</h4>
        <p>
            The class definition is as follow:
        </p>
        <p class="xsdoc-code-block">
            <code>XSClassInfo MyCustomClass =</code><br />
            <code>{</code><br />
            <code>    "MyCustomClass",</code><br />
            <code>    XSClassTypeNormal,</code><br />
            <code>    sizeof( struct MyCustomClassStruct ),</code><br />
            <code>    ( XSClassCallbackConstructor )NULL,</code><br />
            <code>    ( XSClassCallbackDestructor )NULL,</code><br />
            <code>    ( XSClassCallbackCopy )NULL,</code><br />
            <code>    ( XSClassCallbackEquals )NULL,</code><br />
            <code>    ( XSClassCallbackToString )NULL</code><br />
            <code>};</code>
        </p>
        <p>
            The first member is the class name, followed by the class type, the class instance size, and the class callbacks (more on this later).
        </p>
        <a name="private-clsid"></a>
        <h4>Class ID declaration/definition</h4>
        <p>
            As the XSFoundation runtime will give you a class ID for your custom class, you need to declare and define it somewhere:
        </p>
        <p class="xsdoc-code-block">
            <code>XS_EXTERN XSClassID MyCustomClassID;</code>
        </p>
        <p class="xsdoc-code-block">
            <code>XSClassID MyCustomClassID = 0;</code>
        </p>
        <a name="example"></a>
        <h3>Example</h3>
        <p>
            Here's a concrete basic example of a custom XSFoundation class.<br />
            The class will represent a point, and be name <span class="xsdoc-code">PointObject</span>.
        </p>
        <a name="example-public"></a>
        <h4>Public header - <span class="xsdoc-code">PointObject.h</span></h4>
        <p class="xsdoc-code-block">
            <code>/* Header guard */</code><br />
            <code>#ifndef _POINT_OBJECT_H_</code><br />
            <code>#define _POINT_OBJECT_H_</code><br />
            <code></code><br />
            <code>#include &lt;XS/XS.h&gt;</code><br />
            <code></code><br />
            <code>/* Object type */</code><br />
            <code>typedef struct PointObjectStruct * PointObjectRef;</code><br />
            <code></code><br />
            <code>/* Class ID getter */</code><br />
            <code>XS_EXPORT XSStatic XSClassID PointObject_GetClassID( void );</code><br />
            <code></code><br />
            <code>/* Custom public methods */</code><br />
            <code>XS_EXPORT XSStatic PointObjectRef PointObject_Create( int x, int y );</code><br />
            <code>XS_EXPORT int PointObject_GetX( PointObjectRef p );</code><br />
            <code>XS_EXPORT int PointObject_GetY( PointObjectRef p );</code><br />
            <code></code><br />
            <code>#endif /* _POINT_OBJECT_H_ */</code><br />
        </p>
        <a name="example-private"></a>
        <h4>Private header - <span class="xsdoc-code">PointObjectPrivate.h</span></h4>
        <p class="xsdoc-code-block">
            <code>/* Header guard */</code><br />
            <code>#ifndef _POINT_OBJECT_PRIVATE_H_</code><br />
            <code>#define _POINT_OBJECT_PRIVATE_H_</code><br />
            <code></code><br />
            <code>#include &lt;XS/XS.h&gt;</code><br />
            <code></code><br />
            <code>/* Class ID */</code><br />
            <code>XS_EXTERN XSClassID PointObjectClassID;</code><br />
            <code></code><br />
            <code>/* Class info */</code><br />
            <code>XS_EXTERN XSClassInfo PointObjectClass;</code><br />
            <code></code><br />
            <code>/* Class instance definition */</code><br />
            <code>struct PointObjectStruct</code><br />
            <code>{</code><br />
            <code>    int x;</code><br />
            <code>    int y;</code><br />
            <code>};</code><br />
            <code></code><br />
            <code>#endif /* _POINT_OBJECT_PRIVATE_H_ */</code><br />
        </p>
        <a name="example-implementation"></a>
        <h4>Implementation - <span class="xsdoc-code">PointObject.c</span></h4>
        <p class="xsdoc-code-block">
            <code>#include "PointObject.h"</code><br />
            <code>#include "PointObjectPrivate.h"</code><br />
            <code></code><br />
            <code>/* Class ID */</code><br />
            <code>XSClassID PointObjectClassID = 0;</code><br />
            <code></code><br />
            <code>/* Class info */</code><br />
            <code>XSClassInfo PointObjectClass =</code><br />
            <code>{</code><br />
            <code>    "PointObject",</code><br />
            <code>    XSClassTypeNormal,</code><br />
            <code>    sizeof( struct PointObjectStruct ),</code><br />
            <code>    NULL,</code><br />
            <code>    NULL,</code><br />
            <code>    NULL,</code><br />
            <code>    NULL,</code><br />
            <code>    NULL</code><br />
            <code>};</code><br />
            <code></code><br />
            <code>/* Class ID getter */</code><br />
            <code>XSStatic XSClassID PointObject_GetClassID( void )</code><br />
            <code>{</code><br />
            <code>    return PointObjectClassID;</code><br />
            <code>}</code><br />
            <code></code><br />
            <code>/* Custom public methods */</code><br />
            <code></code><br />
            <code>XSStatic PointObjectRef PointObject_Create( int x, int y )</code><br />
            <code>{</code><br />
            <code>    PointObjectRef p;</code><br />
            <code>    </code><br />
            <code>    p = XSRuntime_CreateInstance( PointObject_GetClassID() );</code><br />
            <code>    </code><br />
            <code>    if( p != NULL )</code><br />
            <code>    {</code><br />
            <code>        p->x = x;</code><br />
            <code>        p->y = y;</code><br />
            <code>    }</code><br />
            <code>    </code><br />
            <code>    return p;</code><br />
            <code>}</code><br />
            <code></code><br />
            <code>int PointObject_GetX( PointObjectRef p )</code><br />
            <code>{</code><br />
            <code>    return ( p == NULL ) ? 0 : p->x;</code><br />
            <code>}</code><br />
            <code></code><br />
            <code>int PointObject_GetY( PointObjectRef p )</code><br />
            <code>{</code><br />
            <code>    return ( p == NULL ) ? 0 : p->y;</code><br />
            <code>}</code><br />
        </p>
        <a name="registration"></a>
        <h3>Class registration</h3>
        <p>
            In order to use a custom class, the XSFoundation runtime needs to know about it.<br />
            So you must register all your custom classes, before beginning to use them.
        </p>
        <p>
            Registering a class is done the following way (based on the above example).<br />
            Note that it needs to be done only once (eg. at program's start):
        </p>
        <p class="xsdoc-code-block">
            <code>PointObjectClassID = XSRuntime_RegisterClass( &PointObjectClass );</code>
        </p>
        <p>
            The <span class="xsdoc-code">XSRuntime_RegisterClass</span> will return a unique ID for your class, that you can use to create instances, as shown in the above example.
        </p>
        <a name="callbacks"></a>
        <h3>Class callbacks</h3>
        <p>
            When defining a class, you can provide different callbacks, to help the XSFoundation runtime to deal with your custom class.<br />
            The differnet types of callback are:
        </p>
        <a name="callbacks-constructor"></a>
        <h4>Constructor</h4>
        <p>
            If defined, this callback will be called when an instance of your class in created (eg: through the <span class="xsdoc-code">XSRuntime_CreateInstance</span> function).<br />
            The constructor signature is:
        </p>
        <p class="xsdoc-code-block">
            <code>XSObjectRef __ClassConstructor( XSObjectRef object );</code>
        </p>
        <p>
            The <span class="xsdoc-code">object</span> argument is the newly created instance that you may initialize.<br />
            This object is always a valid instance, so checking for <span class="xsdoc-code">NULL</span> isn't required.
        </p>
        <p>
            You can use this callback to initialize your class members, if needed.
        </p>
        <p>
            The return value is the initialized instance.<br />
            Usually, you'll just return the same object, but you may also return <span class="xsdoc-code">NULL</span> in case of failure, or another object.<br />
            In both cases, the XSFoundation runtime will ensure there's no memory leak.
        </p>
        <p>
            Also note that an object is always initialized to zero by the XSFoundation runtime, when allocated.
        </p>
        <a name="callbacks-destructor"></a>
        <h4>Destructor</h4>
        <p>
            If defined, this callback will be called when an instance of your class is about to be freed.<br />
            The constructor signature is:
        </p>
        <p class="xsdoc-code-block">
            <code>void __ClassDestructor( XSObjectRef object );</code>
        </p>
        <p>
            The <span class="xsdoc-code">object</span> argument is the instance which is about to be freed.<br />
            This object is always a valid instance, so checking for <span class="xsdoc-code">NULL</span> isn't required.
        </p>
        <p>
            You can use this callback to free resources acquired during the lifetime of the object.
        </p>
        <a name="callbacks-copy"></a>
        <h4>Copy constructor</h4>
        <p>
            If defined, this callback will be called when an instance of your class if copied using <span class="xsdoc-code">XSCopy</span>.<br />
            The constructor signature is:
        </p>
        <p class="xsdoc-code-block">
            <code>XSObjectRef __ClassCopyConstructor( XSObjectRef source, XSObjectRef destination );</code>
        </p>
        <p>
            The <span class="xsdoc-code">source</span> argument is the instance beeing copied, while the <span class="xsdoc-code">destination</span> argument is the copied instance.<br />
            Both objects are always valid instances, so checking for <span class="xsdoc-code">NULL</span> isn't required.
        </p>
        <p>
            When an object is copied, the default constructor callback won't be called, so the <span class="xsdoc-code">destination</span> will be a zeroed instance of your class.
            So it's your responsablility to ensure the copied instance is a valid instance, creating or copying everything required.
        </p>
        <p>
            The return value is the copied instance.<br />
            Usually, you'll just return the <span class="xsdoc-code">destination</span> object, but you may also return <span class="xsdoc-code">NULL</span> in case of failure, or another object.<br />
            In both cases, the XSFoundation runtime will ensure there's no memory leak.
        </p>
        <a name="callbacks-equals"></a>
        <h4>Equality</h4>
        <p>
            If defined, this callback will be called when an instance of your class if compared to another one using <span class="xsdoc-code">XSEquals</span>.<br />
            The equality callback signature is:
        </p>
        <p class="xsdoc-code-block">
            <code>bool __ClassEquals( XSObjectRef object1, XSObjectRef object2 );</code>
        </p>
        <p>
            The arguments are the objects beeing compared.<br />
            Both objects are always valid instances, so checking for <span class="xsdoc-code">NULL</span> isn't required.<br />
            There's also no need to check for both objects' classes, as this is done by the XSFoundation runtime before calling the equality callback, meaning both objects are guaranteed to be of the same class.
        </p>
        <p>
            The return value is a boolean value, indicating if both objects are equals.<br />
            Note that you don't need to compare both pointers, as this is also done by the XSFoundation runtime.
        </p>
        <a name="callbacks-tostring"></a>
        <h4>String representation</h4>
        <p>
            If defined, this callback will be called when a string representation of your object is needed (eg: by <span class="xsdoc-code">XSShow</span>).<br />
            The string representation callback signature is:
        </p>
        <p class="xsdoc-code-block">
            <code>const char * __ClassToString( XSObjectRef object );</code>
        </p>
        <p>
            The <span class="xsdoc-code">object</span> argument is the instance for which a string representation is needed.<br />
            This object is always a valid instance, so checking for <span class="xsdoc-code">NULL</span> isn't required.
        </p>
        <p>
            Your are strongly encouraged to add string representation callbacks to your classes, as it eases many aspects of programming and debugging.
        </p>
        <p>
            The return value is the string representation of your class instance.<br />
            You may return <span class="xsdoc-code">NULL</span>. In such a case, the XSFoundation runtime will provide a basic string representation of the object.
        </p>
    </div>
</div>

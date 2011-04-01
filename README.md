XSFoundation
============

XEOS C Foundation Library
-------------------------

### About XEOS

[XEOS][1] is an experimental 32 bits Operating System for x86 platforms, written in Assembly and C, including a C89 Standard Library (with some C99 parts).

### About XSFoundation

The [XEOS][1] C Foundation library provides the base for object-oriented C style coding, reference counting memory management with auto-release capabilities, and basic objects, with polymorphism.
It's purpose is to be integrated in the [XEOS][1] Operating System, once its C standard library will be complete.

For now, it's just a standalone project, that should compile on every OS with a decent C compiler.

### Building

The standard command `make` will build static and dynamic versions of the XSFoundation library.

### Linking

Once built, you can link with the XSFoundation library:

`gcc -Wall -o exec_name libxeos.a source.c`

### Header files

A main header file is provided: `XS.h`.
No other header file should be directly included.

### License

XSFoundation is released under the terms of the [Boost][2] Software License - Version 1.0.

[1]: http://www.eosgarden.com/en/opensource/xeos/   "XEOS"
[2]: http://www.boost.org/LICENSE_1_0.txt           "BOOST"

### Basic example

    #include "XS.h"
    
    int main( void )
    {
        XSAutoreleasePoolRef ap;
        XSStringRef          str1;
        XSStringRef          str2;
        
        // Initialization of XSFoundation
        XSFOUNDATION_START();
        
        // Creation of the auto-release pool
        ap   = XSAutoreleasePool_Create();
        
        // String creation
        str1 = XSSTR( "hello, world" );
        
        // Substring - The object will be released automatically
        str2 = XSAutoRelease( XSString_SubstringtoIndex( str1, 5 ) );
        
        XSLog( "This is a log message: %@%@", str1, str2 );
        
        // Release objects (str2 will be released automatically)
        XSRelease( str1 );
        XSRelease( ap );
        
        // Termination of XSFoundation and program exit
        XSFOUNDATION_END();
    }
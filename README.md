XSFoundation
============

XEOS C Foundation Library
-------------------------

### About XEOS

[XEOS][1] is an experimental 32 bits Operating System for x86 platforms, written in Assembly and C, including a C89 Standard Library (with some C99 parts).

### About XSFoundation

The [XEOS][1] C Foundation library provides the base for object-oriented C style coding, reference counting memory management with auto-release capabilities, reflection, runtime environment, polymorphism and basic objects.
It's purpose is to be integrated in the [XEOS][1] Operating System, once its C standard library will be complete.

For now, it's just a standalone project, that should compile on every OS with a decent C compiler.

### Supported OS

XSFoundation can be used on POSIX compliant systems (Mac OS X, Unix, Linux) as well as on Windows.

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
        XSString str1;
        XSString str2;
        XSString str3;

        // Initialization of XSFoundation
        XSApplication_Start( argc, ( const char ** )argv );

        // String creation - The object will be released automatically
        str1 = XSSTR( "hello, world" );

        // Substring - The object will be released automatically
        str2 = XSString_SubstringtoIndex( str1, 5 );

        // String copy - The object will have to be released explicitly
        str3 = XSCopy( str2 );

        // Prints "hello, world, world, world"    
        XSLog( "This is a log message: $@$@$@", str1, str2, str3 );

        // Release memory
        XSRelease( str3 );

        // Program exit
        return EXIT_SUCCESS;
    }

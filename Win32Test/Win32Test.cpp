#include "stdafx.h"

int _tmain( int argc, _TCHAR * argv[] )
{
    XSString str;

    XSApplication_Start( argc, ( const char ** )argv );
    
    str = XSString_InitWithCString( XSString_Alloc(), "(and universe)" );
    
    XSLog( "hello, world: $@", str );

    return 0;
}

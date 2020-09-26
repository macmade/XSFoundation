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
 * @file        XSStoreCurrentProcessName.c
 * @copyright   (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for XSStoreCurrentProcessName
 */

#include <XS/XS.h>
#include <XS/Private/Functions/Process.h>

#if defined( _WIN32 )

#include <XS/Private/Windows.h>

void XSStoreCurrentProcessName( char * buf, size_t max )
{
    TCHAR  name[ MAX_PATH ];
    char * pos;

    memset( name, 0, sizeof( name ) );
    GetModuleFileName( NULL, ( LPTSTR )name, sizeof( name ) );

    pos = strrchr( name, '\\' );

    if( strlen( name ) == 0 )
    {
        XSCStringCopy( buf, max + 1, "unknown", max );
    }
    else if( pos != NULL )
    {
        XSCStringCopy( buf, max + 1, pos + 1, max );
    }
    else
    {
        XSCStringCopy( buf, max + 1, name, max );
    }
}

#elif defined( __APPLE__ )

#include <mach-o/dyld.h>
#include <sys/syslimits.h>
#include <stdlib.h>
#include <string.h>

void XSStoreCurrentProcessName( char * buf, size_t max )
{
    char     name[ PATH_MAX ];
    uint32_t size;
    char *   pos;

    size = sizeof( name );

    memset( name, 0, sizeof( name ) );
    _NSGetExecutablePath( name, &size );

    pos = strrchr( name, '/' );

    if( strlen( name ) == 0 )
    {
        XSCStringCopy( buf, max + 1, "unknown", max );
    }
    else if( pos != NULL )
    {
        XSCStringCopy( buf, max + 1, pos + 1, max );
    }
    else
    {
        XSCStringCopy( buf, max + 1, name, max );
    }
}

#elif defined( __linux )

#include <stdlib.h>

extern char * program_invocation_short_name;

void XSStoreCurrentProcessName( char * buf, size_t max )
{
    XSCStringCopy( buf, max + 1, program_invocation_short_name, max );
}

#elif defined( __unix__ )

#include <stdlib.h>

void XSStoreCurrentProcessName( char * buf, size_t max )
{
    XSCStringCopy( buf, max + 1, getprogname(), max );
}

#elif defined( __XEOS__ )

void XSStoreCurrentProcessName( char * buf, size_t max )
{
    XSCStringCopy( buf, max + 1, "unknown", max );
}

#else

#error "Platform not implemented"

#endif

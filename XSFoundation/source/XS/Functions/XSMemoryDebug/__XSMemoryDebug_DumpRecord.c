/*******************************************************************************
 * XSFoundation - XEOS C Foundation Library
 * 
 * Copyright (c) 2010-2014, Jean-David Gadina - www.xs-labs.com
 * All rights reserved.
 * 
 * XEOS Software License - Version 1.0 - December 21, 2012
 * 
 * Permission is hereby granted, free of charge, to any person or organisation
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to deal in the Software, with or without
 * modification, without restriction, including without limitation the rights
 * to use, execute, display, copy, reproduce, transmit, publish, distribute,
 * modify, merge, prepare derivative works of the Software, and to permit
 * third-parties to whom the Software is furnished to do so, all subject to the
 * following conditions:
 * 
 *      1.  Redistributions of source code, in whole or in part, must retain the
 *          above copyright notice and this entire statement, including the
 *          above license grant, this restriction and the following disclaimer.
 * 
 *      2.  Redistributions in binary form must reproduce the above copyright
 *          notice and this entire statement, including the above license grant,
 *          this restriction and the following disclaimer in the documentation
 *          and/or other materials provided with the distribution, unless the
 *          Software is distributed by the copyright owner as a library.
 *          A "library" means a collection of software functions and/or data
 *          prepared so as to be conveniently linked with application programs
 *          (which use some of those functions and data) to form executables.
 * 
 *      3.  The Software, or any substancial portion of the Software shall not
 *          be combined, included, derived, or linked (statically or
 *          dynamically) with software or libraries licensed under the terms
 *          of any GNU software license, including, but not limited to, the GNU
 *          General Public License (GNU/GPL) or the GNU Lesser General Public
 *          License (GNU/LGPL).
 * 
 *      4.  All advertising materials mentioning features or use of this
 *          software must display an acknowledgement stating that the product
 *          includes software developed by the copyright owner.
 * 
 *      5.  Neither the name of the copyright owner nor the names of its
 *          contributors may be used to endorse or promote products derived from
 *          this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT OWNER AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE, TITLE AND NON-INFRINGEMENT ARE DISCLAIMED.
 * 
 * IN NO EVENT SHALL THE COPYRIGHT OWNER, CONTRIBUTORS OR ANYONE DISTRIBUTING
 * THE SOFTWARE BE LIABLE FOR ANY CLAIM, DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN ACTION OF CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF OR IN CONNECTION WITH
 * THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/* $Id$ */

/*!
 * @file        __XSMemoryDebug_DumpRecord.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSMemoryDebug_DumpRecord
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSMemoryDebug.h>

void __XSMemoryDebug_DumpRecord( __XSMemoryDebug_Record * record )
{
    #ifndef DEBUG
    
    ( void )record;
    
    return;
    
    #endif
    
    if( record == NULL || record->object == NULL || record->freed )
    {
        return;
    }
    
    fprintf
    (
        stderr,
        "\n"
        "#-------------------------------------------------------------------------------\n"
    );
    
    {
        XSUInteger   s;
        XSUInteger   i;
        const char * data;
        
        data = ( const char * )( record->object );
        s    = record->size;
        s   += sizeof( __XSMemoryObject );
        s   += __XS_MEMORY_FENCE_SIZE;
        i    = 0;
        
        while( i < s && s - i >= 19 )
        {
            fprintf
            (
                stderr,
                "# %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X | %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
                data[ i      ] & 0xFF,
                data[ i +  1 ] & 0xFF,
                data[ i +  2 ] & 0xFF,
                data[ i +  3 ] & 0xFF,
                data[ i +  4 ] & 0xFF,
                data[ i +  5 ] & 0xFF,
                data[ i +  6 ] & 0xFF,
                data[ i +  7 ] & 0xFF,
                data[ i +  8 ] & 0xFF,
                data[ i +  9 ] & 0xFF,
                data[ i + 10 ] & 0xFF,
                data[ i + 11 ] & 0xFF,
                data[ i + 12 ] & 0xFF,
                data[ i + 13 ] & 0xFF,
                data[ i + 14 ] & 0xFF,
                data[ i + 15 ] & 0xFF,
                data[ i + 16 ] & 0xFF,
                data[ i + 17 ] & 0xFF,
                data[ i + 18 ] & 0xFF,
                ( isprint( data[ i      ] & 0xFF ) ) ? data[ i      ] & 0xFF : '.',
                ( isprint( data[ i +  1 ] & 0xFF ) ) ? data[ i +  1 ] & 0xFF : '.',
                ( isprint( data[ i +  2 ] & 0xFF ) ) ? data[ i +  2 ] & 0xFF : '.',
                ( isprint( data[ i +  3 ] & 0xFF ) ) ? data[ i +  3 ] & 0xFF : '.',
                ( isprint( data[ i +  4 ] & 0xFF ) ) ? data[ i +  4 ] & 0xFF : '.',
                ( isprint( data[ i +  5 ] & 0xFF ) ) ? data[ i +  5 ] & 0xFF : '.',
                ( isprint( data[ i +  6 ] & 0xFF ) ) ? data[ i +  6 ] & 0xFF : '.',
                ( isprint( data[ i +  7 ] & 0xFF ) ) ? data[ i +  7 ] & 0xFF : '.',
                ( isprint( data[ i +  8 ] & 0xFF ) ) ? data[ i +  8 ] & 0xFF : '.',
                ( isprint( data[ i +  9 ] & 0xFF ) ) ? data[ i +  9 ] & 0xFF : '.',
                ( isprint( data[ i + 10 ] & 0xFF ) ) ? data[ i + 10 ] & 0xFF : '.',
                ( isprint( data[ i + 11 ] & 0xFF ) ) ? data[ i + 11 ] & 0xFF : '.',
                ( isprint( data[ i + 12 ] & 0xFF ) ) ? data[ i + 12 ] & 0xFF : '.',
                ( isprint( data[ i + 13 ] & 0xFF ) ) ? data[ i + 13 ] & 0xFF : '.',
                ( isprint( data[ i + 14 ] & 0xFF ) ) ? data[ i + 14 ] & 0xFF : '.',
                ( isprint( data[ i + 15 ] & 0xFF ) ) ? data[ i + 15 ] & 0xFF : '.',
                ( isprint( data[ i + 16 ] & 0xFF ) ) ? data[ i + 16 ] & 0xFF : '.',
                ( isprint( data[ i + 17 ] & 0xFF ) ) ? data[ i + 17 ] & 0xFF : '.',
                ( isprint( data[ i + 18 ] & 0xFF ) ) ? data[ i + 18 ] & 0xFF : '.'
            );
            
            i += 19;
        }
        
        if( i > 0 && i % 19 == 0 )
        {
            {
                XSUInteger j;
                
                fprintf( stderr, "#" );
                
                j = i;
                
                while( i < s )
                {
                    fprintf( stderr, " %02X", data[ i ] & 0xFF );
                    
                    i++;
                }
                
                for( i = 0; i < 19 - ( s - j ); i++ )
                {
                    fprintf( stderr, "   " );
                }
                
                fprintf( stderr, " |" );
                
                while( j < s )
                {
                    fprintf( stderr, "%c", ( isprint( data[ j ] & 0xFF ) ) ? data[ j ] & 0xFF : '.' );
                    
                    j++;
                }
                
                fprintf( stderr, "\n" );
            }
        }
    }
    
    fprintf
    (
        stderr,
        "#-------------------------------------------------------------------------------\n"
        "\n"
    );
}

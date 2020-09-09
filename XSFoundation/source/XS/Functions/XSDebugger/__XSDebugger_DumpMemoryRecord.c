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
 * @file        __XSDebugger_DumpMemoryRecord.c
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Definition for __XSDebugger_DumpMemoryRecord
 */

#include <XS/XS.h>
#include <XS/__private/Functions/XSDebugger.h>

void __XSDebugger_DumpMemoryRecord( __XSDebugger_MemoryRecord * record )
{
    #ifndef DEBUG
    
    ( void )record;
    
    return;
    
    #else
    
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
                
                fprintf( stderr, " | " );
                
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
    
    #endif
}

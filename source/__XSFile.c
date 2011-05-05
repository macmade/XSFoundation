/*******************************************************************************
 * Copyright (c) 2011, Jean-David Gadina <macmade@eosgarden.com>
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/
 
/* $Id$ */

/*!
 * @file        __XSFile.c
 * @brief       Private implementation for the XSFile class
 * @author      Jean-David Gadina <macmade@eosgarden.com>
 */

#include "XS.h"
#include "__XSFile.h"

/*!
 * @var         __XSFileClass
 * @brief       Runtime class definition
 */
static const XSClassInfos __XSFileClass =
{
    "XSFile",           /* Class name */
    sizeof( XSFile ),   /* Object size */
    NULL,               /* Constructor */
    NULL,               /* Destructor */
    NULL,               /* Default initializer */
    NULL,               /* Object copy */
    NULL,               /* Object description */
    NULL                /* Object comparison */
};

/*!
 * @var         __XSFileClassID
 * @brief       Type ID for the runtime class
 */
XSClassID __XSFileClassID;

void __XSFile_Initialize( void )
{
    __XSFileClassID = XSRuntime_RegisterClass( &__XSFileClass );
    
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_Flush, "Flush", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_Close, "Close", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_Printf, "Printf", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_VPrintf, "VPrintf", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_Getc, "Getc", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_Putc, "Putc", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_Puts, "Puts", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_Read, "Read", "size_t" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_Write, "Write", "size_t" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_Seek, "Seek", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_Tell, "Tell", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_Rewind, "Rewind", "void" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_GetPos, "GetPos", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_SetPos, "SetPos", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_ClearErr, "ClearErr", "void" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_EndOfFile, "EndOfFile", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_Error, "Error", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_Filename, "Filename", "const char *" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_OpenMode, "OpenMode", "const char *" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsReadable, "IsReadable", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsWriteable, "IsWriteable", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_Copy, "Copy", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_GetBit, "GetBit", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_PutBit, "PutBit", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_GetBits, "GetBits", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_PutBits, "PutBits", "XSInteger" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_DeviceID, "DeviceID", "dev_t" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_SerialNumber, "SerialNumber", "ino_t" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_NumberOfLinks, "NumberOfLinks", "nlink_t" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_UID, "UID", "uid_t" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_GID, "GID", "gid_t" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_Size, "Size", "size_t" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_HumanReadableSize, "HumanReadableSize", "XSFloat" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_AccessTime, "AccessTime", "time_t" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_ModificationTime, "ModificationTime", "time_t" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_CreationTime, "CreationTime", "time_t" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsBlockDevice, "IsBlockDevice", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsCharacterDevice, "IsCharacterDevice", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsFIFO, "IsFIFO", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsRegularFile, "IsRegularFile", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsLink, "IsLink", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsSocket, "IsSocket", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsUserReadable, "IsUserReadable", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsUserWriteable, "IsUserWriteable", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsUserExecutable, "IsUserExecutable", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsGroupReadable, "IsGroupReadable", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsGroupWriteable, "IsGroupWriteable", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsGroupExecutable, "IsGroupExecutable", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsWorldReadable, "IsWorldReadable", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsWorldWriteable, "IsWorldWriteable", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_IsWorldExecutable, "IsWorldExecutable", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_HasSUID, "HasSUID", "BOOL" );
    XSRuntime_BindMethodToClassID( __XSFileClassID, ( void ( * )( void ) )XSFile_HasSGID, "HasSGID", "BOOL" );
}

void __XSFile_WriteAlign( __XSFile * file )
{
    if( file->bit_count > 0 )
    {
        fputc( file->bit_buffer, file->fp );
    }
    
    file->bit_count  = 0;
    file->bit_buffer = 0;
    file->bit_offset = 0;
}

void __XSFile_UpdateStat( __XSFile * file )
{
    stat( file->filename, &( file->stat_buf ) );
}

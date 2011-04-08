/*******************************************************************************
 * Copyright (c) 1991-2, RSA Data Security, Inc. Created 1991.
 * All rights reserved.
 * 
 * License to copy and use this software is granted provided that it
 * is identified as the "RSA Data Security, Inc. MD5 Message-Digest
 * Algorithm" in all material mentioning or referencing this software
 * or this function.
 * 
 * License is also granted to make and use derivative works provided
 * that such works are identified as "derived from the RSA Data
 * Security, Inc. MD5 Message-Digest Algorithm" in all material
 * mentioning or referencing the derived work.
 * 
 * RSA Data Security, Inc. makes no representations concerning either
 * the merchantability of this software or the suitability of this
 * software for any particular purpose. It is provided "as is"
 * without express or implied warranty of any kind.
 ******************************************************************************/
 
/* $Id$ */

/*!
 * @file        md5.h
 * @copyright   RSA Data Security, Inc.
 * @abstract    ...
 */

/*!
 * @typedef     MD5_CTX
 * @abstract    MD5 context
 * @field       state       State (ABCD)
 * @field       count       Number of bits, modulo 2^64 (LSB first)
 * @field       buffer      Input buffer
 */
typedef struct
{
    unsigned long int state[ 4 ];
    unsigned long int count[ 2 ];
    unsigned char     buffer[ 64 ];
}
MD5_CTX;

/*!
 * @function    MD5_Init
 * @abstract    
 * @param       
 * @result      void
 */
void MD5_Init( MD5_CTX * context );

/*!
 * @function    MD5_Update
 * @abstract    
 * @param       
 * @param       
 * @param       
 * @result      void
 */
void MD5_Update( MD5_CTX * context, unsigned char * data, unsigned int length );

/*!
 * @function    MD5_Final
 * @abstract    
 * @param       
 * @param       
 * @result      void
 */
void MD5_Final( unsigned char digest[ 16 ], MD5_CTX * context );

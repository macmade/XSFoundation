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
 * @file        std-md5.h
 * @brief       MD5 hash algorithm
 * @author      RSA Data Security, Inc.
 */

#ifndef _XS_STD_MD5_H_
#define _XS_STD_MD5_H_
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @def         MD5_DIGEST_LENGTH
 * @brief       The length of a MD5 digest
 */
#define MD5_DIGEST_LENGTH   16

/*!
 * @struct      MD5_CTX_Struct
 * @brief       MD5 context structure
 */
struct MD5_CTX_Struct
{
    unsigned long int state[ 4 ];       /*! State (ABCD) */
    unsigned long int count[ 2 ];       /*! Number of bits, modulo 2^64 (LSB first) */
    unsigned char     buffer[ 64 ];     /*! Input buffer */
};

/*!
 * @typedef     MD5_CTX
 * @brief       MD5 context
 */
typedef struct MD5_CTX_Struct MD5_CTX;

/*!
 * @brief       initializes a MD5_CTX structure.
 * @param       context     The MD5 contex
 * @result      void
 */
void MD5_Init( MD5_CTX * context );

/*!
 * @brief       Updates the MD5_CTX structure with chunks of the message to be hashed
 * @param       context     The MD5 context
 * @param       data        The message data
 * @param       length      The length of the message data
 * @result      void
 */
void MD5_Update( MD5_CTX * context, unsigned char * data, unsigned int length );

/*!
 * @brief       Finalizes the message digest
 * @param       digest      The buffer for the digest (16 bytes)
 * @param       context     The MD5 context
 * @result      void
 */
void MD5_Final( unsigned char digest[ MD5_DIGEST_LENGTH ], MD5_CTX * context );

#ifdef __cplusplus
}
#endif

#endif /* _XS_STD_MD5_H_ */

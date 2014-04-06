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
 * @header      XSMacros.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSFoundation macros
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_MACROS_H__
#define __XS_MACROS_H__

#ifdef __cplusplus

/*!
 * @def         XS_EXTERN_C_BEGIN
 * @abstract    Substitution for 'extern "C" {' start, when compiling with C++
 */
#define XS_EXTERN_C_BEGIN           extern "C" {

/*!
 * @def         XS_EXTERN_C_BEGIN
 * @abstract    Substitution for 'extern "C" {' end, when compiling with C++
 */
#define XS_EXTERN_C_END             }

#else

/*!
 * @def         XS_EXTERN_C_BEGIN
 * @abstract    Substitution for 'extern "C" {' start, when compiling with C++
 */
#define XS_EXTERN_C_BEGIN           

/*!
 * @def         XS_EXTERN_C_BEGIN
 * @abstract    Substitution for 'extern "C" {' end, when compiling with C++
 */       
#define XS_EXTERN_C_END             

/*!
 * @def         XSStatic
 * @abstract    Marker for static class methods
 */
#define XSStatic                    

/*!
 * @def         XSAutoreleased
 * @abstract    Marker for methods that return auto-released objects
 */
#define XSAutoreleased              

/*!
 * @def             __XS_VERSION_STR__
 * @abstract        XSFoundation version number string
 */
#define __XS_VERSION_STR__          "2.0.0-0"

/*!
 * @def             __XS_VERSION_MAJ__
 * @abstract        XSFoundation major version number
 */
#define __XS_VERSION_MAJ__          2

/*!
 * @def             __XS_VERSION_MIN__
 * @abstract        XSFoundation minor version number
 */
#define __XS_VERSION_MIN__          0

/*!
 * @def             __XS_VERSION_BUGFIX__
 * @abstract        XSFoundation bugfix version number
 */
#define __XS_VERSION_BUGFIX__       0

/*!
 * @def             __XS_VERSION_PATCH__
 * @abstract        XSFoundation patch level version number
 */
#define __XS_VERSION_PATCH__        0

/*!
 * @def             __XS_VERSION__
 * @abstract        XSFoundation version number
 */
#define __XS_VERSION__              ( __XS_VERS_MAJ__ * 1000000 \
                                    + __XS_VERS_MIN__ * 10000   \
                                    + __XS_VERS_BUG__ * 100     \
                                    + __XS_VERS_PATCH__ )

#if !defined( __STRICT_ANSI__ ) && ( defined( __GNUC__ ) || defined( __clang__ ) )
    
    /*!
     * @def             XS_MIN
     * @abstract        Gets the minimum value of two values
     * @param           _a_     The first value
     * @param           _b_     The second value
     * @return          The minimum value of the two values
     */
    #define XS_MIN( _a_, _b_ )      ( { __typeof__( _a_ ) __a; __typeof__( _b_ ) __b; __a = ( _a_ ); __b = ( _b_ ); ( __a < __b ) ? __a : __b; } )
    
    /*!
     * @def             XS_MAX
     * @abstract        Gets the maximum value of two values
     * @param           _a_     The first value
     * @param           _b_     The second value
     * @return          The maximum value of the two values
     */
    #define XS_MAX( _a_, _b_ )      ( { __typeof__( _a_ ) __a; __typeof__( _b_ ) __b; __a = ( _a_ ); __b = ( _b_ ); ( __a < __b ) ? __b : __a; } )
    
    /*!
     * @def             XS_ABS
     * @abstract        Gets an absolute value of a value
     * @param           _a_     The value
     * @return          The absolute value of the value
     */
    #define XS_ABS( _a_ )           ( { __typeof__( _a_ ) __a = ( _a_ ); ( __a < 0 ) ? -__a : __a; } )
    
#else
    
    /*!
     * @def             XS_MIN
     * @abstract        Gets the minimum value of two values
     * @param           _a_     The first value
     * @param           _b_     The second value
     * @return          The minimum value of the two values
     */
    #define XS_MIN( _a_, _b_ )      ( ( ( _a_ ) < ( _b_ ) ) ? ( _a_ ) : ( _b_ ) )
    
    /*!
     * @def             XS_MAX
     * @abstract        Gets the maximum value of two values
     * @param           _a_     The first value
     * @param           _b_     The second value
     * @return          The maximum value of the two values
     */
    #define XS_MAX( _a_, _b_ )      ( ( ( _a_ ) > ( _b_ ) ) ? ( _a_ ) : ( _b_ ) )
    
    /*!
     * @def             XS_ABS
     * @abstract        Gets an absolute value of a value
     * @param           _a_     The value
     * @return          The absolute value of the value
     */
    #define XS_ABS( _a_ )           ( ( ( _a_ ) < 0 ) ? ( -( _a_ ) ) : ( _a_ ) )
    
#endif

/*!
 * @def         XS_PATH_MAX
 * @abstract    Maximum length for a path
 */
#if defined( _WIN32 )
    #define XS_PATH_MAX     MAX_PATH
#else
    #define XS_PATH_MAX     PATH_MAX
#endif

/*!
 * @def         XSEndian16_Swap
 * @abstract    Swap endiannes of a 16 bits value
 * @param       _value_     The value to swap
 */
#define XSEndian16_Swap( _value_ )                          \
    (                                                       \
        ( ( ( XSUInt16 )( ( _value_ ) & 0x00FF ) ) << 8 ) | \
        ( ( ( XSUInt16 )( ( _value_ ) & 0xFF00 ) ) >> 8 )   \
    )

/*!
 * @def         XSEndian32_Swap
 * @abstract    Swap endiannes of a 32 bits value
 * @param       _value_     The value to swap
 */
#define XSEndian32_Swap( _value_ )                                  \
    (                                                               \
        ( ( ( XSUInt32 )( ( _value_ ) & 0x000000FF ) ) << 24 ) |    \
        ( ( ( XSUInt32 )( ( _value_ ) & 0x0000FF00 ) ) <<  8 ) |    \
        ( ( ( XSUInt32 )( ( _value_ ) & 0x00FF0000 ) ) >>  8 ) |    \
        ( ( ( XSUInt32 )( ( _value_ ) & 0xFF000000 ) ) >> 24 )      \
    )

/*!
 * @def         XSEndian64_Swap
 * @abstract    Swap endiannes of a 64 bits value
 * @param       _value_     The value to swap
 */
#define XSEndian64_Swap( _value_ )                                          \
    (                                                                       \
        ( ( ( ( XSUInt64 )_value_ ) << 56 ) & 0xFF00000000000000ULL )  |    \
        ( ( ( ( XSUInt64 )_value_ ) << 40 ) & 0x00FF000000000000ULL )  |    \
        ( ( ( ( XSUInt64 )_value_ ) << 24 ) & 0x0000FF0000000000ULL )  |    \
        ( ( ( ( XSUInt64 )_value_ ) <<  8 ) & 0x000000FF00000000ULL )  |    \
        ( ( ( ( XSUInt64 )_value_ ) >>  8 ) & 0x00000000FF000000ULL )  |    \
        ( ( ( ( XSUInt64 )_value_ ) >> 24 ) & 0x0000000000FF0000ULL )  |    \
        ( ( ( ( XSUInt64 )_value_ ) >> 40 ) & 0x000000000000FF00ULL )  |    \
        ( ( ( ( XSUInt64 )_value_ ) >> 56 ) & 0x00000000000000FFULL )       \
    )

/*!
 * @def         XS_EXTERN
 * @abstract    Standardization of the extern keyword
 */
#if defined( __cplusplus )
    #define XS_EXTERN               extern "C" 
#else
    #define XS_EXTERN               extern
#endif

/*!
 * @def         XS_EXPORT
 * @abstract    Standardization of the extern keyword for exported symbols
 */
#if defined( __WIN32__ )
    #define XS_EXPORT               XS_EXTERN __declspec( dllimport )
#else
    #define XS_EXPORT               XS_EXTERN
#endif

/*!
 * @def         XS_IMPORT
 * @abstract    Standardization of the extern keyword for imported symbols
 */
#define XS_IMPORT                   XS_EXTERN

/*!
 * @def         XS_WEAK_ATTRIBUTE
 * @abstract    Standardization of the weak compiler attribute
 * @discussion  Not all compiler support this attribute, so it may be defined
 *              to nothing.
 */
#if defined( __GNUC__ ) && ( ( __GNUC__ >= 4 ) || ( ( __GNUC__ == 3 ) && ( __GNUC_MINOR__ >= 1 ) ) )
    #define XS_WEAK_ATTRIBUTE               __attribute__( ( weak ) )
#else
    #define XS_WEAK_ATTRIBUTE               
#endif

/*!
 * @def         XS_WEAK_IMPORT_ATTRIBUTE
 * @abstract    Standardization of the weak import compiler attribute
 * @discussion  Not all compiler support this attribute, so it may be defined
 *              to nothing.
 */
#if defined( __GNUC__ ) && ( ( __GNUC__ >= 4 ) || ( ( __GNUC__ == 3 ) && ( __GNUC_MINOR__ >= 1 ) ) )
    #define XS_WEAK_IMPORT_ATTRIBUTE        __attribute__( ( weak_import ) )
#elif defined(__MWERKS__) && ( __MWERKS__ >= 0x3205 )
    #define XS_WEAK_IMPORT_ATTRIBUTE        __attribute__( ( weak_import ) )
#else
    #define XS_WEAK_IMPORT_ATTRIBUTE        
#endif

/*!
 * @def         XS_DEPRECATED_ATTRIBUTE
 * @abstract    Standardization of the deprecated compiler attribute
 * @discussion  Not all compiler support this attribute, so it may be defined
 *              to nothing.
 */
#if defined( __GNUC__ ) && ( ( __GNUC__ >= 4 ) || ( ( __GNUC__ == 3 ) && ( __GNUC_MINOR__ >= 1 ) ) )
    #define XS_DEPRECATED_ATTRIBUTE         __attribute__( ( deprecated ) )
#else
    #define XS_DEPRECATED_ATTRIBUTE         
#endif

/*!
 * @def         XS_UNAVAILABLE_ATTRIBUTE
 * @abstract    Standardization of the unavailable compiler attribute
 * @discussion  Not all compiler support this attribute, so it may be defined
 *              to nothing.
 */
#if defined( __GNUC__ ) && ( ( __GNUC__ >= 4 ) || ( ( __GNUC__ == 3 ) && ( __GNUC_MINOR__ >= 1 ) ) )
    #define XS_UNAVAILABLE_ATTRIBUTE        __attribute__( ( unavailable ) )
#else
    #define XS_UNAVAILABLE_ATTRIBUTE        
#endif

/*!
 * @def         XS_FORMAT_ATTRIBUTE
 * @abstract    Standardization of the format compiler attribute
 * @discussion  Not all compiler support this attribute, so it may be defined
 *              to nothing.
 */
#if defined( __GNUC__ ) && ( ( __GNUC__ >= 4 ) || ( ( __GNUC__ == 3 ) && ( __GNUC_MINOR__ >= 1 ) ) )
    #define XS_FORMAT_ATTRIBUTE( f, s, v )  __attribute__( ( format( f, s, v ) ) )
#else
    #define XS_FORMAT_ATTRIBUTE( f, s, v )  
#endif

/*!
 * @def         XS_CONST_ATTRIBUTE
 * @abstract    Standardization of the const compiler attribute
 * @discussion  Not all compiler support this attribute, so it may be defined
 *              to nothing.
 */
#if defined( __GNUC__ ) && ( ( __GNUC__ >= 4 ) || ( ( __GNUC__ == 3 ) && ( __GNUC_MINOR__ >= 1 ) ) )
    #define XS_CONST_ATTRIBUTE              __attribute__( ( const ) )
#else
    #define XS_CONST_ATTRIBUTE              
#endif

/*!
 * @def         XS_NORETURN_ATTRIBUTE
 * @abstract    Standardization of the noreturn compiler attribute
 * @discussion  Not all compiler support this attribute, so it may be defined
 *              to nothing.
 */
#if defined( __GNUC__ ) && ( ( __GNUC__ >= 4 ) || ( ( __GNUC__ == 3 ) && ( __GNUC_MINOR__ >= 1 ) ) )
    #define XS_NORETURN_ATTRIBUTE           __attribute__( ( noreturn ) )
#else
    #define XS_NORETURN_ATTRIBUTE           
#endif

/*!
 * @def         XS_INLINE
 * @abstract    Standardization of the inline compiler keyword
 */
#if defined( __GNUC__ ) && ( __GNUC__ == 4 ) && !defined( DEBUG )
    #define XS_INLINE                       static __inline__ __attribute__( ( always_inline ) )
#elif defined( __GNUC__ )
    #define XS_INLINE                       static __inline__
#elif defined( __MWERKS__ ) || defined( __cplusplus )
    #define XS_INLINE                       static inline
#elif defined(_MSC_VER)
    #define XS_INLINE                       static __inline
#else
    #define XS_INLINE                       
#endif

/*!
 * @def         __func__
 * @abstract    Function name
 */
#ifndef __func__
    #ifdef _WIN32
        #if defined( __FUNCTION__ )
            #define __func__                __FUNCTION__
        #elif defined( __FUNCSIG__ )
            #define __func__                __FUNCSIG__
        #elif defined( __FUNCDNAME__ )
            #define __func__                __FUNCDNAME__
        #endif
    #elif __STDC_VERSION__ < 199901L
        #ifdef __GNUC__
            #if __GNUC__ >= 2
                #define __func__            __FUNCTION__
            #else
                #define __func__            "<unknown function>"
            #endif
        #else
            #define __func__                "<unknown function>"
        #endif
    #endif
#endif

#endif /* extern "C" { */

#endif /* __XS_MACROS_H__ */

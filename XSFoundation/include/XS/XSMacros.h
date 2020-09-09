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

/* $Id$ */

/*!
 * @header      XSMacros.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSFoundation macros
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_MACROS_H__
#define __XS_MACROS_H__

/*!
 * @define      XS_EXTERN_C_BEGIN
 * @abstract    Substitution for 'extern "C" {' start, when compiling with C++
 */
#ifdef __cplusplus
    #define XS_EXTERN_C_BEGIN           extern "C" {
#else
    #define XS_EXTERN_C_BEGIN           
#endif

/*!
 * @define      XS_EXTERN_C_END
 * @abstract    Substitution for 'extern "C" {' end, when compiling with C++
 */
#ifdef __cplusplus
    #define XS_EXTERN_C_END             }
#else   
    #define XS_EXTERN_C_END             
#endif

/*!
 * @define      XSStatic
 * @abstract    Marker for static class methods
 */
#define XSStatic                    

/*!
 * @define      XSAutoreleased
 * @abstract    Marker for methods that return auto-released objects
 */
#define XSAutoreleased              

/*!
 * @define          __XS_VERSION_STR__
 * @abstract        XSFoundation version number string
 */
#define __XS_VERSION_STR__          "2.0.0-0"

/*!
 * @define          __XS_VERSION_MAJ__
 * @abstract        XSFoundation major version number
 */
#define __XS_VERSION_MAJ__          2

/*!
 * @define          __XS_VERSION_MIN__
 * @abstract        XSFoundation minor version number
 */
#define __XS_VERSION_MIN__          0

/*!
 * @define          __XS_VERSION_BUGFIX__
 * @abstract        XSFoundation bugfix version number
 */
#define __XS_VERSION_BUGFIX__       0

/*!
 * @define          __XS_VERSION_PATCH__
 * @abstract        XSFoundation patch level version number
 */
#define __XS_VERSION_PATCH__        0

/*!
 * @define          __XS_VERSION__
 * @abstract        XSFoundation version number
 */
#define __XS_VERSION__              ( __XS_VERS_MAJ__ * 1000000 \
                                    + __XS_VERS_MIN__ * 10000   \
                                    + __XS_VERS_BUG__ * 100     \
                                    + __XS_VERS_PATCH__ )

/*!
 * @define          XS_MIN
 * @abstract        Gets the minimum value of two values
 * @param           _a_     The first value
 * @param           _b_     The second value
 * @return          The minimum value of the two values
 */
#if !defined( __STRICT_ANSI__ ) && ( defined( __GNUC__ ) || defined( __clang__ ) )
    #define XS_MIN( _a_, _b_ )      ( { __typeof__( _a_ ) __a; __typeof__( _b_ ) __b; __a = ( _a_ ); __b = ( _b_ ); ( __a < __b ) ? __a : __b; } )
#else
    #define XS_MIN( _a_, _b_ )      ( ( ( _a_ ) < ( _b_ ) ) ? ( _a_ ) : ( _b_ ) )
#endif

/*!
 * @define          XS_MAX
 * @abstract        Gets the maximum value of two values
 * @param           _a_     The first value
 * @param           _b_     The second value
 * @return          The maximum value of the two values
 */
#if !defined( __STRICT_ANSI__ ) && ( defined( __GNUC__ ) || defined( __clang__ ) )
    #define XS_MAX( _a_, _b_ )      ( { __typeof__( _a_ ) __a; __typeof__( _b_ ) __b; __a = ( _a_ ); __b = ( _b_ ); ( __a < __b ) ? __b : __a; } )
#else
    #define XS_MAX( _a_, _b_ )      ( ( ( _a_ ) > ( _b_ ) ) ? ( _a_ ) : ( _b_ ) )
#endif

/*!
 * @define          XS_ABS
 * @abstract        Gets an absolute value of a value
 * @param           _a_     The value
 * @return          The absolute value of the value
 */
#if !defined( __STRICT_ANSI__ ) && ( defined( __GNUC__ ) || defined( __clang__ ) )
    #define XS_ABS( _a_ )           ( { __typeof__( _a_ ) __a = ( _a_ ); ( __a < 0 ) ? -__a : __a; } )
#else
    #define XS_ABS( _a_ )           ( ( ( _a_ ) < 0 ) ? ( -( _a_ ) ) : ( _a_ ) )
#endif

/*!
 * @define      XS_PATH_MAX
 * @abstract    Maximum length for a path
 */
#if defined( _WIN32 )
    #define XS_PATH_MAX     MAX_PATH
#else
    #define XS_PATH_MAX     PATH_MAX
#endif

/*!
 * @define      XSEndian16_Swap
 * @abstract    Swap endiannes of a 16 bits value
 * @param       _value_     The value to swap
 */
#define XSEndian16_Swap( _value_ )                          \
    (                                                       \
        ( ( ( XSUInt16 )( ( _value_ ) & 0x00FF ) ) << 8 ) | \
        ( ( ( XSUInt16 )( ( _value_ ) & 0xFF00 ) ) >> 8 )   \
    )

/*!
 * @define      XSEndian32_Swap
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
 * @define      XSEndian64_Swap
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
 * @define      XS_UNSAFE_POINTER_CAST
 * @abstract    Casts a pointer type to another type
 * @discussion  This can be used to cast away qualifiers.
 * @param       _type_  The target type
 * @param       _var_   The variable to cast
 */
#define XS_UNSAFE_POINTER_CAST( _type_, _var_ ) ( ( _type_ )( uintptr_t )( const void * )( _var_ ) )

/*!
 * @define      XS_EXTERN
 * @abstract    Standardization of the extern keyword
 */
#if defined( __cplusplus )
    #define XS_EXTERN               extern "C" 
#else
    #define XS_EXTERN               extern
#endif

/*!
 * @define      XS_EXPORT
 * @abstract    Standardization of the extern keyword for exported symbols
 */
#if defined( __WIN32__ )
    #define XS_EXPORT               XS_EXTERN __declspec( dllimport )
#else
    #define XS_EXPORT               XS_EXTERN
#endif

/*!
 * @define      XS_IMPORT
 * @abstract    Standardization of the extern keyword for imported symbols
 */
#define XS_IMPORT                   XS_EXTERN

/*!
 * @define      XS_WEAK_ATTRIBUTE
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
 * @define      XS_WEAK_IMPORT_ATTRIBUTE
 * @abstract    Standardization of the weak import compiler attribute
 * @discussion  Not all compiler support this attribute, so it may be defined
 *              to nothing.
 */
#if defined( __GNUC__ ) && ( ( __GNUC__ >= 4 ) || ( ( __GNUC__ == 3 ) && ( __GNUC_MINOR__ >= 1 ) ) )
    #define XS_WEAK_IMPORT_ATTRIBUTE        __attribute__( ( weak_import ) )
#else
    #if defined(__MWERKS__) && ( __MWERKS__ >= 0x3205 )
        #define XS_WEAK_IMPORT_ATTRIBUTE        __attribute__( ( weak_import ) )
    #else
        #define XS_WEAK_IMPORT_ATTRIBUTE        
    #endif
#endif

/*!
 * @define      XS_DEPRECATED_ATTRIBUTE
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
 * @define      XS_UNAVAILABLE_ATTRIBUTE
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
 * @define      XS_FORMAT_ATTRIBUTE
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
 * @define      XS_CONST_ATTRIBUTE
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
 * @define      XS_NORETURN_ATTRIBUTE
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
 * @define      XS_INLINE
 * @abstract    Standardization of the inline compiler keyword
 */
#if defined( __GNUC__ ) && ( __GNUC__ == 4 ) && !defined( DEBUG )
    #define XS_INLINE                       static __inline__ __attribute__( ( always_inline ) )
#else
    #if defined( __GNUC__ )
        #define XS_INLINE                   static __inline__
    #else
        #if defined( __MWERKS__ ) || defined( __cplusplus )
            #define XS_INLINE               static inline
        #else
            #if defined(_MSC_VER)
                #define XS_INLINE           static __inline
            #else
                #define XS_INLINE                       
            #endif
        #endif
    #endif
#endif

/*!
 * @define      __func__
 * @abstract    Function name
 */
#ifndef __func__
    #ifdef _WIN32
        #if defined( __FUNCTION__ )
            #define __func__                __FUNCTION__
        #else
            #if defined( __FUNCSIG__ )
                #define __func__            __FUNCSIG__
            #else
                #if defined( __FUNCDNAME__ )
                    #define __func__        __FUNCDNAME__
                #else
                    #define __func__        "<unknown function>"
                #endif
            #endif
        #endif
    #else
        #if __STDC_VERSION__ < 199901L
            #ifdef __GNUC__
                #if __GNUC__ >= 2
                    #define __func__        __FUNCTION__
                #else
                    #define __func__        "<unknown function>"
                #endif
            #else
                #define __func__            "<unknown function>"
            #endif
        #endif
    #endif
#endif

#endif /* __XS_MACROS_H__ */

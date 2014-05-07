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
 * @header      XSColorRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    XSColor class
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_CLASSES_XS_COLOR_H__
#define __XS_CLASSES_XS_COLOR_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @define      XS_COLOR_HEX
 * @abstract    Creates a color object from an hexadecimal color value
 * @param       _c_     The hexadecimal color value
 * @param       _a_     The alpha value
 */
#define XS_COLOR_HEX( _c_, _a_ ) XSColor_ColorWithRGBA                  \
    (                                                                   \
        ( ( XSFloat )( ( _c_ >> 16 ) & 0x0000FF ) ) / ( XSFloat )255    \
        ( ( XSFloat )( ( _c_ >>  8 ) & 0x0000FF ) ) / ( XSFloat )255    \
        ( ( XSFloat )( ( _c_       ) & 0x0000FF ) ) / ( XSFloat )255    \
        ( XSFloat )_a_                                                  \
    )

/*!
 * @typedef     XSColorRef
 * @abstract    Opaque type for XSColor
 */
typedef struct __XSColor * XSColorRef;

/*!
 * @function    XSColor_GetClassID
 * @abstract    Gets the class ID for XSColor
 * @return      The class ID for XSColor
 */
XS_EXPORT XSStatic XSClassID XSColor_GetClassID( void );

/*!
 * @function    XSColor_BlackColor
 * @abstract    Gets the predefined black color object
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_BlackColor( void );

/*!
 * @function    XSColor_BlueColor
 * @abstract    Gets the predefined blue color object
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_BlueColor( void );

/*!
 * @function    XSColor_BrownColor
 * @abstract    Gets the predefined brown color object
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_BrownColor( void );

/*!
 * @function    XSColor_ClearColor
 * @abstract    Gets the predefined clear color object
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_ClearColor( void );

/*!
 * @function    XSColor_CyanColor
 * @abstract    Gets the predefined cyan color object
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_CyanColor( void );

/*!
 * @function    XSColor_DarkGrayColor
 * @abstract    Gets the predefined dark gray color object
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_DarkGrayColor( void );

/*!
 * @function    XSColor_GrayColor
 * @abstract    Gets the predefined gray color object
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_GrayColor( void );

/*!
 * @function    XSColor_GreenColor
 * @abstract    Gets the predefined green color object
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_GreenColor( void );

/*!
 * @function    XSColor_LightGrayColor
 * @abstract    Gets the predefined light gray color object
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_LightGrayColor( void );

/*!
 * @function    XSColor_MagentaColor
 * @abstract    Gets the predefined magenta color object
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_MagentaColor( void );

/*!
 * @function    XSColor_OrangeColor
 * @abstract    Gets the predefined orange color object
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_OrangeColor( void );

/*!
 * @function    XSColor_PurpleColor
 * @abstract    Gets the predefined purple color object
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_PurpleColor( void );

/*!
 * @function    XSColor_RedColor
 * @abstract    Gets the predefined red color object
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_RedColor( void );

/*!
 * @function    XSColor_WhiteColor
 * @abstract    Gets the predefined white color object
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_WhiteColor( void );

/*!
 * @function    XSColor_YellowColor
 * @abstract    Gets the predefined yellow color object
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_YellowColor( void );

/*!
 * @function    XSColor_ColorWithRGB
 * @abstract    Gets a color object from RGB values
 * @param       r       The red component value
 * @param       g       The green component value
 * @param       b       The blue component value
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_ColorWithRGB( XSFloat r, XSFloat g, XSFloat b );

/*!
 * @function    XSColor_ColorWithHSL
 * @abstract    Gets a color object from HSL values
 * @param       h       The hue component value
 * @param       s       The saturation component value
 * @param       l       The luminance component value
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_ColorWithHSL( XSFloat h, XSFloat s, XSFloat l );

/*!
 * @function    XSColor_ColorWithHSV
 * @abstract    Gets a color object from HSV values
 * @param       h       The hue component value
 * @param       s       The saturation component value
 * @param       v       The value component value
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_ColorWithHSV( XSFloat h, XSFloat s, XSFloat v );

/*!
 * @function    XSColor_ColorWithRGBA
 * @abstract    Gets a color object from RGBA values
 * @param       r       The red component value
 * @param       g       The green component value
 * @param       b       The blue component value
 * @param       a       The alpha component value
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_ColorWithRGBA( XSFloat r, XSFloat g, XSFloat b, XSFloat a );

/*!
 * @function    XSColor_ColorWithHSLA
 * @abstract    Gets a color object from HSLA values
 * @param       h       The hue component value
 * @param       s       The saturation component value
 * @param       l       The luminance component value
 * @param       a       The alpha component value
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_ColorWithHSLA( XSFloat h, XSFloat s, XSFloat l, XSFloat a );

/*!
 * @function    XSColor_ColorWithHSVA
 * @abstract    Gets a color object from HSVA values
 * @param       h       The hue component value
 * @param       s       The saturation component value
 * @param       v       The value component value
 * @param       a       The alpha component value
 * @return      The color object (autoreleased)
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_ColorWithHSVA( XSFloat h, XSFloat s, XSFloat v, XSFloat a );

/*!
 * @function    XSColor_CreateWithRGB
 * @abstract    Creates a color object from RGB values
 * @param       r       The red component value
 * @param       g       The green component value
 * @param       b       The blue component value
 * @return      The color object
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_CreateWithRGB( XSFloat r, XSFloat g, XSFloat b );

/*!
 * @function    XSColor_CreateWithHSL
 * @abstract    Creates a color object from HSL values
 * @param       h       The hue component value
 * @param       s       The saturation component value
 * @param       l       The luminance component value
 * @return      The color object
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_CreateWithHSL( XSFloat h, XSFloat s, XSFloat l );

/*!
 * @function    XSColor_CreateWithHSV
 * @abstract    Creates a color object from HSV values
 * @param       h       The hue component value
 * @param       s       The saturation component value
 * @param       v       The value component value
 * @return      The color object
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_CreateWithHSV( XSFloat h, XSFloat s, XSFloat v );

/*!
 * @function    XSColor_CreateWithRGBA
 * @abstract    Creates a color object from RGBA values
 * @param       r       The red component value
 * @param       g       The green component value
 * @param       b       The blue component value
 * @param       a       The alpha component value
 * @return      The color object
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_CreateWithRGBA( XSFloat r, XSFloat g, XSFloat b, XSFloat a );

/*!
 * @function    XSColor_CreateWithHSLA
 * @abstract    Creates a color object from HSLA values
 * @param       h       The hue component value
 * @param       s       The saturation component value
 * @param       l       The luminance component value
 * @param       a       The alpha component value
 * @return      The color object
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_CreateWithHSLA( XSFloat h, XSFloat s, XSFloat l, XSFloat a );

/*!
 * @function    XSColor_CreateWithHSVA
 * @abstract    Creates a color object from HSVA values
 * @param       h       The hue component value
 * @param       s       The saturation component value
 * @param       v       The value component value
 * @param       a       The alpha component value
 * @return      The color object
 */
XS_EXPORT XSStatic XSAutoreleased XSColorRef XSColor_CreateWithHSVA( XSFloat h, XSFloat s, XSFloat v, XSFloat a );

/*!
 * @function    XSColor_GetRed
 * @abstract    Gets the red component value of a color object
 * @param       object  The color object
 * @return      The red component value
 */
XS_EXPORT XSFloat XSColor_GetRed( XSColorRef object );

/*!
 * @function    XSColor_GetGreen
 * @abstract    Gets the green component value of a color object
 * @param       object  The color object
 * @return      The green component value
 */
XS_EXPORT XSFloat XSColor_GetGreen( XSColorRef object );

/*!
 * @function    XSColor_GetBlue
 * @abstract    Gets the blue component value of a color object
 * @param       object  The color object
 * @return      The blue component value
 */
XS_EXPORT XSFloat XSColor_GetBlue( XSColorRef object );

/*!
 * @function    XSColor_GetHue
 * @abstract    Gets the hue component value of a color object
 * @param       object  The color object
 * @return      The hue component value
 */
XS_EXPORT XSFloat XSColor_GetHue( XSColorRef object );

/*!
 * @function    XSColor_GetSaturation
 * @abstract    Gets the saturation component value of a color object
 * @param       object  The color object
 * @return      The saturation component value
 */
XS_EXPORT XSFloat XSColor_GetSaturation( XSColorRef object );

/*!
 * @function    XSColor_GetLuminance
 * @abstract    Gets the luminance component value of a color object
 * @param       object  The color object
 * @return      The luminance component value
 */
XS_EXPORT XSFloat XSColor_GetLuminance( XSColorRef object );

/*!
 * @function    XSColor_GetValue
 * @abstract    Gets the value component value of a color object
 * @param       object  The color object
 * @return      The value component value
 */
XS_EXPORT XSFloat XSColor_GetValue( XSColorRef object );

/*!
 * @function    XSColor_GetAlpha
 * @abstract    Gets the alpha component value of a color object
 * @param       object  The color object
 * @return      The alpha component value
 */
XS_EXPORT XSFloat XSColor_GetAlpha( XSColorRef object );

/*!
 * @function    XSColor_SetRed
 * @abstract    Sets the red component value of a color object
 * @param       object  The color object
 * @param       r       The red component value
 */
XS_EXPORT void XSColor_SetRed( XSColorRef object, XSFloat r );

/*!
 * @function    XSColor_SetGreen
 * @abstract    Sets the green component value of a color object
 * @param       object  The color object
 * @param       g       The redgreencomponent value
 */
XS_EXPORT void XSColor_SetGreen( XSColorRef object, XSFloat g );

/*!
 * @function    XSColor_SetBlue
 * @abstract    Sets the blue component value of a color object
 * @param       object  The color object
 * @param       b       The blue component value
 */
XS_EXPORT void XSColor_SetBlue( XSColorRef object, XSFloat b );

/*!
 * @function    XSColor_SetHue
 * @abstract    Sets the hue component value of a color object
 * @param       object  The color object
 * @param       h       The hue component value
 */
XS_EXPORT void XSColor_SetHue( XSColorRef object, XSFloat h );

/*!
 * @function    XSColor_SetSaturation
 * @abstract    Sets the saturation component value of a color object
 * @param       object  The color object
 * @param       s       The saturation component value
 */
XS_EXPORT void XSColor_SetSaturation( XSColorRef object, XSFloat s );

/*!
 * @function    XSColor_SetLuminance
 * @abstract    Sets the luminance component value of a color object
 * @param       object  The color object
 * @param       l       The luminance component value
 */
XS_EXPORT void XSColor_SetLuminance( XSColorRef object, XSFloat l );

/*!
 * @function    XSColor_SetValue
 * @abstract    Sets the value component value of a color object
 * @param       object  The color object
 * @param       v       The value component value
 */
XS_EXPORT void XSColor_SetValue( XSColorRef object, XSFloat v );

/*!
 * @function    XSColor_SetAlpha
 * @abstract    Sets the alpha component value of a color object
 * @param       object  The color object
 * @param       a       The alpha component value
 */
XS_EXPORT void XSColor_SetAlpha( XSColorRef object, XSFloat a );

/*!
 * @function    XSColor_GetRGB
 * @abstract    Gets the RGB component values of a color object
 * @param       object  The color object
 * @param       r       A pointer to the red component value (may be NULL)
 * @param       g       A pointer to the green component value (may be NULL)
 * @param       b       A pointer to the blue component value (may be NULL)
 */
XS_EXPORT void XSColor_GetRGB( XSColorRef object, XSFloat * r, XSFloat * g, XSFloat * b );

/*!
 * @function    XSColor_GetHSL
 * @abstract    Gets the HSL component values of a color object
 * @param       object  The color object
 * @param       h       A pointer to the hue component value (may be NULL)
 * @param       s       A pointer to the saturation component value (may be NULL)
 * @param       l       A pointer to the luminance component value (may be NULL)
 */
XS_EXPORT void XSColor_GetHSL( XSColorRef object, XSFloat * h, XSFloat * s, XSFloat * l );

/*!
 * @function    XSColor_GetHSV
 * @abstract    Gets the HSV component values of a color object
 * @param       object  The color object
 * @param       h       A pointer to the hue component value (may be NULL)
 * @param       s       A pointer to the saturation component value (may be NULL)
 * @param       v       A pointer to the value component value (may be NULL)
 */
XS_EXPORT void XSColor_GetHSV( XSColorRef object, XSFloat * h, XSFloat * s, XSFloat * v );

/*!
 * @function    XSColor_GetRGBA
 * @abstract    Gets the RGBA component values of a color object
 * @param       object  The color object
 * @param       r       A pointer to the red component value (may be NULL)
 * @param       g       A pointer to the green component value (may be NULL)
 * @param       b       A pointer to the blue component value (may be NULL)
 * @param       a       A pointer to the alpha component value (may be NULL)
 */
XS_EXPORT void XSColor_GetRGBA( XSColorRef object, XSFloat * r, XSFloat * g, XSFloat * b, XSFloat * a );

/*!
 * @function    XSColor_GetHSLA
 * @abstract    Gets the HSLA component values of a color object
 * @param       object  The color object
 * @param       h       A pointer to the hue component value (may be NULL)
 * @param       s       A pointer to the saturation component value (may be NULL)
 * @param       l       A pointer to the luminance component value (may be NULL)
 * @param       a       A pointer to the alpha component value (may be NULL)
 */
XS_EXPORT void XSColor_GetHSLA( XSColorRef object, XSFloat * h, XSFloat * s, XSFloat * l, XSFloat * a );

/*!
 * @function    XSColor_GetHSVA
 * @abstract    Gets the HSVA component values of a color object
 * @param       object  The color object
 * @param       h       A pointer to the hue component value (may be NULL)
 * @param       s       A pointer to the saturation component value (may be NULL)
 * @param       v       A pointer to the value component value (may be NULL)
 * @param       a       A pointer to the alpha component value (may be NULL)
 */
XS_EXPORT void XSColor_GetHSVA( XSColorRef object, XSFloat * h, XSFloat * s, XSFloat * v, XSFloat * a );

/*!
 * @function    XSColor_SetRGB
 * @abstract    Sets the RGB component values of a color object
 * @param       object  The color object
 * @param       r       The red component value
 * @param       g       The green component value
 * @param       b       The blue component value
 */
XS_EXPORT void XSColor_SetRGB( XSColorRef object, XSFloat r, XSFloat g, XSFloat b );

/*!
 * @function    XSColor_SetHSL
 * @abstract    Sets the HSL component values of a color object
 * @param       object  The color object
 * @param       h       The hue component value
 * @param       s       The saturation component value
 * @param       l       The luminance component value
 */
XS_EXPORT void XSColor_SetHSL( XSColorRef object, XSFloat h, XSFloat s, XSFloat l );

/*!
 * @function    XSColor_SetHSV
 * @abstract    Sets the HSV component values of a color object
 * @param       object  The color object
 * @param       h       The hue component value
 * @param       s       The saturation component value
 * @param       v       The value component value
 */
XS_EXPORT void XSColor_SetHSV( XSColorRef object, XSFloat h, XSFloat s, XSFloat v );

/*!
 * @function    XSColor_SetRGBA
 * @abstract    Sets the RGBA component values of a color object
 * @param       object  The color object
 * @param       r       The red component value
 * @param       g       The green component value
 * @param       b       The blue component value
 * @param       a       The alpha component value
 */
XS_EXPORT void XSColor_SetRGBA( XSColorRef object, XSFloat r, XSFloat g, XSFloat b, XSFloat a );

/*!
 * @function    XSColor_SetHSLA
 * @abstract    Sets the HSLA component values of a color object
 * @param       object  The color object
 * @param       h       The hue component value
 * @param       s       The saturation component value
 * @param       l       The luminance component value
 * @param       a       The alpha component value
 */
XS_EXPORT void XSColor_SetHSLA( XSColorRef object, XSFloat h, XSFloat s, XSFloat l, XSFloat a );

/*!
 * @function    XSColor_SetHSVA
 * @abstract    Sets the HSVA component values of a color object
 * @param       object  The color object
 * @param       h       The hue component value
 * @param       s       The saturation component value
 * @param       v       The value component value
 * @param       a       The alpha component value
 */
XS_EXPORT void XSColor_SetHSVA( XSColorRef object, XSFloat h, XSFloat s, XSFloat v, XSFloat a );

#endif /* __XS_CLASSES_XS_COLOR_H__ */

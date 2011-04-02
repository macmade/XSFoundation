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
 * @header      XSData.h
 * @copyright   eosgarden 2011 - Jean-David Gadina <macmade@eosgarden.com>
 * @abstract    ...
 */

#ifndef _XS_COLOR_H_
#define _XS_COLOR_H_
#pragma once

#include "XSMacros.h"

XS_EXTERN_C_BEGIN

/*!
 * @typedef     XSColorRef
 * @abstract    Opaque type for the XSColor objects
 */
typedef struct XSColor * XSColorRef;

/*!
 * @function    XSColor_CreateWithRGB
 * @abstract    Creates a color with RGB components
 * @param       r   The red value
 * @param       g   The green value
 * @param       b   The blue value
 * @result      The color object
 */
XSColorRef XSColor_CreateWithRGB( XSFloat r, XSFloat g, XSFloat b );

/*!
 * @function    XSColor_CreateWithHSL
 * @abstract    Creates a color with RGB components
 * @param       h   The hue value
 * @param       s   The saturation value
 * @param       l   The luminance value
 * @result      The color object
 */
XSColorRef XSColor_CreateWithHSL( XSFloat h, XSFloat s, XSFloat l );

/*!
 * @function    XSColor_CreateWithHSV
 * @abstract    Creates a color with HSL components
 * @param       h   The hue value
 * @param       s   The saturation value
 * @param       v   The value value
 * @result      The color object
 */
XSColorRef XSColor_CreateWithHSV( XSFloat h, XSFloat s, XSFloat v );

/*!
 * @function    XSColor_CreateWithRGB
 * @abstract    Creates a color with RGB components
 * @param       r   The red value
 * @param       g   The green value
 * @param       b   The blue value
 * @param       a   The alpha value
 * @result      The color object
 */
XSColorRef XSColor_CreateWithRGBA( XSFloat r, XSFloat g, XSFloat b, XSFloat a );

/*!
 * @function    XSColor_CreateWithHSL
 * @abstract    Creates a color with RGB components
 * @param       h   The hue value
 * @param       s   The saturation value
 * @param       l   The luminance value
 * @param       a   The alpha value
 * @result      The color object
 */
XSColorRef XSColor_CreateWithHSLA( XSFloat h, XSFloat s, XSFloat l, XSFloat a );

/*!
 * @function    XSColor_CreateWithHSV
 * @abstract    Creates a color with HSL components
 * @param       h   The hue value
 * @param       s   The saturation value
 * @param       v   The value value
 * @param       a   The alpha value
 * @result      The color object
 */
XSColorRef XSColor_CreateWithHSVA( XSFloat h, XSFloat s, XSFloat v, XSFloat a );

/*!
 * @function    XSColor_BlackColor
 * @abstract    Creates a color with HSVA components
 * @result      The color object
 */
XSColorRef XSColor_BlackColor( void );

/*!
 * @function    XSColor_WhiteColor
 * @abstract    Create a black color object
 * @result      The color object
 */
XSColorRef XSColor_WhiteColor( void );

/*!
 * @function    XSColor_RedColor
 * @abstract    Creates a red color object
 * @result      The color object
 */
XSColorRef XSColor_RedColor( void );

/*!
 * @function    XSColor_GreenColor
 * @abstract    Creates a green color object
 * @result      The color object
 */
XSColorRef XSColor_GreenColor( void );

/*!
 * @function    XSColor_BlueColor
 * @abstract    Creates a blue color object
 * @result      The color object
 */
XSColorRef XSColor_BlueColor( void );

/*!
 * @function    XSColor_GetRed
 * @abstract    Get the red component
 * @param       color   The color object
 * @result      The red component
 */
XSFloat XSColor_GetRed( XSColorRef color );

/*!
 * @function    XSColor_GetGreen
 * @abstract    Get the green component
 * @param       color   The color object
 * @result      The green component
 */
XSFloat XSColor_GetGreen( XSColorRef color );

/*!
 * @function    XSColor_GetBlue
 * @abstract    Get the blue component
 * @param       color   The color object
 * @result      The blue component
 */
XSFloat XSColor_GetBlue( XSColorRef color );

/*!
 * @function    XSColor_GetHue
 * @abstract    Get the hue component
 * @param       color   The color object
 * @result      The hue component
 */
XSFloat XSColor_GetHue( XSColorRef color );

/*!
 * @function    XSColor_GetSaturation
 * @abstract    Get the saturation component
 * @param       color   The color object
 * @result      The saturation component
 */
XSFloat XSColor_GetSaturation( XSColorRef color );

/*!
 * @function    XSColor_GetLuminance
 * @abstract    Get the luminance component
 * @param       color   The color object
 * @result      The luminance component
 */
XSFloat XSColor_GetLuminance( XSColorRef color );

/*!
 * @function    XSColor_GetValue
 * @abstract    Get the value component
 * @param       color   The color object
 * @result      The value component
 */
XSFloat XSColor_GetValue( XSColorRef color );

/*!
 * @function    XSColor_GetAlpha
 * @abstract    Get the alpha component
 * @param       color   The color object
 * @result      The alpha component
 */
XSFloat XSColor_GetAlpha( XSColorRef color );

/*!
 * @function    XSColor_SetRed
 * @abstract    Sets the red component
 * @param       color   The color object
 * @param       v       The red component
 * @result      void
 */
void XSColor_SetRed( XSColorRef color, XSFloat v );

/*!
 * @function    XSColor_SetGreen
 * @abstract    Sets the green component
 * @param       color   The color object
 * @param       v       The green component
 * @result      void
 */
void XSColor_SetGreen( XSColorRef color, XSFloat v );

/*!
 * @function    XSColor_SetBlue
 * @abstract    Sets the blue component
 * @param       color   The color object
 * @param       v       The blue component
 * @result      void
 */
void XSColor_SetBlue( XSColorRef color, XSFloat v );

/*!
 * @function    XSColor_SetHue
 * @abstract    Sets the hue component
 * @param       color   The color object
 * @param       v       The hue component
 * @result      void
 */
void XSColor_SetHue( XSColorRef color, XSFloat v );

/*!
 * @function    XSColor_SetSaturation
 * @abstract    Sets the saturation component
 * @param       color   The color object
 * @param       v       The saturation component
 * @result      void
 */
void XSColor_SetSaturation( XSColorRef color, XSFloat v );

/*!
 * @function    XSColor_SetLuminance
 * @abstract    Sets the luminance component
 * @param       color   The color object
 * @param       v       The luminance component
 * @result      void
 */
void XSColor_SetLuminance( XSColorRef color, XSFloat v );

/*!
 * @function    XSColor_SetValue
 * @abstract    Sets the value component
 * @param       color   The color object
 * @param       v       The value component
 * @result      void
 */
void XSColor_SetValue( XSColorRef color, XSFloat v );

/*!
 * @function    XSColor_SetAlpha
 * @abstract    Sets the alpha component
 * @param       color   The color object
 * @param       v       The alpha component
 * @result      void
 */
void XSColor_SetAlpha( XSColorRef color, XSFloat v );

XS_EXTERN_C_END

#endif /* _XS_COLOR_H_ */

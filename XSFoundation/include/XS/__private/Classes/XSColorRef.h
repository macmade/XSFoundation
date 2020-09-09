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
 * @header      XSColorRef.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    Private definitions for XSColorRef.h
 * @discussion  ...
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS___PRIVATE_CLASSES_XS_COLOR_H__
#define __XS___PRIVATE_CLASSES_XS_COLOR_H__

#include <XS/XSTypes.h>
#include <XS/XSMacros.h>

/*!
 * @struct      __XSColor
 * @abstract    Structure for XSColor
 */
struct __XSColor
{
    XSFloat             r;      /*! The red component */
    XSFloat             g;      /*! The green component */
    XSFloat             b;      /*! The blue component */
    XSFloat             h;      /*! The hue component */
    XSFloat             s;      /*! The saturation component */
    XSFloat             l;      /*! The luminance component */
    XSFloat             v;      /*! The value component */
    XSFloat             a;      /*! The alpha component */
    XSRecursiveLockRef  lock;   /*! The lock for thread-safety */
};

/*!
 * @var         __XSColor_ClassID
 * @abstract    Class ID
 */
XS_EXTERN XSClassID __XSColor_ClassID;

/*!
 * @var         __XSColor_Class
 * @abstract    Class info
 */
XS_EXTERN XSClassInfo __XSColor_Class;

/*!
 * @function    __XSColor_Initialize
 * @abstract    Class initializer
 */
XSStatic void __XSColor_Initialize( void );

/*!
 * @function    __XSColor_Constructor
 * @abstract    Class constructor callback
 * @param       object      The object beeing construct
 * @return      The new object
 */
XSColorRef __XSColor_Constructor( XSColorRef object );

/*!
 * @function    __XSColor_Destructor
 * @abstract    Class destructor callback
 * @param       object      The object beeing destruct
 */
void __XSColor_Destructor( XSColorRef object );

/*!
 * @function    __XSColor_Copy
 * @abstract    Class copy callback
 * @param       source      The object to copy
 * @param       destination The object beeing copied
 * @result      The copied object
 */
XSColorRef __XSColor_Copy( XSColorRef source, XSColorRef destination );

/*!
 * @function    __XSColor_Equals
 * @abstract    Class equals callback
 * @param       object1     The first object to compare
 * @param       object2     The second object to compare
 * @return      True if both objects are equals, otherwise false
 */
bool __XSColor_Equals( XSColorRef object1, XSColorRef object2 );

/*!
 * @function    __XSColor_ToString
 * @abstract    Class to-string callback
 * @param       object      The object for which to get a description
 * @return      The object's description
 */
const char * __XSColor_ToString( XSColorRef object );

/*!
 * @function    __XSColor_ConvertFromRGB
 * @abstract    Converts all values of a color object from RGB values
 * @param       object      The color object
 */
void __XSColor_ConvertFromRGB( XSColorRef object );

/*!
 * @function    __XSColor_ConvertFromHSL
 * @abstract    Converts all values of a color object from HSL values
 * @param       object      The color object
 */
void __XSColor_ConvertFromHSL( XSColorRef object );

/*!
 * @function    __XSColor_ConvertFromHSV
 * @abstract    Converts all values of a color object from HSV values
 * @param       object      The color object
 */
void __XSColor_ConvertFromHSV( XSColorRef object );

/*!
 * @function    __XSColor_RGBToHSL
 * @abstract    Converts RGB values of a color object to HSL values
 * @param       object      The color object
 */
void __XSColor_RGBToHSL( XSColorRef object );

/*!
 * @function    __XSColor_RGBToHSV
 * @abstract    Converts RGB values of a color object to HSV values
 * @param       object      The color object
 */
void __XSColor_RGBToHSV( XSColorRef object );

/*!
 * @function    __XSColor_HSLToRGB
 * @abstract    Converts HSL values of a color object to RGB values
 * @param       object      The color object
 */
void __XSColor_HSLToRGB( XSColorRef object );

/*!
 * @function    __XSColor_HSVToRGB
 * @abstract    Converts HSV values of a color object to RGB values
 * @param       object      The color object
 */
void __XSColor_HSVToRGB( XSColorRef object );

/*!
 * @function    __XSColor_Create
 * @abstract    Creates an XSColor object
 * @return      The XSColor object
 */
XSStatic struct __XSColor * __XSColor_Create( void );

#endif /* __XS___PRIVATE_CLASSES_XS_COLOR_H__ */

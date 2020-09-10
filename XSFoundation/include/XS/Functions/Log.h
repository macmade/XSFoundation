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
 * @header          XSLog.h
 * @copyright       (c) 2020 - Jean-David Gadina - www.xs-labs.com
 * @author          Jean-David Gadina - www.xs-labs.com
 * @abstract        XSFoundation log functions
 * @ignorefuncmacro XS_FORMAT_ATTRIBUTE
 */

#ifndef XS_FUNCTIONS_LOG_H
#define XS_FUNCTIONS_LOG_H

#include <XS/Macros.h>
#include <XS/Types/XSObjectRef.h>
#include <XS/Types/XSLogLevel.h>
#include <stdint.h>
#include <stdarg.h>

XS_EXTERN_C_BEGIN

/*!
 * @define      XSLog
 * @abstract    Logs a message (info level) to the standard error output
 * @param       ...     The format string (printf like) with optional format arguments for the format
 */
#define XSLog( ... ) XSLogWithInfos( XSLogLevelInfo, __FILE__, __LINE__, __func__, __VA_ARGS__ )

/*!
 * @define      XSLogEmergency
 * @abstract    Logs a message (emergency level) to the standard error output
 * @param       ...     The format string (printf like) with optional format arguments for the format
 */
#define XSLogEmergency( ... ) XSLogWithInfos( XSLogLevelEmergency, __FILE__, __LINE__, __func__, __VA_ARGS__ )

/*!
 * @define      XSLogAlert
 * @abstract    Logs a message (alert level) to the standard error output
 * @param       ...     The format string (printf like) with optional format arguments for the format
 */
#define XSLogAlert( ... ) XSLogWithInfos( XSLogLevelAlert, __FILE__, __LINE__, __func__, __VA_ARGS__ )

/*!
 * @define      XSLogCritical
 * @abstract    Logs a message (critical level) to the standard error output
 * @param       ...     The format string (printf like) with optional format arguments for the format
 */
#define XSLogCritical( ... ) XSLogWithInfos( XSLogLevelCritical, __FILE__, __LINE__, __func__, __VA_ARGS__ )

/*!
 * @define      XSLogError
 * @abstract    Logs a message (error level) to the standard error output
 * @param       ...     The format string (printf like) with optional format arguments for the format
 */
#define XSLogError( ... ) XSLogWithInfos( XSLogLevelError, __FILE__, __LINE__, __func__, __VA_ARGS__ )

/*!
 * @define      XSLogWarning
 * @abstract    Logs a message (warning level) to the standard error output
 * @param       ...     The format string (printf like) with optional format arguments for the format
 */
#define XSLogWarning( ... ) XSLogWithInfos( XSLogLevelWarning, __FILE__, __LINE__, __func__, __VA_ARGS__ )

/*!
 * @define      XSLogNotice
 * @abstract    Logs a message (notice level) to the standard error output
 * @param       ...     The format string (printf like) with optional format arguments for the format
 */
#define XSLogNotice( ... ) XSLogWithInfos( XSLogLevelNotice, __FILE__, __LINE__, __func__, __VA_ARGS__ )

/*!
 * @define      XSLogInfo
 * @abstract    Logs a message (info level) to the standard error output
 * @param       ...     The format string (printf like) with optional format arguments for the format
 */
#define XSLogInfo( ... ) XSLogWithInfos( XSLogLevelInfo, __FILE__, __LINE__, __func__, __VA_ARGS__ )

/*!
 * @define      XSLogDebug
 * @abstract    Logs a message (debug level) to the standard error output
 * @param       ...     The format string (printf like) with optional format arguments for the format
 */
#define XSLogDebug( ... ) XSLogWithInfos( XSLogLevelDebug, __FILE__, __LINE__, __func__, __VA_ARGS__ )

/*!
 * @define      XSVLog
 * @abstract    Logs a message (info level) to the standard error output
 * @param       _fmt_   The format string (printf like)
 * @param       _args_  Arguments for the format (va_list)
 */
#define XSVLog( _fmt_, _args_ ) XSLogWithInfos( XSLogLevelInfo, __FILE__, __LINE__, __func__, _fmt_, _args_ )

/*!
 * @define      XSVLogEmergency
 * @abstract    Logs a message (emergency level) to the standard error output
 * @param       _fmt_   The format string (printf like)
 * @param       _args_  Arguments for the format (va_list)
 */
#define XSVLogEmergency( _fmt_, _args_ ) XSLogWithInfos( XSLogLevelEmergency, __FILE__, __LINE__, __func__, _fmt_, _args_ )

/*!
 * @define      XSVLogAlert
 * @abstract    Logs a message (alert level) to the standard error output
 * @param       _fmt_   The format string (printf like)
 * @param       _args_  Arguments for the format (va_list)
 */
#define XSVLogAlert( _fmt_, _args_ ) XSLogWithInfos( XSLogLevelAlert, __FILE__, __LINE__, __func__, _fmt_, _args_ )

/*!
 * @define      XSVLogCritical
 * @abstract    Logs a message (critical level) to the standard error output
 * @param       _fmt_   The format string (printf like)
 * @param       _args_  Arguments for the format (va_list)
 */
#define XSVLogCritical( _fmt_, _args_ ) XSLogWithInfos( XSLogLevelCritical, __FILE__, __LINE__, __func__, _fmt_, _args_ )

/*!
 * @define      XSVLogError
 * @abstract    Logs a message (error level) to the standard error output
 * @param       _fmt_   The format string (printf like)
 * @param       _args_  Arguments for the format (va_list)
 */
#define XSVLogError( _fmt_, _args_ ) XSLogWithInfos( XSLogLevelError, __FILE__, __LINE__, __func__, _fmt_, _args_ )

/*!
 * @define      XSVLogWarning
 * @abstract    Logs a message (warning level) to the standard error output
 * @param       _fmt_   The format string (printf like)
 * @param       _args_  Arguments for the format (va_list)
 */
#define XSVLogWarning( _fmt_, _args_ ) XSLogWithInfos( XSLogLevelWarning, __FILE__, __LINE__, __func__, _fmt_, _args_ )

/*!
 * @define      XSVLogNotice
 * @abstract    Logs a message (notice level) to the standard error output
 * @param       _fmt_   The format string (printf like)
 * @param       _args_  Arguments for the format (va_list)
 */
#define XSVLogNotice( _fmt_, _args_ ) XSLogWithInfos( XSLogLevelNotice, __FILE__, __LINE__, __func__, _fmt_, _args_ )

/*!
 * @define      XSVLogInfo
 * @abstract    Logs a message (info level) to the standard error output
 * @param       _fmt_   The format string (printf like)
 * @param       _args_  Arguments for the format (va_list)
 */
#define XSVLogInfo( _fmt_, _args_ ) XSLogWithInfos( XSLogLevelInfo, __FILE__, __LINE__, __func__, _fmt_, _args_ )

/*!
 * @define      XSVLogDebug
 * @abstract    Logs a message (debug level) to the standard error output
 * @param       _fmt_   The format string (printf like)
 * @param       _args_  Arguments for the format (va_list)
 */
#define XSVLogDebug( _fmt_, _args_ ) XSLogWithInfos( XSLogLevelDebug, __FILE__, __LINE__, __func__, _fmt_, _args_ )

/*!
 * @define      XSFatalError
 * @abstract    Issues a fatal error message and aborts the program
 * @param       ...         The error message with optional format arguments
 */
#define XSFatalError( ... ) XSFatalErrorWithInfos( __FILE__, __LINE__, __func__, __VA_ARGS__ )

/*!
 * @define      XSShow
 * @abstract    Logs the description of an object to the console
 * @param       _obj_   The object to log
 */
#define XSShow( _obj_ ) XSShowWithInfos( _obj_, __FILE__, __LINE__, __func__ )

/*!
 * @function    XSGetLogLevel
 * @abstract    Gets the log level for XSLog functions/macros
 * @return      The actual log level
 * @see         XSLogLevel
 */
XS_EXPORT int64_t XSGetLogLevel( void );

/*!
 * @function    XSSetLogLevel
 * @abstract    Sets the log level for XSLog functions/macros
 * @param       level   The desired log level
 * @see         XSLogLevel
 */
XS_EXPORT void XSSetLogLevel( int64_t level );

/*!
 * @function    XSLogWithInfos
 * @abstract    Logs a message to the standard error output
 * @param       file    The file in which the log occurs
 * @param       line    The line number of the file in which the log occurs
 * @param       func    The function in which the log occurs
 * @param       fmt     The format string (printf like)
 * @param       ...     Arguments for the format
 * @discussion  Do not use this function directly. Use the XSLog... macros
 *              instead.
 */
XS_EXPORT void XSLogWithInfos( XSLogLevel level, const char * file, int line, const char * func, const char * fmt, ... ) XS_FORMAT_ATTRIBUTE( printf, 5, 6 );

/*!
 * @function    XSVLogWithInfos
 * @abstract    Logs a message to the standard error output
 * @param       file    The file in which the log occurs
 * @param       line    The line number of the file in which the log occurs
 * @param       func    The function in which the log occurs
 * @param       fmt     The format string (printf like)
 * @param       args    Arguments for the format
 * @discussion  Do not use this function directly. Use the XSVLog... macros
 *              instead.
 */
XS_EXPORT void XSVLogWithInfos( XSLogLevel level, const char * file, int line, const char * func, const char * fmt, va_list args ) XS_FORMAT_ATTRIBUTE( printf, 5, 0 );

/*!
 * @function    XSFatalErrorWithInfos
 * @abstract    Logs a fatal message to the standard error output and aborts the program
 * @param       file    The file in which the log occurs
 * @param       line    The line number of the file in which the log occurs
 * @param       func    The function in which the log occurs
 * @param       fmt     The format string (printf like)
 * @param       ...     Arguments for the format
 * @discussion  Do not use this function directly. Use the XSFatalError macro
 *              instead.
 */
XS_EXPORT void XSFatalErrorWithInfos( const char * file, int line, const char * func, const char * fmt, ... ) XS_FORMAT_ATTRIBUTE( printf, 4, 5 ) XS_NORETURN_ATTRIBUTE;

/*!
 * @function    XSShow
 * @abstract    Logs the description of an object to the console
 * @param       object  The object to log
 * @param       file    The file in which the log occurs
 * @param       line    The line number of the file in which the log occurs
 * @param       func    The function in which the log occurs
 * @discussion  Do not use this function directly. Use the XSShow macro
 *              instead.
 */
XS_EXPORT void XSShowWithInfos( XSObjectRef object, const char * file, int line, const char * func );

XS_EXTERN_C_END

#endif /* XS_FUNCTIONS_LOG_H */

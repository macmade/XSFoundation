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
 * @header      STD-POSIX.h
 * @copyright   (c) 2010-2014 - Jean-David Gadina - www.xs-labs.com
 * @author      Jean-David Gadina - www.xs-labs.com
 * @abstract    POSIX include files
 */

#ifndef __XS_H__
#error "Please include '<XS/XS.h>' instead of this file!"
#endif

#ifndef __XS_STD_POSIX_H__
#define __XS_STD_POSIX_H__

#include <cpio.h>           /* Magic numbers for the cpio archive format. */
#include <dirent.h>         /* Allows the opening and listing of directories. */
#include <fcntl.h>          /* File opening, locking and other operations. */
#include <grp.h>            /* User group information and control. */
#include <pthread.h>        /* Defines an API for creating and manipulating POSIX threads. */
#include <pwd.h>            /* passwd (user information) access and control. */
#include <semaphore.h>      /* Semaphores */
#include <sys/ipc.h>        /* Inter-process communication (IPC). */
#include <sys/msg.h>        /* POSIX message queues. */
#include <sys/sem.h>        /* POSIX semaphores. */
#include <sys/stat.h>       /* File information (stat et al.). */
#include <sys/time.h>       /* Time and date functions and structures. */
#include <sys/types.h>      /* Various data types used elsewhere. */
#include <sys/utsname.h>    /* uname and related structures. */
#include <sys/wait.h>       /* Status of terminated child processes (see wait). */
#include <tar.h>            /* Magic numbers for the tar archive format. */
#include <termios.h>        /* Allows terminal I/O interfaces. */
#include <unistd.h>         /* Various essential POSIX functions and constants. */
#include <utime.h>          /* inode access and modification times. */

#endif /* __XS_STD_POSIX_H__ */

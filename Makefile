#-------------------------------------------------------------------------------
# Copyright (c) 2010-2013, Jean-David Gadina - www.xs-labs.com
# All rights reserved.
# 
# XEOS Software License - Version 1.0 - December 21, 2012
# 
# Permission is hereby granted, free of charge, to any person or organisation
# obtaining a copy of the software and accompanying documentation covered by
# this license (the "Software") to deal in the Software, with or without
# modification, without restriction, including without limitation the rights
# to use, execute, display, copy, reproduce, transmit, publish, distribute,
# modify, merge, prepare derivative works of the Software, and to permit
# third-parties to whom the Software is furnished to do so, all subject to the
# following conditions:
# 
#       1.  Redistributions of source code, in whole or in part, must retain the
#           above copyright notice and this entire statement, including the
#           above license grant, this restriction and the following disclaimer.
# 
#       2.  Redistributions in binary form must reproduce the above copyright
#           notice and this entire statement, including the above license grant,
#           this restriction and the following disclaimer in the documentation
#           and/or other materials provided with the distribution, unless the
#           Software is distributed by the copyright owner as a library.
#           A "library" means a collection of software functions and/or data
#           prepared so as to be conveniently linked with application programs
#           (which use some of those functions and data) to form executables.
# 
#       3.  The Software, or any substancial portion of the Software shall not
#           be combined, included, derived, or linked (statically or
#           dynamically) with software or libraries licensed under the terms
#           of any GNU software license, including, but not limited to, the GNU
#           General Public License (GNU/GPL) or the GNU Lesser General Public
#           License (GNU/LGPL).
# 
#       4.  All advertising materials mentioning features or use of this
#           software must display an acknowledgement stating that the product
#           includes software developed by the copyright owner.
# 
#       5.  Neither the name of the copyright owner nor the names of its
#           contributors may be used to endorse or promote products derived from
#           this software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT OWNER AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
# THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE, TITLE AND NON-INFRINGEMENT ARE DISCLAIMED.
# 
# IN NO EVENT SHALL THE COPYRIGHT OWNER, CONTRIBUTORS OR ANYONE DISTRIBUTING
# THE SOFTWARE BE LIABLE FOR ANY CLAIM, DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
# OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
# WHETHER IN ACTION OF CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF OR IN CONNECTION WITH
# THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE, EVEN IF ADVISED
# OF THE POSSIBILITY OF SUCH DAMAGE.
#-------------------------------------------------------------------------------

include Make/Config.mk
include Make/Targets.mk

#-------------------------------------------------------------------------------
# Basic Configuration
#-------------------------------------------------------------------------------

CC            := clang
PRODUCT       := libxs
OPTIM_DEBUG   := O0
OPTIM_RELEASE := Os
STDC          := c99

#-------------------------------------------------------------------------------
# Files
#-------------------------------------------------------------------------------

# Gets every C file in the source directories
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSAtomic/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSDebugger/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSFileSystem/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSGeometry/XSEdgeInsets/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSGeometry/XSPoint/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSGeometry/XSRange/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSGeometry/XSRect/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSGeometry/XSSize/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSLog/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSMath/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSMemory/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSProcess/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSRuntime/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSSort/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSThreading/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSAllocator/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSArray/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSAutoreleasePool/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSBag/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSBinaryTree/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSBoolean/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSColor/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSData/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSDate/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSDictionary/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSError/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSFile/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSFileManager/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSLock/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSNode/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSNotification/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSNotificationCenter/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSNull/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSNumber/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSOrderedSet/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSPrimitiveArray/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSRecursiveLock/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSSemaphore/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSSet/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSStack/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSString/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSThread/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSURL/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSValue/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSXMLParser/)

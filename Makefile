#-------------------------------------------------------------------------------
# The MIT License (MIT)
# 
# Copyright (c) 2020 Jean-David Gadina - www.xs-labs.com
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
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
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSArray/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_CLASSES)XSAutoreleasePool/)
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

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

# $Id$

#-------------------------------------------------------------------------------
# Configuration
#-------------------------------------------------------------------------------

OPTIM   := Os
IOS_SDK := 7.1

#-------------------------------------------------------------------------------
# Paths
#-------------------------------------------------------------------------------

# Root build directory (debug or release)
ifeq ($(findstring 1,$(DEBUG)),)
    DIR_BUILD   := ./Build/Release/
else
    DIR_BUILD   := ./Build/Debug/
endif

# Relative build directories
DIR_BUILD_PRODUCTS              := $(DIR_BUILD)Products/
DIR_BUILD_TEMP                  := $(DIR_BUILD)Intermediates/
DIR_BUILD_TEMP                  := $(DIR_BUILD)Intermediates/
DIR_BUILD_TEMP_INTEL_32         := $(DIR_BUILD_TEMP)i386/
DIR_BUILD_TEMP_INTEL_64         := $(DIR_BUILD_TEMP)x86_64/
DIR_BUILD_TEMP_ARM_7            := $(DIR_BUILD_TEMP)armv7/
DIR_BUILD_TEMP_ARM_7S           := $(DIR_BUILD_TEMP)armv7s/
DIR_BUILD_TEMP_ARM_64           := $(DIR_BUILD_TEMP)arm64/
DIR_BUILD_TEMP_INTEL_32_BIN     := $(DIR_BUILD_TEMP_INTEL_32)bin/
DIR_BUILD_TEMP_INTEL_32_OBJ     := $(DIR_BUILD_TEMP_INTEL_32)obj/
DIR_BUILD_TEMP_INTEL_64_BIN     := $(DIR_BUILD_TEMP_INTEL_64)bin/
DIR_BUILD_TEMP_INTEL_64_OBJ     := $(DIR_BUILD_TEMP_INTEL_64)obj/
DIR_BUILD_TEMP_ARM_7_BIN        := $(DIR_BUILD_TEMP_ARM_7)bin/
DIR_BUILD_TEMP_ARM_7_OBJ        := $(DIR_BUILD_TEMP_ARM_7)obj/
DIR_BUILD_TEMP_ARM_7S_BIN       := $(DIR_BUILD_TEMP_ARM_7S)bin/
DIR_BUILD_TEMP_ARM_7S_OBJ       := $(DIR_BUILD_TEMP_ARM_7S)obj/
DIR_BUILD_TEMP_ARM_64_BIN       := $(DIR_BUILD_TEMP_ARM_64)bin/
DIR_BUILD_TEMP_ARM_64_OBJ       := $(DIR_BUILD_TEMP_ARM_64)obj/

# Source directories
DIR_INC                         := ./XSFoundation/include/
DIR_SRC                         := ./XSFoundation/source/XS/
DIR_SRC_FUNCTIONS               := $(DIR_SRC)Functions/
DIR_SRC_CLASSES                 := $(DIR_SRC)Classes/

#-------------------------------------------------------------------------------
# Search paths
#-------------------------------------------------------------------------------

# Define the search paths for source files
vpath %$(EXT_C) $(DIR_SRC)

#-------------------------------------------------------------------------------
# File suffixes
#-------------------------------------------------------------------------------

# File extensions
EXT_C   := .c
EXT_H   := .h
EXT_O   := .o

# Adds the suffixes used in this file
.SUFFIXES: $(EXT_C) $(EXT_H) $(EXT_O)

#-------------------------------------------------------------------------------
# Files
#-------------------------------------------------------------------------------

# Gets every C file in a specific source directory
_GET_C_FILES    = $(foreach dir,$(1), $(wildcard $(dir)*$(EXT_C)))

# Gets every C file in the source directories
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSAtomic/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSGeometry/XSEdgeInsets/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSGeometry/XSPoint/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSGeometry/XSRange/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSGeometry/XSRect/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSGeometry/XSSize/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSLog/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSMath/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSMemory/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSProcess/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSRuntime/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSThreading/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSApplication/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSApplicationArgument/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSArray/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSAutoreleasePool/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSBag/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSBinaryTree/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSBoolean/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSColor/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSData/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSDate/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSDictionary/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSError/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSFile/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSLock/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSNode/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSNotification/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSNotificationCenter/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSNull/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSNumber/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSPrimitiveArray/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSRecursiveLock/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSSemaphore/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSSet/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSString/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSThread/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSTimer/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSURL/)
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_CLASSES)XSValue/)

# Gets only the file name of the C files
_FILES_C_REL    = $(subst $(DIR_SRC),,$(_FILES_C))

# Replace the code extension by the object one
_FILES_C_OBJ    = $(subst $(EXT_C),$(EXT_O),$(_FILES_C_REL))

# Prefix all object files with the build directory for each platform
_FILES_C_BUILD_INTEL_32 = $(addprefix $(DIR_BUILD_TEMP_INTEL_32_OBJ),$(_FILES_C_OBJ))
_FILES_C_BUILD_INTEL_64 = $(addprefix $(DIR_BUILD_TEMP_INTEL_64_OBJ),$(_FILES_C_OBJ))
_FILES_C_BUILD_ARM_7    = $(addprefix $(DIR_BUILD_TEMP_ARM_7_OBJ),$(_FILES_C_OBJ))
_FILES_C_BUILD_ARM_7S   = $(addprefix $(DIR_BUILD_TEMP_ARM_7S_OBJ),$(_FILES_C_OBJ))
_FILES_C_BUILD_ARM_64   = $(addprefix $(DIR_BUILD_TEMP_ARM_64_OBJ),$(_FILES_C_OBJ))

#-------------------------------------------------------------------------------
# Commands configuration
#-------------------------------------------------------------------------------

# C compiler
CC  := clang -Werror -$(OPTIM) -std=c99 -I$(DIR_INC) -D__XS_BUILD__

# C compiler - Debug mode
ifneq ($(findstring 1,$(DEBUG)),)
CC  += -DDEBUG=1
CC  += -g
endif

# iOS SDK root
_IOS_SDK_PATH := /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS$(IOS_SDK).sdk

#-------------------------------------------------------------------------------
# Display
#-------------------------------------------------------------------------------

# Terminal colors
COLOR_NONE                              := "\x1b[0m"
COLOR_GRAY                              := "\x1b[30;01m"
COLOR_RED                               := "\x1b[31;01m"
COLOR_GREEN                             := "\x1b[32;01m"
COLOR_YELLOW                            := "\x1b[33;01m"
COLOR_BLUE                              := "\x1b[34;01m"
COLOR_PURPLE                            := "\x1b[35;01m"
COLOR_CYAN                              := "\x1b[36;01m"

# Pretty printing
ifeq ($(findstring 1,$(DEBUG)),)
_PRINT_CC   = "["$(COLOR_GREEN)" XSFoundation "$(COLOR_NONE)"]> Compiling C file [ "$(COLOR_CYAN)"Release - $(3)"$(COLOR_NONE)" ]: "$(COLOR_YELLOW)"$(patsubst %.,%,$(subst /,.,$(dir $(patsubst $(DIR_SRC)%,%,$<))))."$(COLOR_NONE)$(COLOR_GRAY)"$(notdir $(1))"$(COLOR_NONE)
else
_PRINT_CC   = "["$(COLOR_GREEN)" XSFoundation "$(COLOR_NONE)"]> Compiling C file [ "$(COLOR_CYAN)"Debug - $(3)"$(COLOR_NONE)" ]: "$(COLOR_YELLOW)"$(patsubst %.,%,$(subst /,.,$(dir $(patsubst $(DIR_SRC)%,%,$<))))."$(COLOR_NONE)$(COLOR_GRAY)"$(notdir $(1))"$(COLOR_NONE)
endif

#-------------------------------------------------------------------------------
# Build type
#-------------------------------------------------------------------------------

# Checks if we're on OS-X to determine the build type
ifeq ($(findstring Darwin, $(shell uname)),)
    _BUILD_TYPE := unix-like
else
    _BUILD_TYPE := os-x
endif

#-------------------------------------------------------------------------------
# Built-in targets
#-------------------------------------------------------------------------------

# Declaration for phony targets, to avoid problems with local files
.PHONY: all             \
        clean           \
        os-x            \
        unix-like       \
        lib             \
        dylib           \
        ios-lib         \
        mac-framework

# Declaration for precious targets, to avoid cleaning of intermediate files
.PRECIOUS:  $(DIR_BUILD_TEMP_INTEL_32_OBJ)%$(EXT_O) \
            $(DIR_BUILD_TEMP_INTEL_64_OBJ)%$(EXT_O) \
            $(DIR_BUILD_TEMP_ARM_7_OBJ)%$(EXT_O)    \
            $(DIR_BUILD_TEMP_ARM_7S_OBJ)%$(EXT_O)   \
            $(DIR_BUILD_TEMP_ARM_64_OBJ)%$(EXT_O)

#-------------------------------------------------------------------------------
# Phony targets
#-------------------------------------------------------------------------------

# Main Target
all: $(_BUILD_TYPE)
	
	@:

# Cleans all build files
clean:
	
	@rm -rf $(DIR_BUILD_TEMP_INTEL_32_OBJ)*
	@rm -rf $(DIR_BUILD_TEMP_INTEL_32_BIN)*
	@rm -rf $(DIR_BUILD_TEMP_INTEL_64_OBJ)*
	@rm -rf $(DIR_BUILD_TEMP_INTEL_64_BIN)*
	@rm -rf $(DIR_BUILD_TEMP_ARM_7_OBJ)*
	@rm -rf $(DIR_BUILD_TEMP_ARM_7_BIN)*
	@rm -rf $(DIR_BUILD_TEMP_ARM_7S_OBJ)*
	@rm -rf $(DIR_BUILD_TEMP_ARM_7S_BIN)*
	@rm -rf $(DIR_BUILD_TEMP_ARM_64_OBJ)*
	@rm -rf $(DIR_BUILD_TEMP_ARM_64_BIN)*
	@rm -rf $(DIR_BUILD_PRODUCTS)*

# Build for OS-X
os-x: lib dylib ios-lib mac-framework
	
	@:

# Build for Unix-like systems (non OS-X)
unix-like: lib dylib
	
	@:

# Builds a static library (generic)
lib: $(_FILES_C_BUILD_INTEL_32) $(_FILES_C_BUILD_INTEL_64)
	
	@:

# Builds a dynamic library (generic)
dylib: $(_FILES_C_BUILD_INTEL_32) $(_FILES_C_BUILD_INTEL_64)
	
	@:

# Builds an iOS static library (OS-X only)
ios-lib: $(_FILES_C_BUILD_ARM_7) $(_FILES_C_BUILD_ARM_7S) $(_FILES_C_BUILD_ARM_64)
	
	@:

# Builds an Mac framework (OS-X only)
mac-framework: $(_FILES_C_BUILD_INTEL_32) $(_FILES_C_BUILD_INTEL_64)
	
	@:

#-------------------------------------------------------------------------------
# Targets with second expansion
#-------------------------------------------------------------------------------

.SECONDEXPANSION:

# Target: i386
$(DIR_BUILD_TEMP_INTEL_32_OBJ)%$(EXT_O): $$(shell mkdir -p $$(dir $$@)) %$(EXT_C)
	
	@echo $(call _PRINT_CC,$<,$@,i386)
	@$(CC) -arch i386 -o $@ -c $<

# Target: x86_64
$(DIR_BUILD_TEMP_INTEL_64_OBJ)%$(EXT_O): $$(shell mkdir -p $$(dir $$@)) %$(EXT_C)
	
	@echo $(call _PRINT_CC,$<,$@,x86_64)
	@$(CC) -arch x86_64 -o $@ -c $<

# Target: armv7
$(DIR_BUILD_TEMP_ARM_7_OBJ)%$(EXT_O): $$(shell mkdir -p $$(dir $$@)) %$(EXT_C)
	
	@echo $(call _PRINT_CC,$<,$@,armv7)
	@$(CC) -arch armv7 -isysroot $(_IOS_SDK_PATH) -o $@ -c $<

# Target: armv7s
$(DIR_BUILD_TEMP_ARM_7S_OBJ)%$(EXT_O): $$(shell mkdir -p $$(dir $$@)) %$(EXT_C)
	
	@echo $(call _PRINT_CC,$<,$@,armv7s)
	@$(CC) -arch armv7s -isysroot $(_IOS_SDK_PATH) -o $@ -c $<

# Target: arm64
$(DIR_BUILD_TEMP_ARM_64_OBJ)%$(EXT_O): $$(shell mkdir -p $$(dir $$@)) %$(EXT_C)
	
	@echo $(call _PRINT_CC,$<,$@,arm64)
	@$(CC) -arch arm64 -isysroot $(_IOS_SDK_PATH) -o $@ -c $<

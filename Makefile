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

CC          := clang
MAC_TARGET  := 10.9
IOS_SDK     := 7.1
OPTIM       := Os

#-------------------------------------------------------------------------------
# Products
#-------------------------------------------------------------------------------

PRODUCT_LIB             := libxs
PRODUCT_DYLIB           := libxs
PRODUCT_MAC_FRAMEWORK   := XSFoundation
PRODUCT_IOS_LIB         := libxs-ios

#-------------------------------------------------------------------------------
# Paths
#-------------------------------------------------------------------------------

# Root directory
DIR                             := ./

# Root build directory (debug or release)
ifeq ($(findstring 1,$(DEBUG)),)
    DIR_BUILD                   := $(DIR)Build/Release/
else
    DIR_BUILD                   := $(DIR)Build/Debug/
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
DIR_INC                         := $(DIR)XSFoundation/include/
DIR_RES                         := $(DIR)XSFoundation/resources/
DIR_SRC                         := $(DIR)XSFoundation/source/XS/
DIR_SRC_FUNCTIONS               := $(DIR_SRC)Functions/
DIR_SRC_CLASSES                 := $(DIR_SRC)Classes/

# Scripts directory
DIR_SCRIPTS                     := $(DIR)Scripts/

#-------------------------------------------------------------------------------
# Search paths
#-------------------------------------------------------------------------------

# Define the search paths for source files
vpath %$(EXT_C) $(DIR_SRC)

#-------------------------------------------------------------------------------
# File suffixes
#-------------------------------------------------------------------------------

# File extensions
EXT_C           := .c
EXT_H           := .h
EXT_O           := .o
EXT_LIB         := .a
EXT_DYLIB       := .dylib
EXT_FRAMEWORK   := .framework

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
_FILES_C       += $(call _GET_C_FILES, $(DIR_SRC_FUNCTIONS)XSMemoryDebug/)
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

_CC = $(CC) -Werror -$(OPTIM) -std=c99 -fno-strict-aliasing -I$(DIR_INC) -D__XS_BUILD__

# C compiler - Debug mode
ifneq ($(findstring 1,$(DEBUG)),)
_CC += -DDEBUG=1
_CC += -g
endif

_CC_XS = $(_CC) -D__XS_BUILD__

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
_PRINT_FILE = $(call _PRINT,$(1),$(2),$(patsubst %.,%,$(subst /,.,$(dir $(patsubst $(DIR_SRC)%,%,$<)))).)$(COLOR_GRAY)"$(notdir $(3))"$(COLOR_NONE)
ifeq ($(findstring 1,$(DEBUG)),)
_PRINT      = "["$(COLOR_GREEN)" XSFoundation "$(COLOR_NONE)"]> $(1) [ "$(COLOR_CYAN)"Release - $(2)"$(COLOR_NONE)" ]: "$(COLOR_YELLOW)"$(3)"$(COLOR_NONE)
else
_PRINT      = "["$(COLOR_GREEN)" XSFoundation "$(COLOR_NONE)"]> $(1) [ "$(COLOR_CYAN)"Debug - $(2)"$(COLOR_NONE)" ]: "$(COLOR_YELLOW)"$(3)"$(COLOR_NONE)
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
        mac-framework   \
        i386            \
        x86-64          \
        armv7           \
        armv7s          \
        arm64

# Declaration for precious targets, to avoid cleaning of intermediate files
.PRECIOUS:  $(DIR_BUILD_TEMP_INTEL_32_OBJ)%$(EXT_O) \
            $(DIR_BUILD_TEMP_INTEL_64_OBJ)%$(EXT_O) \
            $(DIR_BUILD_TEMP_ARM_7_OBJ)%$(EXT_O)    \
            $(DIR_BUILD_TEMP_ARM_7S_OBJ)%$(EXT_O)   \
            $(DIR_BUILD_TEMP_ARM_64_OBJ)%$(EXT_O)

#-------------------------------------------------------------------------------
# Functions
#-------------------------------------------------------------------------------

_MAKE_FRAMEWORK_BIN = $(CC)                                                 \
    -Werror                                                                 \
    -arch $(1)                                                              \
    -dynamiclib                                                             \
    -mmacosx-version-min=$(MAC_TARGET)                                      \
    -single_module                                                          \
    -compatibility_version 1                                                \
    -current_version 1                                                      \
    -install_name /Library/Frameworks/$(2)$(EXT_FRAMEWORK)/Versions/A/$(2)  \
    -o $(3)                                                                 \
    $(4)

_MAKE_DYLIB_BIN = $(CC)                             \
    -Werror                                         \
    -arch $(1)                                      \
    -dynamiclib                                     \
    -install_name /usr/local/lib/$(2)$(EXT_DYLIB)   \
    -mmacosx-version-min=$(MAC_TARGET)              \
    -single_module                                  \
    -compatibility_version 1                        \
    -current_version 1                              \
    -o $(3)$(EXT_DYLIB)                             \
    $(4)

_XCODE_SDK_VALUE = $(shell /usr/libexec/PlistBuddy -c "Print $(1)" /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Info.plist) $(DIR_BUILD_PRODUCTS)$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK)/Versions/A/Resources/Info.plist

#-------------------------------------------------------------------------------
# Phony targets
#-------------------------------------------------------------------------------

# Main Target
all: $(_BUILD_TYPE)
	
	@:
	
# Test target
test: all
	
	@echo $(call _PRINT,XSTest,universal,Compiling test file)
	@$(_CC) -arch i386 -arch x86_64 XSTest/main.c $(DIR_BUILD_PRODUCTS)$(PRODUCT_LIB)$(EXT_LIB) -o $(DIR_BUILD_PRODUCTS)XSTest
	@echo $(call _PRINT,XSTest,universal,Running test file)
	@$(DIR_BUILD_PRODUCTS)XSTest

# Cleans all build files
clean:
	
	@echo $(call _PRINT,Cleaning,i386,Cleaning all intermediate files)
	@rm -rf $(DIR_BUILD_TEMP_INTEL_32_OBJ)*
	@rm -rf $(DIR_BUILD_TEMP_INTEL_32_BIN)*
	
	@echo $(call _PRINT,Cleaning,x86-64,Cleaning all intermediate files)
	@rm -rf $(DIR_BUILD_TEMP_INTEL_64_OBJ)*
	@rm -rf $(DIR_BUILD_TEMP_INTEL_64_BIN)*
	
	@echo $(call _PRINT,Cleaning,armv7,Cleaning all intermediate files)
	@rm -rf $(DIR_BUILD_TEMP_ARM_7_OBJ)*
	@rm -rf $(DIR_BUILD_TEMP_ARM_7_BIN)*
	
	@echo $(call _PRINT,Cleaning,armv7s,Cleaning all intermediate files)
	@rm -rf $(DIR_BUILD_TEMP_ARM_7S_OBJ)*
	@rm -rf $(DIR_BUILD_TEMP_ARM_7S_BIN)*
	
	@echo $(call _PRINT,Cleaning,arm64,Cleaning all intermediate files)
	@rm -rf $(DIR_BUILD_TEMP_ARM_64_OBJ)*
	@rm -rf $(DIR_BUILD_TEMP_ARM_64_BIN)*
	
	@echo $(call _PRINT,Cleaning,universal,Cleaning all product files)
	@rm -rf $(DIR_BUILD_PRODUCTS)*

# Build for OS-X
os-x: lib dylib mac-framework ios-lib
	
	@:
	
# Build for Unix-like systems (non OS-X)
unix-like: lib dylib
	
	@:

# Builds a static library (generic)
lib: i386 x86-64
	
	@echo $(call _PRINT,$(PRODUCT_LIB)$(EXT_LIB),universal,Linking the i386 binary)
	@libtool -static -arch_only i386 -o $(DIR_BUILD_TEMP_INTEL_32_BIN)$(PRODUCT_LIB)$(EXT_LIB) $(DIR_BUILD_TEMP_INTEL_32_OBJ)XSFoundation$(EXT_O)
	
	@echo $(call _PRINT,$(PRODUCT_LIB)$(EXT_LIB),universal,Linking the x86-64 binary)
	@libtool -static -arch_only x86_64 -o $(DIR_BUILD_TEMP_INTEL_64_BIN)$(PRODUCT_LIB)$(EXT_LIB) $(DIR_BUILD_TEMP_INTEL_64_OBJ)XSFoundation$(EXT_O)
	
	@echo $(call _PRINT,$(PRODUCT_LIB)$(EXT_LIB),universal,Linking the universal binary)
	@libtool -static $(DIR_BUILD_TEMP_INTEL_32_BIN)$(PRODUCT_LIB)$(EXT_LIB) $(DIR_BUILD_TEMP_INTEL_64_BIN)$(PRODUCT_LIB)$(EXT_LIB) -o $(DIR_BUILD_PRODUCTS)$(PRODUCT_LIB)$(EXT_LIB)
	
ifeq ($(findstring 1,$(DEBUG)),)
	@echo $(call _PRINT,$(PRODUCT_LIB)$(EXT_LIB),universal,Stripping the debug symbols)
	@strip -S $(DIR_BUILD_PRODUCTS)$(PRODUCT_LIB)$(EXT_LIB)
endif
	
# Builds a dynamic library (generic)
dylib: i386 x86-64
	
	@echo $(call _PRINT,$(PRODUCT_DYLIB)$(EXT_DYLIB),universal,Linking the i386 binary)
	@$(call _MAKE_DYLIB_BIN,i386,$(PRODUCT_DYLIB),$(DIR_BUILD_TEMP_INTEL_32_BIN)$(PRODUCT_DYLIB),$(DIR_BUILD_TEMP_INTEL_32_OBJ)XSFoundation$(EXT_O))
	
	@echo $(call _PRINT,$(PRODUCT_DYLIB)$(EXT_DYLIB),universal,Linking the x86-64 binary)
	@$(call _MAKE_DYLIB_BIN,x86_64,$(PRODUCT_DYLIB),$(DIR_BUILD_TEMP_INTEL_64_BIN)$(PRODUCT_DYLIB),$(DIR_BUILD_TEMP_INTEL_64_OBJ)XSFoundation$(EXT_O))
	
	@echo $(call _PRINT,$(PRODUCT_LIB)$(EXT_DYLIB),universal,Linking the universal binary)
	@lipo -create $(DIR_BUILD_TEMP_INTEL_32_BIN)$(PRODUCT_DYLIB)$(EXT_DYLIB) $(DIR_BUILD_TEMP_INTEL_64_BIN)$(PRODUCT_DYLIB)$(EXT_DYLIB) -output $(DIR_BUILD_PRODUCTS)$(PRODUCT_DYLIB)$(EXT_DYLIB)
	
ifeq ($(findstring 1,$(DEBUG)),)
	@echo $(call _PRINT,$(PRODUCT_LIB)$(EXT_DYLIB),universal,Stripping the debug symbols)
	@strip -S $(DIR_BUILD_PRODUCTS)$(PRODUCT_LIB)$(EXT_DYLIB)
endif

# Builds an iOS static library (OS-X only)
ios-lib: armv7 armv7s arm64
	
	@echo $(call _PRINT,$(PRODUCT_IOS_LIB)$(EXT_LIB),universal,Linking the armv7 binary)
	@libtool -static -arch_only armv7 -o $(DIR_BUILD_TEMP_ARM_7_BIN)$(PRODUCT_IOS_LIB)$(EXT_LIB) $(DIR_BUILD_TEMP_ARM_7_OBJ)XSFoundation$(EXT_O)
	
	@echo $(call _PRINT,$(PRODUCT_IOS_LIB)$(EXT_LIB),universal,Linking the armv7s binary)
	@libtool -static -arch_only armv7s -o $(DIR_BUILD_TEMP_ARM_7S_BIN)$(PRODUCT_IOS_LIB)$(EXT_LIB) $(DIR_BUILD_TEMP_ARM_7S_OBJ)XSFoundation$(EXT_O)
	
	@echo $(call _PRINT,$(PRODUCT_IOS_LIB)$(EXT_LIB),universal,Linking the arm64 binary)
	@libtool -static -arch_only arm64 -o $(DIR_BUILD_TEMP_ARM_64_BIN)$(PRODUCT_IOS_LIB)$(EXT_LIB) $(DIR_BUILD_TEMP_ARM_64_OBJ)XSFoundation$(EXT_O)
	
	@echo $(call _PRINT,$(PRODUCT_IOS_LIB)$(EXT_LIB),universal,Linking the universal binary)
	@libtool -static $(DIR_BUILD_TEMP_ARM_7_BIN)$(PRODUCT_IOS_LIB)$(EXT_LIB) $(DIR_BUILD_TEMP_ARM_7S_BIN)$(PRODUCT_IOS_LIB)$(EXT_LIB) $(DIR_BUILD_TEMP_ARM_64_BIN)$(PRODUCT_IOS_LIB)$(EXT_LIB) -o $(DIR_BUILD_PRODUCTS)$(PRODUCT_IOS_LIB)$(EXT_LIB)
	
ifeq ($(findstring 1,$(DEBUG)),)
	@echo $(call _PRINT,$(PRODUCT_IOS_LIB)$(EXT_LIB),universal,Stripping the debug symbols)
	@strip -S $(DIR_BUILD_PRODUCTS)$(PRODUCT_IOS_LIB)$(EXT_LIB)
endif

# Builds an Mac framework (OS-X only)
mac-framework: i386 x86-64
	
	@echo $(call _PRINT,$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK),universal,Creating the directory structure)
	@rm -rf $(DIR_BUILD_PRODUCTS)$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK)
	@mkdir -p $(DIR_BUILD_PRODUCTS)$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK)/Versions/A/Headers/
	@mkdir -p $(DIR_BUILD_PRODUCTS)$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK)/Versions/A/Resources/
	
	@echo $(call _PRINT,$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK),universal,Creating the symbolic links)
	@ln -s A/ $(DIR_BUILD_PRODUCTS)$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK)/Versions/Current
	@ln -s Versions/A/Headers/ $(DIR_BUILD_PRODUCTS)$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK)/Headers
	@ln -s Versions/A/Resources/ $(DIR_BUILD_PRODUCTS)$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK)/Resources
	@ln -s Versions/A/$(PRODUCT_MAC_FRAMEWORK) $(DIR_BUILD_PRODUCTS)$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK)/$(PRODUCT_MAC_FRAMEWORK)

	@echo $(call _PRINT,$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK),universal,Copying the public header files)
	@cp -rf $(DIR_INC)XS/* $(DIR_BUILD_PRODUCTS)$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK)/Versions/A/Headers/
	@rm -rf $(DIR_BUILD_PRODUCTS)$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK)/Versions/A/Headers/__private/
	
	@echo $(call _PRINT,$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK),universal,Creating the Info.plist file)
	@cp -rf $(DIR_RES)$(PRODUCT_MAC_FRAMEWORK)-Info.plist $(DIR_BUILD_PRODUCTS)$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK)/Versions/A/Resources/Info.plist
	@plutil -insert BuildMachineOSBuild -string $(shell sw_vers -buildVersion) $(DIR_BUILD_PRODUCTS)$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK)/Versions/A/Resources/Info.plist
	@plutil -insert DTSDKName -string macosx$(MAC_TARGET) $(DIR_BUILD_PRODUCTS)$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK)/Versions/A/Resources/Info.plist
	@plutil -insert DTCompiler -string $(call _XCODE_SDK_VALUE,DTCompiler)
	@plutil -insert DTPlatformBuild -string $(call _XCODE_SDK_VALUE,DTPlatformBuild)
	@plutil -insert DTPlatformVersion -string $(call _XCODE_SDK_VALUE,DTPlatformVersion)
	@plutil -insert DTSDKBuild -string $(call _XCODE_SDK_VALUE,DTSDKBuild)
	@plutil -insert DTXcode -string $(call _XCODE_SDK_VALUE,DTXcode)
	@plutil -insert DTXcodeBuild -string $(call _XCODE_SDK_VALUE,DTXcodeBuild)
	
	@echo $(call _PRINT,$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK),universal,Copying the bundle resources)
	@:
	
	@echo $(call _PRINT,$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK),universal,Linking the i386 binary)
	@$(call _MAKE_FRAMEWORK_BIN,i386,$(PRODUCT_MAC_FRAMEWORK),$(DIR_BUILD_TEMP_INTEL_32_BIN)$(PRODUCT_MAC_FRAMEWORK),$(DIR_BUILD_TEMP_INTEL_32_OBJ)XSFoundation$(EXT_O))
	
	@echo $(call _PRINT,$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK),universal,Linking the x86-64 binary)
	@$(call _MAKE_FRAMEWORK_BIN,x86_64,$(PRODUCT_MAC_FRAMEWORK),$(DIR_BUILD_TEMP_INTEL_64_BIN)$(PRODUCT_MAC_FRAMEWORK),$(DIR_BUILD_TEMP_INTEL_64_OBJ)XSFoundation$(EXT_O))
	
	@echo $(call _PRINT,$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK),universal,Linking the universal binary)
	@lipo -create $(DIR_BUILD_TEMP_INTEL_32_BIN)$(PRODUCT_MAC_FRAMEWORK) $(DIR_BUILD_TEMP_INTEL_64_BIN)$(PRODUCT_MAC_FRAMEWORK) -output $(DIR_BUILD_PRODUCTS)$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK)/Versions/A/$(PRODUCT_MAC_FRAMEWORK)
	
ifeq ($(findstring 1,$(DEBUG)),)
	@echo $(call _PRINT,$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK),universal,Stripping the debug symbols)
	@strip -S $(DIR_BUILD_PRODUCTS)$(PRODUCT_MAC_FRAMEWORK)$(EXT_FRAMEWORK)/Versions/A/$(PRODUCT_MAC_FRAMEWORK)
endif

# Target: i386
i386: $(_FILES_C_BUILD_INTEL_32)
	
	@echo $(call _PRINT,Linking object files,i386,XSFoundation$(EXT_O))
	@rm -rf $(DIR_BUILD_TEMP_ARM_64_OBJ)XSFoundation$(EXT_O)
	@ld -r $(_FILES_C_BUILD_INTEL_32) -o $(DIR_BUILD_TEMP_INTEL_32_OBJ)XSFoundation$(EXT_O)
	
ifeq ($(findstring 1,$(DEBUG)),)
	@echo $(call _PRINT,XSFoundation$(EXT_O),i386,Stripping the private symbols)
	@$(shell chmod u+x $(DIR_SCRIPTS)Strip-Symbols.sh)
	@$(DIR_SCRIPTS)Strip-Symbols.sh "$(DIR_BUILD_TEMP_INTEL_32_OBJ)XSFoundation$(EXT_O)" ^___XS
endif

# Target: x86-64
x86-64: $(_FILES_C_BUILD_INTEL_64)
	
	@echo $(call _PRINT,Linking object files,x86-64,XSFoundation$(EXT_O))
	@rm -rf $(DIR_BUILD_TEMP_ARM_64_OBJ)XSFoundation$(EXT_O)
	@ld -r $(_FILES_C_BUILD_INTEL_64) -o $(DIR_BUILD_TEMP_INTEL_64_OBJ)XSFoundation$(EXT_O)
	
ifeq ($(findstring 1,$(DEBUG)),)
	@echo $(call _PRINT,XSFoundation$(EXT_O),x86-64,Stripping the private symbols)
	@$(shell chmod u+x $(DIR_SCRIPTS)Strip-Symbols.sh)
	@$(DIR_SCRIPTS)Strip-Symbols.sh $(DIR_BUILD_TEMP_INTEL_64_OBJ)XSFoundation$(EXT_O) ^___XS
endif

# Target: armv7
armv7: $(_FILES_C_BUILD_ARM_7)
	
	@echo $(call _PRINT,Linking object files,armv7,XSFoundation$(EXT_O))
	@rm -rf $(DIR_BUILD_TEMP_ARM_64_OBJ)XSFoundation$(EXT_O)
	@ld -r $(_FILES_C_BUILD_ARM_7) -o $(DIR_BUILD_TEMP_ARM_7_OBJ)XSFoundation$(EXT_O)
	
#ifeq ($(findstring 1,$(DEBUG)),)
#	@echo $(call _PRINT,XSFoundation$(EXT_O),armv7,Stripping the private symbols)
#	@$(shell chmod u+x $(DIR_SCRIPTS)Strip-Symbols.sh)
#	@$(DIR_SCRIPTS)Strip-Symbols.sh $(DIR_BUILD_TEMP_ARM_7_OBJ)XSFoundation$(EXT_O) ^___XS
#endif

# Target: armv7s
armv7s: $(_FILES_C_BUILD_ARM_7S)
	
	@echo $(call _PRINT,Linking object files,armv7s,XSFoundation$(EXT_O))
	@rm -rf $(DIR_BUILD_TEMP_ARM_64_OBJ)XSFoundation$(EXT_O)
	@ld -r $(_FILES_C_BUILD_ARM_7S) -o $(DIR_BUILD_TEMP_ARM_7S_OBJ)XSFoundation$(EXT_O)
	
#ifeq ($(findstring 1,$(DEBUG)),)
#	@echo $(call _PRINT,XSFoundation$(EXT_O),armv7s,Stripping the private symbols)
#	@$(shell chmod u+x $(DIR_SCRIPTS)Strip-Symbols.sh)
#	@$(DIR_SCRIPTS)Strip-Symbols.sh $(DIR_BUILD_TEMP_ARM_7S_OBJ)XSFoundation$(EXT_O) ^___XS
#endif

# Target: arm64
arm64: $(_FILES_C_BUILD_ARM_64)
	
	@echo $(call _PRINT,Linking object files,arm64,XSFoundation$(EXT_O))
	@rm -rf $(DIR_BUILD_TEMP_ARM_64_OBJ)XSFoundation$(EXT_O)
	@ld -r $(_FILES_C_BUILD_ARM_64) -o $(DIR_BUILD_TEMP_ARM_64_OBJ)XSFoundation$(EXT_O)
	
#ifeq ($(findstring 1,$(DEBUG)),)
#	@echo $(call _PRINT,XSFoundation$(EXT_O),arm64,Stripping the private symbols)
#	@$(shell chmod u+x $(DIR_SCRIPTS)Strip-Symbols.sh)
#	@$(DIR_SCRIPTS)Strip-Symbols.sh $(DIR_BUILD_TEMP_ARM_64_OBJ)XSFoundation$(EXT_O) ^___XS
#endif

#-------------------------------------------------------------------------------
# Targets with second expansion
#-------------------------------------------------------------------------------

.SECONDEXPANSION:

# Target: i386 object file
$(DIR_BUILD_TEMP_INTEL_32_OBJ)%$(EXT_O): $$(shell mkdir -p $$(dir $$@)) %$(EXT_C)
	
	@echo $(call _PRINT_FILE,"Compiling C file",i386,$<)
	@$(_CC_XS) -arch i386 -o $@ -c $<

# Target: x86_64 object file
$(DIR_BUILD_TEMP_INTEL_64_OBJ)%$(EXT_O): $$(shell mkdir -p $$(dir $$@)) %$(EXT_C)
	
	@echo $(call _PRINT_FILE,"Compiling C file",x86-64,$<)
	@$(_CC_XS) -arch x86_64 -o $@ -c $<

# Target: armv7 object file
$(DIR_BUILD_TEMP_ARM_7_OBJ)%$(EXT_O): $$(shell mkdir -p $$(dir $$@)) %$(EXT_C)
	
	@echo $(call _PRINT_FILE,"Compiling C file",armv7,$<)
	@$(_CC_XS) -arch armv7 -isysroot $(_IOS_SDK_PATH) -o $@ -c $<

# Target: armv7s object file
$(DIR_BUILD_TEMP_ARM_7S_OBJ)%$(EXT_O): $$(shell mkdir -p $$(dir $$@)) %$(EXT_C)
	
	@echo $(call _PRINT_FILE,"Compiling C file",armv7s,$<)
	@$(_CC_XS) -arch armv7s -isysroot $(_IOS_SDK_PATH) -o $@ -c $<

# Target: arm64 object file
$(DIR_BUILD_TEMP_ARM_64_OBJ)%$(EXT_O): $$(shell mkdir -p $$(dir $$@)) %$(EXT_C)
	
	@echo $(call _PRINT_FILE,"Compiling C file",arm64,$<)
	@$(_CC_XS) -arch arm64 -isysroot $(_IOS_SDK_PATH) -o $@ -c $<

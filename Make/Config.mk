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

#-------------------------------------------------------------------------------
# Platform
#-------------------------------------------------------------------------------

# Host architecture
_HOST_ARCH := $(shell uname -m)

# Host architecture
_HOST_OS := $(shell uname -s)

ifneq (,$(findstring CYGWIN_NT,$(_HOST_OS)))
_OS_CYGWIN := 1
endif

ifneq (,$(findstring Linux,$(_HOST_OS)))
_OS_LINUX := 1
endif

ifneq (,$(findstring Darwin,$(_HOST_OS)))
_OS_DARWIN := 1
endif

#-------------------------------------------------------------------------------
# Paths
#-------------------------------------------------------------------------------

# Root directory
DIR := ./

# Root build directory (debug or release)
ifeq ($(findstring 1,$(DEBUG)),)
DIR_BUILD := $(DIR)Build/Release/
else
DIR_BUILD := $(DIR)Build/Debug/
endif

# Relative build directories
DIR_BUILD_PRODUCTS   := $(DIR_BUILD)Products/
DIR_BUILD_TEMP       := $(DIR_BUILD)Intermediates/
DIR_BUILD_TEMP_XS    := $(DIR_BUILD_TEMP)XSFoundation/
DIR_BUILD_TEMP_TESTS := $(DIR_BUILD_TEMP)Unit-Tests/

# Source directories
DIR_INC           := $(DIR)XSFoundation/include/
DIR_SRC           := $(DIR)XSFoundation/source/
DIR_SRC_FUNCTIONS := $(DIR_SRC)Functions/
DIR_SRC_CLASSES   := $(DIR_SRC)Classes/
DIR_SRC_TESTS     := $(DIR)Unit-Tests/

# Other directories
DIR_SUBMODULES    := $(DIR)Submodules/
DIR_XSCTEST       := $(DIR_SUBMODULES)XSCTest/
DIR_XSCTEST_INC   := $(DIR_XSCTEST)XSCTest/include/
DIR_XSCTEST_BUILD := $(DIR_XSCTEST)Build/Products/

#-------------------------------------------------------------------------------
# Search paths
#-------------------------------------------------------------------------------

# Clear any existing search path
VPATH =
vpath

# Define the search paths for source files
vpath %$(EXT_C) $(DIR_SRC)
vpath %$(EXT_C) $(DIR_SRC_TESTS)

#-------------------------------------------------------------------------------
# File suffixes
#-------------------------------------------------------------------------------

# Source extensions
EXT_C := .c
EXT_H := .h

ifdef _OS_CYGWIN

# Windows specific
EXT_O      := .obj
EXT_LIB    := .lib
EXT_EXE    := .exe
PREFIX_LIB :=

else

# POSIX specific
EXT_O      := .o
EXT_LIB    := .a
EXT_EXT    :=
PREFIX_LIB := lib

endif

# Adds the suffixes used in this file
.SUFFIXES: $(EXT_C) $(EXT_H) $(EXT_O)

#-------------------------------------------------------------------------------
# Files
#-------------------------------------------------------------------------------

# 
# Gets every C file in a specific source directory
# 
# @param    The directory
# 
GET_C_FILES = $(foreach dir,$(1), $(wildcard $(dir)*$(EXT_C)))

# Gets only the file name of the C files
_FILES_C_REL       = $(subst $(DIR_SRC),,$(FILES_C))
_FILES_C_REL_TESTS = $(subst $(DIR_SRC_TESTS),,$(FILES_C_TESTS))

# Replace the code extension by the object one
_FILES_C_OBJ       = $(subst $(EXT_C),$(EXT_O),$(_FILES_C_REL))
_FILES_C_OBJ_TESTS = $(subst $(EXT_C),$(EXT_O),$(_FILES_C_REL_TESTS))

# Prefix all object files with the build directory
_FILES_C_BUILD       = $(addprefix $(DIR_BUILD_TEMP_XS),$(_FILES_C_OBJ))
_FILES_C_BUILD_TESTS = $(addprefix $(DIR_BUILD_TEMP_TESTS),$(_FILES_C_OBJ_TESTS))

#-------------------------------------------------------------------------------
# Commands configuration
#-------------------------------------------------------------------------------

# Build flags
ifeq ($(findstring 1,$(DEBUG)),)
_CC_FLAGS = $(strip $(CC_FLAGS_WARN) $(CC_FLAGS_RELEASE) $(_CC_EXTRA_FLAGS))
else
_CC_FLAGS = $(strip $(CC_FLAGS_WARN) $(CC_FLAGS_DEBUG) $(_CC_EXTRA_FLAGS))
endif

ifdef _OS_CYGWIN

# Build flags
CC_FLAGS_WARN    := /W4 /WX
CC_FLAGS_DEBUG   := /Od /sdl
CC_FLAGS_RELEASE := /GL /Gw /O2 /sdl

# C compiler
_CC = Make/cl.bat /nologo /utf-8 $(_CC_FLAGS) /std:$(STDC) /I $(call _WIN_PATH,$(abspath $(DIR_INC)))

else

# Build flags
CC_FLAGS_WARN    := -Werror -Weverything -Wno-unknown-warning-option -Wno-poison-system-directories
CC_FLAGS_DEBUG   := -O0 -gfull
CC_FLAGS_RELEASE := -Os

# C compiler
_CC = $(CC) $(_CC_FLAGS) -std=$(STDC) -I$(DIR_INC)

endif

# Additional libraries
ifdef _OS_LINUX
_EXTRA_LIBS := m
else
_EXTRA_LIBS :=
endif

# 
# Compiles a single source file
# 
# @param    The source file
# @param    The output file
# 
ifdef _OS_CYGWIN
COMPILE_FILE = @$(_CC) /c $(call _WIN_PATH,$(abspath $1)) /Fo$(call _WIN_PATH,$(abspath $2))
else
COMPILE_FILE = @$(_CC) -o $2 -c $(abspath $1)
endif

# 
# Creates a static library
# 
# @param    The library output file
# @param    The object files to add to the library
# 
ifdef _OS_CYGWIN
CREATE_STATIC_LIB = @Make/lib.bat /NOLOGO /OUT:$(call _WIN_PATH,$1) $(foreach _F,$2,$(call _WIN_PATH,$(_F)))
else
CREATE_STATIC_LIB = @ar rcs $1 $2
endif

# 
# Creates a executable
# 
# @param    The executabée output file
# @param    The source/object files to compile/link
# @param    The search paths for libraries (if any)
# @param    The libraries to link with (if any)
# 
ifdef _OS_CYGWIN
CREATE_EXEC = @Make/link.bat /NOLOGO /WX /OUT:$(call _WIN_PATH,$1) $(addprefix /LIBPATH:,$(foreach _L,$3,$(call _WIN_PATH,$(abspath $(_L))))) $(foreach _F,$2,$(call _WIN_PATH,$(_F))) $(_LIB) $(addsuffix $(EXT_LIB),$4)
else
CREATE_EXEC = @$(_CC) -o $1 $2 $(foreach _L,$3,$(addprefix -L,$(_L))) $(foreach _L,$4,$(addprefix -l,$(_L)))
endif

#-------------------------------------------------------------------------------
# Display
#-------------------------------------------------------------------------------

# Terminal colors
COLOR_NONE   := "\033[0m"
COLOR_GRAY   := "\033[30;01m"
COLOR_RED    := "\033[31;01m"
COLOR_GREEN  := "\033[32;01m"
COLOR_YELLOW := "\033[33;01m"
COLOR_BLUE   := "\033[34;01m"
COLOR_PURPLE := "\033[35;01m"
COLOR_CYAN   := "\033[36;01m"

# Platform specific
ifdef _OS_CYGWIN
_ECHO_ARGS := -e
else
_ECHO_ARGS :=
endif

# 
# Prints a message to the standard output
# 
# @param    The prompt components
# @param    The message
# 
PRINT = @echo $(_ECHO_ARGS) "[ "$(COLOR_CYAN)XSFoundation$(COLOR_NONE) "]> [ "$(COLOR_PURPLE)$(MAKELEVEL)$(COLOR_NONE) "]> "$(foreach _P,$(_BRANCH) $(1),"[ "$(COLOR_GREEN)$(_P)$(COLOR_NONE)" ]>")" *** "$(2)

# 
# Prints a message to the standard output
# 
# @param    The prompt components
# @param    The message
# 
ifeq ($(findstring 1,$(DEBUG)),)
PRINT_BUILD = $(call PRINT,Release $1,$2)
else
PRINT_BUILD = $(call PRINT,Debug $1,$2)
endif

# 
# Prints an architecture related message to the standard output
# 
# @param    The architecture
# @param    The message
# 
PRINT_ARCH = $(call PRINT_BUILD,,$(2) [ $(COLOR_RED)$(1)$(COLOR_NONE) ])

# 
# Prints an architecture related message about a file to the standard output
# 
# @param    The architecture
# @param    The message
# @param    The file
# 
#PRINT_FILE = $(call PRINT_ARCH,$(1),$(2)): $(COLOR_YELLOW)$(patsubst %.,%,$(subst /,.,$(dir $(patsubst $(DIR_SRC)%,%,$3))))$(COLOR_NONE).$(COLOR_GRAY)"$(notdir $(3))"$(COLOR_NONE)
PRINT_FILE = $(call PRINT_ARCH,$(1),$(2)): $(COLOR_YELLOW)$(subst .$(COLOR_NONE).,,$(patsubst %.,%,$(subst /,.,$(dir $(patsubst $(DIR_SRC_TESTS)%,%,$(patsubst $(DIR_SRC)%,%,$3)))))$(COLOR_NONE).)$(COLOR_GRAY)"$(notdir $(3))"$(COLOR_NONE)

#-------------------------------------------------------------------------------
# Tools
#-------------------------------------------------------------------------------

# Make version (version 4 allows parallel builds with output sync) 
_MAKE_VERSION_MAJOR := $(shell echo $(MAKE_VERSION) | cut -f1 -d.)
_MAKE_4             := $(shell [ $(_MAKE_VERSION_MAJOR) -ge 4 ] && echo true)

# Check for the XSDocgen utility
_HAS_XSDOCGEN := $(shell if [ -f "/usr/local/bin/XSDocgen" ]; then echo true; else echo false; fi )

# Check for the xcodebuild utility
_HAS_XCBUILD := $(shell if [ -f "/usr/bin/xcodebuild" ]; then echo true; else echo false; fi )

#-------------------------------------------------------------------------------
# Miscellaneous
#-------------------------------------------------------------------------------

# Current GIT branch
_BRANCH := $(shell git rev-parse --abbrev-ref HEAD 2>/dev/null)

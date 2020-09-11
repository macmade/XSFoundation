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
DIR_BUILD_PRODUCTS := $(DIR_BUILD)Products/
DIR_BUILD_TEMP     := $(DIR_BUILD)Intermediates/

# Source directories
DIR_INC           := $(DIR)XSFoundation/include/
DIR_SRC           := $(DIR)XSFoundation/source/
DIR_SRC_FUNCTIONS := $(DIR_SRC)Functions/
DIR_SRC_CLASSES   := $(DIR_SRC)Classes/

# Scripts directory
DIR_SCRIPTS := $(DIR)Scripts/

#-------------------------------------------------------------------------------
# Search paths
#-------------------------------------------------------------------------------

# Clear any existing search path
VPATH =
vpath

# Define the search paths for source files
vpath %$(EXT_C) $(DIR_SRC)

#-------------------------------------------------------------------------------
# File suffixes
#-------------------------------------------------------------------------------

# File extensions
EXT_C         := .c
EXT_H         := .h
EXT_O         := .o
EXT_LIB       := .a

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
_FILES_C_REL = $(subst $(DIR_SRC),,$(FILES_C))

# Replace the code extension by the object one
_FILES_C_OBJ = $(subst $(EXT_C),$(EXT_O),$(_FILES_C_REL))

# Prefix all object files with the build directory
_FILES_C_BUILD = $(addprefix $(DIR_BUILD_TEMP),$(_FILES_C_OBJ))

#-------------------------------------------------------------------------------
# Commands configuration
#-------------------------------------------------------------------------------

# Build flags
ifeq ($(findstring 1,$(DEBUG)),)
_CC_FLAGS = $(OPTIM_RELEASE)
else
_CC_FLAGS = $(OPTIM_DEBUG) -DDEBUG=1 -gfull
endif

# C compiler - Debug mode
_CC = $(CC) -Werror -Weverything -std=$(STDC) -I$(DIR_INC) -DXS_BUILD $(_CC_FLAGS)

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

# 
# Prints a message to the standard output
# 
# @param    The prompt components
# @param    The message
# 
PRINT = @echo "[ "$(COLOR_CYAN)XSFoundation$(COLOR_NONE) "]> [ "$(COLOR_PURPLE)$(MAKELEVEL)$(COLOR_NONE) "]> "$(foreach _P,$(_BRANCH) $(1),"[ "$(COLOR_GREEN)$(_P)$(COLOR_NONE)" ]>")" *** "$(2)

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
PRINT_FILE = $(call PRINT_ARCH,$(1),$(2)): $(COLOR_YELLOW)$(patsubst %.,%,$(subst /,.,$(dir $(patsubst $(DIR_SRC)%,%,$3))))$(COLOR_NONE).$(COLOR_GRAY)"$(notdir $(3))"$(COLOR_NONE)

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

# Host architecture
_HOST_ARCH := $(shell uname -m)

# Current GIT branch
_BRANCH := $(shell git rev-parse --abbrev-ref HEAD 2>/dev/null)

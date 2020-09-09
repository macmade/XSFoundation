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
DIR_SRC           := $(DIR)XSFoundation/source/XS/
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
_CC_FLAGS = $(OPTIM_DEBUG) -DDEBUG=1 -gfull
else
_CC_FLAGS = $(OPTIM_RELEASE)
endif

# C compiler - Debug mode
_CC = $(CC) -Werror -$(_CC_FLAGS) -std=$(STDC) -I$(DIR_INC) -D__XS_BUILD__

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
PRINT_BUILD = $(call PRINT,Debug $1,$2)
else
PRINT_BUILD = $(call PRINT,Release $1,$2)
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

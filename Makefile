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

CC      := clang
PRODUCT := XSFoundation
STDC    := c11

#-------------------------------------------------------------------------------
# Files
#-------------------------------------------------------------------------------

# Gets every C file in the source directories (XSFoundation)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)Atomic/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)Memory/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)Runtime/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)Sleep/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)SpinLock/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)Threading/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)Process/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)Log/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC_FUNCTIONS)CString/)

# Gets every C file in the source directories (Unit-Tests)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS))
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)Atomic/)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)Process/)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)SpinLock/)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)CString/)

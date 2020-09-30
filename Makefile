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
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Functions/Atomic/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Functions/Memory/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Functions/Runtime/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Functions/Sleep/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Functions/SpinLock/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Functions/Threading/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Functions/Process/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Functions/Log/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Functions/CString/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Classes/XSAutoreleasePool/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Classes/XSString/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Classes/XSMutableString/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Classes/XSBoolean/)
FILES_C += $(call GET_C_FILES, $(DIR_SRC)Classes/XSData/)

# Gets every C file in the source directories (Unit-Tests)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS))
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)Macros/)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)Functions/)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)Functions/Atomic/)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)Functions/Process/)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)Functions/SpinLock/)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)Functions/CString/)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)Functions/Memory/)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)Functions/Runtime/)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)Functions/Threading/)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)Classes/XSAutoreleasePool/)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)Classes/XSString/)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)Classes/XSMutableString/)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)Classes/XSBoolean/)
FILES_C_TESTS += $(call GET_C_FILES, $(DIR_SRC_TESTS)Classes/XSData/)

# Gets every C file in the source directories (Example)
FILES_C_EXAMPLE += $(call GET_C_FILES, $(DIR_SRC_EXAMPLE))

#-------------------------------------------------------------------------------
# Dependencies
#-------------------------------------------------------------------------------

ifndef _OS_CYGWIN

-include $(_FILES_C_BUILD:$(EXT_O)=$(EXT_DEP))
-include $(_FILES_C_BUILD_TESTS:$(EXT_O)=$(EXT_DEP))
-include $(_FILES_C_BUILD_EXAMPLE:$(EXT_O)=$(EXT_DEP))

endif

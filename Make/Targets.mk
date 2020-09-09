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
# Built-in targets
#-------------------------------------------------------------------------------

# Default make target
.DEFAULT_GOAL := all

# Declaration for phony targets, to avoid problems with local files
.PHONY: all clean clean_temp clean_products doc debug release lib

# Declaration for precious targets, to avoid cleaning of intermediate files
.PRECIOUS: $(DIR_BUILD_TEMP)%$(EXT_O)

#-------------------------------------------------------------------------------
# Phony targets
#-------------------------------------------------------------------------------

# Main Target
all: debug release
	
	@:

# Cleans all build files
clean:
	
	@$(MAKE) -s clean_temp DEBUG=1
	@$(MAKE) -s clean_products DEBUG=1
	@$(MAKE) -s clean_temp
	@$(MAKE) -s clean_products
	
# Clean temporary files
clean_temp:
	
	$(call PRINT_ARCH,$(_HOST_ARCH),Cleaning all intermediate files)
	@rm -rf $(DIR_BUILD_TEMP)*
	
# Clean products
clean_products:
	
	$(call PRINT_ARCH,$(_HOST_ARCH),Cleaning all product files)
	@rm -rf $(DIR_BUILD_PRODUCTS)*
	
# Documentation
doc:
	
ifeq ($(_HAS_XSDOCGEN),true)
	$(call PRINT,XSDoc,Generating the documentation)
	@/usr/local/bin/XSDocgen \
	@    --clear \
	@    --source XSFoundation/include \
	@    --output Documentation \
	@    --exclude-file HeaderDoc-Exclude.txt \
	@    --project-name "XSFoundation" \
	@    --project-copyright "XS-Labs &copy; %Y - All Rights Reserved" \
	@    --project-version "2.0.0-0" \
	@    --project-timezone "Europe/Zurich" \
	@    --company-name "XS-Labs" \
	@    --company-url "http://www.xs-labs.com/" \
	@    --page-home "Pages/Home.inc.php" \
	@    --source-root-prefix "/XSFoundation/include/" \
	@    --classes-prefix "XSFoundation/include/XS/Classes/" \
	@    --functions-prefix "XSFoundation/include/XS/Functions/" \
	@    --types-prefix "XSFoundation/include/XS/XSTypes/" \
	@    --page-add "Building XSFoundation" "Pages/Build.inc.php" \
	@    --page-add "Memory management" "Pages/Memory.inc.php" \
	@    --page-add "Class definition" "Pages/Classes.inc.php" \
	@    --google-analytics "UA-51035898-4" "xs-labs.com" \
	@    --google-analytics-display-features
else
	$(call PRINT,XSDoc,Skipping documentation generation - XSDocgen is not installed)
endif

# Debug build (parallel if available)
debug:
	
ifeq ($(_MAKE_4),true)
	@$(MAKE) -s -j 50 --output-sync lib DEBUG=1
else
	@$(MAKE) lib DEBUG=1
endif
	
# Release build (parallel if available)
release:
	
ifeq ($(_MAKE_4),true)
	@$(MAKE) -s -j 50 --output-sync lib
else
	@$(MAKE) lib
endif

#-------------------------------------------------------------------------------
# Targets with second expansion
#-------------------------------------------------------------------------------

.SECONDEXPANSION:

# Static library
lib: _OBJ = $(DIR_BUILD_TEMP)XSFoundation$(EXT_O)
lib: _LIB = $(DIR_BUILD_PRODUCTS)$(PRODUCT)$(EXT_LIB)
lib: $$(_FILES_C_BUILD)

	$(call PRINT_ARCH,$(_HOST_ARCH),"Linking object files"): $(COLOR_BLUE)$(notdir $(_OBJ))$(COLOR_NONE)
	@rm -f $(_OBJ)
	@ld -r $(_FILES_C_BUILD) -o $(_OBJ)
	
	$(call PRINT_ARCH,$(_HOST_ARCH),"Creating static library"): $(COLOR_BLUE)$(notdir $(_LIB))$(COLOR_NONE)
	@libtool -static -o $(_LIB) $(_OBJ)
	
ifneq ($(findstring 1,$(DEBUG)),)
	$(call PRINT_ARCH,$(_HOST_ARCH),"Stripping debug symbols"): $(COLOR_BLUE)$(notdir $(_LIB))$(COLOR_NONE)
	@strip -S $(_LIB)
endif

# Target: Object file
$(DIR_BUILD_TEMP)%$(EXT_O): $$(shell mkdir -p $$(dir $$@)) %$(EXT_C)
	
	$(call PRINT_FILE,$(_HOST_ARCH),"Compiling C file",$<)
	@$(_CC) -o $@ -c $<

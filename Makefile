LIBNAME                 = libxeos

CC                      = gcc
LIBTOOL                 = glibtool
LIBTOOL_DYNAMIC			= libtool
ARGS_CC                 = -std=c99 -Os -pedantic -Werror -Wall -Wextra -Wbad-function-cast -Wdeclaration-after-statement -Werror-implicit-function-declaration -Wmissing-braces -Wmissing-declarations -Wmissing-field-initializers -Wmissing-prototypes -Wnested-externs -Wold-style-definition -Wparentheses -Wreturn-type -Wshadow -Wsign-compare -Wstrict-prototypes -Wswitch -Wuninitialized -Wunknown-pragmas -Wunused-function -Wunused-label -Wunused-parameter -Wunused-value -Wunused-variable
ARGS_LIBTOOL_LO         = --mode=compile
ARGS_LIBTOOL_LA         = --mode=link
ARGS_LIBTOOL_DYLIB      = -dynamic -flat_namespace -lSystem -undefined suppress -macosx_version_min 10.6
ARGS_LIBTOOL            = --quiet

EXT_CODE                = .c
EXT_HEADERS             = .h
EXT_OBJECT              = .o
EXT_ARCHIVE             = .a
EXT_LIB_OBJECT          = .lo
EXT_LIB_ARCHIVE         = .la
EXT_LIB_DYNAMIC         = .dylib

DIR_BUILD               = build/
DIR_SRC                 = source/
DIR_INC                 = $(DIR_SRC)include/
DIR_INSTALL		        = /usr/local/$(LIBNAME)
DIR_INSTALL_LIB		    = $(DIR_INSTALL)lib/
DIR_INSTALL_INC		    = $(DIR_INSTALL)include/

.SUFFIXES:
.SUFFIXES: $(EXT_CODE) $(EXT_HEADERS) $(EXT_OBJECT) $(EXT_LIB_OBJECT) $(EXT_LIB_ARCHIVE) $(EXT_LIB_DYNAMIC)

VPATH =
vpath
vpath %$(EXT_CODE) $(DIR_SRC)
vpath %$(EXT_HEADERS) $(DIR_INC)
vpath %$(EXT_OBJECT) $(DIR_BUILD)
vpath %$(EXT_LIB_OBJECT) $(DIR_BUILD)
vpath %$(EXT_LIB_ARCHIVE) $(DIR_BUILD)
vpath %$(EXT_LIB_DYNAMIC) $(DIR_BUILD)

_FILES_SRC             = $(foreach dir,$(DIR_SRC),$(wildcard $(DIR_SRC)*$(EXT_CODE)))
_FILES_SRC_REL         = $(notdir $(_FILES_SRC))
_FILES_SRC_O           = $(subst $(EXT_CODE),$(EXT_OBJECT),$(_FILES_SRC_REL))
_FILES_SRC_O_BUILD     = $(addprefix $(DIR_BUILD),$(_FILES_SRC_O))
_FILES_SRC_LO          = $(subst $(EXT_CODE),$(EXT_LIB_OBJECT),$(_FILES_SRC_REL))
_FILES_SRC_LO_BUILD    = $(addprefix $(DIR_BUILD),$(_FILES_SRC_LO))
_FILES_SRC_LA_BUILD    = $(addprefix $(DIR_BUILD),$(LIBNAME)$(EXT_LIB_ARCHIVE))
_FILES_SRC_DYLIB_BUILD = $(addprefix $(DIR_BUILD),$(LIBNAME)$(EXT_LIB_DYNAMIC))
_STEM                  = %
_ARGS_CC               = -I $(DIR_INC) $(ARGS_CC)

.PHONY: all clean install uninstall __copyright

all: __copyright $(_FILES_SRC_O_BUILD) $(_FILES_SRC_LO_BUILD) $(_FILES_SRC_LA_BUILD) $(_FILES_SRC_DYLIB_BUILD)
	
clean:
	@echo "    - Removing all build files"
	@rm -rf $(DIR_BUILD)*
	@rm -rf $(DIR_BUILD).libs
	@if [ -d "$(DIR_INSTALL).libs" ]; then rm -rf "$(DIR_INSTALL).libs"; fi
	
install: all
	@if [ ! -d "$(DIR_INSTALL)" ]; then sudo mkdir $(DIR_INSTALL); fi
	@if [ ! -d "$(DIR_INSTALL_LIB)" ]; then sudo mkdir $(DIR_INSTALL_LIB); fi
	@if [ ! -d "$(DIR_INSTALL_INC)" ]; then sudo mkdir $(DIR_INSTALL_INC); fi
	@echo "    - Installing header files to:      $(DIR_INSTALL_INC)"
	@sudo cp $(DIR_INC)* $(DIR_INSTALL_INC)
	@echo "    - Installing static libraries to:  $(DIR_INSTALL_LIB)"
	@sudo cp $(DIR_BUILD)*$(EXT_ARCHIVE) $(DIR_INSTALL_LIB)
	@echo "    - Installing dynamic libraries to: $(DIR_INSTALL_LIB)"
	@sudo cp $(DIR_BUILD)*$(EXT_LIB_DYNAMIC) $(DIR_INSTALL_LIB)
	
uninstall:
	@if [ -d "$(DIR_INSTALL)" ]; then sudo rm -rf $(DIR_INSTALL); fi
	
$(DIR_BUILD)%$(EXT_OBJECT): %$(EXT_CODE)
	@echo "    - Building object file:     "$(subst $(DIR_BUILD),"",$@)
	@$(CC) $(_ARGS_CC) -o $(DIR_BUILD)$(@F) -c $< $(CFLAGS)

$(DIR_BUILD)%$(EXT_LIB_OBJECT): %$(EXT_CODE)
	@echo "    - Building library object:  "$(subst $(DIR_BUILD),"",$(subst $(EXT_LIB_ARCHIVE),$(EXT_LIB_OBJECT),$@))
	@$(LIBTOOL) $(ARGS_LIBTOOL) $(ARGS_LIBTOOL_LO) $(CC) -o $(subst $(EXT_LIB_ARCHIVE),$(EXT_LIB_OBJECT),$@) -c $< $(_ARGS_CC) $(CFLAGS)
	
$(DIR_BUILD)%$(EXT_LIB_ARCHIVE): $(_FILES_SRC_LO_BUILD)
	@echo "    - Building static library:  "$(subst $(DIR_BUILD),"",$@)
	@$(LIBTOOL) $(ARGS_LIBTOOL) $(ARGS_LIBTOOL_LA) $(CC) -o $@ -c $? $(_ARGS_CC) $(CFLAGS)
	@cp $(subst $(DIR_BUILD),$(DIR_BUILD).libs/,$(subst $(EXT_LIB_ARCHIVE),$(EXT_ARCHIVE),$@)) $(subst $(EXT_LIB_ARCHIVE),$(EXT_ARCHIVE),$@)

$(DIR_BUILD)%$(EXT_LIB_DYNAMIC): $(_FILES_SRC_O_BUILD)
	@echo "    - Building dynamic library: "$(subst $(DIR_BUILD),"",$@)
	@$(LIBTOOL_DYNAMIC) $(ARGS_LIBTOOL_DYLIB) -install_name $(DIR_INSTALL_LIB)$(subst $(DIR_BUILD),"",$@) -o $@ $?
	
__copyright:
	@echo 
	@echo "----------------------------------------------------------------------"
	@echo "Copyright (c) 2011, Jean-David Gadina <macmade@eosgarden.com>"
	@echo "Distributed under the Boost Software License, Version 1.0."
	@echo "----------------------------------------------------------------------"
	@echo 

test: test.c all
	@echo 
	@echo "----------------------------------------------------------------------"
	@echo "Compiling the test executable"
	@echo "----------------------------------------------------------------------"
	@echo 
	$(CC) -Wall -I$(DIR_INC) -o $(DIR_BUILD)$@ $(DIR_BUILD)$(LIBNAME)$(EXT_ARCHIVE) $<
	@echo 
	@echo "----------------------------------------------------------------------"
	@echo "Running the test executable"
	@echo "----------------------------------------------------------------------"
	@echo 
	@./$(DIR_BUILD)$@
	@echo 

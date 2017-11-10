include Makefile.config
PKGNAME = mlgmpidl
PKGVERS = 1.2.5

#---------------------------------------
# Directories
#---------------------------------------

SRCDIR = $(shell pwd)
#
# Installation directory
#
PREFIX = $(MLGMPIDL_PREFIX)

ifeq ($(OCAMLFIND),)
OCAMLCCOPT = -ccopt -L$(MLGMPIDL_PREFIX)
else
SITE-LIB = $(shell $(OCAMLFIND) printconf destdir)
PKG-NAME = gmp
SITE-LIB-PKG = $(SITE-LIB)/$(PKG-NAME)
REQ_PKG = bigarray
OCAMLCCOPT = -ccopt -L$(SITE-LIB)/stublibs -ccopt -L$(SITE-LIB-PKG)
OCAMLC := $(OCAMLFIND) ocamlc -package "$(REQ_PKG)"
OCAMLOPT := $(OCAMLFIND) ocamlopt -package "$(REQ_PKG)"
endif

#---------------------------------------
# CAML part
#---------------------------------------

OCAMLCCOPT += \
-ccopt "$(LDFLAGS)" \
-ccopt -L$(CAMLIDL_DIR) \
-ccopt -L$(CAML_DIR) \
-ccopt -L$(GMP_PREFIX)/lib \
-ccopt -L$(MPFR_PREFIX)/lib \

LIBS = -lmpfr -lgmp -lcamlidl
OCAMLLDFLAGS = $(OCAMLCCOPT) $(addprefix -cclib ,$(LIBS))

IDLMODULES = mpz mpq mpf mpfr gmp_random
MLMODULES = $(IDLMODULES) mpzf mpqf mpfrf

#---------------------------------------
# C part
#---------------------------------------

ICFLAGS = \
$(CPPFLAGS) \
-I$(GMP_PREFIX)/include \
-I$(MPFR_PREFIX)/include \
-I$(CAML_DIR) -I$(CAMLIDL_DIR)

LDFLAGS += \
-L$(GMP_PREFIX)/lib \
-L$(MPFR_PREFIX)/lib \
-L$(CAML_DIR) -L$(CAML_DIR)/stublibs -L$(CAMLIDL_DIR) \
 -lmpfr -lgmp -lcamlidl

CCMODULES = $(IDLMODULES:%=%_caml) gmp_caml

CCLIB = libgmp_caml.a libgmp_caml.p.a
ifneq ($(HAS_SHARED),)
CCLIB += dllgmp_caml.so
endif

ifneq ($(HAS_OCAMLOPT),)
  MLLIBx = $(MLMODULES:%=%.cmx) gmp.cmxa gmp.a		\
	   $(MLMODULES:%=%.p.cmx) gmp.p.cmxa gmp.p.a
  ifneq ($(HAS_NATIVE_PLUGINS),)
    MLLIBx += gmp.cmxs
  endif
endif

FILES_TOINSTALL = \
	META \
	gmp_caml.h \
	$(IDLMODULES:%=%.idl) \
	$(MLMODULES:%=%.ml) $(MLMODULES:%=%.mli) \
	$(MLMODULES:%=%.cmi) gmp.cma \
	$(MLLIBx) \
	$(CCLIB)

ifneq ($(HAS_TYPEREX),)
FILES_TOINSTALL += $(MLMODULES:%=%.cmt) $(MLMODULES:%=%.cmti)
endif

#---------------------------------------
# Rules
#---------------------------------------

all: byte opt prof

byte: $(MLMODULES:%=%.cmi) gmp.cma
opt: $(MLMODULES:%=%.cmx) gmp.cmxa
ifneq ($(HAS_NATIVE_PLUGINS),)
  opt: gmp.cmxs
endif
prof: $(MLMODULES:%=%.p.cmx) gmp.p.cmxa

# Example of compilation command with ocamlfind
%.byte: %.ml
	$(OCAMLFIND) ocamlc $(OCAMLFLAGS) -o $@ $*.ml \
	-package gmp -linkpkg
%.opt: %.ml
	$(OCAMLFIND) ocamlopt -verbose $(OCAMLOPTFLAGS) -o $@ $*.ml \
	-package gmp -linkpkg
# without ocamlfind
session.byte: session.ml gmp.cma
	$(OCAMLC) -I $(PREFIX)/lib -o $@ bigarray.cma gmp.cma $<
session.opt: session.ml gmp.cmxa
	$(OCAMLOPT) -I $(PREFIX)/lib -cclib -L. -o $@ bigarray.cmxa gmp.cmxa $<
# and with noautolink
session2.opt: session.ml
	$(OCAMLOPT) -noautolink -I$(SITE-LIB-PKG) -o $@ bigarray.cmxa gmp.cmxa $<
	$(OCAMLLDFLAGS) -cclib "-lbigarray -lgmp_caml"

# CAML gmp
gmp.cma: $(MLMODULES:%=%.cmo) $(CCLIB)
	$(OCAMLC) $(OCAMLFLAGS) -a -o $@ $(MLMODULES:%=%.cmo) \
	-dllib -lgmp_caml $(OCAMLLDFLAGS)

gmp.cmxa: $(MLMODULES:%=%.cmx) $(CCLIB)
	$(OCAMLOPT) $(OCAMLOPTFLAGS) -a -o $@ $(MLMODULES:%=%.cmx) \
	-cclib -lgmp_caml $(OCAMLLDFLAGS)

gmp.p.cmxa: $(MLMODULES:%=%.p.cmx) $(CCLIB)
	$(OCAMLOPT) -p $(OCAMLOPTFLAGS) -a -o $@ $(MLMODULES:%=%.p.cmx) \
	-cclib -lgmp_caml.p $(OCAMLLDFLAGS)

ifneq ($(HAS_NATIVE_PLUGINS),)
gmp.cmxs: gmp.cmxa
	$(OCAMLOPT) $(OCAMLOPTFLAGS) -linkall -shared -o $@ -I . $<
endif

# CAML libraries
dll%.p.so lib%.p.a: $(CCMODULES:%=%.p.o)
	$(OCAMLMKLIB) -oc $*.p $^ $(LDFLAGS) -custom
dll%.so lib%.a: $(CCMODULES:%=%.o)
	$(OCAMLMKLIB) -oc $* $^ $(LDFLAGS)

.PHONY: META
META:
	/bin/rm -f META
	echo "description = \"OCaml Interface to GMP and MPFR libraries\"" >META
	echo "version = \"$(PKGVERS)\"" >>META
	echo "requires = \"$(REQ_PKG)\"" >>META
	echo "archive(byte) = \"gmp.cma\"" >>META
	echo "archive(byte,plugin) = \"gmp.cma\"" >>META
	echo "archive(native) = \"gmp.cmxa\"" >>META
	echo "archive(native,plugin) = \"gmp.cmxs\"" >>META
	echo "archive(native,gprof) = \"gmp.p.cmxa\"" >>META

ifeq ($(OCAMLFIND),)
install:
	$(INSTALLd) $(MLGMPIDL_PREFIX)/include
	$(INSTALLd) $(MLGMPIDL_PREFIX)/lib
	$(INSTALL) gmp_caml.h $(MLGMPIDL_PREFIX)/include
	$(INSTALL) \
		$(IDLMODULES:%=%.idl) \
		$(MLMODULES:%=%.ml) $(MLMODULES:%=%.mli) \
		$(MLMODULES:%=%.cmi) gmp.cma \
		$(MLLIBx) $(CCLIB) \
		$(MLGMPIDL_PREFIX)/lib
uninstall:
	(cd $(MLGMPIDL_PREFIX)/include; /bin/rm -f gmp_caml.h)
	(cd $(MLGMPIDL_PREFIX)/lib; /bin/rm -f \
		$(IDLMODULES:%=%.idl) \
		$(MLMODULES:%=%.ml) $(MLMODULES:%=%.mli) \
		$(MLMODULES:%=%.cmi) gmp.cma \
		$(MLLIBx) $(CCLIB) libgmp*caml.a libgmp*caml.so)
	(cd $(MLGMPIDLPREFIX)/bin; /bin/rm -f gmprun gmptop)
else
install: $(FILES_TOINSTALL)
	$(OCAMLFIND) remove $(PKG-NAME)
	$(OCAMLFIND) install $(PKG-NAME) $^

uninstall:
	$(OCAMLFIND) remove $(PKG-NAME)
endif

clean:
	/bin/rm -fr tmp html
	/bin/rm -f gmprun gmptop
	/bin/rm -f *.aux *.bbl *.ilg *.idx *.ind *.out *.blg *.dvi *.log *.toc *.ps *.html *.pdf
	/bin/rm -f *.o *.a *.cm[ioxat] *.cmti *.cmx[as] *.annot *.so session.byte session.opt session.opt2 tmp/* html/*
	/bin/rm -f ocamldoc.[cefkimoptv]* ocamldoc.sty

distclean: clean
	/bin/rm -f Makefile.depend $(IDLMODULES:%=%.ml) $(IDLMODULES:%=%.mli) $(IDLMODULES:%=%_caml.c) META

#---------------------------------------
# TEX and HTML rules
#---------------------------------------

.PHONY: html mlgmpidl.dvi

mlgmpidl.pdf: mlgmpidl.dvi
	$(DVIPDF) mlgmpidl.dvi

mlgmpidl.dvi: introduction.mli $(MLMODULES:%=%.mli)
	$(OCAMLDOC) \
	-latextitle 1,chapter -latextitle 2,section -latextitle 3,subsection -latextitle 4,subsubsection -latextitle 5,paragraph -latextitle 6,subparagraph -noheader -notrailer -latex -o ocamldoc.tex $^
	$(LATEX) mlgmpidl
	$(MAKEINDEX) mlgmpidl
	$(LATEX) mlgmpidl
	$(LATEX) mlgmpidl

html: $(MLMODULES:%=%.mli)
	mkdir -p html
	$(OCAMLDOC) $(OCAMLINC) -html -d html -colorize-code $^

homepage: html mlgmpidl.pdf
	hyperlatex index
	scp -r index.html html mlgmpidl.pdf \
		salgado:/home/wwwpop-art/people/bjeannet/mlxxxidl-forge/mlgmpidl
	ssh salgado chmod -R ugoa+rx /home/wwwpop-art/people/bjeannet/mlxxxidl-forge/mlgmpidl

#--------------------------------------------------------------
# IMPLICIT RULES AND DEPENDENCIES
#--------------------------------------------------------------

.SUFFIXES: .tex .fig .c .h .o .ml .mli .cmi .cmo .cmx .idl _debug.o _prof.o _caml.c

#-----------------------------------
# IDL
#-----------------------------------

# sed -f sedscript_caml allows to remove prefixes generated by camlidl
# and to modify type name
# sed -f sedscript_c allows to deal with GMP peculiarity for types
# grep --extended-regexp '^(.)+$$' removes blanks lines

tmp/cpp-defs.h:
	mkdir -p tmp;
	grep '#define *MPFR_VERSION_MAJOR' $(MPFR_PREFIX)/include/mpfr.h > $@

%_caml.c %.ml %.mli: %.idl tmp/cpp-defs.h sedscript_caml sedscript_c
	@echo "module $*";
	cp -p $*.idl tmp/$*.idl;
	$(CAMLIDL) -no-include -prepro "cpp -imacros tmp/cpp-defs.h" -I $(SRCDIR) tmp/$*.idl;
	$(SED) -f sedscript_c tmp/$*_stubs.c >$*_caml.c;
	$(SED) -f sedscript_caml tmp/$*.ml >$*.ml;
	$(SED) -f sedscript_caml tmp/$*.mli >$*.mli;

#-----------------------------------
# C
#-----------------------------------

%.o: %.c gmp_caml.h
	$(OCAMLOPT) $(addprefix -ccopt ,$(CFLAGS_DEBUG) $(ICFLAGS)) -g -c -o $@ $<
%.p.o: %.c gmp_caml.h
	$(OCAMLOPT) $(addprefix -ccopt ,$(CFLAGS_PROF) $(ICFLAGS)) -ccopt -o -ccopt $@ -c $<

#-----------------------------------
# CAML
#-----------------------------------

%.cmi: %.mli
	$(OCAMLC) $(OCAMLFLAGS) -c $<

%.cmo: %.ml %.cmi
	$(OCAMLC) $(OCAMLFLAGS) -c $<

%.cmx: %.ml %.cmi
	$(OCAMLOPT) $(OCAMLOPTFLAGS) -c $<

%.p.cmx: %.ml %.cmi
	$(OCAMLOPT) -p $(OCAMLOPTFLAGS) $(OCAMLINC) -c -o $@ $<

#-----------------------------------
# Dependencies
#-----------------------------------

depend: $(IDLMODULES:%=%.ml) $(IDLMODULES:%=%.mli)
	$(OCAMLDEP) $(MLMODULES:%=%.mli) $(MLMODULES:%=%.ml) >Makefile.depend

Makefile.depend: $(IDLMODULES:%=%.ml) $(IDLMODULES:%=%.mli)
	$(OCAMLDEP) $(MLMODULES:%=%.mli) $(MLMODULES:%=%.ml) >Makefile.depend

-include Makefile.depend

#-----------------------------------
# OPAM Packaging
#-----------------------------------

# see `https://github.com/nberth/opam-dist'
ifneq ($(OPAM_DIST_DIR),)

  OPAM_DIR = opam
  OPAM_FILES = descr opam

  MLSRCS = $(filter-out $(IDLMODULES),$(MLMODULES))
  DIST_FILES = *.idl *.c *.h *.tex $(MLSRCS:%=%.ml) $(MLSRCS:%=%.mli)	\
    Changes README COPYING Makefile Makefile.config.* sedscript_*	\
    session.ml introduction.mli configure

  -include $(OPAM_DIST_DIR)/opam-dist.mk

endif

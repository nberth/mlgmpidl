include Makefile.config
PKGNAME = mlgmpidl
PKGVERS = 1.2.11

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
-ccopt -L$(CAML_PREFIX) \
-ccopt -L$(CAMLIDL_PREFIX) \
$(if $(GMP_PREFIX),-ccopt -L$(GMP_PREFIX)/lib) \
$(if $(MPFR_PREFIX),-ccopt -L$(MPFR_PREFIX)/lib) \

LIBS = -lmpfr -lgmp -lcamlidl
OCAMLLDFLAGS = $(OCAMLCCOPT) $(addprefix -cclib ,$(LIBS))

IDLMODULES = mpz mpq mpf mpfr gmp_random
MLMODULES = $(IDLMODULES) mpzf mpqf mpfrf

#---------------------------------------
# C part
#---------------------------------------

ICFLAGS = \
$(CPPFLAGS) \
$(if $(GMP_PREFIX),-I$(GMP_PREFIX)/include) \
$(if $(MPFR_PREFIX),-I$(MPFR_PREFIX)/include) \
-I$(CAML_PREFIX) -I$(CAMLIDL_PREFIX)

LDFLAGS += \
$(if $(GMP_PREFIX),-L$(GMP_PREFIX)/lib) \
$(if $(MPFR_PREFIX),-L$(MPFR_PREFIX)/lib) \
-L$(CAML_PREFIX) -L$(CAML_PREFIX)/stublibs -L$(CAMLIDL_PREFIX) \
$(LIBS)

EXT_DLL ?= .so

CCMODULES = $(IDLMODULES:%=%_caml) gmp_caml

CCLIB = libgmp_caml.a
ifneq ($(ENABLE_PROF),0)
  CCLIB += libgmp_caml.p.a
endif
ifneq ($(HAS_SHARED),)
  CCLIB += dllgmp_caml$(EXT_DLL)
endif

ifneq ($(HAS_OCAMLOPT),)
  MLLIBx = $(MLMODULES:%=%.cmx) gmp.cmxa gmp.a
  ifneq ($(ENABLE_PROF),0)
    MLLIBx += $(MLMODULES:%=%.p.cmx) gmp.p.cmxa gmp.p.a
  endif
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

all: byte opt
byte: $(MLMODULES:%=%.cmi) gmp.cma
opt: $(MLMODULES:%=%.cmx) gmp.cmxa

ifneq ($(ENABLE_PROF),0)
  all: prof
  prof: $(MLMODULES:%=%.p.cmx) gmp.p.cmxa
endif

ifneq ($(HAS_NATIVE_PLUGINS),)
  opt: gmp.cmxs
endif

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
	$(OCAMLOPT) -noautolink -I$(SITE-LIB-PKG) -o $@ bigarray.cmxa gmp.cmxa $< \
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
dll%.p$(EXT_DLL) lib%.p.a: $(CCMODULES:%=%.p.o)
	$(OCAMLMKLIB) -oc $*.p $^ $(LDFLAGS) -custom
dll%$(EXT_DLL) lib%.a: $(CCMODULES:%=%.o)
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
  ifneq ($(ENABLE_PROF),0)
	echo "archive(native,gprof) = \"gmp.p.cmxa\"" >>META
  endif

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
		$(MLLIBx) $(CCLIB) libgmp*caml.a libgmp*caml$(EXT_DLL))
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
	/bin/rm -f *.o *.a *.cm[ioxat] *.cmti *.cmx[as] *.annot lib*$(EXT_DLL) dll*$(EXT_DLL) session.byte session.opt session.opt2 tmp/* html/*
	/bin/rm -f ocamldoc.[cefkimoptv]* ocamldoc.sty
	/bin/rm -f $(IDLMODULES:%=%.ml) $(IDLMODULES:%=%.mli) $(IDLMODULES:%=%_caml.c) META

distclean: clean
	/bin/rm -f Makefile.config

PKG  = $(PKGNAME)-$(PKGVERS)
PKGFILES = $(IDLMODULES:%=%.idl) mpfrf.ml  mpqf.ml  mpzf.ml  session.ml introduction.mli  mpfrf.mli  mpqf.mli  mpzf.mli Changes configure COPYING gmp_caml.c gmp_caml.h Makefile mlgmpidl.tex README perlscript_caml.pl perlscript_c.pl META

dist: $(IDLMODULES:%=%.idl) mpfrf.ml  mpqf.ml  mpzf.ml  session.ml introduction.mli  mpfrf.mli  mpqf.mli  mpzf.mli Changes configure COPYING gmp_caml.c gmp_caml.h Makefile mlgmpidl.tex README perlscript_caml.pl perlscript_c.pl META
	mkdir -p $(PKG)
	cp  $(PKGFILES) $(PKG)
	tar zcvf $(PKG).tgz $(PKG)
	rm -rf $(PKG)

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

doc: byte html mlgmpidl.pdf

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

$(IDLMODULES:%=%.mli): %.mli: %.ml
$(IDLMODULES:%=%_caml.c): %_caml.c: %.ml
# Generate for each %.idl: %i.ml, %i.mli, %_caml.c
$(IDLMODULES:%=%.ml): %.ml: %.idl perlscript_c.pl perlscript_caml.pl
	tmpdir=$$(mktemp -d tmp.XXXXXX);				\
	trap "rm -rf $${tmpdir};" EXIT QUIT INT;			\
	{ cp $*.idl $${tmpdir}/$*.idl;					\
	  $(CAMLIDL) -no-include -prepro cpp $${tmpdir}/$*.idl;		\
	  $(PERL) perlscript_c.pl < $${tmpdir}/$*_stubs.c >$*_caml.c;	\
	  $(PERL) perlscript_caml.pl < $${tmpdir}/$*.ml >$*.ml;		\
	  $(PERL) perlscript_caml.pl < $${tmpdir}/$*.mli >$*.mli; }

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

$(MLMODULES:%=%.cmx): %.cmx: %.ml %.cmi
	$(OCAMLOPT) $(OCAMLOPTFLAGS) -c $<

$(MLMODULES:%=%.p.cmx): %.p.cmx: %.ml %.cmi
	$(OCAMLOPT) -p $(OCAMLOPTFLAGS) $(OCAMLINC) -c -o $@ $<

#-----------------------------------
# Dependencies
#-----------------------------------

#  Workaround to avoid an infinite loop when generating dependences
#  within Docker
ifneq ($(filter Makefile.depend,$(MAKECMDGOALS)),)
  Makefile.depend: $(MLMODULES:%=%.mli) $(MLMODULES:%=%.ml)
	$(OCAMLDEP) -one-line $+ |						\
	  $(SED) -e '/\.cm[ox]/ { p; s/\.cmx/.p.cmx/; }' > $@
else
  -include Makefile.depend
endif

#-----------------------------------
# OPAM Packaging
#-----------------------------------

# see `https://github.com/nberth/opam-dist'
ifneq ($(OPAM_DIST_DIR),)

  OPAM_DIR = opam
  OPAM_FILES = descr opam

  MLSRCS = $(filter-out $(IDLMODULES),$(MLMODULES))
  DIST_FILES = *.idl *.c *.h *.tex $(MLSRCS:%=%.ml) $(MLSRCS:%=%.mli)	\
    Changes README COPYING Makefile Makefile.config.* perlscript_*	\
    session.ml introduction.mli configure Makefile.depend

  -include $(OPAM_DIST_DIR)/opam-dist.mk

endif

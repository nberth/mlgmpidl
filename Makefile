include Makefile.config

#---------------------------------------
# Directories
#---------------------------------------

SRCDIR = $(shell pwd)
#
# Installation directory prefix
# MLGMPIDL_PREFIX =
#
PREFIX = $(MLGMPIDL_PREFIX)

#---------------------------------------
# CAML part
#---------------------------------------

OCAMLINC =

ifeq ($(HAS_MPFR),)
LDFLAGS = \
-L$(GMP_PREFIX)/lib -lgmp \
-L$(CAMLIDL_PREFIX)/lib/ocaml -lcamlidl
RPATH=$(GMP_PREFIX)/lib:$(CAMLIDL_PREFIX)/lib/ocaml
else
LDFLAGS = \
-L$(MPFR_PREFIX)/lib -lmpfr \
-L$(GMP_PREFIX)/lib -lgmp \
-L$(CAMLIDL_PREFIX)/lib/ocaml -lcamlidl
RPATH=$(MPFR_PREFIX)/lib:$(GMP_PREFIX)/lib:$(CAMLIDL_PREFIX)/lib/ocaml
endif

ifeq ($(HAS_SHARED),)
OCAMLLDFLAGS = $(OCAMLOPTLDFLAGS)
else
OCAMLLDFLAGS = $(OCAMLOPTLDFLAGS) -dllib -lgmp_caml
endif

#---------------------------------------
# C part
#---------------------------------------

ifeq ($(HAS_MPFR),)
ICFLAGS = \
-DHAS_MPFR=$(HAS_MPFR) \
-I$(GMP_PREFIX)/include \
-I$(CAML_PREFIX)/lib/ocaml -I$(CAMLIDL_PREFIX)/lib/ocaml
else
ICFLAGS = \
-DHAS_MPFR=$(HAS_MPFR) \
-I$(GMP_PREFIX)/include \
-I$(MPFR_PREFIX)/include \
-I$(CAML_PREFIX)/lib/ocaml -I$(CAMLIDL_PREFIX)/lib/ocaml
endif

#---------------------------------------
# Files
#---------------------------------------

ifeq ($(HAS_MPFR),)
IDLMODULES = mpz mpq mpf gmp_random
MLMODULES  = mpz mpqf mpq mpqf mpf gmp_random
else
IDLMODULES = mpz mpq mpf mpfr gmp_random
MLMODULES  = mpz mpzf mpq mpqf mpf mpfr mpfrf gmp_random
endif

MLSRC = $(MLMODULES:%=%.mli) $(MLMODULES:%=%.ml)
MLINT = $(MLMODULES:%=%.cmi)
MLOBJ = $(MLMODULES:%=%.cmo)
MLOBJx = $(MLMODULES:%=%.cmx)
MLLIB_TOINSTALL = $(IDLMODULES:%=%.idl) $(MLMODULES:%=%.mli) $(MLMODULES:%=%.cmi) gmp.cma
MLLIB_TOINSTALLx = $(MLMODULES:%=%.cmx) gmp.cmxa gmp.a

CCMODULES = gmp_caml $(IDLMODULES:%=%_caml)
CCSRC = gmp_caml.h $(CCMODULES:%=%.c)

CCBIN_TOINSTALL = gmptop
CCLIB_TOINSTALL = libgmp_caml.a libgmp_caml.so  
CCINC_TOINSTALL = gmp_caml.h

#---------------------------------------
# Rules
#---------------------------------------

all: $(MLSRC) $(MLINT) $(MLOBJ) $(MLOBJx) gmp.cma gmp.cmxa libgmp_caml.a

ifneq ($(HAS_SHARED),)
all: libgmp_caml.so
endif

mldep: $(MLSRC)
	ocamldep $(OCAMLINC) $(MLSRC)

install:
	$(INSTALLd) $(PREFIX)/include $(PREFIX)/lib $(PREFIX)/bin
	$(INSTALL) gmp_caml.h $(PREFIX)/include
	for i in $(MLLIB_TOINSTALL) $(MLLIB_TOINSTALLx) $(CCLIB_TOINSTALL); do \
		if test -f $$i; then $(INSTALL) $$i $(PREFIX)/lib; fi; \
	done
	(cd $(PREFIX)/lib; if test -f libgmp_caml.so; then ln -s -f libgmp_caml.so dllgmp_caml.so; fi)

#---------------------------------------
# Misc rules
#---------------------------------------

uninstall:
	(cd $(PREFIX)/include; /bin/rm -f gmp_caml.h)
	(cd $(PREFIX)/lib; /bin/rm -f $(MLLIB_TOINSTALL) $(MLLIB_TOINSTALLx) $(CCLIB_TOINSTALL) *gmp_caml*.a *gmp_caml*.so)
	(cd $(PREFIX)/bin; /bin/rm -f $(CCBIN_TOINSTALL))

distclean: uninstall

clean:
	/bin/rm -fr tmp html
	/bin/rm -f gmprun gmptop
	/bin/rm -f *.aux *.bbl *.ilg *.idx *.ind *.out *.blg *.dvi *.log *.toc *.ps *.html *.pdf
	/bin/rm -f *.o *.a *.cmi *.cmo *.cmx *.cmxa *.cma *.annot *.so session.byte session.opt session.opt2 tmp/* html/*
	/bin/rm -f ocamldoc.[cefkimoptv]* ocamldoc.sty

mostlyclean: clean
	/bin/rm -f $(IDLMODULES:%=%.ml) $(IDLMODULES:%=%.mli) $(IDLMODULES:%=%_caml.c)

tar: $(IDLMODULES:%=%.idl) $(MLSRC) $(CCSRC) Makefile Makefile.config.model README COPYING Changes session.ml mlgmpidl.tex sedscript_c sedscript_caml
	(cd ..; tar zcvf $(HOME)/mlgmpidl.tgz $(^:%=mlgmpidl/%))

dist: $(IDLMODULES:%=%.idl) $(MLSRC) $(CCSRC) Makefile Makefile.config.model README COPYING Changes session.ml mlgmpidl.tex mlgmpidl.pdf html sedscript_c sedscript_caml
	(cd ..; tar zcvf $(HOME)/mlgmpidl.tgz $(^:%=mlgmpidl/%))

#---------------------------------------
# Compilation Example
#---------------------------------------
# bytecode
session.byte: session.ml gmp.cma
	$(OCAMLC) -I $(PREFIX)/lib -o $@ bigarray.cma gmp.cma $<
# native code
session.opt: session.ml gmp.cmxa
	$(OCAMLOPT) -I $(PREFIX)/lib -cclib -L. -o $@ bigarray.cmxa gmp.cmxa $<
# native code with noautolink
session2.opt: session.ml
	$(OCAMLOPT) -noautolink -I $(PREFIX)/lib -o $@ bigarray.cmxa gmp.cmxa $<
	-ccopt "-L$(MLGMPIDL_PREFIX)/lib" -cclib "-lgmp_caml" \
	-ccopt "-L$(MPFR_PREFIX)/lib" -cclib "-lmpfr" \
	-ccopt "-L$(GMP_PREFIX)/lib" -cclib "-lgmp" \
	-ccopt "-L$(CAML_PREFIX)/lib/ocaml" -cclib "-lbigarray" \
	-ccopt "-L$(CAMLIDL_PREFIX)/lib/ocaml" -cclib "-lcamlidl"

#---------------------------------------
# CAML rules
#---------------------------------------

gmp.cma: $(MLOBJ) libgmp_caml.a
	$(OCAMLMKLIB) -ocamlc "$(OCAMLC)" -verbose -o gmp -oc gmp_caml $(MLOBJ) $(LDFLAGS)

gmp.cmxa: $(MLOBJx) libgmp_caml.a
	$(OCAMLMKLIB) -ocamlopt "$(OCAMLOPT)" -verbose -o gmp -oc gmp_caml $(MLOBJx) $(LDFLAGS)
	$(RANLIB) gmp.a

libgmp_caml.a: $(CCMODULES:%=%.o)
	$(AR) rc $@ $^
	$(RANLIB) $@
libgmp_caml_debug.a: $(CCMODULES:%=%_debug.o)
	$(AR) rc $@ $^
	$(RANLIB) $@

libgmp_caml.so: $(CCMODULES:%=%.o)
	$(CC) $(CFLAGS) -shared -o $@ $^ $(LDFLAGS) -Wl,-rpath,$(RPATH)
libgmp_caml_debug.so: $(CCMODULES:%=%.o)
	$(CC) $(CFLAGS_DEBUG) -shared -o $@ $^ $(LDFLAGS) -Wl,-rpath,$(RPATH)

dllgmp_caml.so: libgmp_caml.so
	ln -s $^ $@
dllgmp_caml_debug.so: libgmp_caml_debug.so
	ln -s $^ $@

#---------------------------------------
# TEX and HTML rules
#---------------------------------------

.PHONY: html mlgmpidl.dvi

mlgmpidl.pdf: mlgmpidl.dvi
	$(DVIPDF) mlgmpidl.dvi

mlgmpidl.dvi: introduction.mli $(MLMODULES:%=%.mli)
	$(OCAMLDOC) $(OCAMLINC) \
	-latextitle 1,chapter -latextitle 2,section -latextitle 3,subsection -latextitle 4,subsubsection -latextitle 5,paragraph -latextitle 6,subparagraph -noheader -notrailer -latex -o ocamldoc.tex $^
	$(LATEX) mlgmpidl
	$(MAKEINDEX) mlgmpidl
	$(LATEX) mlgmpidl
	$(LATEX) mlgmpidl

html: introduction.mli $(MLMODULES:%=%.mli)
	mkdir -p html
	$(OCAMLDOC) $(OCAMLINC) -html -d html -colorize-code $^

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

rebuild:
	mkdir -p tmp
	for i in $(IDLMODULES); do \
		echo "module $$i"; \
		cp $${i}.idl tmp/$${i}.idl; \
		$(CAMLIDL) -prepro cpp -D HAS_MPFR=$(HAS_MPFR) -no-include -I $(SRCDIR) tmp/$${i}.idl; \
		$(SED) -f sedscript_c tmp/$${i}_stubs.c >$${i}_caml.c; \
		$(SED) -f sedscript_caml tmp/$${i}.ml >$${i}.ml; \
		$(SED) -f sedscript_caml tmp/$${i}.mli >$${i}.mli; \
	done

#-----------------------------------
# C
#-----------------------------------

%.o: %.c gmp_caml.h
	$(CC) $(CFLAGS) $(ICFLAGS) -c -o $@ $<
%_debug.o: %.c gmp_caml.h
	$(CC) $(CFLAGS_DEBUG) $(ICFLAGS) -c -o $@ $<

#-----------------------------------
# CAML
#-----------------------------------

%.cmi: %.mli
	$(OCAMLC) $(OCAMLFLAGS) $(OCAMLINC) -c $<

%.cmo: %.ml %.cmi
	$(OCAMLC) $(OCAMLFLAGS) $(OCAMLINC) -c $<

%.cmx: %.ml %.cmi
	$(OCAMLOPT) $(OCAMLOPTFLAGS) $(OCAMLINC) -c $<

#-----------------------------------
# Dependencies
#-----------------------------------

gmp_random.cmo: mpz.cmi mpf.cmi gmp_random.cmi
gmp_random.cmx: mpz.cmx mpf.cmx gmp_random.cmi
mpf.cmo: mpz.cmi mpq.cmi mpf.cmi
mpf.cmx: mpz.cmx mpq.cmx mpf.cmi

ifneq ($(HAS_MPFR),)
mpfr.cmo: mpz.cmi mpq.cmi mpqf.cmi mpf.cmi mpfr.cmi
mpfr.cmx: mpz.cmx mpq.cmx mpqf.cmx mpf.cmx mpfr.cmi
mpfr.cmi: mpz.cmi mpq.cmi mpqf.cmi mpf.cmi
mpfrf.cmo: mpzf.cmi mpqf.cmi mpfr.cmi mpfrf.cmi
mpfrf.cmx: mpzf.cmx mpqf.cmx mpfr.cmx mpfrf.cmi
mpfrf.cmi: mpzf.cmi mpz.cmi mpqf.cmi mpq.cmi mpfr.cmi
endif

mpqf.cmo: mpzf.cmi mpz.cmi mpq.cmi mpqf.cmi
mpqf.cmx: mpzf.cmx mpz.cmx mpq.cmx mpqf.cmi
mpq.cmo: mpz.cmi mpq.cmi
mpq.cmx: mpz.cmx mpq.cmi
mpzf.cmo: mpz.cmi mpzf.cmi
mpzf.cmx: mpz.cmx mpzf.cmi
mpz.cmo: mpz.cmi
mpz.cmx: mpz.cmi
session.cmo: mpq.cmi
session.cmx: mpq.cmx
gmp_random.cmi: mpz.cmi mpf.cmi
mpf.cmi: mpz.cmi mpq.cmi
mpqf.cmi: mpzf.cmi mpz.cmi mpq.cmi
mpq.cmi: mpz.cmi
mpzf.cmi: mpz.cmi

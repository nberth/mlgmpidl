
include ../Makefile.config

HAS_MPFR=1

#---------------------------------------
# Directories
#---------------------------------------

SRCDIR = $(shell pwd)
#
# Installation directory prefix
# MLGMPIDL_INSTALL =
#
PREFIX = $(MLGMPIDL_PREFIX)

#---------------------------------------
# CAML part
#---------------------------------------
OCAMLC = $(CAML_PREFIX)/bin/ocamlc.opt 
OCAMLOPT = $(CAML_PREFIX)/bin/ocamlopt.opt
OCAMLDEP = $(CAML_PREFIX)/bin/ocamldep
OCAMLLEX = $(CAML_PREFIX)/bin/ocamllex.opt
OCAMLYACC = $(CAML_PREFIX)/bin/ocamlyacc
OCAMLDOC = $(CAML_PREFIX)/bin/ocamldoc.opt

OCAMLINC =
OCAMLFLAGS = -g
OCAMLOPTFLAGS = -inline 20
ifeq ($(HAS_MPFR),0)
OCAMLLDFLAGS = \
-ccopt "-L$(MLGMPIDL_PREFIX)/lib" -cclib "-lgmp_caml" \
-ccopt "-L$(GMP_PREFIX)/lib" -cclib "-lgmp" \
-ccopt "-L$(CAMLIDL_PREFIX)/lib/ocaml" -cclib "-lcamlidl"
else
OCAMLLDFLAGS = \
-ccopt "-L$(MLGMPIDL_PREFIX)/lib" -cclib "-lgmp_caml" \
-ccopt "-L$(MPFR_PREFIX)/lib" -cclib "-lmpfr" \
-ccopt "-L$(GMP_PREFIX)/lib" -cclib "-lgmp" \
-ccopt "-L$(CAMLIDL_PREFIX)/lib/ocaml" -cclib "-lcamlidl"
endif


CAMLIDL = $(CAMLIDL_PREFIX)/bin/camlidl

#---------------------------------------
# C part
#---------------------------------------

CC = gcc
ifeq ($(HAS_MPFR),0)
ICFLAGS = \
-DHAS_MPFR=$(HAS_MPFR) \
-I$(GMP_PREFIX)/include \
-I$(CAML_PREFIX)/lib/ocaml -I$(CAMLIDL_PREFIX)/lib/ocaml \
-Wall -Winline -Wimplicit-function-declaration 
else
ICFLAGS = \
-DHAS_MPFR=$(HAS_MPFR) \
-I$(GMP_PREFIX)/include \
-I$(MPFR_PREFIX)/include \
-I$(CAML_PREFIX)/lib/ocaml -I$(CAMLIDL_PREFIX)/lib/ocaml \
-Wall -Winline -Wimplicit-function-declaration 
endif

CFLAGS = $(ICFLAGS) $(OPTFLAGS) -DNDEBUG
CFLAGS_DEBUG = $(ICFLAGS) -O0 -g -UNDEBUG
CFLAGS_PROF = $(CFLAGS) -g -pg

#---------------------------------------
# TEX
#---------------------------------------

LATEX=latex
DVIPDF=dvipdf

#---------------------------------------
# Files
#---------------------------------------

ifeq ($(HAS_MPFR),0)
IDLMODULES = mpz mpq mpf gmp_random 
else
IDLMODULES = mpz mpq mpf mpfr gmp_random 
endif

MLMODULES = $(IDLMODULES) mpzf mpqf
MLSRC = $(MLMODULES:%=%.mli) $(MLMODULES:%=%.ml)
MLINT = $(MLMODULES:%=%.cmi)
MLOBJ = $(MLMODULES:%=%.cmo)
MLOBJx = $(MLMODULES:%=%.cmx)
MLLIB_TOINSTALL = $(IDLMODULES:%=%.idl) $(MLMODULES:%=%.mli) $(MLMODULES:%=%.cmi) gmp.cma 
MLLIB_TOINSTALLx = $(MLMODULES:%=%.cmx) gmp.cmxa gmp.a 

CCMODULES = gmp_caml $(IDLMODULES:%=%_caml) 
CCSRC = gmp_caml.h $(CCMODULES:%=%.c) 

CCBIN_TOINSTALL = gmptop
CCLIB_TOINSTALL = libgmp_caml.a libgmp_caml_debug.a
CCINC_TOINSTALL = gmp_caml.h

#---------------------------------------
# Rules
#---------------------------------------

all: $(MLSRC) $(MLINT) $(MLOBJ) $(MLOBJx) gmp.cma gmp.cmxa libgmp_caml.a

mldep: $(MLSRC)
	ocamldep $(OCAMLINC) $(MLSRC)

gmprun: gmp.cma libgmp_caml.a 
	$(OCAMLC) $(OCAMLFLAGS) -verbose -o $@ -make_runtime -cc "$(CC)" \
	-ccopt "-L." gmp.cma bigarray.cma
gmptop: gmp.cma libgmp_caml.a 
	ocamlmktop $(OCAMLFLAGS) -verbose -o $@ -custom -cc "$(CC)" \
	-ccopt "-L." gmp.cma bigarray.cma 

install:
	mkdir -p $(PREFIX)/include $(PREFIX)/lib $(PREFIX)/bin
	cp -f $(MLLIB_TOINSTALL) $(MLLIB_TOINSTALLx) $(PREFIX)/lib
	cp -f $(CCINC_TOINSTALL) $(PREFIX)/include
	for i in $(CCLIB_TOINSTALL); do if test -f $$i; then cp -f $$i $(PREFIX)/lib; fi; done
	for i in $(CCBIN_TOINSTALL); do if test -f $$i; then cp -f $$i $(PREFIX)/bin; fi; done

#---------------------------------------
# Misc rules
#---------------------------------------

distclean: clean
	(cd $(PREFIX)/include; /bin/rm -f $(CCINC_TOINSTALL))
	(cd $(PREFIX)/lib; /bin/rm -f $(MLLIB_TOINSTALL) $(MLLIB_TOINSTALLx) $(CCLIB_TOINSTALL))
	(cd $(PREFIX)/bin; /bin/rm -f $(CCBIN_TOINSTALL))

clean:
	/bin/rm -fr tmp html
	/bin/rm -f gmprun gmptop 
	/bin/rm -f *.aux *.bbl *.ilg *.idx *.ind *.out *.blg *.dvi *.log *.toc *.ps *.html
	/bin/rm -f *.o *.a *.cmi *.cmo *.cmx *.cmxa *.cma tmp/* html/*
	/bin/rm -f ocamldoc.[cefkimoptv]*

mostlyclean: clean
	/bin/rm -f $(IDLMODULES:%=%.ml) $(IDLMODULES:%=%.mli) $(IDLMODULES:%=%_caml.c)

tar: $(IDLMODULES:%=%.idl) $(MLSRC) $(CCSRC) Makefile README session.ml mlgmpidl.tex sedscript_c sedscript_caml
	(cd ..; tar zcvf mlgmpidl.tgz $(^:%=mlgmpidl/%))

dist: $(IDLMODULES:%=%.idl) $(MLSRC) $(CCSRC) Makefile README session.ml mlgmpidl.tex mlgmpidl.pdf html sedscript_c sedscript_caml
	(cd ..; tar zcvf mlgmpidl.tgz $(^:%=mlgmpidl/%))

#---------------------------------------
# Compilation Example
#---------------------------------------
# bytecode
dummy.cmo: dummy.ml
	$(OCAMLC) -I $(PREFIX)/lib -o dummy.cmo dummy.mllatex

dummy: dummy.cmo
	$(OCAMLC) -I $(PREFIX)/lib -use-runtime gmprun -o $@ $< gmp.cma
# native code
dummy.cmx: dummy.ml
	$(OCAMLOPT) -I $(PREFIX)/lib -o $@ dummy.ml
dummy.opt: dummy.cmx
	$(OCAMLOPT) -I $(PREFIX)/lib -o $@ dummy.ml gmp.cmxa \
	-ccopt -L. -cclib -lgmp_caml \
	-ccopt -L$(CAMLIDL_PREFIX)/lib/ocaml -cclib -lcamlidl \
	-ccopt -L$(GMP_PREFIX)/lib -cclib -lgmp -cclib -lmtr -cclib -lst -cclib -lutil -cclib -lepd

#---------------------------------------
# CAML rules
#---------------------------------------
gmp.cma: $(MLOBJ) libgmp_caml.a
	$(OCAMLC) $(OCAMLFLAGS) -a -o $@ $(MLOBJ) $(OCAMLLDFLAGS)

gmp.cmxa: $(MLOBJx) libgmp_caml.a
	$(OCAMLOPT) $(OCAMLOPTFLAGS) -a -o $@ $(MLOBJx) $(OCAMLLDFLAGS)

libgmp_caml.a: $(CCMODULES:%=%.o)
	ar rcs $@ $^
libgmp_caml_debug.a: $(CCMODULES:%=%_debug.o)
	ar rcs $@ $^

#---------------------------------------
# TEX and HTML rules
#---------------------------------------

.PHONY: html

mlgmpidl.pdf: mlgmpidl.dvi
	$(DVIPDF) mlgmpidl.dvi

mlgmpidl.dvi: $(MLINT) $(MLSRC)
	$(OCAMLDOC) $(OCAMLINC) \
	-latextitle 1,chapter -latextitle 2,section -latextitle 3,subsection -latextitle 4,subsubsection -latextitle 5,paragraph -latextitle 6,subparagraph -noheader -notrailer -latex -o ocamldoc.tex $(MLMODULES:%=%.mli)
	$(LATEX) mlgmpidl
	makeindex mlgmpidl
	$(LATEX) mlgmpidl
	$(LATEX) mlgmpidl

html: $(MLINT) $(MLSRC)
	mkdir -p html
	$(OCAMLDOC) $(OCAMLINC) -html -d html -colorize-code $(MLMODULES:%=%.mli)

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

%_caml.c %.ml %.mli: %.idl sedscript_caml sedscript_c
	mkdir -p tmp
	cp $*.idl tmp/$*.idl
	$(CAMLIDL) -no-include -I $(SRCDIR) tmp/$*.idl
	sed -f sedscript_c tmp/$*_stubs.c >$*_caml.c
	sed -f sedscript_caml tmp/$*.ml >$*.ml
	sed -f sedscript_caml tmp/$*.mli >$*.mli

#-----------------------------------
# C
#-----------------------------------

%.o: %.c gmp_caml.h 
	$(CC) $(CFLAGS) -c -o $@ $<
%_debug.o: %.c gmp_caml.h 
	$(CC) $(CFLAGS_DEBUG) -c -o $@ $<
%_prof.o: %.c gmp_caml.h 
	$(CC) $(CFLAGS_PROF) -c -o $@ $<

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

mpq.idl: mpz.idl
mpf.idl: mpz.idl mpq.idl
mpfr.idl: mpz.idl mpq.idl mpf.idl

mpq.cmi: mpz.cmi
mpf.cmi: mpz.cmi mpq.cmi
mpfr.cmi: mpz.cmi mpq.cmi mpf.cmi
gmp_random.cmi: mpz.cmi mpq.cmi mpf.cmi 
mpz.cmo: mpz.cmi
mpz.cmx: mpz.cmi
mpq.cmo: mpz.cmi mpq.cmi
mpq.cmx: mpz.cmx mpq.cmi
mpf.cmo: mpz.cmi mpq.cmi mpf.cmo
mpf.cmx: mpz.cmx mpq.cmi mpf.cmi
gmp_random.cmo: mpz.cmi mpf.cmi gmp_random.cmi
gmp_random.cmx: mpz.cmx mpf.cmx gmp_random.cmi


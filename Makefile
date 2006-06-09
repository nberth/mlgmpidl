
include ../Makefile.config

#---------------------------------------
# Directories
#---------------------------------------

SRCDIR = $(shell pwd)
#
# Installation directory prefix
# MLGMPIDL_INSTALL =
#
PREFIX = $(MLGMPIDL_PREFIX)
# C include and lib directories
INCDIR = $(PREFIX)/include
LIBDIR = $(PREFIX)/lib
BINDIR = $(PREFIX)/bin

#---------------------------------------
# CAML part
#---------------------------------------
OCAMLC = ocamlc.opt 
OCAMLOPT = ocamlopt.opt
OCAMLDEP = ocamldep
OCAMLLEX = ocamllex.opt
OCAMLYACC = ocamlyacc
OCAMLINC =
OCAMLFLAGS = -g
OCAMLOPTFLAGS = -inline 20

CAMLIDL = camlidl

#---------------------------------------
# C part
#---------------------------------------

CC = gcc
ICFLAGS = \
-I$(GMP_PREFIX)/include \
-I$(CAML_PREFIX)/lib/ocaml -I$(CAMLIDL_PREFIX)/lib/ocaml \
-Wall -Winline -Wimplicit-function-declaration 

CFLAGS = $(ICFLAGS) -O3 -DNDEBUG
CFLAGS_DEBUG = $(ICFLAGS) -O0 -g -UNDEBUG
CFLAGS_PROF = $(CFLAGS) -g -pg

#---------------------------------------
# Files
#---------------------------------------

IDLMODULES = mpz mpq gmp_random 

MLMODULES = $(IDLMODULES) mpzf mpqf
MLSRC = $(MLMODULES:%=%.mli) $(MLMODULES:%=%.ml)
MLINT = $(MLMODULES:%=%.cmi)
MLOBJ = $(MLMODULES:%=%.cmo)
MLOBJx = $(MLMODULES:%=%.cmx)
MLLIB_TOINSTALL = $(MLMODULES:%=%.mli) $(MLMODULES:%=%.cmi) gmp.cma 
MLLIB_TOINSTALLx = $(MLMODULES:%=%.cmx) gmp.cmxa gmp.a

CCMODULES = gmp_caml $(IDLMODULES:%=%_caml) 
CCSRC = $(CCMODULES:%=%.c) gmp_caml.h

CCBIN_TOINSTALL = gmptop
CCLIB_TOINSTALL = libgmp_caml.a libgmp_caml_debug.a
CCINC_TOINSTALL = gmp_caml.h

#---------------------------------------
# Rules
#---------------------------------------

all: common libgmp_caml.a libgmp_caml_debug.a
debug: common libgmp_caml_debug.a 
prof: common libgmp_caml_prof.a
common: $(MLINT) $(MLOBJ) $(MLOBJx) gmp.cma gmp.cmxa

mlsrc: $(MLSRC) 

mldep: $(MLSRC)
	ocamldep $(OCAMLINC) $(MLSRC)

doc: mlgmpidl.dvi html

gmprun: gmp.cma libgmp_caml.a 
	$(OCAMLC) $(OCAMLFLAGS) -o $@ -make_runtime -cc "$(CC)" gmp.cma \
	-ccopt -L. -cclib -lgmp_caml \
	-ccopt -L$(CAMLIDL_PREFIX)/lib/ocaml -cclib -lcamlidl \
	-ccopt -L$(GMP_PREFIX)/lib -cclib -lgmp
gmptop: gmp.cma libgmp_caml_debug.a 
	ocamlmktop $(OCAMLFLAGS) -o $@ -custom -cc "$(CC)" gmp.cma \
	-ccopt -L. -cclib -lgmp_caml_debug \
	-ccopt -L$(CAML_PREFIX)/lib/ocaml -cclib -lbigarray \
	-ccopt -L$(CAMLIDL_PREFIX)/lib/ocaml -cclib -lcamlidl \
	-ccopt -L$(GMP_PREFIX)/lib -cclib -lgmp


install:
	mkdir -p $(INCDIR) $(LIBDIR) $(BINDIR)
	cp -f $(MLLIB_TOINSTALL) $(MLLIB_TOINSTALLx) $(LIBDIR)
	cp -f $(CCINC_TOINSTALL) $(INCDIR)
	for i in $(CCLIB_TOINSTALL); do if test -f $$i; then cp -f $$i $(LIBDIR); fi; done
	for i in $(CCBIN_TOINSTALL); do if test -f $$i; then cp -f $$i $(BINDIR); fi; done

#---------------------------------------
# Misc rules
#---------------------------------------

distclean: clean
	(cd $(INCDIR); /bin/rm -f $(CCINC_TOINSTALL))
	(cd $(LIBDIR); /bin/rm -f $(LIB_TOINSTALL) $(LIB_TOINSTALLx))
	(cd $(BINDIR); /bin/rm -f $(CCBIN_TOINSTALL))


clean:
	/bin/rm -f $(IDLMODULES:%=%.ml) $(IDLMODULES:%=%.mli) $(IDLMODULES:%=%_caml.c)
	/bin/rm -fr tmp html
	/bin/rm -f gmprun gmptop 
	/bin/rm -f *.aux *.bbl *.ilg *.idx *.ind *.out *.blg *.dvi *.log *.toc *.ps *.html
	/bin/rm -f *.o *.a *.cmi *.cmo *.cmx *.cmxa *.cma tmp/* html/*
	/bin/rm -f ocamldoc.[cefkimoptv]*

tar: $(IDLMODULES:%=%.idl) $(MLSRC) $(CCSRC) Makefile README session.ml mlgmpidl.tex sedscript_c sedscript_caml
	(cd ..; tar zcvf $(HOME)/mlgmpidl.tgz $(^:%=mlgmpidl/%))

dist: $(IDLMODULES:%=%.idl) $(MLSRC) $(CCSRC) Makefile COPYING README session.ml mlgmpidl.tex mlgmpidl.dvi html sedscript_c sedscript_caml
	(cd ..; tar zcvf $(HOME)/mlgmpidl.tgz $(^:%=mlgmpidl/%))

#---------------------------------------
# Compilation Example
#---------------------------------------
# bytecode
dummy.cmo: dummy.ml
	$(OCAMLC) -I $(LIBDIR) -o dummy.cmo dummy.ml
dummy: dummy.cmo
	$(OCAMLC) -I $(LIBDIR) -use-runtime gmprun -o $@ $< gmp.cma
# native code
dummy.cmx: dummy.ml
	$(OCAMLOPT) -I $(LIBDIR) -o $@ dummy.ml
dummy.opt: dummy.cmx
	$(OCAMLOPT) -I $(LIBDIR) -o $@ dummy.ml gmp.cmxa \
	-ccopt -L. -cclib -lgmp_caml \
	-ccopt -L$(CAMLIDL_PREFIX)/lib/ocaml -cclib -lcamlidl \
	-ccopt -L$(GMP_PREFIX)/lib -cclib -lgmp -cclib -lmtr -cclib -lst -cclib -lutil -cclib -lepd

#---------------------------------------
# CAML rules
#---------------------------------------
gmp.cma: $(MLOBJ)
	$(OCAMLC) $(OCAMLFLAGS) -a -o $@ $^
gmp.cmxa: $(MLOBJx)
	$(OCAMLOPT) $(OCAMLOPTFLAGS) -a -o $@ $^
libgmp_caml.a: $(CCMODULES:%=%.o)
	ar rcs $@ $^
libgmp_caml_debug.a: $(CCMODULES:%=%_debug.o)
	ar rcs $@ $^
libgmp_caml_prof.a: $(CCMODULES:%=%_prof.o)
	ar rcs $@ $^

#---------------------------------------
# TEX and HTML rules
#---------------------------------------

.PHONY: mlgmpidl.dvi html

mlgmpidl.dvi: $(MLINT) $(MLSRC)
	ocamldoc $(OCAMLINC) \
	-latextitle 1,chapter -latextitle 2,section -latextitle 3,subsection -latextitle 4,subsubsection -latextitle 5,paragraph -latextitle 6,subparagraph -noheader -notrailer -latex -o ocamldoc.tex $(MLMODULES:%=%.mli)
	latex mlgmpidl
	makeindex mlgmpidl
	latex mlgmpidl
	latex mlgmpidl

html: $(MLINT) $(MLSRC)
	mkdir -p html
	ocamldoc $(OCAMLINC) -html -d html -colorize-code $(MLMODULES:%=%.mli)

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

mpq.cmi: mpz.cmi
gmp_random.cmi: mpz.cmi
mpz.cmo: mpz.cmi
mpz.cmx: mpz.cmi
mpq.cmo: mpz.cmi mpq.cmi
mpq.cmx: mpz.cmx mpq.cmi
gmp_random.cmo: mpz.cmi gmp_random.cmi
gmp_random.cmx: mpz.cmx gmp_random.cmi

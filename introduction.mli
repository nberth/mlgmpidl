(** *)

(**

   This package is an OCaml interface for the GMP
   interface, which is decomposed into 7 submodules, corresponding to C
   modules:

   {ul
   {- {module: Mpz}: GMP integers, with side-effect semantics (as in C library)}
   {- {module: Mpq}: GMP rationals, with side-effect semantics (as in C library)}
   {- {module: Mpf}: GMP multiprecision floating-point numbers, with side-effect semantics (as in C library)}
   {- {module: Mpzf}: GMP integers, with functional semantics}
   {- {module: Mpqf}: GMP integers, with functional semantics}
   {- {module: Gmp_random}: GMP random number functions}
   {- {module: Mpfr}: MPFR multiprecision floating-point numbers, with side-effect semantics (as in C library)}
   {- {module: Mpfrf}: MPFR multiprecision floating-point numbers, with functional semantics}
   }

   There already exists such an interface,
   {{:http://www.di.ens.fr/~monniaux/programmes.html.en}[mlgmp]},
   written by D. Monniaux. The motivation for writing a new one in
   the APRON project were

   {ol
   {- The fact that mlgmp provides by default a functional
   interface to GMP, potentially more costly in term of memory
   allocation than an imperative interface.  mlgmp provides
   only a relative small numbers of functions in an imperative
   version.}
   {- The compatibility with the CamlIDL tool.  MLGmpIDL uses
   CamlIDL, so that other OCaml/C interfaces written with CamlIDL
   may reuse the MLGmpIDL [.idl] files.}
   }

   {2 Requirements}

   {ul
   {- GMP library (tested with version 4.0 and up)}
   {- MPFR library (optional, tested with version 2.2.x)}
   {- FINDLIB/ocamlfind}
   {- OCaml 3.0 or up (tested with 3.09 and 3.10)}
   {- Camlidl (tested with 1.05)}
   }

   {2 Installation}

   {ul
   {- {bf Library}

   Set the file Makefile.config using the Makefile.config model to your own
   setting.  You might also have to modify the Makefile for executables

   If you download from the subversion repository, type 'make
   rebuild', which builds [.ml], [.mli], and [_caml.c] files from [.idl]
   files.

   type 'make', possibly 'make debug', and then 'make install'

   The OCaml part of the library is named [gmp.cma], ([.cmxa], [.a]).
   The C part of the library is named [libgmp_caml.a], [libgmp_caml.so/dllgmp_caml.so].

   'make install' installs not only [.mli], [.cmi], but also [.idl] files.

   Be aware however that importing those [.idl] files from other [.idl]
   files will probably request the application of SED editor with the
   scripts [sedscript_caml] and [sedscript_c] (look at the Makefile).
   }
   {- {b Interpreter and toplevel}

   With dynamic linking, you can use ordinary runtime ocamlrun and
   toplevel.

   You can play with [session.ml], and compile it with 'make
   session.byte', 'make session.opt'.
   }
   {- {b Documentation}

   The documentation is generated with ocamldoc.

   'make mlapronidl.dvi'

   'make html' (put the HTML files in the html subdirectoy)
   }
   {- {b Miscellaneous}
   'make clean' and 'make distclean' have the usual behaviour.

   'make mostlyclean', in addition to 'make clean', removes the [.ml],
   [.mli] and [_caml.c] files generated from .[idl] files.
   }
   }
*)

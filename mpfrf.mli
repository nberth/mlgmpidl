(** MPFR multi-precision floating-point version, functional version *)

(* This file is part of the MLGmpIDL interface, released under LGPL license.
   Please read the COPYING file packaged in the distribution  *)

(** Functions in this module has a functional semantics, unlike the
corresponding functions in {!Mpfr}. These functions do not return the rounding
information and are less efficients, due to the additional memory allocation
neded for the result. *)

type t = Mpfr.t
  (** multi-precision floating-point numbers *)

val to_mpfr : t -> Mpfr.t
val of_mpfr : Mpfr.t -> t
(** Safe conversion from and to Mpfr.t.

  There is no sharing between the argument and the result. *)

val mpfr : t -> Mpfr.t
val mpfrf : Mpfr.t -> t
(** Unsafe conversion from and to Mpfr.t.

  The argument and the result actually share the same number: be cautious ! *)

  (** Conversion from and to Mpz.t, Mpq.t and Mpfr.t
    There is no sharing between the argument and the result. *)

(*  ====================================================================== *)
(** {2 Constructors} *)
(*  ====================================================================== *)

val of_string : string -> Mpfr.round -> t
val of_float : float -> Mpfr.round -> t
val of_int : int -> Mpfr.round -> t
val of_frac : int -> int -> Mpfr.round -> t
val of_mpz : Mpz.t -> Mpfr.round -> t
val of_mpz2 : Mpz.t -> Mpz.t -> Mpfr.round -> t
val of_mpzf : Mpzf.t -> Mpfr.round -> t
val of_mpzf2 : Mpzf.t -> Mpzf.t -> Mpfr.round -> t
val of_mpq : Mpq.t -> Mpfr.round -> t
val of_mpqf : Mpqf.t -> Mpfr.round -> t

(*  ====================================================================== *)
(** {2 Conversions and Printing} *)
(*  ====================================================================== *)

val to_string : t -> string
val to_float : ?round:Mpfr.round -> t -> float
val to_mpqf : t -> Mpqf.t

val print : Format.formatter -> t -> unit

(*  ====================================================================== *)
(** {2 Arithmetic Functions} *)
(*  ====================================================================== *)

val add : t -> t -> Mpfr.round -> t
val add_int : t -> int -> Mpfr.round -> t
val sub : t -> t -> Mpfr.round -> t
val sub_int : t -> int -> Mpfr.round -> t
val mul : t -> t -> Mpfr.round -> t
val mul_ui : t -> int -> Mpfr.round -> t
val ui_div : int -> t -> Mpfr.round -> t
val div : t -> t -> Mpfr.round -> t
val div_ui : t -> int -> Mpfr.round -> t
val sqrt : t -> Mpfr.round -> t
val ui_pow : int -> t -> Mpfr.round -> t
val pow : t -> t -> Mpfr.round -> t
val pow_int : t -> int -> Mpfr.round -> t
val neg : t -> Mpfr.round -> t
val abs : t -> Mpfr.round -> t

(*  ====================================================================== *)
(** {2 Comparison Functions} *)
(*  ====================================================================== *)

val equal : t -> t -> bits:int -> bool
val cmp : t -> t -> int
val cmp_int : t -> int -> int
val sgn : t -> int

val nan_p : t -> bool
val inf_p : t -> bool
val number_p : t -> bool

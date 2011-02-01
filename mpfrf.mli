(** MPFR multi-precision floating-point version, functional version *)

(* This file is part of the MLGmpIDL interface, released under LGPL license.
   Please read the COPYING file packaged in the distribution  *)

(** Functions in this module has a functional semantics, unlike the
corresponding functions in {!Mpfr}. These functions do not return the rounding
information and are less efficients, due to the additional memory allocation
neded for the result. *)

type 'a tt = 'a Mpfr.tt
type t = Mpfr.f tt
  (** multi-precision floating-point numbers *)

val to_mpfr : t -> 'a Mpfr.tt
val of_mpfr : 'a Mpfr.tt -> t
(** Safe conversion from and to Mpfr.t.

  There is no sharing between the argument and the result. *)

val _mpfr : t -> Mpfr.t
val _mpfrf : Mpfr.t -> t
(** Unsafe conversion from and to Mpfr.t.

  The argument and the result actually share the same number: be cautious ! *)

  (** Conversion from and to Mpz.t, Mpq.t and Mpfr.t
    There is no sharing between the argument and the result. *)

(*  ====================================================================== *)
(** {2 Pretty-printing} *)
(*  ====================================================================== *)

val print : Format.formatter -> t -> unit

(*  ====================================================================== *)
(** {2 Constructors} *)
(*  ====================================================================== *)

val of_string : string -> Mpfr.round -> t
val of_float : float -> Mpfr.round -> t
val of_int : int -> Mpfr.round -> t
val of_frac : int -> int -> Mpfr.round -> t
val of_mpz : 'a Mpz.tt -> Mpfr.round -> t
val of_mpz2 : 'a Mpz.tt -> 'b Mpz.tt -> Mpfr.round -> t
val of_mpq : 'a Mpq.tt -> Mpfr.round -> t

(*  ====================================================================== *)
(** {2 Conversions} *)
(*  ====================================================================== *)

val to_string : t -> string
val to_float : ?round:Mpfr.round -> t -> float
val to_mpqf : t -> Mpqf.t

(*  ====================================================================== *)
(** {2 Arithmetic Functions} *)
(*  ====================================================================== *)

val add : 'a tt -> 'b tt -> Mpfr.round -> t
val add_int : 'a tt -> int -> Mpfr.round -> t
val sub : 'a tt -> 'b tt -> Mpfr.round -> t
val sub_int : 'a tt -> int -> Mpfr.round -> t
val mul : 'a tt -> 'b tt -> Mpfr.round -> t
val mul_ui : 'a tt -> int -> Mpfr.round -> t
val ui_div : int -> 'b tt -> Mpfr.round -> t
val div : 'a tt -> 'b tt -> Mpfr.round -> t
val div_ui : 'a tt -> int -> Mpfr.round -> t
val sqrt : 'a tt -> Mpfr.round -> t
val ui_pow : int -> 'b tt -> Mpfr.round -> t
val pow : 'a tt -> 'b tt -> Mpfr.round -> t
val pow_int : 'a tt -> int -> Mpfr.round -> t
val neg : 'a tt -> Mpfr.round -> t
val abs : 'a tt -> Mpfr.round -> t

(*  ====================================================================== *)
(** {2 Comparison Functions} *)
(*  ====================================================================== *)

val equal : 'a tt -> 'b tt -> bits:int -> bool
val cmp : 'a tt -> 'b tt -> int
val cmp_int : 'a tt -> int -> int
val sgn : 'a tt -> int

val nan_p : 'a tt -> bool
val inf_p : 'a tt -> bool
val number_p : 'a tt -> bool

(** GMP multi-precision integers, functional version *)

(* This file is part of the MLGmpIDL interface, released under LGPL license.
   Please read the COPYING file packaged in the distribution  *)

(** Functions in this module has a functional semantics, unlike the
corresponding functions in {!Mpz}.  These functions are less efficients, due to
the additional memory allocation neded for the result.

This module could be extended to offer more functions with a functional
semantics. *)

type t
  (** multi-precision integer *)

val to_mpz : t -> Mpz.t
val of_mpz : Mpz.t -> t
(** Safe conversion from and to Mpz.t.

  There is no sharing between the argument and the result. *)

val mpz : t -> Mpz.t
val mpzf : Mpz.t -> t
(** Unsafe conversion from and to Mpz.t.

  The argument and the result actually share the same number: be cautious ! *)

(*  ====================================================================== *)
(** {2 Pretty-printing} *)
(*  ====================================================================== *)

val print : Format.formatter -> t -> unit

(*  ====================================================================== *)
(** {2 Constructors} *)
(*  ====================================================================== *)

val of_string : string -> t
val of_float : float -> t
val of_int : int -> t

(*  ====================================================================== *)
(** {2 Conversions} *)
(*  ====================================================================== *)

val to_string : t -> string
val to_float : t -> float

(*  ====================================================================== *)
(** {2 Arithmetic Functions} *)
(*  ====================================================================== *)

val add : t -> t -> t
val add_int : t -> int -> t
val sub : t -> t -> t
val sub_int : t -> int -> t
val mul : t -> t -> t
val mul_int : t -> int -> t
val cdiv_q : t -> t -> t
val cdiv_r : t -> t -> t
val cdiv_qr : t -> t -> t * t
val fdiv_q : t -> t -> t
val fdiv_r : t -> t -> t
val fdiv_qr : t -> t -> t * t
val tdiv_q : t -> t -> t
val tdiv_r : t -> t -> t
val tdiv_qr : t -> t -> t * t
val divexact : t -> t -> t
val gmod : t -> t -> t
val gcd : t -> t -> t
val lcm : t -> t -> t
val neg : t -> t
val abs : t -> t

(*  ====================================================================== *)
(** {2 Comparison Functions} *)
(*  ====================================================================== *)

val cmp : t -> t -> int
val cmp_int : t -> int -> int
val sgn : t -> int

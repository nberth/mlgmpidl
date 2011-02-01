(** GMP multi-precision integers, functional version *)

(* This file is part of the MLGmpIDL interface, released under LGPL license.
   Please read the COPYING file packaged in the distribution  *)

(** Functions in this module has a functional semantics, unlike the
corresponding functions in {!Mpz}.  These functions are less efficients, due to
the additional memory allocation needed for the result.

This module could be extended to offer more functions with a functional
semantics, if asked for. *)

type 'a tt = 'a Mpz.tt
type t = Mpz.f tt
  (** multi-precision integer *)

val _mpz : t -> Mpz.t
val _mpzf : Mpz.t -> t


val to_mpz : t -> 'a Mpz.tt
val of_mpz : 'a Mpz.tt -> t
(** Safe conversion from and to Mpz.t.

  There is no sharing between the argument and the result. *)

(*  ====================================================================== *)
(** {2 Pretty-printing} *)
(*  ====================================================================== *)

val print : Format.formatter -> 'a tt -> unit

(*  ====================================================================== *)
(** {2 Constructors} *)
(*  ====================================================================== *)

val of_string : string -> t
val of_float : float -> t
val of_int : int -> t

(*  ====================================================================== *)
(** {2 Conversions} *)
(*  ====================================================================== *)

val to_string : 'a tt -> string
val to_float : 'a tt -> float

(*  ====================================================================== *)
(** {2 Arithmetic Functions} *)
(*  ====================================================================== *)

val add : 'a tt -> 'b tt -> t
val add_int : 'a tt -> int -> t
val sub : 'a tt -> 'b tt -> t
val sub_int : 'a tt -> int -> t
val mul : 'a tt -> 'b tt -> t
val mul_int : 'a tt -> int -> t
val cdiv_q : 'a tt -> 'b tt -> t
val cdiv_r : 'a tt -> 'b tt -> t
val cdiv_qr : 'a tt -> 'b tt -> t * t
val fdiv_q : 'a tt -> 'b tt -> t
val fdiv_r : 'a tt -> 'b tt -> t
val fdiv_qr : 'a tt -> 'b tt -> t * t
val tdiv_q : 'a tt -> 'b tt -> t
val tdiv_r : 'a tt -> 'b tt -> t
val tdiv_qr : 'a tt -> 'b tt -> t * t
val divexact : 'a tt -> 'b tt -> t
val gmod : 'a tt -> 'b tt -> t
val gcd : 'a tt -> 'b tt -> t
val lcm : 'a tt -> 'b tt -> t
val neg : 'a tt -> t
val abs : 'a tt -> t

(*  ====================================================================== *)
(** {2 Comparison Functions} *)
(*  ====================================================================== *)

val cmp : 'a tt -> 'b tt -> int
val cmp_int : 'a tt -> int -> int
val sgn : 'a tt -> int

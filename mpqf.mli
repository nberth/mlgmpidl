(** GMP multi-precision rationals, functional version *)

(* This file is part of the MLGmpIDL interface, released under LGPL license.
   Please read the COPYING file packaged in the distribution  *)

(** Functions in this module has a functional semantics, unlike the
corresponding functions in {!Mpq}. These functions are less efficients, due to
the additional memory allocation neded for the result. *)

type 'a tt = 'a Mpq.tt
type t = Mpq.f tt
  (** multi-precision rationals *)

val to_mpq : t -> 'a Mpq.tt
val of_mpq : 'a Mpq.tt -> t
(** Safe conversion from and to Mpq.t.

  There is no sharing between the argument and the result. *)

val _mpq : t -> Mpq.t
val _mpqf : Mpq.t -> t
(** Unsafe conversion from and to Mpq.t.

  Sharing between the argument and the result. *)

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
val of_frac : int -> int -> t
val of_mpz : 'a Mpz.tt -> t
val of_mpz2 : 'a Mpz.tt -> 'b Mpz.tt -> t

(*  ====================================================================== *)
(** {2 Conversions} *)
(*  ====================================================================== *)

val to_string : 'a tt -> string
val to_float : 'a tt -> float
val to_mpzf2 : 'a tt -> Mpzf.t * Mpzf.t

(*  ====================================================================== *)
(** {2 Arithmetic Functions} *)
(*  ====================================================================== *)

val add : 'a tt -> 'b tt -> t
val sub : 'a tt -> 'b tt -> t
val mul : 'a tt -> 'b tt -> t
val div : 'a tt -> 'b tt -> t
val neg : 'a tt -> t
val abs : 'a tt -> t
val inv : 'a tt -> t
val equal : 'a tt -> 'b tt -> bool

(*  ====================================================================== *)
(** {2 Comparison Functions} *)
(*  ====================================================================== *)

val cmp : 'a tt -> 'b tt -> int
val cmp_int : 'a tt -> int -> int
val cmp_frac : 'a tt -> int -> int -> int
val sgn : 'a tt -> int

(*  ====================================================================== *)
(** {2 Extraction Functions} *)
(*  ====================================================================== *)

val get_num : t -> Mpzf.t
val get_den : t -> Mpzf.t

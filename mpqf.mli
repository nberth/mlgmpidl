(** GMP multi-precision rationals, functional version *)

(* This file is part of the MLGmpIDL interface, released under LGPL license.
   Please read the COPYING file packaged in the distribution  *)

(** Functions in this module has a functional semantics, unlike the
corresponding functions in {!Mpq}. These functions are less efficients, due to
the additional memory allocation neded for the result. *)

type t
  (** multi-precision rationals *)

val to_mpq : t -> Mpq.t
val of_mpq : Mpq.t -> t
(** Safe conversion from and to Mpq.t.

  There is no sharing between the argument and the result. *)

val mpq : t -> Mpq.t
val mpqf : Mpq.t -> t
(** Unsafe conversion from and to Mpq.t.

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
val of_frac : int -> int -> t
val of_mpz : Mpz.t -> t
val of_mpz2 : Mpz.t -> Mpz.t -> t
val of_mpzf : Mpzf.t -> t
val of_mpzf2 : Mpzf.t -> Mpzf.t -> t

(*  ====================================================================== *)
(** {2 Conversions} *)
(*  ====================================================================== *)

val to_string : t -> string
val to_float : t -> float
val to_mpzf2 : t -> Mpzf.t * Mpzf.t

(*  ====================================================================== *)
(** {2 Arithmetic Functions} *)
(*  ====================================================================== *)

val add : t -> t -> t
val sub : t -> t -> t
val mul : t -> t -> t
val div : t -> t -> t
val neg : t -> t
val abs : t -> t
val inv : t -> t
val equal : t -> t -> bool

(*  ====================================================================== *)
(** {2 Comparison Functions} *)
(*  ====================================================================== *)

val cmp : t -> t -> int
val cmp_int : t -> int -> int
val cmp_frac : t -> int -> int -> int
val sgn : t -> int

(*  ====================================================================== *)
(** {2 Extraction Functions} *)
(*  ====================================================================== *)

val get_num : t -> Mpzf.t
val get_den : t -> Mpzf.t

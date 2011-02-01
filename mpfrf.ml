(** MPFR multi-precision floating-point version, functional version *)

(* This file is part of the MLGmpIDL interface, released under LGPL license.
   Please read the COPYING file packaged in the distribution  *)

open Mpfr

type 'a tt = 'a Mpfr.tt
type t = Mpfr.f tt

let (_mpfr : t -> Mpfr.t) = Obj.magic
let (_mpfrf : Mpfr.t -> t) = Obj.magic

let to_mpfr x =
  let res = Mpfr.init2 (Mpfr.get_prec x) in
  let r = Mpfr.set res x Mpfr.Near in
  assert(r=0);
  Obj.magic res

let of_mpfr x = to_mpfr x


(*  ====================================================================== *)
(** {2 Constructors} *)
(*  ====================================================================== *)

let of_string = Mpfr.of_string
let of_float = Mpfr.of_float
let of_int = Mpfr.of_int
let of_frac = Mpfr.of_frac
let of_mpz = Mpfr.of_mpz
let of_mpz2 = Mpfr.of_mpz2
let of_mpq = Mpfr.of_mpq

(*  ====================================================================== *)
(** {2 Conversions and Printing} *)
(*  ====================================================================== *)

let to_string = Mpfr.to_string
let to_float = Mpfr.to_float
let to_mpqf = Mpfr.to_mpq

let print = Mpfr.print

(*  ====================================================================== *)
(** {2 Arithmetic Functions} *)
(*  ====================================================================== *)

let wrap1 (f: Mpfr.t -> 'a -> 'b -> 'c) =
  begin fun t r ->
    let mpfr = Mpfr.init () in
    ignore (f mpfr t r);
    _mpfrf mpfr
  end
let wrap2 (f: Mpfr.t -> 'a -> 'b -> 'c -> 'd) =
  begin fun t1 t2 r ->
    let mpfr = Mpfr.init () in
    ignore (f mpfr t1 t2 r);
    _mpfrf mpfr
  end

let add x y z = wrap2 Mpfr.add x y z
let add_int x n r =
  let mpfr = Mpfr.init () in
  ignore (
    if n>0
    then Mpfr.add_ui mpfr x n r
    else Mpfr.sub_ui mpfr x (-n) r
  );
  _mpfrf mpfr

let sub x y z = wrap2 Mpfr.sub x y z
let sub_int x n r =
  let mpfr = Mpfr.init () in
  ignore (
    if n>0
    then Mpfr.sub_ui mpfr x n r
    else Mpfr.add_ui mpfr x (-n) r
  );
  _mpfrf mpfr
let mul x y z = wrap2 Mpfr.mul x y z
let mul_ui x y z = wrap2 Mpfr.mul_ui x y z
let ui_div x y z = wrap2 Mpfr.ui_div x y z
let div x y z = wrap2 Mpfr.div x y z
let div_ui x y z = wrap2 Mpfr.div_ui x y z
let sqrt x y = wrap1 Mpfr.sqrt x y
let ui_pow x y z = wrap2 Mpfr.ui_pow x y z
let pow x y z = wrap2 Mpfr.pow x y z
let pow_int x y z = wrap2 Mpfr.pow_si x y z
let neg x = wrap1 Mpfr.neg x
let abs x = wrap1 Mpfr.abs x

(*  ====================================================================== *)
(** {2 Comparison Functions} *)
(*  ====================================================================== *)

let equal = Mpfr.equal
let cmp = Mpfr.cmp
let cmp_int = Mpfr.cmp_si
let nan_p = Mpfr.nan_p
let inf_p = Mpfr.inf_p
let number_p = Mpfr.number_p

let sgn = Mpfr.sgn

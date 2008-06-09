(** MPFR multi-precision floating-point version, functional version *)

(* This file is part of the MLGmpIDL interface, released under LGPL license.
   Please read the COPYING file packaged in the distribution  *)

open Mpfr

type t = Mpfr.t

let to_mpfr x = 
  let res = Mpfr.init2 (Mpfr.get_prec x) in
  let r = Mpfr.set res x Mpfr.Near in
  assert(r=0);
  res

let of_mpfr = to_mpfr

let mpfr x = x
let mpfrf x = x

(*  ====================================================================== *)
(** {2 Constructors} *)
(*  ====================================================================== *)

let of_string = Mpfr.of_string
let of_float = Mpfr.of_float
let of_int = Mpfr.of_int
let of_frac = Mpfr.of_frac
let of_mpzf (z:Mpzf.t) = Mpfr.of_mpz (Mpzf.mpz z)
let of_mpzf2 (num:Mpzf.t) (den:Mpzf.t) = Mpfr.of_mpz2 (Mpzf.mpz num) (Mpzf.mpz den)
let of_mpqf (z:Mpqf.t) = Mpfr.of_mpq (Mpqf.mpq z)
let of_mpz = Mpfr.of_mpz
let of_mpz2 = Mpfr.of_mpz2 
let of_mpq = Mpfr.of_mpq

(*  ====================================================================== *)
(** {2 Conversions and Printing} *)
(*  ====================================================================== *)

let to_string = Mpfr.to_string
let to_float = Mpfr.to_float
let to_mpqf x = Mpqf.mpqf (Mpfr.to_mpq x)

let print = Mpfr.print

(*  ====================================================================== *)
(** {2 Arithmetic Functions} *)
(*  ====================================================================== *)

let wrap1 (f: Mpfr.t -> 'a -> 'b -> 'c) = 
  begin fun t r ->
    let mpfr = Mpfr.init () in
    ignore (f mpfr t r);
    mpfr
  end
let wrap2 (f: Mpfr.t -> 'a -> 'b -> 'c -> 'd) = 
  begin fun t1 t2 r ->
    let mpfr = Mpfr.init () in
    ignore (f mpfr t1 t2 r);
    mpfr
  end

let add = wrap2 Mpfr.add
let add_int x n r =
  let mpfr = Mpfr.init () in
  ignore (
    if n>0
    then Mpfr.add_ui mpfr x n r
    else Mpfr.sub_ui mpfr x (-n) r  
  );
  mpfr

let sub = wrap2 Mpfr.sub
let sub_int x n r =
  let mpfr = Mpfr.init () in
  ignore (
    if n>0
    then Mpfr.sub_ui mpfr x n r
    else Mpfr.add_ui mpfr x (-n) r  
  );
  mpfr
let mul = wrap2 Mpfr.mul
let mul_ui = wrap2 Mpfr.mul_ui
let ui_div = wrap2 Mpfr.ui_div
let div = wrap2 Mpfr.div
let div_ui = wrap2 Mpfr.div_ui
let sqrt = wrap1 Mpfr.sqrt
let ui_pow = wrap2 Mpfr.ui_pow
let pow = wrap2 Mpfr.pow
let pow_int = wrap2 Mpfr.pow_si
let neg = wrap1 Mpfr.neg
let abs = wrap1 Mpfr.abs

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

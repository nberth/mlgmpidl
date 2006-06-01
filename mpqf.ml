(** GMP multi-precision rationals, functional version *)

(* This file is part of the MLGmpIDL interface, released under LGPL license.
   Please read the COPYING file packaged in the distribution  *)

open Mpq

type t = Mpq.t

let to_mpq (x:t) : Mpq.t = (x:Mpq.t)
let of_mpq = Mpq.init_set

let of_mpz x = Mpq.init_set_z x
let of_mpz2 = Mpq.of_mpz2 

let of_string = Mpq.of_string
let of_float = Mpq.of_float
let of_int = Mpq.of_int
let of_frac = Mpq.of_frac
let of_mpzf (z:Mpzf.t) = Mpq.of_mpz (Obj.magic z)
let of_mpzf2 (num:Mpzf.t) (den:Mpzf.t) = Mpq.of_mpz2 (Obj.magic num) (Obj.magic den)

let to_string = Mpq.to_string
let to_float = Mpq.to_float

let print = Mpq.print

let wrap1 (f: Mpq.t -> 'a -> unit) = 
  begin fun t ->
    let mpq = Mpq.init () in
    f mpq t;
    mpq
  end
let wrap2 (f: Mpq.t -> 'a -> 'b -> unit) = 
  begin fun t1 t2 ->
    let mpq = Mpq.init () in
    f mpq t1 t2;
    mpq
  end

let add = wrap2 Mpq.add
let sub = wrap2 Mpq.sub
let mul = wrap2 Mpq.mul
let div = wrap2 Mpq.div

let neg = wrap1 Mpq.neg
let abs = wrap1 Mpq.abs
let inv = wrap1 Mpq.inv
let equal = Mpq.equal
let cmp = Mpq.cmp
let cmp_int q n = Mpq.cmp_si q n 1
let cmp_frac = Mpq.cmp_si
let sgn = Mpq.sgn

let get_num q = 
  let num = Mpz.init() in
  Mpq.get_num num q;
  ((Obj.magic num):Mpzf.t)

let get_den q = 
  let den = Mpz.init() in
  Mpq.get_den den q;
  ((Obj.magic den):Mpzf.t)


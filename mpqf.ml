(** GMP multi-precision rationals, functional version *)

(* This file is part of the MLGmpIDL interface, released under LGPL license.
   Please read the COPYING file packaged in the distribution  *)

open Mpq

type 'a tt = 'a Mpq.tt
type t = Mpq.f tt
  (** multi-precision rationals *)

let _mpq : t -> Mpq.t = Obj.magic
let _mpqf : Mpq.t -> t = Obj.magic

let to_mpq = Mpq.init_set
let of_mpq = Mpq.init_set

let of_mpz = Mpq.init_set_z
let of_mpz2 = Mpq.of_mpz2

let of_string x = _mpqf (Mpq.of_string x)
let of_float x = _mpqf (Mpq.of_float x)
let of_int x = _mpqf (Mpq.of_int x)
let of_frac x y = _mpqf (Mpq.of_frac x y)

let of_mpzf (z:Mpzf.t) = Mpq.init_set_z
let of_mpzf2 (num:Mpzf.t) (den:Mpzf.t) = Mpq.of_mpz2

let to_string = Mpq.to_string
let to_float = Mpq.to_float

let print = Mpq.print

let wrap1 (f: Mpq.t -> 'a -> unit) t =
  let mpq = Mpq.init () in
  f mpq t;
  _mpqf mpq

let wrap2 (f: Mpq.t -> 'a -> 'b -> unit) t1 t2 =
  let mpq = Mpq.init () in
  f mpq t1 t2;
  _mpqf mpq

let add x y = wrap2 Mpq.add x y
let sub x y = wrap2 Mpq.sub x y
let mul x y = wrap2 Mpq.mul x y
let div x y = wrap2 Mpq.div x y

let neg x = wrap1 Mpq.neg x
let abs x = wrap1 Mpq.abs x
let inv x = wrap1 Mpq.inv x
let equal = Mpq.equal
let cmp = Mpq.cmp
let cmp_int q n = Mpq.cmp_si q n 1
let cmp_frac = Mpq.cmp_si
let sgn = Mpq.sgn

let get_num q =
  let num = Mpz.init() in
  Mpq.get_num num q;
  Mpzf._mpzf num

let get_den q =
  let den = Mpz.init() in
  Mpq.get_den den q;
  Mpzf._mpzf den

let to_mpzf2 q = (get_num q, get_den q)

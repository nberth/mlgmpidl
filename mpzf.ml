(** GMP multi-precision integers, functional version *)

(* This file is part of the MLGmpIDL interface, released under LGPL license.
   Please read the COPYING file packaged in the distribution  *)

open Mpz

type 'a tt = 'a Mpz.tt
type t = Mpz.f tt
  (** multi-precision integer *)

let _mpz : t -> Mpz.t = Obj.magic
let _mpzf : Mpz.t -> t = Obj.magic

let to_mpz = Mpz.init_set
let of_mpz = Mpz.init_set

let of_string = Mpz.of_string
let of_float = Mpz.of_float
let of_int = Mpz.of_int

let to_string = Mpz.to_string
let to_float = Mpz.to_float

let print = Mpz.print

let wrap1 (f: 'a tt -> 'b -> unit) t =
  let mpz = Mpz.init () in
  f mpz t;
  _mpzf mpz
let wrap2 (f: 'a tt -> 'b -> 'c -> unit) t1 t2 =
    let mpz = Mpz.init () in
    f mpz t1 t2;
    _mpzf mpz
let wrap22 (f: 'a tt -> 'b tt -> 'c -> 'd -> unit) t1 t2 =
  let mpz1 = Mpz.init () in
  let mpz2 = Mpz.init () in
  f mpz1 mpz2 t1 t2;
  (_mpzf mpz1, _mpzf mpz2)

let add x y = wrap2 Mpz.add x y
let add_int z n =
  let mpz = Mpz.init() in
  if n>0
  then Mpz.add_ui mpz z n
  else Mpz.sub_ui mpz z (-n)
  ;
  _mpzf mpz
let sub x y = wrap2 Mpz.sub x y
let sub_int z n =
  let mpz = Mpz.init() in
  if n>0
  then Mpz.sub_ui mpz z n
  else Mpz.add_ui mpz z (-n)
  ;
  _mpzf mpz
let mul x y = wrap2 Mpz.mul x y
let mul_int x y = wrap2 Mpz.mul_si x y
let cdiv_q x y = wrap2 Mpz.cdiv_q x y
let cdiv_r x y = wrap2 Mpz.cdiv_r x y
let cdiv_qr x y = wrap22 Mpz.cdiv_qr x y
let fdiv_q x y = wrap2 Mpz.fdiv_q x y
let fdiv_r x y = wrap2 Mpz.fdiv_r x y
let fdiv_qr x y = wrap22 Mpz.fdiv_qr x y
let tdiv_q x y = wrap2 Mpz.tdiv_q x y
let tdiv_r x y = wrap2 Mpz.tdiv_r x y
let tdiv_qr x y = wrap22 Mpz.tdiv_qr x y
let divexact x y = wrap2 Mpz.divexact x y
let gmod x y = wrap2 Mpz.gmod x y
let gcd x y = wrap2 Mpz.gcd x y
let lcm x y = wrap2 Mpz.lcm x y

let neg x = wrap1 Mpz.neg x
let abs x = wrap1 Mpz.abs x
let cmp = Mpz.cmp
let cmp_int = Mpz.cmp_si
let sgn = Mpz.sgn

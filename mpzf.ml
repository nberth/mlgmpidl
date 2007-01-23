(** GMP multi-precision integers, functional version *)

(* This file is part of the MLGmpIDL interface, released under LGPL license.
   Please read the COPYING file packaged in the distribution  *)

open Mpz

type t = Mpz.t

let to_mpz : t -> Mpz.t = Mpz.init_set
let of_mpz : Mpz.t -> t = Mpz.init_set

let mpz (x:t) : Mpz.t = x
let mpzf (x:Mpz.t) : t = x


let of_string = Mpz.of_string
let of_float = Mpz.of_float
let of_int = Mpz.of_int

let to_string = Mpz.to_string
let to_float = Mpz.to_float

let print = Mpz.print

let wrap1 (f: Mpz.t -> 'a -> unit) = 
  begin fun t ->
    let mpz = Mpz.init () in
    f mpz t;
    mpz
  end
let wrap2 (f: Mpz.t -> 'a -> 'b -> unit) = 
  begin fun t1 t2 ->
    let mpz = Mpz.init () in
    f mpz t1 t2;
    mpz
  end
let wrap22 (f: Mpz.t -> Mpz.t -> 'a -> 'b -> unit) = 
  begin fun t1 t2 ->
    let mpz1 = Mpz.init () in
    let mpz2 = Mpz.init () in
    f mpz1 mpz2 t1 t2;
    (mpz1,mpz2)
  end

let add = wrap2 Mpz.add
let add_int z n =
  let mpz = Mpz.init() in
  if n>0 
  then Mpz.add_ui mpz z n 
  else Mpz.sub_ui mpz z (-n)
  ;
  mpz
let sub = wrap2 Mpz.sub
let sub_int z n =
  let mpz = Mpz.init() in
  if n>0 
  then Mpz.sub_ui mpz z n 
  else Mpz.add_ui mpz z (-n)
  ;
  mpz
let mul = wrap2 Mpz.mul
let mul_int = wrap2 Mpz.mul_si
let cdiv_q = wrap2 Mpz.cdiv_q
let cdiv_r = wrap2 Mpz.cdiv_r
let cdiv_qr = wrap22 Mpz.cdiv_qr
let fdiv_q = wrap2 Mpz.fdiv_q
let fdiv_r = wrap2 Mpz.fdiv_r
let fdiv_qr = wrap22 Mpz.fdiv_qr
let tdiv_q = wrap2 Mpz.tdiv_q
let tdiv_r = wrap2 Mpz.tdiv_r
let tdiv_qr = wrap22 Mpz.tdiv_qr
let divexact = wrap2 Mpz.divexact
let gmod = wrap2 Mpz.gmod
let gcd = wrap2 Mpz.gcd
let lcm = wrap2 Mpz.lcm

let neg = wrap1 Mpz.neg
let abs = wrap1 Mpz.abs
let cmp = Mpz.cmp
let cmp_int = Mpz.cmp_si
let sgn = Mpz.sgn

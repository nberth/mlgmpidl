(*

ocaml -I $MLGMPDIL_PREFIX

#load "bigarray.cma";;
#load "gmp.cma";;

#install_printer Mpq.print;;

*)


open Mpq;;

let a = init();;
let b = init();;
set_si a 2 3;;
set_si b 1 5;;
get_str ~base:10 a;;
get_str ~base:10 b;;

add a a b;;

let c = init();;

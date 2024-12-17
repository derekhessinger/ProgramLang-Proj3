(*
*
* Derek Hessinger and Sumira Naroola
* Prof. Ying Li
* CS 333
* 10/16/24
* 
* This file demonstrates identifier naming, varible declaration, 
* and identifier scoping in OCaml
*)

(*OCaml is a functional programming language which uses expressions
to assign identifiers*)

(*here, the identifier x is expressed as an integer 5*)
(*essentially, in OCaml expressions are used instead of variables, and
every expression returns a value. Every expression has a distinct type*)
let x = 5;;
(*x is defined with global scope here*)

(*local definitions bind an identifier, here d is only defined on line 22 *)
let d = 2 in d + 3;;

(*names can be redefined with a new binding*)
let x = x+10;;

(*sincer ocaml is a functional programming language, there are not
many rules surrounding names, there are only global and local scopes*)

(*to define a mutable variable (which isn't suggested since OCaml is a 
functional programming language) use the 'ref' keyword*)
let mut = ref 10;;






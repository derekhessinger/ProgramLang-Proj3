(*
*
* Derek Hessinger and Sumira Naroola
* Prof. Ying Li
* CS 333
* 10/16/24
* 
* This file demonstrates functions in OCaml
*)

(*In OCaml, functions are values*)
(*no parentheses are needed to call a function and pass arguments*)
(*The following function finds the max of two values*)
max (10*2) (int_of_string "123");;

(*To declare a function, the fun keyword is needed.
Funtions dont need to have an identifier unless they are recursive*)
(*this function returns the argument x squared *)
fun x->x*x;;

(*to define a global function, bind a function to a name with a global def*)
let f = fun x -> x * x;;

(*functions can also be defined locally too*)
let sq x = x * x in sq 7 * sq 7;;

(*the keyword rec is needed to define recursive functions*)
(*fibonacci number is defined below recursively*)
let rec fibo n =
  if n <= 1 then n else fibo (n - 1) + fibo (n - 2);;

(*anonymous function that doubles a number *)
let double = fun x -> x * 2


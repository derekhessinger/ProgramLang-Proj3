(*
*
* Derek Hessinger and Sumira Naroola
* Prof. Ying Li
* CS 333
* 10/16/24
* 
* This file demonstrates all of the basic built-in types 
* and how to construct aggregate types
*)

(*Ocaml lists:
* > immutable 
* > all of same type
* > singly linked list
*)
open Printf

let x = [1;2;3;4;5;6];;
(*although lists are immutable, one can add an element to a copy *)
let x_new = 7 :: x;;

let () = List.iter (printf "%d ") x_new;;

(*All lists in OCaml are either empty or an element cons onto 
* another list*)
(*To see if a list is empty: *)
let empty lst =
  match lst with
  | [] -> true
  | _ :: _ -> false;;

(*to add all of the elements in a list*)
let rec sum_lst lst = 
  match lst with 
  | [] -> 0
  | h :: t -> h + sum_lst t;;

sum_lst x;;

(*the other main data type in ocaml is a variant, which is similar
to an enum in c/java*)
type month = Jan | Feb | Mar | Apr | May | Jun | Jul | Aug | Sep | Oct |
Nov | Dec
let this_month = Oct

(*OCaml also possesses ints, floats, chars, strings, bools
*These are declared without specificying the type since OCaml is dynamically
type*)
let a = 1;;
let b = 2.0;;
let c = 'c';;
let d = "string";;
let e = true;;

(*OCaml also has options and results*)
(*Options are can store any type of data or the absensce of it*)
None;; (*None option*)
Some 50;; (*some type with value 50*)

(*Results are used to handle whether a function suceeds or fails*)
(*It can be thought of as error handling in other languages*)
Ok "hello";;
Error "goodbye";;
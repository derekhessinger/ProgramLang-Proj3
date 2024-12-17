(*
*
* Derek Hessinger and Sumira Naroola
* Prof. Ying Li
* CS 333
* 10/16/24
* 
* This file demonstrates control flows for OCaml
*)

(*For loops are defined as variable = start_value to end_value do
    code
done*)

for var = 0 to 10 do
  print_int var
done;;

(*also can be declared in descending order*)
for var =  10 to 0 do
  print_int var
done;;

(*while loops are defined as "while boolean condition do 
  expression
done"*)
let x = ref 0;; (* ref is needed to make x mutable *)
while !x < 5 do
  print_string "Hello!";
  x := !x + 1
done;;

(*if statements are expressions in OCaml*)
if 0 = 0 then print_endline("True") else print_endline("False");;

(*this statement can also be expressed as the following*)
print_endline (if 0 = 0 then "True" else "False");;


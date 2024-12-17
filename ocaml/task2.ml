(*
*
* Derek Hessinger and Sumira Naroola
* Prof. Ying Li
* CS 333
* 10/16/24
* 
* This file performs a binary search in OCaml
*)

(* Binary search implementation for sorted arrays *)

(*Define function for binary search*)
let binary_search arr target =
  (*Define helper function to recursively search array*)
  let rec search left right =
    if left > right then
      None  (*Element not found*)
    else
      let mid = (left + right) / 2 in
      let mid_val = arr.(mid) in
      if mid_val = target then
        Some mid  (*Found the element, return its index*)
      else if mid_val < target then
        search (mid + 1) right  (*Search right half*)
      else
        search left (mid - 1)  (*Search left half*)
  in
  search 0 (Array.length arr - 1)

(*Test the binary search implementation*)
let () =
  let test_array = [|1; 3; 4; 6; 8; 9; 11; 13; 14; 15|] in
  
  (*Test cases*)
  let test_cases = [1; 8; 15; 7; 0; 16] in
  
  (*iterate through the test cases*)
  List.iter (fun target ->
    match binary_search test_array target with
    | Some index -> 
        Printf.printf "Found %d at index %d\n" target index
    | None -> 
        Printf.printf "%d not found in array\n" target
  ) test_cases

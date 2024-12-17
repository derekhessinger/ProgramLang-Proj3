/*
* Derek Hessinger and Sumira Naroola
* Prof. Ying Li
* CS 333
* 10/15/24
*
* This file demonstrates a binary search in c++
*/
#include <iostream>
using namespace std;

// use recursion to perform binary search
int binary_search(int arr[], int low, int high, int val){
    // check if high index is still greater than or equal to low index
    if (high >= low){
        // find midpoint
        int mid = (low+high)/2;
        // return index if value found
        if (val == arr[mid]){
            return mid;
        }
        // recursively search right side
        else if (val > arr[mid])
        {
            return binary_search(arr, mid+1, high, val);
        }
        // recursively search left side
        else if (val < arr[mid])
        {
            return binary_search(arr, low, mid-1, val);
        }
    }
    // return -1 if value not found
    return -1;
}

int main(){
    int arr[] = {1,2,4,5,6,7,10,12,14,56};
    int guess1 = 20;
    int guess2 = 0;
    int guess3 = 14;
    int guess4 = 7;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result1 = binary_search(arr, 0, n - 1, guess1);
    if (result1 == -1) cout << "20 is not present in array\n";
    else cout << "20 is present at index " << result1 << " \n";

    int result2 = binary_search(arr, 0, n - 1, guess2);
    if (result2 == -1) cout << "0 is not present in array\n";
    else cout << "0 is present at index " << result2 << " \n";

    int result3 = binary_search(arr, 0, n - 1, guess3);
    if (result3 == -1) cout << "14 is not present in array\n";
    else cout << "14 is present at index " << result3 << " \n";

    int result4 = binary_search(arr, 0, n - 1, guess4);
    if (result4 == -1) cout << "7 is not present in array\n";
    else cout << "7 is present at index " << result4 << " \n";

}
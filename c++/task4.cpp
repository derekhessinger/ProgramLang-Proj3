/*
* Derek Hessinger and Sumira Naroola
* Prof. Ying Li
* CS 333
* 10/15/24
*
* This file demonstrates control flows for c++
*/

#include <iostream>
using namespace std;

int main(){
    // c++ has the same if/else statement structures as c
    bool b  = true;
    if (b){
        cout << "True\n";
    }
    else{
        cout << "False\n";
    }

    // as well as if/elif/else statements
    int a = 10;
    if (a==5){
        cout << "5\n";
    }
    else if (a==10){
        cout << "10\n";
    }
    else{
        cout << "none\n";
    }

    // switch statments are similar to if/else, but allow for many specific cases
    int month = 10;
    switch (month){
        case 1:
            cout << "January\n";
            break;
        case 2:
            cout << "February\n";
            break;
        case 3:
            cout << "March\n";
            break;
        case 4:
            cout << "April\n";
            break;
        case 5:
            cout << "May\n";
            break;
        case 6:
            cout << "June\n";
            break;
        case 7:
            cout << "July\n";
            break;
        case 8:
            cout << "August\n";
            break;
        case 9:
            cout << "September\n";
            break;
        case 10:
            cout << "October\n";
            break;
        case 11:
            cout << "November\n";
            break;
        case 12:
            cout << "December\n";
            break;        
    }

    // While loops work the same as in c
    int f = 0;
    while (f<10){
        cout << f << "\n";
        f++;
    }

    // For loops also work the same in c as well
    for (int i = 0; i < 5; i++) {
        cout << i << "\n";
    }
}

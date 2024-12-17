/*
* Derek Hessinger and Sumira Naroola
* Prof. Ying Li
* CS 333
* 10/16/24
*
* This file demonstrates how functions are treated in c++
*/

#include <iostream>
using namespace std;

// in c++, functions are treated the same as they are in c,
// where functions are assigned to variable types such as int
// ex:
int helloWord(){
    cout << "hello world!";
    return 0;
}
// or, to not have to return an arbitrary integer:
void helloWorld2(){
    cout << "hello world!";
}
// both are valid functions that serve the same purpose,
// but assigning a funciton to a void type if it does not need to return 
// anything makes sense

// functions can also be assigned to variables, and passed into other functions
int addTwo(int x){
    return x+2;
}

// functions can take other functions as parameters
int bar(int (*func)(int)) {
    return func(5);  // Calls the passed-in function
}

// example anonymous function
int result = [](int x) { return x * 1; }(5);

int main(){
    int (*foo)(int) = &addTwo;
    cout << foo(3) << "\n";

    // functions can be passed to other functions
    cout<< bar(foo);
}



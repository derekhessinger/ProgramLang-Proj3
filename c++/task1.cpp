/*
* Derek Hessinger and Sumira Naroola
* Prof. Ying Li
* CS 333
* 10/15/24
*
* This file demonstrates identifier naming, varible declaration, and identifier scoping
*/

#include <iostream>
using namespace std;

// the variable glob is global, and can be accessed anywhere within the file
int glob = 4;

void localVar(){
    // the variable loc is limited to this function
    // it would not be accessible in the main funcion
    int loc = 1;
}

int main(){
    // demonstrate identifier rules

    // declaring variables
    // variables must be declared in the following order:
    // type variableName = value;
    // ex:
    char ex = 'a';

    // multiple variables can be decared with commas
    // ex:
    double x, y, z;
    x =  y = z = 5.0;
    // or 
    int e = 1, f = 2, g = 3;

    // variables are case sensitive in c++:
    // here, both variables with the same name are initialized to the same value
    int a = 5;
    int b = 5;

    int* myNum = &a;
    int* mynum = &b;
    // we see that although myNum and mynum point to the same value of 5, they have different memory addresses
    // and hence are different due to the case sensitivity of identifiers in c++
    cout << "Are myNum and mynum the same? " << (myNum == mynum) << endl;
    // in c++, cout is used to display variables rather than printf in c

    bool _underscore = true;
    // c++ alows for underscores to be used wherever in identifiers
    cout << "Can identifiers in c++ have/begin with underscores? " << _underscore << endl;


    return 0;
}
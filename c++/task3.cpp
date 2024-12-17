/*
* Derek Hessinger and Sumira Naroola
* Prof. Ying Li
* CS 333
* 10/15/24
*
* This file demonstrates built-in types, aggregate types, and operators
* for c++
*/
#include <iostream>
using namespace std;

// There are 6 built-in data types for c++
// The main differenc between c and c++ data types is the addition of bool and string

int integer_num = 1;         // Integer
float float_num = 0.99;     // Floating point
double double_num = 9.98;   // Double
char letter = 'x';         // Character
bool boolean = true;       // Boolean
string txt = "Hello";     // String 

// To create a structure in c++, it follows the same logic as in c 
struct{
    int age;
    string name;
    float height;
    bool isTired;
}Student;

// c++ has the ability to make classes, while c does not
// To make a class, use the `class` keyword and enter in attributes and methods
class Car{
    public:
        string type;
        string model;
        int year;
        int governor;

        Car(string carMake, string carModel, int carYear, int carSpeed) {
            type = carMake;
            carModel = carModel;
            year = carYear;
            governor = carSpeed;
        }

        void carMaxSpeed(){
            cout << "The car can reach a max speed of: " << governor << endl;
        }
};

int main(){
    // demonstrate creating a class and using a class method
    Car ferrari("Ferrari", "812 GTS", 1990, 250);
    ferrari.carMaxSpeed();

    // demonstrate operators
    int q = 5;
    float r = 1.1;
    double s = 2.2;
    // floats ints, and doubles can be used in any operation together
    // the output of mixing these types is a float
    cout << q+r-(s*q)+(r/s) << endl;
    // modulus only works on integers
    cout<< 5%2 << endl;
    // The result is an integer

    // can increment the value of any number with ++ and subtract with --
    q++;
    r++;
    s++;

    // chars can be added to strings and vice versa
    char t = 't';
    string u = "uuuu";
    cout << t+u << endl;
    return 0;
}
//pointers are the variables that stores the memory location of another variable
//pointer variable is declared by using * sign
//Important note
//* = Dereference operator
//&  =Reference or Address Of  operator

#include "pointersAndReferences.h"
#include <iostream>

using namespace std;

void demoPointersAndReferences() {
    int x = 10;
    int* ptr;  // ptr is a pointer variable that stores the memory address of an integer variable
    ptr = &x;  // & operator gets the memory address of x

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;  // & is the address operator
    cout << "Value of ptr: " << ptr << endl;
    cout << "Value pointed by ptr: " << *ptr << endl;  // * is the Dereference operator

    *ptr = 20;  // Changing x using the pointer
    cout << "Value of x after modification: " << x << endl;

    int &z = x;  // z is a reference to x
    cout << "Value of z (reference to x): " << z << endl;
    z = 30;
    cout << "Value of x after changing z: " << x << endl;  // x is changed to 30 because z is a reference
}

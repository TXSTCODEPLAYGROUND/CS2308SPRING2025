//pointers are the variables that stores the memory location of another variable
//pointer variable is declared by using * sign
//Important note
//* = Dereference operator
//&  =Reference or Address Of  operator

#include<iostream>
using namespace std;

int main() {
    int x = 10;
    int* ptr; // ptr is a pointer variable that can store the memory address of an integer variable
    ptr = &x; // & operator is used to get the memory address of the variable x

    cout<<"Value of x: "<<x<<endl;
    cout<<"Address of x: "<<&x<<endl;//& is a reference or address operator
    cout<<"Value of ptr: "<<ptr<<endl;
    cout<<"Value pointed by ptr: "<<*ptr<<endl;//* is a Deference operator
    
    *ptr = 20; // value of x is changed using the dereferenced pointer
    cout<<"Value of x: "<<x<<endl;

    int &z = x;
    cout<<"Value of z: "<<z<<endl;
    z = 30;
    cout<<"Value of x: "<<x<<endl;//Changes the value of x because z is a reference to x and z is changed to 30, so x will be 30
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    //Pointers are simply used for storing the memory address of the variables
    int* ptr; // We can use auto for specifying the variable type
    int var = 12;
    ptr = &var;
    cout<<"The value of ptr is"<<ptr<<endl; //prints the memory address
    cout<<"The value of var is"<<*&var<<endl; // * changes the memory address(&var) into the value 
    cout<<"The value of *ptr is"<<*ptr<<endl; // same implies here
    int arr[] = {22,23,24};
    cout<<"The first element is " << *arr;
    //*arr ~ &arr[0]
    cout<<"The second element is "<< *(arr+1) << endl;
    for (auto ip=arr ; ip< arr+3 ; ip++) cout << *ip << endl;
    //Iterating the pointer values

    return 0;
}
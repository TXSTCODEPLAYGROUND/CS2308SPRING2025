#include <iostream>
using namespace std;

int main(){
    /*
        Whenever you create a variable in c++ , a memory is allocated for that variable which has its own address.
        The address is a hexademcimal number [0-9 and a to f] 
     */

    int a = 10; // a variable a is created which occupies memory which has its own address.
    
    // you can print the address of a using address of operator (&)
    cout << &a << endl;

    /*
        Now what are pointers then?
        Pointer is nothing but a variable that is used to store address of other variables.
    */

    // Now in the above example we printed the address of a in line 10. Lets create a pointer to store that address.

    int* ptr = &a;
    /*
        Here we use a astrerick (*) to  denote the data type of a pointer.
        Lets print the ptr and &a to check if ptr has the address of a.

        Note: You have to use the &a to assign adress of a to ptr , 
        if you dont then its same like assigning a number to a string variable.(wrong data type assignment)
    */ 

    cout << ptr << " == " << &a << endl;

    // We can also create a pointer to store another pointer.

    int** ptr2 = &ptr;
    cout << ptr2 << endl;
    /*
        Here is a thing to understand the above code in line 28 and 30. Whenever you create a pointer, it also allocates memory like variables. 
        And just like variables you could also assign pointer to another pointer.
        In order to do so, you do int** now, why int** and not int* ? Thats a fair question. 

        Lemme show you this way.
        int => its a variable, you create a pointer and its int*
        now , int* => to create a pointer to a pointer add a star to existing star. int**

        Lets talk about dereferemce operators. (*)
        It is used to fetch the value which is store in a memory address. Consider the following code:
    */ 

    int x = *ptr; // * fetches the value that is stored in ptr(which is a pointer and has a address stored in it.) We had assigned the value 10 to a and then ptr had the address of a. Now we can extract the value of a using *
    cout << x << endl;

    // we can also fetch the value of pointers to pointers using *
    cout << **ptr2 << endl;

    /* 
        Now lets talk about NULL pointers. Its a pointer that doesnt point to any location. 
        You cannot dereference any null pointers.
    */ 
    int* np = NULL;
    cout << np;

    

    return 0;
}
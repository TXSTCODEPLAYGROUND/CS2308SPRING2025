//global variable scope
#include <iostream>
int globalVab = 12;

int main()
{
    int globalVab = 5;
    std::cout << "The value of globalVab is " << globalVab<<"   ";
//     The output will be 5 because the globalVab is shadowed by the local variable
//     so the compiler gives priority to the local variable
    // To use the global variable we use :: infront of the variable name
    std::cout <<"The global value of globalVab is "<<::globalVab;

    return 0;
}

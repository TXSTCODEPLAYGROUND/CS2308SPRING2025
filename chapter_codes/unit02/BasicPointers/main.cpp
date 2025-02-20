#include <iostream>

int main() {
    int x = 10;  // Normal integer variable
    int* ptr = &x;  // Pointer to x (stores address of x)
    
    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Value stored in ptr: " << ptr << std::endl;
    std::cout << "Value pointed by ptr: " << *ptr << std::endl;

    // Changing value using pointer
    *ptr = 20;
    std::cout << "Updated value of x: " << x << std::endl;

    // Pointer Copy
    int* ptr2 = ptr;
    std::cout << "Value pointed by ptr2: " << *ptr2 << std::endl;

    // Reference (Alias)
    int& ref = x;
    ref = 30;
    std::cout << "Updated value of x using reference: " << x << std::endl;

    return 0;
}

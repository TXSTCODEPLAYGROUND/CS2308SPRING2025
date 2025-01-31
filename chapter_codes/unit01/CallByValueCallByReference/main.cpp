/**
 * @file    call_by_value_reference.cpp
 * @author  Keshav Bhandari
 * @course  CS2308 - Foundations of Programming
 * @date    2025-01-30
 *
 * @brief   Demonstrates the difference between Call by Value and Call by Reference in C++.
 *
 * This program shows:
 * - Call by Value: Function receives a copy of the variable.
 * - Call by Reference: Function receives a reference to the original variable.
 * - Call by Pointer: Another way to modify the original variable using pointers.
 */

#include <iostream>

/**
 * @brief Function demonstrating Call by Value.
 *
 * Modifies the parameter inside the function, but does NOT affect the original variable.
 *
 * @param x Integer passed by value.
 */
void modifyByValue(int x) {
    x = x + 10;  // Changes local copy only
    std::cout << "Inside modifyByValue: x = " << x << "\n";
}

/**
 * @brief Function demonstrating Call by Reference.
 *
 * Modifies the parameter inside the function, which directly affects the original variable.
 *
 * @param x Integer passed by reference.
 */
void modifyByReference(int &x) {
    x = x + 10;  // Changes the original variable
    std::cout << "Inside modifyByReference: x = " << x << "\n";
}

/**
 * @brief Function demonstrating Call by Pointer.
 *
 * Modifies the parameter using a pointer, which also affects the original variable.
 *
 * @param x Pointer to an integer.
 */
void modifyByPointer(int *x) {
    *x = *x + 10;  // Dereferencing pointer to modify original value
    std::cout << "Inside modifyByPointer: x = " << *x << "\n";
}

/**
 * @brief Function demonstrating how to modify arrays
 *
 * Modifies array using a pointer, which affects the original value
 *
 * @param arr pointer to the array
 */
void modifyArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] += 10; // Modifies the original array
    }
}

int main() {
    int a = 5, b = 5, c = 5;

    std::cout << "Original values: a = " << a << ", b = " << b << ", c = " << c << "\n";

    // Call by Value (Original 'a' remains unchanged)
    modifyByValue(a);
    std::cout << "After modifyByValue: a = " << a << " (Unchanged)\n\n";

    // Call by Reference (Original 'b' is modified)
    modifyByReference(b);
    std::cout << "After modifyByReference: b = " << b << " (Changed)\n\n";

    // Call by Pointer (Original 'c' is modified)
    modifyByPointer(&c);
    std::cout << "After modifyByPointer: c = " << c << " (Changed)\n\n"; //added new line here to make the output look cleaner

    int arr[3] = {a, b, c};         //Creating an array arr consisting of a,b,c
    std::cout << "Unmodified array: ";         //After modifying by reference and pointers, values of a,b,c are 5,15,15 respectively.
    for(int i = 0; i < 3; i++){
        std::cout << arr[i] << ",";
    }
    std::cout << "\b \n";                                // "\b " to remove the last comma and replace with a space, and move to a new line with "\n"
    modifyArray(arr, 3);                            //After function is called and the array is modified in the function
    std::cout << "Modified array: ";                    //it also modifies the actual array as arrays are always passed by pointers
    for(int i = 0; i < 3; i++){
        std::cout << arr[i] << ",";
    }
    std::cout << "\b ";                                 // "\b " to remove the last comma and replace with a space

    return 0;
}
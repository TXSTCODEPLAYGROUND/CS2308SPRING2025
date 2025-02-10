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
    std::cout << "After modifyByPointer: c = " << c << " (Changed)\n";

    return 0;
}
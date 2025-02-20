# Basic Pointers in C++

This repository demonstrates fundamental pointer concepts in C++.

## Concepts Covered

1. **Address Resolution & Pointer Declaration**
   - A pointer stores the memory address of a variable.
   - Example:
     ```cpp
     int x = 10;
     int* ptr = &x;  // Pointer to x
     ```

2. **Dereferencing a Pointer**
   - `*ptr` gives the value stored at the memory address.
   - Example:
     ```cpp
     std::cout << *ptr;  // Outputs the value of x
     ```

3. **Modifying Value via Pointer**
   - Changing `*ptr` affects the original variable.
   - Example:
     ```cpp
     *ptr = 20;  // Changes x to 20
     ```

4. **Pointer Copy**
   - Two pointers can point to the same variable.
   - Example:
     ```cpp
     int* ptr2 = ptr;
     ```

5. **Reference Variables**
   - References act as an alias to a variable.
   - Example:
     ```cpp
     int& ref = x;
     ref = 30;  // Changes x to 30
     ```
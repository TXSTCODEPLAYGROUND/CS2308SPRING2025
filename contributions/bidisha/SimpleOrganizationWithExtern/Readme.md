# Extern Command in C++

This project is about using the `extern` keyword in C++ to share variables and functions across multiple source files. The `extern` keyword allows for efficient modular programming by declaring variables or functions in one file and defining them in another.

## Example Usage

```cpp
// File1.cpp
#include <iostream>
int globalVar = 10;  // Definition

// File2.cpp
#include <iostream>
extern int globalVar; // Declaration
int main() {
    std::cout << globalVar; // Accessing globalVar from File1.cpp
    return 0;
}

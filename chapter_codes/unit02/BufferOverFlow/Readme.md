# Dangerous Pointer Usage in C++

## Overview
This project demonstrates the **dangers of pointers** in C++ through a simple example that highlights common pitfalls like **buffer overflows** and **memory corruption**. The code helps students understand how improper pointer usage can lead to crashes, undefined behavior, and vulnerabilities.

## Concepts Covered
- **Pointers and Memory Management**:
    - Demonstrates how pointers can access unintended memory locations.
    - Shows the impact of writing beyond the bounds of allocated memory.
- **Buffer Overflow**:
    - Explains how writing beyond allocated buffer sizes can overwrite adjacent memory.
- **Undefined Behavior**:
    - Discusses how corrupted pointers can lead to unexpected program behavior, crashes, or silent data corruption.

## Example Highlight: Buffer Overflow
This example includes a buffer overflow scenario where a dynamically allocated pointer overwrites memory it doesn’t own, simulating real-world issues like memory corruption or security vulnerabilities.

### Code Snippet
```cpp
void bufferOverflowExample() {
    char password[8];  // Buffer to store a password
    char *hack = nullptr;

    strcpy(password, "secret"); // Initialize with valid data
    cout << "Password before overflow: " << password << endl;

    hack = password; // Pointer to the same memory location

    // Writing beyond allocated memory (buffer overflow)
    strcpy(hack, "longpasswordthatbreaks");

    // Accessing corrupted memory
    cout << "Password after overflow: " << password << endl;
    cout << "Pointer hack value: " << hack << endl;
}

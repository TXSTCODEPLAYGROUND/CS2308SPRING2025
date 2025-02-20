# Call by Value vs Call by Reference in C++

This program demonstrates the differences between **Call by Value**, **Call by Reference**, and **Call by Pointer** in C++. It also explains when to use each technique and the role of the `const` keyword to ensure immutability.

>Feel Free to make any changes you see fit on readme.md file
---
## Key Concepts

### Call by Value
- **Definition**: The function receives a copy of the variable.
- **Effect**: Changes made inside the function do **not** affect the original variable.
- **Usage**: Use when you want to ensure the original variable remains unchanged.
- **Example**:
    ```cpp
    void modifyByValue(int x) {
        x = x + 10; // Changes only the local copy
    }
    ```

---

### Call by Reference
- **Definition**: The function receives a reference to the original variable.
- **Effect**: Changes made inside the function directly modify the original variable.
- **Usage**: Use when you want the function to modify the original variable.
- **Example**:
    ```cpp
    void modifyByReference(int &x) {
        x = x + 10; // Changes the original variable
    }
    ```

---

### Call by Pointer
- **Definition**: The function receives a pointer to the original variable.
- **Effect**: Changes made via dereferencing the pointer modify the original variable.
- **Usage**: Use when working with raw pointers or for dynamic memory management.
- **Example**:
    ```cpp
    void modifyByPointer(int *x) {
        *x = *x + 10; // Dereferencing modifies the original variable
    }
    ```

---

### The Role of `const`
- Use the `const` keyword to prevent unintended modifications when passing variables.
- **Call by Value**: Ensures the function doesn’t accidentally modify a local copy.
    ```cpp
    void printValue(const int x) {
        std::cout << x; // Cannot modify 'x'
    }
    ```
- **Call by Reference**: Protects the referenced variable from being changed.
    ```cpp
    void printByReference(const int &x) {
        std::cout << x; // Cannot modify 'x'
    }
    ```

---

## Comparison Table

| Technique            | Changes Original Variable? | Syntax                     | When to Use                                                                 |
|-----------------------|----------------------------|----------------------------|-----------------------------------------------------------------------------|
| **Call by Value**     | No                         | `void func(int x)`         | When you don’t want the original variable to be modified.                   |
| **Call by Reference** | Yes                        | `void func(int &x)`        | When you want to modify the original variable.                              |
| **Call by Pointer**   | Yes                        | `void func(int *x)`        | When working with raw pointers or dynamic memory allocation.                |
| **Call with `const`** | No                         | `void func(const int &x)`  | When you want to pass by reference for performance but ensure immutability. |

---

## Sample Output

```plaintext
Original values: a = 5, b = 5, c = 5

Inside modifyByValue: x = 15
After modifyByValue: a = 5 (Unchanged)

Inside modifyByReference: x = 15
After modifyByReference: b = 15 (Changed)

Inside modifyByPointer: x = 15
After modifyByPointer: c = 15 (Changed)

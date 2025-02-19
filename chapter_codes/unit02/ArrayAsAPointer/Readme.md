# Array as a Pointer in C++

This example demonstrates how arrays behave like pointers in C++, with an important caveat about swapping array pointers.

## Key Facts

1. **Array Name is a Pointer**
    - The name of an array (`arr`) is a pointer to its first element.
    - Example:
      ```cpp
      int arr[] = {1, 2, 3};
      std::cout << arr;      // Prints address of arr[0]
      std::cout << &arr[0];  // Prints same address
      ```

2. **Dereferencing the Array Name**
    - `*arr` gives the first element.
    - Example:
      ```cpp
      std::cout << *arr;  // Outputs arr[0]
      ```

3. **Pointer Arithmetic**
    - `(arr + i)` moves the pointer to the next element.
    - Example:
      ```cpp
      std::cout << *(arr + 1);  // Outputs arr[1]
      ```

4. **Passing an Array to a Function**
    - Arrays decay to pointers when passed to functions.
    - Example:
      ```cpp
      void printArray(int* arr, int size);
      printArray(arr, 5);
      ```

## 🚨 Caveat: Cannot Swap Arrays Directly!

Although an array name acts like a pointer, it **cannot be reassigned**. This means swapping two array names will not work.

### ❌ Incorrect Example (Compilation Error!)
```cpp
int arr1[] = {1, 2, 3};
int arr2[] = {4, 5, 6};

// ❌ This line causes a compilation error!
arr1 = arr2;
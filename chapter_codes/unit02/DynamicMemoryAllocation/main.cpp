#include <iostream>

// ❌ Function that returns a statically allocated array (invalid approach)
int* createArrayUsingStaticArray(int size) {
    int staticArray[size];  // 🚨 Warning: VLA (Variable-Length Array) is non-standard in C++

    // Initialize array
    for (int i = 0; i < size; i++) {
        staticArray[i] = i * 2;
    }

    return staticArray;  // 🚨 Returning a local stack array, will cause undefined behavior!
}

// ✅ Function that returns a dynamically allocated array (correct approach)
int* createArrayUsingDynamicMemoryAllocation(int size) {
    int* dynamicArray = new int[size];  // Allocates memory on the heap

    // Initialize array
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = i * 2;
    }

    return dynamicArray;  // ✅ Safe to return, memory persists until manually deleted
}

int main() {
    int size = 5;

    // ❌ Calling function that returns a static array
    int* invalidArray = createArrayUsingStaticArray(size);

    std::cout << "Invalid array output (stack memory flushed, unpredictable values): ";
    for (int i = 0; i < size; i++) {
        std::cout << invalidArray[i] << " ";  // 🚨 Undefined behavior! Stack memory is flushed!
    }
    std::cout << "\n";

    // ✅ Calling function that returns dynamically allocated memory
    int* validArray = createArrayUsingDynamicMemoryAllocation(size);

    std::cout << "Valid array output (heap memory allocated correctly): ";
    for (int i = 0; i < size; i++) {
        std::cout << validArray[i] << " ";  // ✅ Works correctly
    }
    std::cout << "\n";

    // ✅ Memory Cleanup: Free the heap memory
    delete[] validArray;  // Prevent memory leaks

    return 0;
}
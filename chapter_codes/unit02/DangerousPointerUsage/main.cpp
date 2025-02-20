#include <iostream>
#include <cstring>  // For memcpy()

// ❌ Incorrect function: Causes memory leak by reassigning pointer
void incorrectUsage() {
    int* ptr = new int[5];  // ✅ Dynamically allocated memory

    // Initialize values
    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 10;
    }

    std::cout << "First allocation, ptr points to: ";
    for (int i = 0; i < 5; i++) {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;

    // ❌ Memory leak: The old array is lost and not freed before reassigning ptr
    ptr = new int[10];  // ✅ New memory allocated, but previous memory is lost!

    // Initialize new values
    for (int i = 0; i < 10; i++) {
        ptr[i] = i * 20;
    }

    std::cout << "Second allocation, ptr now points to: ";
    for (int i = 0; i < 10; i++) {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;

    delete[] ptr;  // ✅ Only deletes last allocated memory, first allocation is leaked!
}

// ✅ Correct function: Prevents memory leak by deleting old memory before reassigning
void correctUsage() {
    int* ptr = new int[5];

    // Initialize values
    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 10;
    }

    std::cout << "First allocation, ptr points to: ";
    for (int i = 0; i < 5; i++) {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;

    // ✅ Free old memory before reassigning pointer
    delete[] ptr;
    ptr = new int[10];

    // Initialize new values
    for (int i = 0; i < 10; i++) {
        ptr[i] = i * 20;
    }

    std::cout << "Second allocation, ptr now points to: ";
    for (int i = 0; i < 10; i++) {
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;

    delete[] ptr;  // ✅ Free memory properly
}

// ❌ Function demonstrating incorrect deletion of copied pointers
void incorrectPointerCopy() {
    int* arr1 = new int[5];  // ✅ Dynamically allocated memory

    // Initialize values
    for (int i = 0; i < 5; i++) {
        arr1[i] = i + 1;
    }

    // ❌ Incorrect Copy: Both pointers now point to the same memory!
    int* arr2 = arr1;  // 🚨 arr2 is just another pointer to arr1’s memory!

    std::cout << "arr1: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << "\narr2 (same memory as arr1): ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    // ❌ Double delete issue!
    delete[] arr1;
    // delete[] arr2;  // 🚨 This will cause undefined behavior (double free)! if you uncomment
}

// ✅ Correct way to copy an array using dynamic allocation
void correctPointerCopy() {
    int* arr1 = new int[5];

    // Initialize values
    for (int i = 0; i < 5; i++) {
        arr1[i] = i + 1;
    }

    // ✅ Correct Copy: Allocate separate memory and copy values
    int* arr2 = new int[5];
    memcpy(arr2, arr1, 5 * sizeof(int));  // ✅ Copies data safely

    std::cout << "arr1: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << "\narr2 (separate memory copy): ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    // ✅ Properly delete both arrays separately
    delete[] arr1;
    delete[] arr2;
}

int main() {
    std::cout << "Demonstrating incorrect usage (memory leak):\n";
    incorrectUsage();

    std::cout << "\nDemonstrating correct usage (no memory leak):\n";
    correctUsage();

    std::cout << "\nDemonstrating incorrect pointer copying (double delete error):\n";
    incorrectPointerCopy();

    std::cout << "\nDemonstrating correct pointer copying (safe allocation & deletion):\n";
    correctPointerCopy();

    return 0;
}
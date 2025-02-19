#include <iostream>

void printArrayUsingPointer(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << *(arr + i) << ", ";
    }
    std::cout << "\b\b ]" << std::endl;
}

int main() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {4, 5, 6};

    int* p1 = arr1;
    int* p2 = arr2;

    std::cout << "Before swapping pointers:\n";
    std::cout << "arr1 = [ ";
    printArrayUsingPointer(arr1, 3);

    std::cout << "  p1 = [ ";
    printArrayUsingPointer(p1, 3);

    std::cout << "arr2 = [ ";
    printArrayUsingPointer(arr2, 3);

    std::cout << "  p2 = [ ";
    printArrayUsingPointer(p2, 3);

    std::cout << "p1 points to: " << *p1 << " (should be arr1[0])\n";
    std::cout << "p2 points to: " << *p2 << " (should be arr2[0])\n";

    // ❌ Compilation Error: Array names cannot be reassigned
    // arr1 = arr2; // Uncommenting this line will cause a compilation error!

    // ✅ Correct way: Swapping pointers instead
    int* temp = p1;
    p1 = p2;
    p2 = temp;

    std::cout << "\nAfter swapping pointers:\n";

    std::cout << "arr1 = [ ";
    printArrayUsingPointer(arr1, 3);

    std::cout << "  p1 = [ ";
    printArrayUsingPointer(p1, 3);

    std::cout << "arr2 = [ ";
    printArrayUsingPointer(arr2, 3);

    std::cout << "  p2 = [ ";
    printArrayUsingPointer(p2, 3);

    std::cout << "p1 points to: " << *p1 << " (should be arr2[0])\n";
    std::cout << "p2 points to: " << *p2 << " (should be arr1[0])\n";

    return 0;
}
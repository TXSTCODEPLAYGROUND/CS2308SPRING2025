#include <iostream>
#include "functions/functions.h"

int main()
{
    // Bubble Sort
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    bubbleSort(arr1, n1);
    std::cout << "Bubble Sort: ";
    for (int i = 0; i < n1; i++)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;

    // Selection Sort
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    selectionSort(arr2, n2);
    std::cout << "Selection Sort: ";
    for (int i = 0; i < n2; i++)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;

    // Insertion Sort
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    insertionSort(arr3, n3);
    std::cout << "Insertion Sort: ";
    for (int i = 0; i < n3; i++)
        std::cout << arr3[i] << " ";
    std::cout << std::endl;

    // Merge Sort
    int arr4[] = {64, 34, 25, 12, 22, 11, 90};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    mergeSort(arr4, 0, n4 - 1);
    std::cout << "Merge Sort: ";
    for (int i = 0; i < n4; i++)
        std::cout << arr4[i] << " ";
    std::cout << std::endl;

    // Quick Sort
    int arr5[] = {64, 34, 25, 12, 22, 11, 90};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    quickSort(arr5, 0, n5 - 1);
    std::cout << "Quick Sort: ";
    for (int i = 0; i < n5; i++)
        std::cout << arr5[i] << " ";
    std::cout << std::endl;

    return 0;
}
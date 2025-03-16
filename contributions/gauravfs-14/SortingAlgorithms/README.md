# Sorting Algorithms

This project contains implementations of common sorting algorithms in C++. These implementations are part of the CS2308 (Data Structures) course at Texas State University.

## Table of Contents

- [Overview](#overview)
- [Algorithms Included](#algorithms-included)
- [Complexity Comparison](#complexity-comparison)
- [Usage](#usage)

## Overview

Sorting is a fundamental operation in computer science that arranges elements in a specific order (typically ascending or descending). This project demonstrates various sorting techniques with their implementations and analysis.

## Algorithms Included

### Bubble Sort

A simple comparison-based sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

### Selection Sort

An in-place comparison sorting algorithm that divides the input list into two parts: a sorted sublist and an unsorted sublist. It repeatedly finds the minimum element from the unsorted sublist and moves it to the end of the sorted sublist.

### Insertion Sort

Builds the final sorted array one item at a time. It is efficient for small data sets and is often used as part of more sophisticated algorithms.

### Merge Sort

A divide-and-conquer algorithm that divides the input array into two halves, recursively sorts them, and then merges the sorted halves.

### Quick Sort

Another divide-and-conquer algorithm that selects a 'pivot' element and partitions the array around it, recursively sorting the sub-arrays.

## Complexity Comparison

| Algorithm      | Time Complexity (Best) | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
| -------------- | ---------------------- | ------------------------- | ----------------------- | ---------------- |
| Bubble Sort    | O(n)                   | O(n²)                     | O(n²)                   | O(1)             |
| Selection Sort | O(n²)                  | O(n²)                     | O(n²)                   | O(1)             |
| Insertion Sort | O(n)                   | O(n²)                     | O(n²)                   | O(1)             |
| Merge Sort     | O(n log n)             | O(n log n)                | O(n log n)              | O(n)             |
| Quick Sort     | O(n log n)             | O(n log n)                | O(n²)                   | O(log n)         |

## Usage

Each sorting algorithm is implemented in its own C++ file. To use a specific algorithm, include the corresponding header in your program:

```cpp
#include "bubble_sort.h"
#include "selection_sort.h"
// ... other includes as needed

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    // To use bubble sort
    bubbleSort(arr, n);

    // To use selection sort
    // selectionSort(arr, n);

    return 0;
}
```

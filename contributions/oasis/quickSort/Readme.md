# Quick Sort Implementation

## Overview
This project implements the **Quick Sort** algorithm in C++ to sort a vector of integers. Quick Sort is an efficient divide-and-conquer sorting algorithm that selects a pivot element, partitions the array, and recursively sorts the subarrays. The sorting is performed in-place, making it memory-efficient.

## Files
- **`quick_sort.h`** - Header file containing the function prototypes and documentation.
- **`main.cpp`** - program to demonstrate the Quick Sort function.

## Usage
1. Include the `quick_sort.h` header file in your program.
2. Call the `quicksort` function by passing a vector of integers, along with `low` and `high` indices.
3. The function will sort the vector in ascending order and print the sorted array.

## Example
```cpp
#include <iostream>
#include <vector>
#include "quick_sort.h"

int main() {
    std::vector<int> arr = {4, 3, 1, 7, 2, 5, 9};
    int low = 0;
    int high = arr.size() - 1;

    quicksort(arr, low, high);
    
    for (int num : arr) {
        std::cout << num << " ";
    }
    return 0;
}
```

## Output
```
1 2 3 4 5 7 9
```

## Complexity Analysis
- **Best Case:** O(n log n) (Balanced partitioning)
- **Average Case:** O(n log n)
- **Worst Case:** O(n²) (Unbalanced partitioning, e.g., sorted or reverse-sorted array)

## Author
- Oasis Pandey
- Date: March 13, 2025


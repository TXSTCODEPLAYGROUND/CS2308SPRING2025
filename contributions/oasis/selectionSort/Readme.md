# Selection Sort Implementation

## Overview
This project implements the **Selection Sort** algorithm in C++ to sort a vector of integers. The Selection Sort algorithm works by repeatedly selecting the minimum element from the unsorted portion of the array and swapping it with the first element of the unsorted section. The sorting is performed in-place without using additional memory.

## Files
- **`selection_sort.h`** - Header file containing the function prototype and documentation.
- **`selection_sort.cpp`** - Implementation file defining the `selectionSort` function.
- **`main.cpp`** - Driver program to demonstrate the Selection Sort function.

## Usage
1. Include the `selection_sort.h` header file in your program.
2. Call the `selectionSort` function by passing a vector of integers.
3. The function will sort the vector in ascending order and print the sorted array.

## Example
```cpp
#include <iostream>
#include <vector>
#include "selection_sort.h"

int main() {
    std::vector<int> arr = {3, 2, 7, 4, 10, 1};
    selectionSort(arr);
    return 0;
}
```

## Output
```
1 2 3 4 7 10 
```

## Complexity Analysis
- **Best Case:** O(n²) (Already sorted array)
- **Average Case:** O(n²)
- **Worst Case:** O(n²) (Reverse sorted array)

## Author
- Oasis Pandey
- Date: March 13, 2025
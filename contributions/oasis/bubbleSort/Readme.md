# Bubble Sort Implementation

## Overview

This project implements the **Bubble Sort** algorithm in C++ to sort a vector of integers. The Bubble Sort algorithm works by repeatedly swapping adjacent elements if they are in the wrong order until the array is fully sorted. The sorting is performed in-place without using additional memory.

## Files

- **`bubble_sort.h`** - Header file containing the function prototype and documentation.
- **`main.cpp`** - program to demonstrate the Bubble Sort function.

## Usage

1. Include the `bubble_sort.h` header file in your program.
2. Call the `bubbleSort` function by passing a vector of integers.
3. The function will sort the vector in ascending order and print the sorted array.

## Example

```cpp
#include <iostream>
#include <vector>
#include "bubble_sort.h"

int main() {
    std::vector<int> arr = {3, 2, 7, 4, 10, 1};
    bubbleSort(arr);
    return 0;
}
```

## Output

```
1 2 3 4 7 10
```

## Complexity Analysis

- **Best Case:** O(n) (Already sorted array)
- **Average Case:** O(n²)
- **Worst Case:** O(n²) (Reverse sorted array)

## Author

- Oasis Pandey
- Date: March 13, 2025


# Binary Search Implementation

## Overview
This project implements the **Binary Search** algorithm in C++ to search for a target value in a sorted vector of integers. Binary Search is an efficient search algorithm that works by repeatedly dividing the search range in half until the target is found or the range becomes empty.

## Files
- **`binary_search.h`** - Header file containing the function prototype and documentation.
- **`binary_search.cpp`** - Implementation file defining the `binarySearch` function.
- **`main.cpp`** - Driver program to demonstrate the Binary Search function.

## Usage
1. Include the `binary_search.h` header file in your program.
2. Call the `binarySearch` function by passing a sorted vector of integers, along with `low`, `high`, and `target` values.
3. The function will return the index of the target value if found; otherwise, it will return -1.

## Example
```cpp
#include <iostream>
#include <vector>
#include "binary_search.h"

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target;
    std::cin >> target;
    
    int index = binarySearch(arr, 0, arr.size() - 1, target);
    std::cout << index;
    
    return 0;
}
```

## Output Example
If the user inputs `7`:
```
6
```
If the user inputs `11`:
```
-1
```

## Complexity Analysis
- **Best Case:** O(1) (Target found at the middle index)
- **Average Case:** O(log n)
- **Worst Case:** O(log n) (Target not in array or at extreme ends)

## Author
- Oasis Pandey
- Date: March 13, 2025


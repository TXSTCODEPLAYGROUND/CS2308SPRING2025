/**
 * @file binary_search.h
 * @brief Function prototype for Binary Search algorithm.
 *
 * This header defines a function to:
 * - Search for a target value in a sorted array using the Binary Search algorithm.
 * - Recursively divide the search range until the target is found or the range is empty.
 * - Return the index of the target value if found, or -1 if not found.
 *
 * Detailed function description and parameters are provided below.
 *
 * @author
 * Oasis Pandey
 *
 * @date
 * March 13, 2025
 */

 #ifndef BINARY_SEARCH_H
 #define BINARY_SEARCH_H
 
 #include <vector>
 
 /**
  * @brief Performs a recursive Binary Search on a sorted vector.
  *
  * This function searches for a target value within a sorted vector by repeatedly dividing
  * the search interval in half. If the target is found, the function returns its index;
  * otherwise, it returns -1.
  *
  * @param arr Reference to a sorted vector of integers.
  * @param low Starting index of the search range.
  * @param high Ending index of the search range.
  * @param target The value to search for.
  * @return The index of the target if found, otherwise -1.
  */
 int binarySearch(std::vector<int>& arr, int low, int high, int target);
 
 #endif // BINARY_SEARCH_H
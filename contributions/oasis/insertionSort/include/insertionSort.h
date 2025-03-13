/**
 * @file insertion_sort.h
 * @brief Function prototype for Insertion Sort algorithm.
 *
 * This header defines a function to:
 * - Sort an array using the Insertion Sort algorithm.
 * - Iteratively insert elements into their correct position.
 * - Perform in-place sorting without using additional space.
 *
 * Detailed function description and parameters are provided below.
 *
 * @author
 * Oasis Pandey
 *
 * @date
 * March 13, 2025
 */

 #ifndef INSERTION_SORT_H
 #define INSERTION_SORT_H
 
 #include <vector>
 
 /**
  * @brief Sorts a vector using the Insertion Sort algorithm.
  *
  * This function sorts the input vector in ascending order using the Insertion Sort algorithm.
  * It iterates through the array, inserting each element into its correct position relative to the sorted portion.
  *
  * @param arr Reference to a vector of integers to be sorted.
  */
 void insertionSort(std::vector<int>& arr);
 
 #endif // INSERTION_SORT_H
 
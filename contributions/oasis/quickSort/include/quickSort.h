/**
 * @file quick_sort.h
 * @brief Function prototypes for Quick Sort algorithm.
 *
 * This header defines functions to:
 * - Partition an array using the Quick Sort algorithm.
 * - Recursively sort the left and right subarrays.
 * - Perform in-place sorting with an efficient divide-and-conquer approach.
 *
 * Detailed function descriptions and parameters are provided below.
 *
 * @author
 * Oasis Pandey
 *
 * @date
 * March 13, 2025
 */

 #ifndef QUICK_SORT_H
 #define QUICK_SORT_H
 
 #include <vector>
 
 /**
  * @brief Partitions the array around a pivot element.
  *
  * This function selects a pivot element and arranges elements so that elements
  * smaller than the pivot are placed on the left and elements greater than the pivot
  * are placed on the right.
  *
  * @param arr Reference to a vector of integers to be partitioned.
  * @param low Starting index of the partition.
  * @param high Ending index of the partition.
  * @return The index where the partitioning ends.
  */
 int partition(std::vector<int>& arr, int low, int high);
 
 /**
  * @brief Sorts a vector using the Quick Sort algorithm.
  *
  * This function sorts the input vector in ascending order using the Quick Sort algorithm.
  * It recursively partitions the array and sorts each partition independently.
  *
  * @param arr Reference to a vector of integers to be sorted.
  * @param low Starting index of the array.
  * @param high Ending index of the array.
  */
 void quicksort(std::vector<int>& arr, int low, int high);
 
 #endif // QUICK_SORT_H
/**
* @file selection_sort.h
 * @brief Function prototype for Selection Sort algorithm.
 *
 * This header defines a function to:
 * - Sort an array using the Selection Sort algorithm.
 * - Identify the minimum element in the unsorted part and swap it with the first element.
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

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <vector>

/**
 * @brief Sorts a vector using the Selection Sort algorithm.
 *
 * This function sorts the input vector in ascending order using the Selection Sort algorithm.
 * It repeatedly finds the minimum element from the unsorted part and swaps it with the first
 * element of the unsorted section.
 *
 * @param arr Reference to a vector of integers to be sorted.
 */
void selectionSort(std::vector<int>& arr);

#endif // SELECTION_SORT_H

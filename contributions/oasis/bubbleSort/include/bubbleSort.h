/**
* @file bubble_sort.h
 * @brief Function prototype for Bubble Sort algorithm.
 *
 * This header defines a function to:
 * - Sort an array using the Bubble Sort algorithm.
 * - Repeatedly swap adjacent elements if they are in the wrong order.
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

#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <vector>

/**
 * @brief Sorts a vector using the Bubble Sort algorithm.
 *
 * This function sorts the input vector in ascending order using the Bubble Sort algorithm.
 * It repeatedly swaps adjacent elements if they are in the wrong order until the entire
 * array is sorted.
 *
 * @param arr Reference to a vector of integers to be sorted.
 */
void bubbleSort(std::vector<int>& arr);

#endif // BUBBLE_SORT_H
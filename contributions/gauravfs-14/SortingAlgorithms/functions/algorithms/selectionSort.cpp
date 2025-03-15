#include "../functions.h"

/**
 * @brief Sorts an array using the selection sort algorithm.
 *
 * Selection sort is an in-place comparison-based sorting algorithm that divides the input list into two parts:
 * the sublist of items already sorted and the sublist of items remaining to be sorted.
 * It repeatedly selects the minimum element from the unsorted sublist and swaps it with the leftmost unsorted element.
 *
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}
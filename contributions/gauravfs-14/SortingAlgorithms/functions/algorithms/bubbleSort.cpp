#include "../functions.h"

/**
 * @brief Sorts an array using the bubble sort algorithm.
 *
 * Bubble sort is a simple comparison-based sorting algorithm that repeatedly steps through the list to be sorted,
 * compares each pair of adjacent items, and swaps them if they are in the wrong order.
 * The pass through the list is repeated until no swaps are needed, which indicates that the list is sorted.
 *
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
#include "../functions.h"

/**
 * @brief Sorts an array using the insertion sort algorithm.
 *
 * Insertion sort is a simple comparison-based sorting algorithm that builds the final sorted array one item at a time.
 * It takes each element from the input array and inserts it into its correct position in the sorted array.
 *
 * @param arr The array to be sorted.
 * @param n The number of elements in the array.
 */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
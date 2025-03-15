#include "../functions.h"
#include <algorithm>

/**
 * @brief Partitions an array.
 *
 * This function partitions an array by selecting the last element as the pivot and placing it in its correct position in the sorted array.
 * All elements smaller than the pivot are moved to the left of the pivot, and all elements greater than the pivot are moved to the right.
 *
 * @param arr The array to be partitioned.
 * @param low The index of the first element of the array.
 * @param high The index of the last element of the array.
 * @return The index of the pivot element.
 */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

/**
 * @brief Sorts an array using the quick sort algorithm.
 *
 * This function sorts an array of integers using the quick sort algorithm.
 * The quick sort algorithm is a comparison-based sorting algorithm that uses a divide-and-conquer strategy to sort an array.
 *
 * @param arr The array to be sorted.
 * @param low The index of the first element of the array.
 * @param high The index of the last element of the array.
 */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

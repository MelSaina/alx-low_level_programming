#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary_recursive - Recursively search for a value in a sorted array
 * @array: Pointer to the first element of the sorted array
 * @left: Index of the left boundary of the subarray
 * @right: Index of the right boundary of the subarray
 * @value: Value to search for
 *
 * Return: The index where the value is located; -1 if not found
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
    size_t i;

    if (left > right)
        return (-1);

    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
        else
            printf("\n");
    }

    i = left + (right - left) / 2;

    if (array[i] == value)
    {
        if (i > left && array[i - 1] == value)
            return advanced_binary_recursive(array, left, i, value);
        return i;
    }

    if (array[i] < value)
        return advanced_binary_recursive(array, i + 1, right, value);

    return advanced_binary_recursive(array, left, i - 1, value);
}

/**
 * advanced_binary - Search for a value in a sorted array using advanced binary search
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The index where the value is located; -1 if not found or if
 *         array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return advanced_binary_recursive(array, 0, size - 1, value);
}

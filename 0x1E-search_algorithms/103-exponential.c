#include <stdio.h>
#include "search_algos.h"

/**
 * exponential_search - Search for a value in a sorted array using exponential search
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The index where the value is located; -1 if not found or if
 *         array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;
    size_t low, high, mid;
    size_t i;

    if (array == NULL || size == 0)
        return (-1);

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    low = bound / 2;
    high = (bound < size - 1) ? bound : size - 1;

    printf("Value found between indexes [%lu] and [%lu]\n", low, high);
    printf("Searching in array: ");
    for (i = low; i <= high; i++)
    {
        printf("%d", array[i]);
        if (i < high)
            printf(", ");
        else
            printf("\n");
    }

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        printf("Searching in array: ");
        for (i = low; i <= high; i++)
        {
            printf("%d", array[i]);
            if (i < high)
                printf(", ");
            else
                printf("\n");
        }

        if (array[mid] == value)
            return (mid);
        else if (array[mid] < value)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return (-1);
}


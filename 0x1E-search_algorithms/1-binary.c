#include <stdio.h>
#include "search_algos.h"

/**
 * binary_search - Search for a value in a sorted array using binary search
 * @array: Pointer to the first element of the sorted array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The index where the value is located; -1 if not found or if
 *         array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = size - 1;
	size_t mid;
	size_t i;

	if (array == NULL)
		return (-1);
	while (left <= right)
	{
		mid = (left + right) / 2;
		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			printf("%d", array[i]);
			if (i < right)
				printf(", ");
			else
				printf("\n");
		}
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

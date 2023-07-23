#include "sort.h"

/**
 * bubble_sort - Calls function that sorts the arrays
 * @array: Array to be sorted by the above function
 * @size: Size of array to be generated
 * Description: Function that sorts an array using the bubble sort method
 * Return: zero
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int a, b;

	if (!array)
		return;

	for (a = 0; a < size - 1; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				swap(&array[b], &array[b + 1]);
				print_array(array, size);
			}
		}
	}
}

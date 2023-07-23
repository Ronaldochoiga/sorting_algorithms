#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts an array in ascending manner
 * @array: array of ints to be sorted
 * @size: size of the generated array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int a, b;
	int Temp;

	if (size < 2)
		return;

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				Temp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = Temp;
				print_array(array, size);
			}
		}
	}
}

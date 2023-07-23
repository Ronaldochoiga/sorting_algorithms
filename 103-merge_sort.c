#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _merge_sort - initiates merging
 * @array: array to be sorted
 * @temp: temporary array to hold sorted elements
 * @size: size of the array
 */
void _merge_sort(int *array, int *temp, size_t size)
{
	size_t half = size / 2, a = 0, b = 0, c;

	if (size < 2)
		return;

	_merge_sort(array, temp, half);
	_merge_sort(array + half, temp + half, size - half);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, half);
	printf("[right]: ");
	print_array(array + half, size - half);
	for (c = 0; c < size; c++)
		if (b >= size - half || (a < half && array[a] < (array + half)[b]))
		{
			temp[c] = array[a];
			a++;
		}
		else
		{
			temp[c] = (array + half)[b];
			b++;
		}
	for (c = 0; c < size; c++)
		array[c] = temp[c];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - initiates merging
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(*tmp) * size);
	if (!tmp)
		return;

	_merge_sort(array, tmp, size);
	free(tmp);
}
#include "sort.h"

/**
 * swap - Function that swaps values
 * @a: Fisrt value
 * @b: Second value
 * Return: 0
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

/**
 * gap_sort - sort array with gaps betwwen the characters
 * @array: array to be sorted inclusive of gaps
 * @size: size of array to be sorted
 * @gap: gap size of the arrays
 */
void gap_sort(int *array, size_t size, unsigned int gap)
{
	size_t i, h;

	for (i = gap; i < size; i++)
	{
		h = i;
		while (h >= gap && array[h] < array[h - gap])
		{
			swap(array + h, array + h - gap);
			h -= gap;
		}
	}
}

/**
 * shell_sort - shell sort function
 * @array: array to be sorted by the above function
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		gap_sort(array, size, gap);
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}

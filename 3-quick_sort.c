#include "sort.h"

/**
 * quick_sort - Function that sorts an array
 * @array: Array to be sorted by the function
 * @size: Size of array to be sorted
 * Return: zero
 */
void quick_sort(int *array, size_t size)
{
	size_t piv;

	if (!array || size < 2)
		return;

	print_sort(array, size, 1);

	/* partition and get piv index */
	piv = partition(array, size);

	/* repeat for left of index */
	quick_sort(array, piv);
	/* repeat for index and right */
	quick_sort(array + piv, size - piv);
}

/**
 * swap - Function that swaps two values based on the algorithmic function
 *
 * @a: Fisrt value
 * @b: Second value
 * Return: 0
 */
void swap(int *a, int *b)
{
	int Tmp;

	Tmp = *b;
	*b = *a;
	*a = Tmp;
}

/**
 * partition - Function that sets the piv for quick_sort inorder to sort
 * @array: Array to partition
 * @size: Size of array
 * Return: (i + 1)
 */
size_t partition(int array[], size_t size)
{
	int piv;
	size_t a = -1;
	size_t b;

	if (!array || size < 2)
		return (0);

	piv = array[size - 1];

	for (b = 0; b < size - 1; b++)
	{
		if (array[b] <= piv)
		{
			a++;
			if (a != b)
			{
				swap(&array[a], &array[b]);
				print_sort(array, size, 0);
			}
		}
	}
	if (a + 1 != size - 1)
	{
		swap(&array[a + 1], &array[size - 1]);
		print_sort(array, size, 0);
	}
	return (a + 1);
}

/**
 * print_sort - Function that prints the sorted array
 * @array: Array to be printed
 * @size: Size of array
 * @init: initializes the array
 * Return: zero
 */
void print_sort(int array[], size_t size, int init)
{
	static int *i = (void *)0;
	static size_t j;

	if (!i && init)
	{
		i = array;
		j = size;
	}
	if (!init)
		print_array(i, j);
}

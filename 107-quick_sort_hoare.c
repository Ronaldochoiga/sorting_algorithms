#include "sort.h"

/**
 * quick_sort_hoare - sorts array with Quicksort algorithm
 * @array: array of ints into sort
 * @size: size of the array to be generated
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_recursion(array, 0, (int)size - 1, size);
}

/**
 * quick_recursion - helper function for Quicksort algorithm
 * @array: array to be sorted
 * @left: index of thet most left element
 * @right: index of the most right element
 * @size: size of the array generated
 */
void quick_recursion(int *array, int left, int right, size_t size)
{
	int piv;

	if (left < right)
	{
		piv = partition(array, left, right, size);
		quick_recursion(array, left, piv - 1, size);
		quick_recursion(array, piv, right, size);
	}
}

/**
 * partition - gives a pivot index for Quicksort algorithm
 * @array: array to find the pivot inside
 * @left: index of the most left element
 * @right: index of the most_right element
 * @size: size of the array to be generated
 * Return: the index of the pivot element
 */
int partition(int *array, int left, int right, size_t size)
{
	int temp, piv = array[right];
	size_t a, b;

	a = left - 1;
	b = right + 1;
	while (1)
	{
		do {
			a++;
		} while (array[a] < piv);
		do {
			b--;
		} while (array[b] > piv);
		if (a >= b)
			return (a);
		if (a != b)
		{
			temp = array[a];
			array[a] = array[b];
			array[b] = temp;
			print_array(array, size);
		}
	}
	return (0);
}

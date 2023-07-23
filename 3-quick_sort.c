#include "sort.h"

/**
 * quick_sort - functionsorts an array with the Quicksort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_recursion(array, 0, (int)size - 1, size);
}

/**
 * quick_recursion - helper function for the Quicksort algorithm
 * @array: array to be sorted
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array
 */
void quick_recursion(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(array, left, right, size);
		quick_recursion(array, left, pivot - 1, size);
		quick_recursion(array, pivot + 1, right, size);
	}
}

/**
 * partition - gives a pivot index for Quicksort algorithm
 * @array: array to find the pivot function in
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array generated
 *
 * Return: the index of the pivot element
 */
int partition(int *array, int left, int right, size_t size)
{
	int temp, a;
	int b;

	a = left - 1;

	for (b = left; b < right; b++)
	{
		if (array[b] < array[right])
		{
			a++;
			if (a != b)
			{
				temp = array[a];
				array[a] = array[b];
				array[b] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[right] < array[a + 1])
	{
		temp = array[a + 1];
		array[a + 1] = array[right];
		array[right] = temp;
		print_array(array, size);
	}

	return (a + 1);
}

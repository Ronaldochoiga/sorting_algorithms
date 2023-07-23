#include "sort.h"

/**
 * heap_sort - Sorting array with heap sorting algorithm
 * @array: Array to be sorted
 * @size: Size of the array to be generated
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int a;

	if (!array || size < 2)
		return;

	for (a = size / 2; a >= 0; a--)
		heapify(array, size, a, size);
	for (a = size - 1; a >= 0; a--)
	{
		swap(&array[a], &array[0]);
		if (a != 0)
			print_array(array, size);
		heapify(array, a, 0, size);
	}
}

/**
 * heapify - Recursive function thats sorts a binary tree
 * @array: array to sort as a binary tree
 * @end: Last_node in the binary tree
 * @start: First_node in the binary tree
 * @size: Size of the array to be sorted
 * Return: zero
 */
void heapify(int *array, int end, int start, size_t size)
{
	int mx = start;
	int l = 2 * start + 1;
	int r = 2 * start + 2;

	if (!array || size < 2)
		return;

	if (l < end && array[l] > array[mx])
		mx = l;

	if (r < end && array[r] > array[mx])
		mx = r;

	if (start != mx)
	{
		swap(&array[start], &array[mx]);
		print_array(array, size);
		heapify(array, end, mx, size);
	}
}

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

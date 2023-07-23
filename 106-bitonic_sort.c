#include "sort.h"

/**
 * bitonic_sort - sorts an array at Bitonic sort algorithm
 * @array: array of ints to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_recursion(array, 0, size - 1, 1, size);
}

/**
 * bitonic_recursion - recursive function for bitonic sorting
 * @array: array to be sorted
 * @l: index of the left-most element
 * @r: index of the right-most element
 * @direction: asc or desc
 * @size: size of the array
 */
void bitonic_recursion(int *array, int l, int r, int direction, size_t size)
{
	int step;

	if (r - l >= 1)
	{
		step = (r + l) / 2;
		printf("Merging [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
		bitonic_recursion(array, l, step, 1, size);
		bitonic_recursion(array, step + 1, r, 0, size);
		bitonic_merge(array, l, r, direction);
		printf("Result [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
	}
}

/**
 * bitonic_merge - sorts or merge a sequence in desc or asc order
 * @array: array to be sorted
 * @l: index of the left-most element
 * @r: index of the right-most element
 * @direction: asc or desc
 */
void bitonic_merge(int *array, int l, int r, int direction)
{
	int temp, a, step = (l + r) / 2, median = (r - l + 1) / 2;

	if (r - l >= 1)
	{
		for (a = l; a < l + median; a++)
		{
			if (direction == (array[a] > array[a + median]))
			{
				temp = array[a + median];
				array[a + median] = array[a];
				array[a] = temp;
			}
		}
		bitonic_merge(array, l, step, direction);
		bitonic_merge(array, step + 1, r, direction);
	}

}

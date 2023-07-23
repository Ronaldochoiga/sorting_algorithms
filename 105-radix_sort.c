#include "sort.h"

/**
 * radix_sort - sorts an array as set by Radix sort algorithm
 * @array: array of ints to be sorted
 * @size: size of the array to sort
 */
void radix_sort(int *array, size_t size)
{
	int mx;
	size_t a, lsd;

	if (!array || size < 2)
		return;

	mx = 0;
	for (a = 0; a < size; a++)
		if (array[a] > mx)
			mx = array[a];

	for (lsd = 1; mx / lsd > 0; lsd *= 10)
	{
		count_sort_LSD(array, size, lsd);
		print_array(array, size);
	}
}

/**
 * count_sort_LSD - count sort with LSD functionality
 * @array: array to be sorted
 * @size: size of the array to be generated
 * @lsd: least significant digit of the array generated
 */
void count_sort_LSD(int *array, size_t size, size_t lsd)
{
	int count_array[10] = {0}, *out_array, d, e;
	size_t c, f;

	out_array = malloc(sizeof(int) * size);

	for (c = 0; c < size; c++)
		count_array[(array[c] / lsd) % 10]++;
	for (d = 1; d < 10; d++)
		count_array[d] += count_array[d - 1];

	for (e = size - 1; e >= 0; e--)
	{
		out_array[count_array[(array[e] / lsd) % 10] - 1] = array[e];
		count_array[(array[e] / lsd) % 10]--;
	}

	for (f = 0; f < size; f++)
		array[f] = out_array[f];

	free(out_array);
}

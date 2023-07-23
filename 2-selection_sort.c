#include "sort.h"

/**
 * selection_sort - Calls function for sorting
 * @array: Array to be sorted by the above function
 * @size: Size of array given for sortin
 * Return: zero
 */
void selection_sort(int *array, size_t size)
{
	unsigned int k, l, m_index;

	if (!array)
		return;

	for (k = 0; k < size - 1; k++)
	{
		m_index = k;
		for (l = k + 1; l < size; l++)
			if (array[l] < array[m_index])
				m_index = l;

		if (k != m_index)
		{
			swap(&array[m_index], &array[k]);
			print_array(array, size);
		}
	}
}

/**
 * swap - Function that swaps two values
 * of an algorithm
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

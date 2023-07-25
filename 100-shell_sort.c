#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gapp, index, n;

	if (array == NULL || size < 2)
		return;

	for (gapp = 1; gapp < (size / 3);)
		gapp = gapp * 3 + 1;

	for (; gapp >= 1; gapp /= 3)
	{
		for (index = gapp; index < size; index++)
		{
			n = index;
			while (n >= gapp && array[n - gapp] > array[n])
			{
				swap(array + n, array + (n - gapp));
				n -= gapp;
			}
		}
		print_array(array, size);
	}
}

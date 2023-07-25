#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_element_ptr, temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_element_ptr = array + i;
		for (j = i + 1; j < size; j++)
			if (array[j] < *min_element_ptr)
				min_element_ptr = array + j;

		if (array + i != min_element_ptr)
		{
			temp = array[i];
			array[i] = *min_element_ptr;
			*min_element_ptr = temp;
			print_array(array, size);
		}
	}
}

#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;
	bool bubble;
	int temp;

	if (array == NULL || size < 2)
		return;

	do {
		bubble = false;
		for (i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);

				bubble = true;
			}
		}
		length--;
	} while (bubble);
}

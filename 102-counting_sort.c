#include "sort.h"

/**
 * max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int max(int *array, int size)
{
	int maximum, i;

	for (maximum = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maximum)
			maximum = array[i];
	}

	return (maximum);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *sort_array, maximum, i;

	if (array == NULL || size < 2)
		return;

	sort_array = malloc(sizeof(int) * size);
	if (sort_array == NULL)
		return;
	maximum = max(array, size);
	count_array = malloc(sizeof(int) * (maximum + 1));
	if (count_array == NULL)
	{
		free(sort_array);
		return;
	}

	for (i = 0; i < (maximum + 1); i++)
		count_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		count_array[array[i]] += 1;
	for (i = 0; i < (maximum + 1); i++)
		count_array[i] += count_array[i - 1];
	print_array(count_array, maximum + 1);

	for (i = 0; i < (int)size; i++)
	{
		sort_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sort_array[i];

	free(sort_array);
	free(count_array);
}

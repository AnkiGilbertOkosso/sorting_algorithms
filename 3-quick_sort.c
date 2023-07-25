#include "sort.h"

void data_swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * data_swap - Swap two integers in an array.
 * @anum1: The first integer to swap.
 * @bnum2: The second integer to swap.
 */
void data_swap(int *anum1, int *bnum2)
{
	int tmp;

	tmp = *anum1;
	*anum1 = *bnum2;
	*bnum2 = tmp;
}


/**
 * lomuto_partition - Partition a subset of an array of integers
 * using the Lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subset to partition.
 * @high: The ending index of the subset to partition.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot_value = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot_value)
		{
			i++;
			data_swap(array + i, array + j);
			print_array(array, size);
		}
	}

	data_swap(array + i + 1, array + high);
	print_array(array, size);

	return (i + 1);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to sort.
 * @high: The ending index of the array partition to sort.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int part = lomuto_partition(array, size, low, high);

		lomuto_sort(array, size, low, part - 1);
		lomuto_sort(array, size, part + 1, high);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

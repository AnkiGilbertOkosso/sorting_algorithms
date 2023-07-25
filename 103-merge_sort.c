#include "sort.h"

void merge_sub_array(int *sub_array, int *buffer, size_t first, size_t mid,
		size_t last);
void merge_sort_rec(int *sub_array, int *buffer, size_t first, size_t last);
void merge_sort(int *array, size_t size);

/**
 * merge_sub_array - Sort a sub_array of integers.
 * @sub_array: A sub_array of an array of integers to sort.
 * @buffer: A bufferer to store the sorted sub_array.
 * @first: The first index of the array.
 * @mid: The middle index of the array.
 * @last: The last index of the array.
 */
void merge_sub_array(int *sub_array, int *buffer, size_t first, size_t mid,
		size_t last)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_array + first, mid - first);

	printf("[right]: ");
	print_array(sub_array + mid, last - mid);

	for (i = first, j = mid; i < mid && j < last; k++)
		buffer[k] = (sub_array[i] < sub_array[j]) ? sub_array[i++] : sub_array[j++];
	for (; i < mid; i++)
		buffer[k++] = sub_array[i];
	for (; j < last; j++)
		buffer[k++] = sub_array[j];
	for (i = first, k = 0; i < last; i++)
		sub_array[i] = buffer[k++];

	printf("[Done]: ");
	print_array(sub_array + first, last - first);
}

/**
 * merge_sort_rec - Implement the merge sort algorithm through recursion.
 * @sub_array: A sub_arrayay of an array of integers to sort.
 * @buffer: A bufferer to store the sorted result.
 * @first: The first index of the sub_arrayay.
 * @last: The last index of the sub_arrayay.
 */
void merge_sort_rec(int *sub_array, int *buffer, size_t first, size_t last)
{
	size_t mid;

	if (last - first > 1)
	{
		mid = first + (last - first) / 2;
		merge_sort_rec(sub_array, buffer, first, mid);
		merge_sort_rec(sub_array, buffer, mid, last);
		merge_sub_array(sub_array, buffer, first, mid, last);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_rec(array, buffer, 0, size);

	free(buffer);
}

#include "sort.h"

void data_swap(int *num1, int *num2);
void heapify(int *array, size_t size, size_t bs, size_t root_node);
void heap_sort(int *array, size_t size);

/**
 * data_swap - Swap two integers in an array.
 * @num1: The first integer to swap.
 * @num2: The second integer to swap.
 */
void data_swap(int *num1, int *num2)
{
	int tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
 * heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @bs: The index of the bs row of the tree.
 * @root_node: The root_node node of the binary tree.
 */
void heapify(int *array, size_t size, size_t bs, size_t root_node)
{
	size_t first, last, i;

	first = 2 * root_node + 1;
	last = 2 * root_node + 2;
	i = root_node;

	if (first < bs && array[first] > array[i])
		i = first;
	if (last < bs && array[last] > array[i])
		i = last;

	if (i != root_node)
	{
		data_swap(array + root_node, array + i);
		print_array(array, size);
		heapify(array, size, bs, i);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		data_swap(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}


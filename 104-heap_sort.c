#include "sort.h"

/**
 * swap_numbers - Function to Swap two numbers in an array.
 * @first_number: The first number to swap.
 * @second_number: The second number to swap.
 */
void swap_numbers(int *first_number, int *second_number)
{
	int temp;

	temp = *first_number;
	*first_number = *second_number;
	*second_number = temp;
}

/**
 * max_heap_main - to maintain the max-heap property in a given array.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/binary tree.
 * @tree_base: The index of the base row of the tree.
 * @tree_root: The root node of the binary tree.
 */
void max_heap_main(int *array, size_t size, size_t tree_base, size_t tree_root)
{
	size_t left, right, cur_node_index;

	left = 2 * tree_root + 1;
	right = 2 * tree_root + 2;
	cur_node_index = tree_root;

	if (left < tree_base && array[left] > array[cur_node_index])
		cur_node_index = left;
	if (right < tree_base && array[right] > array[cur_node_index])
		cur_node_index = right;

	if (cur_node_index != tree_root)
	{
		swap_numbers(array + tree_root, array + cur_node_index);
		print_array(array, size);
		max_heap_main(array, size, tree_base, cur_node_index);
	}
}

/**
 * heap_sort - function that sorts an array of integers
 * in ascending order using the Heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Print the array after each time you swap two elements.
 */
void heap_sort(int *array, size_t size)
{
	int index;

	if (array == NULL || size < 2)
		return;

	for (index = (size / 2) - 1; index >= 0; index--)
		max_heap_main(array, size, size, index);

	for (index = size - 1; index > 0; index--)
	{
		swap_numbers(array, array + index);
		print_array(array, size);
		max_heap_main(array, size, index, 0);
	}
}

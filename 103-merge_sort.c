#include "sort.h"

/**
 * sub_array_merge - function that performs the merging step
 * in the merge sort algorithm for sorting an array of integers
 * @sub_array: Pointer to the array that contains the subarrays
 * to be merged.
 * @temp_buffer: Pointer to a temporary buffer array used during
 * the merging process.
 * @front_index: The front index of the array.
 * @mid_index: The middle index of the array.
 * @back_index: The back index of the array.
 */
void sub_array_merge(int *sub_array, int *temp_buffer, size_t front_index,
	size_t mid_index, size_t back_index)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_array + front_index, mid_index - front_index);

	printf("[right]: ");
	print_array(sub_array + mid_index, back_index - mid_index);

	for (i = front_index, j = mid_index; i < mid_index && j < back_index; k++)
		temp_buffer[k] = (sub_array[i] < sub_array[j]) ? sub_array[i++] : sub_array[j++];
	for (; i < mid_index; i++)
		temp_buffer[k++] = sub_array[i];
	for (; j < back_index; j++)
		temp_buffer[k++] = sub_array[j];
	for (i = front_index, k = 0; i < back_index; i++)
		sub_array[i] = temp_buffer[k++];

	printf("[Done]: ");
	print_array(sub_array + front_index, back_index - front_index);
}

/**
 * recursive_merge_sort - function that implements the merge sort
 * algorithm to sort a given subarray of integers.
 * @sub_array: Pointer to the array that contains the subarray to be sorted.
 * @temp_buffer: Pointer to a temporary buffer array used during the
 * merging process.
 * @front_index: Index indicating the start of the subarray to be sorted.
 * @back_index: Index indicating the end of the subarray to be sorted.
 */
void recursive_merge_sort(int *sub_array, int *temp_buffer, size_t front_index, size_t back_index)
{
	size_t mid_index;

	if (back_index - front_index > 1)
	{
		mid_index = front_index + (back_index - front_index) / 2;
		recursive_merge_sort(sub_array, temp_buffer, front_index, mid_index);
		recursive_merge_sort(sub_array, temp_buffer, mid_index, back_index);
		sub_array_merge(sub_array, temp_buffer, front_index, mid_index, back_index);
	}
}

/**
 * merge_sort - unction that sorts an array of integers in
 * ascending order using the Merge sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *temp_buffer;

	if (array == NULL || size < 2)
		return;

	temp_buffer = malloc(sizeof(int) * size);
	if (temp_buffer == NULL)
		return;

	recursive_merge_sort(array, temp_buffer, 0, size);

	free(temp_buffer);
}
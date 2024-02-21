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
 * lomuto_partition_scheme - function to implements the Lomuto
 * partition scheme for the quicksort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left_portion: left_portion portion of the array.
 * @right_portion: right_portion portion of the array.
 *
 * Return: returns the position of the pivot after partitioning.
 */
int lomuto_partition_scheme(int *array, size_t size,
	int left_portion, int right_portion)
{
	int *pivot, above, below;

	pivot = array + right_portion;
	for (above = below = left_portion; below < right_portion; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_numbers(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_numbers(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - function implements the quicksort algorithm
 * using the Lomuto partition scheme.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left_portion: The starting index of the array partition to order.
 * @right_portion: The ending index of the array partition to order.
 *
 * Description: Sorting using Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left_portion, int right_portion)
{
	int pivot_position;

	if (right_portion - left_portion > 0)
	{
		pivot_position = lomuto_partition_scheme(array, size,
			left_portion, right_portion);
		lomuto_sort(array, size, left_portion, pivot_position - 1);
		lomuto_sort(array, size, pivot_position + 1, right_portion);
	}
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Print the array after each time you swap two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

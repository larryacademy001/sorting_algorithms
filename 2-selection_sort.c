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
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Print the array after each time you swap two elements.
 */
void selection_sort(int *array, size_t size)
{
	int *min_element;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_element = array + i;
		for (j = i + 1; j < size; j++)
			min_element = (array[j] < *min_element) ? (array + j) : min_element;

		if ((array + i) != min_element)
		{
			swap_numbers(array + i, min_element);
			print_array(array, size);
		}
	}
}

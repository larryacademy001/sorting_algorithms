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
 * shell_sort -function that sorts an array of integers in
 * ascending order using the Shell sort algorithm, using the
 * Knuth sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Print the array each time you decrease the interval.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, inner, outer;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (inner = gap; inner < size; inner++)
		{
			outer = inner;
			while (outer >= gap && array[outer - gap] > array[outer])
			{
				swap_numbers(array + outer, array + (outer - gap));
				outer -= gap;
			}
		}
		print_array(array, size);
	}
}

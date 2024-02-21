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
 * bubble_sort - function to sort an array of numbers in ascending order.
 * @array: An array of numbers to sort.
 * @size: The array size.
 *
 * Description: print the array after each time you swap two elements.
 */
void bubble_sort(int *array, size_t size)
{
	size_t index, array_size = size;
	bool bubble_status = false;

	if (array == NULL || array_size < 2)
		return;

	while (bubble_status == false)
	{
		bubble_status = true;
		for (index = 0; index < array_size - 1; index++)
		{
			if (array[index] > array[index + 1])
			{
				swap_numbers(array + index, array + index + 1);
				print_array(array, size);
				bubble_status = false;
			}
		}
		array_size--;
	}
}
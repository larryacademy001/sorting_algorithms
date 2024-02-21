#include "sort.h"

/**
 * get_max_value - function to find and return the
 * maximum value present in an array.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: the maximum value found in the array.
 */
int get_max_value(int *array, int size)
{
	int max_value, index;

	for (max_value = array[0], index = 1; index < size; index++)
	{
		if (array[index] > max_value)
			max_value = array[index];
	}

	return (max_value);
}

/**
 * counting_sort - function sorts an array of integers
 * using the Counting Sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Print counting array once it is set up.
 */
void counting_sort(int *array, size_t size)
{
	int *counter, *temp_array, max_value, index;

	if (array == NULL || size < 2)
		return;

	temp_array = malloc(sizeof(int) * size);
	if (temp_array == NULL)
		return;
	max_value = get_max_value(array, size);
	counter = malloc(sizeof(int) * (max_value + 1));
	if (counter == NULL)
	{
		free(temp_array);
		return;
	}

	for (index = 0; index < (max_value + 1); index++)
		counter[index] = 0;
	for (index = 0; index < (int)size; index++)
		counter[array[index]] += 1;
	for (index = 0; index < (max_value + 1); index++)
		counter[index] += counter[index - 1];
	print_array(counter, max_value + 1);

	for (index = 0; index < (int)size; index++)
	{
		temp_array[counter[array[index]] - 1] = array[index];
		counter[array[index]] -= 1;
	}

	for (index = 0; index < (int)size; index++)
		array[index] = temp_array[index];

	free(temp_array);
	free(counter);
}

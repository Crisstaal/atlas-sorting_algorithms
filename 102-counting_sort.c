#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, size_t size);

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @array: Array of integers.
 * @size: Number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array = NULL, *output_array = NULL;
	int max = 0, i;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Allocate memory for counting array and output array */
	counting_array = malloc((max + 1) * sizeof(int));
	output_array = malloc(size * sizeof(int));

	if (counting_array == NULL || output_array == NULL)
	{
		free(counting_array);
		free(output_array);
		return;
	}

	/* Initialize counting array with zeros */
	for (i = 0; i <= max; i++)
		counting_array[i] = 0;

	/* Populate the counting array with the count of each number */
	for (i = 0; i < (int)size; i++)
	{
		counting_array[array[i]]++;
	}

	/* Compute the cumulative count */
	for (i = 1; i <= max; i++)
	{
		counting_array[i] += counting_array[i - 1];
	}

	/* Print the counting array */
	print_array(counting_array, max + 1);

	/* Build the output sorted array */
	for (i = (int)size - 1; i >= 0; i--)
	{
		output_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}

	/* Copy sorted elements back to original array */
	for (i = 0; i < (int)size; i++)
	{
		array[i] = output_array[i];
	}

	/* Free allocated memory */
	free(counting_array);
	free(output_array);
}
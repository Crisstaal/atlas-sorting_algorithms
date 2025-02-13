#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - Prints the elements of the array.
 * @array: Array of integers.
 * @size: Number of elements in the array.
 */
void print_array(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @array: Array of integers.
 * @size: Number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array = NULL;
	int max = 0, i;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Allocate memory for counting array of size max + 1 */
	counting_array = malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;

	/* Initialize counting array with zeros */
	for (i = 0; i <= max; i++)
		counting_array[i] = 0;

	/* Populate the counting array with the count of each number */
	for (i = 0; i < (int)size; i++)
	{
		counting_array[array[i]]++;
	}

	/* Print the counting array */
	print_array(counting_array, max + 1);

	/* Rebuild the original array using the counting array */
	i = 0;
	for (int j = 0; j <= max; j++)
	{
		while (counting_array[j] > 0)
		{
			array[i] = j;
			i++;
			counting_array[j]--;
		}
	}

	/* Free the allocated memory for the counting array */
	free(counting_array);
}
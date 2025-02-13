#include <stdio.h>
#include <stddef.h>

void print_array(int *array, size_t size);

/**
 * shell_sort - Sorts an array of integers in ascending order
 *             using the Shell sort algorithm (Knuth sequence).
 * @array: Array of integers.
 * @size: Number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int temp;

	/* Find the maximum gap using the Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Perform sorting with decreasing gap */
	while (gap > 0)
	{
		/* Perform insertion sort with the current gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		/* Print the array after each gap decrease */
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
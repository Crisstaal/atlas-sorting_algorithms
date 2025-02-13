#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, size_t size);

/**
 * merge - Merges two sorted subarrays into a single sorted subarray.
 * @array: The original array.
 * @temp: Temporary array used for merging.
 * @left: Left index (inclusive) of the subarray.
 * @mid: Middle index (start of right subarray).
 * @right: Right index (exclusive) of the subarray.
 *
 * Description: Creates temporary copies of the left and right subarrays
 * for printing, then merges them into temp, copies the result back to array,
 * and prints the merged result.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;
	int *left_copy, *right_copy;
	size_t left_size, right_size;

	left_size = mid - left;
	right_size = right - mid;

	left_copy = malloc(left_size * sizeof(int));
	right_copy = malloc(right_size * sizeof(int));
	if (left_copy == NULL || right_copy == NULL)
	{
		free(left_copy);
		free(right_copy);
		return;
	}

	/* Copy left subarray */
	for (i = 0; i < left_size; i++)
		left_copy[i] = array[left + i];
	/* Copy right subarray */
	for (j = 0; j < right_size; j++)
		right_copy[j] = array[mid + j];

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left_copy, left_size);
	printf("[right]: ");
	print_array(right_copy, right_size);

	free(left_copy);
	free(right_copy);

	/* Merge the two subarrays into temp */
	i = left;
	j = mid;
	k = left;
	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
		k++;
	}
	while (i < mid)
	{
		temp[k] = array[i];
		i++;
		k++;
	}
	while (j < right)
	{
		temp[k] = array[j];
		j++;
		k++;
	}
	/* Copy sorted subarray back to array */
	for (i = left; i < right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_rec - Recursively splits and sorts the array.
 * @array: The array of integers.
 * @temp: Temporary array used for merging.
 * @left: Left index (inclusive) of the current subarray.
 * @right: Right index (exclusive) of the current subarray.
 *
 * Description: Divides the array into two subarrays, sorts them, and merges.
 */
void merge_sort_rec(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = left + (right - left) / 2;
	merge_sort_rec(array, temp, left, mid);
	merge_sort_rec(array, temp, mid, right);
	merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort.
 * @array: The array of integers.
 * @size: Number of elements in the array.
 *
 * Description: Allocates a temporary array and calls the recursive merge sort.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_rec(array, temp, 0, size);
	free(temp);
}
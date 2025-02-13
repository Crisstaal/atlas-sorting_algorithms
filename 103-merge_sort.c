#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, size_t size);

/**
 * merge - Merges two sorted subarrays into one sorted subarray.
 * @array: The original array.
 * @temp: Temporary array used for merging.
 * @left: Left index (inclusive) of the subarray.
 * @mid: Middle index (start of the right subarray).
 * @right: Right index (exclusive) of the subarray.
 *
 * Description: Prints the left and right subarrays before merging,
 * then merges them into the temporary array and copies the result back
 * to the original array, and prints the merged subarray.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	/* Print the subarrays before merging */
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

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
	for (i = left; i < right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_rec - Recursively splits and sorts the array.
 * @array: The array of integers.
 * @temp: Temporary array for merging.
 * @left: Left index (inclusive) of the current subarray.
 * @right: Right index (exclusive) of the current subarray.
 *
 * Description: Recursively sorts the subarray of array from index left to
 * right and then merges the sorted halves.
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
 * Description: Allocates a temporary array for merging (one call to malloc),
 * calls the recursive merge sort function, and then frees the temporary array
 * (one call to free).
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
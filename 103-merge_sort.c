#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, size_t size);

/**
 * merge - Merges two sorted subarrays into one sorted array.
 * @array: The original array (to be updated).
 * @temp: Temporary array for merging.
 * @left: Starting index of the left subarray.
 * @mid: Middle index (end of left, start of right).
 * @right: End index of the right subarray.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	/* Merge elements into temp */
	while (i < mid && j < right)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	/* Copy remaining elements from left subarray */
	while (i < mid)
		temp[k++] = array[i++];
	/* Copy remaining elements from right subarray */
	while (j < right)
		temp[k++] = array[j++];

	/* Copy sorted elements back into the original array */
	for (i = left; i < right; i++)
		array[i] = temp[i];

	/* Print merge process */
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);
	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_rec - Recursively splits the array and sorts it.
 * @array: The array of integers.
 * @temp: Temporary array for merging.
 * @left: Left index of the subarray.
 * @right: Right index of the subarray.
 */
void merge_sort_rec(int *array, int *temp, size_t left, size_t right)
{
	if (right - left < 2)
		return;

	size_t mid = left + (right - left) / 2;

	merge_sort_rec(array, temp, left, mid);
	merge_sort_rec(array, temp, mid, right);
	merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Sorts an array using Merge Sort algorithm.
 * @array: The array of integers.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int *temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_rec(array, temp, 0, size);
	free(temp);
}
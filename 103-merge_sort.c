#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, size_t size);

/**
 * merge - Merges two sorted subarrays into one sorted array.
 * @array: Array of integers.
 * @left: Left subarray.
 * @right: Right subarray.
 * @size_left: Size of the left subarray.
 * @size_right: Size of the right subarray.
 */
void merge(int *array, int *left, int *right, size_t size_left, size_t size_right)
{
	size_t i = 0, j = 0, k = 0;

	while (i < size_left && j < size_right)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < size_left)
		array[k++] = left[i++];
	while (j < size_right)
		array[k++] = right[j++];

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);
	printf("[Done]: ");
	print_array(array, size_left + size_right);
}

/**
 * merge_sort_rec - Recursively splits the array and sorts it.
 * @array: Array of integers.
 * @temp: Temporary array for merging.
 * @size: Size of the array.
 */
void merge_sort_rec(int *array, int *temp, size_t size)
{
	size_t mid;

	if (size < 2)
		return;

	mid = size / 2;

	merge_sort_rec(array, temp, mid);
	merge_sort_rec(array + mid, temp, size - mid);

	merge(array, array, array + mid, mid, size - mid);
}

/**
 * merge_sort - Sorts an array using the Merge sort algorithm.
 * @array: Array of integers.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	merge_sort_rec(array, temp, size);

	free(temp);
}
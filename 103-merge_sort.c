#include <stdio.h>
#include <stdlib.h>

void print_array(int *array, size_t size);

/**
 * merge - Merges two sorted subarrays into one sorted array.
 * @array: The original array.
 * @temp: Temporary array used for merging.
 * @left: Left index (inclusive) of the subarray.
 * @mid: Middle index (the start of the right subarray).
 * @right: Right index (exclusive) of the subarray.
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i, j, k;

    i = left;
    j = mid;
    k = left;

    while (i < mid && j < right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while (i < mid)
        temp[k++] = array[i++];
    while (j < right)
        temp[k++] = array[j++];

    for (i = left; i < right; i++)
        array[i] = temp[i];

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
 * @left: Left index (inclusive) of the current subarray.
 * @right: Right index (exclusive) of the current subarray.
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
 * merge_sort - Sorts an array using the Merge sort algorithm.
 * @array: Array of integers.
 * @size: Number of elements in the array.
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
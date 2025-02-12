#include <stdio.h>

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
        gap = 3 * gap + 1;

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
        gap = (gap - 1) / 3;
    }
}

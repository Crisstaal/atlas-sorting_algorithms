#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Function prototypes */
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);

void print_array(const int *array, size_t size);

#endif /* SORT_H */
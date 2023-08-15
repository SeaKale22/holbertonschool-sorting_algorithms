#include "sort.h"

void swap(int *a, int *b);

/**
 * quick_sort- sorts an array of ints using quick sort
 * @array: the array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	int pivot;
	size_t i, j

	if (size < 2)
		return;
	pivot = array[size - 1];
	i = -1;

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	i++;
	swap(&array[i], &array[size - 1]);
	print_array(array, size);
	quick_sort(array, i);
	quick_sort(array + i + 1, size - i - 1);
	print_array(array, size);
}
/**
 * swap- swaps two elements
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

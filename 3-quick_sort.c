#include "sort.h"

void swap(int *a, int *b);
void quick_sort_a(int *array, int low, int high, size_t size);
int lomuto(int *array, int low, int high, size_t size);

/**
 * quick_sort- sorts an array of ints using quick sort
 * @array: the array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		quick_sort_a(array, 0, size - 1, size);
}

/**
 * quick_sort_a- sorts an array of ints
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of array
 */
void quick_sort_a(int *array, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto(array, low, high, size);
		quick_sort_a(array, low, pivot_idx - 1, size);
		quick_sort_a(array, pivot_idx + 1, high, size);
	}
}

/**
 * lomuto- partitions array using lomuto scheme
 * @array: array
 * @low: starting index
 * @high: ending index
 * @size: size of array
 * Return: index of pivot
 */
int lomuto(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > pivot)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
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

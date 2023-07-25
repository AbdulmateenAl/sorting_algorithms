#include "sort.h"

void swap_integers(int *num1, int *num2);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int low, int high);

/**
 * swap_integers - Swap two integers in an array.
 * @num1: The first integer to swap.
 * @num2: The second integer to swap.
 */

void swap_integers(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot_elem, idx_above, idx_below;

	pivot_elem = array + right;
	for (idx_above = idx_below = left; idx_below < right; idx_below++)
	{
		if (array[idx_below] < *pivot_elem)
		{
			if (idx_above < idx_below)
			{
				swap_integers(array + idx_below, array + idx_above);
				print_array(array, size);
			}
			idx_above++;
		}
	}

	if (array[idx_above] > *pivot_elem)
	{
		swap_integers(array + idx_above, pivot_elem);
		print_array(array, size);
	}

	return (idx_above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int low, int high)
{
	int partition_index;

	if (high - low > 0)
	{
		partition_index = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, partition_index - 1);
		lomuto_sort(array, size, partition_index + 1, high);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

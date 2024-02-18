#include "sort.h"

/**
 * swap_ints - This func swaps two integers in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t itr, il;

	if (array == NULL || size < 2)
		return;

	for (itr = 0; itr < size - 1; itr++)
	{
		min = array + itr;
		for (il = itr + 1; il < size; il++)
			min = (array[il] < *min) ? (array + il) : min;

		if ((array + itr) != min)
		{
			swap_ints(array + itr, min);
			print_array(array, size);
		}
	}
}
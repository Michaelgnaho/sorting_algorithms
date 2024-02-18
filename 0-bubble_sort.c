#include "sort.h"

/**
 * swap_ints - This func swaps two integers in an array.
 * @a: first integer to swap.
 * @b: second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp_h;

	temp_h = *a;
	*a = *b;
	*b = temp_h;
}

/**
 * bubble_sort - This func sorts an array of integers in ascending order.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t itr, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (itr = 0; itr < len - 1; itr++)
		{
			if (array[itr] > array[itr + 1])
			{
				swap_ints(array + itr, array + itr + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}

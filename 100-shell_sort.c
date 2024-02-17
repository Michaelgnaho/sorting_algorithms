#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell algorithim using the Knuth sequence
 * @array: pointer to to the array
 * @size: sie of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || size < 2)
		return;

	for (gap = (size / 3 + 1); gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

			array[j] = temp;
		}
		print_array(array, size);
	}
}

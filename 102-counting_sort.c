#include "sort.h"

/**
* counting_sort - sorts an array of integers
* in ascending order using Counting sort algorithm
* @array: array to sort
* @size: size of the array
*/

void counting_sort(int *array, size_t size)
{
size_t i, j, max;
int *ptr;

max = array[0];
for (i =  1; i < size; i++)
{
if (array[i] > (int)max)
{
max = array[i];
}
}

ptr = malloc(sizeof(int) * (max + 1));
if (ptr == NULL)
return;

for (i =  0; i <= max; i++)
{
ptr[i] =  0;
}
print_array(ptr, max + 1);

for (i =  0; i < size; i++)
{
ptr[array[i]]++;
}

j =  0;
for (i =  0; i <= max; i++)
{
while (ptr[i] >  0)
{
array[j] = i;
j++;
ptr[i]--;
}
}
free(ptr);
}

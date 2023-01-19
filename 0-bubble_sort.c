#include "sort.h"

/**
 * bubble_sort - bubble sort func
 *
 * @array: Integer stored in the array
 * @size: size of array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j, tmp;

	while (i < size)
	{
		for (j = 1; j < size; j++)
		{
			if (array[j - 1] > array[j])
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				print_array(array, size);
			}
		}
		++i;
	}
}

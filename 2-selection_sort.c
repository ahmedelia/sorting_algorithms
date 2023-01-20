#include "sort.h"

/**
 * selection_sort - selection sort func
 *
 * @array: Integer stored in the array
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;
	int value, tmp, flag;


	if (!array || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		idx = i;
		value = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (value > array[j])
			{
				idx = j;
				value = array[j];
			}

		}
		tmp = array[i];
		array[i] = array[idx];
		array[idx] = tmp;
		if (idx != i)
			print_array(array, size);

		for (j = 1; j < size; j++)
		{
			if (array[j - 1] > array[j])
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
			break;
		flag = 0;

	}

}

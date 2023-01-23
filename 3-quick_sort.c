#include "sort.h"

/**
 * swap - swap two elements
 * @a:first
 * @b:second
 * Retrun: void
 */
void swap(int *a, int *b)
{
	int tmp = *b;


	*b = *a;
	*a = tmp;
}

/**
 * partition - solve sub problem
 * @arr: array
 * @n: size
 * @low: start
 * @high: end
 * Return: int
 */

int partition(int *arr, size_t n, int low, int high)
{
	int curr = low, i, pivot = arr[high];


	for (i = low; i < high; i++)
	{
		if (pivot > arr[i])
		{
			swap(&arr[i], &arr[curr]);
			if (arr[i] != arr[curr])
				print_array(arr, n);
			curr++;
		}
	}
	swap(&arr[curr], &arr[high]);
	if (arr[curr] != arr[high])
		print_array(arr, n);
	return (curr);
}
/**
 * quick - helping func
 * @arr: array
 * @n: size
 * @low: first n
 * @high: last n
 * Return: void
 */
void quick(int *arr, size_t n, int low, int high)
{
	int pivot;

	if (low > high)
		return;
	pivot = partition(arr, n, low, high);
	quick(arr, n, pivot + 1, high);
	quick(arr, n, low, pivot - 1);
}
/**
 * quick_sort - sort func
 * @arr: Integer stored in the array
 * @n: size of array
 * Return: void
 */

void quick_sort(int *arr, size_t n)
{
	if (!arr || n <= 1)
		return;
	quick(arr, n, 0, n - 1);

}

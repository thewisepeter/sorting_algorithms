#include "sort.h"

/**
 * bubble_sort - implements bubble sort algorithm
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int temp = 0, swaps;

	while (len > 1)
	{
		swaps = 0;

		for (i = 0; i < (len - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				swaps = 1;
			}
		}
		if (swaps == 0)
		{
			break;
		}

		len -= 1;
	}
}

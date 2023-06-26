#include "sort.h"

/**
 * swap - switches two elements of an array
 * @array: double pointer to array
 * @first: index to element in array
 * @second: index to element in array
 *
 * Return: nothing
 */
void swap(int **array, size_t first, size_t second)
{
	int temp;

	temp = (*array)[first];
	(*array)[first] = (*array)[second];
	(*array)[second] = temp;
}

/**
 * selection_sort - sorts an array using selection sort
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min_val, min_index, flag;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_val = array[i];
		min_index = i;
		flag = 0;
		for (j = i + 1; j < size; j++)
		{
			if (min_val > array[j])
			{
				min_val = array[j];
				min_index = j;
				flag = 1;
			}

		}
		if (flag)
		{
			swap(&array, i, min_index);
			print_array(array, size);
		}
	}
}

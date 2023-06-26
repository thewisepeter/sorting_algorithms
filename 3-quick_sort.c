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
 * moses - who parts the red sea
 * @array: double pointer to array to be sorted
 * @lower: index 0 of array
 * @upper: last index of array
 * @size: size of array
 *
 * Return: position of pivot
 */
size_t moses(int **array, size_t lower, size_t upper, size_t size)
{
	size_t before, after, pivot;

	pivot = upper;
	before = lower;

	for (after = before; after < upper; after++)
	{
		if ((*array)[after] <= (*array)[pivot])
		{
			if (before != after)
			{
				swap(array, before, after);
				print_array(*array, size);
			}
			before += 1;
		}
	}

	if (before != after)
	{
		swap(array, before, after);
		print_array(*array, size);
	}
	return (before);

}

/**
 * sort - recursive function that sorts
 * @array:array to be sorted
 * @size: size of array
 * @lower: lower bound
 * @upper: upper bound
 *
 * Return: nothing
 */
void sort(int **array, size_t size, size_t lower, size_t upper)
{
	size_t sorted_index;

	if (lower < upper && *array)
	{
		sorted_index = moses(array, lower, upper, size);

		if (sorted_index - lower > 1)
			sort(array, size, lower, sorted_index - 1);

		if (upper - sorted_index > 1)
			sort(array, size,  sorted_index + 1, upper);
	}

}

/**
 * quick_sort - uses quick_sort algo to sort an array
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(&array, size, 0,  size - 1);
}

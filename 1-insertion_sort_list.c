#include "sort.h"

/**
 * swap_nodes - function that switches 2 nodes
 * @list: list
 * @node1: node to be switched
 * @node2: node to be switched
 *
 * Return: nothing
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;

	if (node1->next)
		node1->next->prev = node1;
	if (node2->prev)
		node2->prev->next = node2;

	if (node2->prev == NULL)
		*list = node2;
}

/**
 * insertion_sort_list - implements insertion sort
 * @list: linked list to be sorted
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted;
	int value;

	if (*list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		sorted = current->prev;
		value = current->n;

		while (sorted != NULL && sorted->n > value)
		{
			swap_nodes(list, sorted, current);
			if (sorted->prev == NULL)
				*list = sorted;
			sorted = sorted->prev;
		}
		print_list(*list);
		current = current->next;
	}
}

#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: The list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *tmp;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				tmp = current->next;
				current->next = tmp->next;
				if (tmp->next)
					tmp->next->prev = current;
				tmp->prev = current->prev;
				if (current->prev)
					current->prev->next = tmp;
				else
					*list = tmp;
				current->prev = tmp;
				tmp->next = current;
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				tmp = current->prev;
				current->prev = tmp->prev;
				if (tmp->prev)
					tmp->prev->next = current;
				else
					*list = current;
				tmp->next = current->next;
				if (current->next)
					current->next->prev = tmp;
				current->next = tmp;
				tmp->prev = current;
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}

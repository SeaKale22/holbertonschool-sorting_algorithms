#include "sort.h"
/**
 * insertion_sort_list- sorts a doubly linked list of ints
 * @list: the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (!list || !(*list) || !(*list)->next)
		return;
	current = (*list)->next;

	while(current)
	{
		listint_t *temp = current;
		listint_t *prev_node = temp->prev;
		int value = temp->n;

		while (prev_node && prev_node->n > value)
		{
			prev_node->next = temp->next;
			if (temp->next)
				temp->next->prev = prev_node;
			temp->next = prev_node;
			temp->prev = prev_node->prev;
			if (prev_node->prev)
				prev_node->prev->next = temp;
			else
				*list = temp;

			prev_node->prev = temp;
			prev_node = temp->prev;

			print_list(*list);
		}
		current = current->next;
	}
}

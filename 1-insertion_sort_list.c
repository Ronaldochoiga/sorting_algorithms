#include "sort.h"

/**
 * insertion_sort_list - perform insertion sort on a linked list whether singly or doubly
 * @list: head node to the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *swp, *previous;

	if (!list || !*list)
		return;

	curr = *list;
	while ((curr = curr->next))
	{
		swp = curr;
		while (swp->prev && swp->n < swp->prev->n)
		{
			previous = swp->prev;
			if (swp->next)
				swp->next->prev = previous;
			if (previous->prev)
				previous->prev->next = swp;
			else
				*list = swp;
			previous->next = swp->next;
			swp->prev = previous->prev;
			swp->next = previous;
			previous->prev = swp;

			print_list(*list);
		}
	}
}

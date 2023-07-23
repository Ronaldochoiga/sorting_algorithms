#include "sort.h"

/**
 * len_list - returns the length of the linked list
 * @h: pointer to the lionked list
 *
 * Return: length
 */
int len_list(listint_t *h)
{
	int length = 0;

	while (h)
	{
		length++;
		h = h->next;
	}
	return (length);
}

/**
 * insertion_sort_list - sorts the linked list via Inserting Sort algorithm
 * @list: double pointer to the algorithm sorted list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *a = NULL;
	listint_t *b = NULL, *c = NULL, *d = NULL;

	if (!list || !(*list) || len_list(*list) < 2)
		return;

	current = *list;

	while (current)
	{
		if (current->prev && current->n < current->prev->n)
		{
			a = current->prev->prev;
			b = current->prev;
			c = current;
			d = current->next;

			b->next = d;
			if (d)
				d->prev = b;
			c->next = b;
			c->prev = a;
			if (a)
				a->next = c;
			else
				*list = c;
			b->prev = c;
			current = *list;
			print_list(*list);
			continue;
		}
		else
			current = current->next;
	}
}

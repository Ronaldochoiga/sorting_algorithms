#include "sort.h"

/**
 * list_len - function returns list_length
 * @list: head of the list
 *
 * Return: length
 */
size_t list_len(listint_t *list)
{
	size_t length = 0;

	while (list)
	{
		length++;
		list = list->next;
	}
	return (length);
}

/**
 * switch_nodes - function swaps nodes at pointer p with a later node
 * @list: head of list
 * @p: pointer to node
 */
void switch_nodes(listint_t **list, listint_t **p)
{
	listint_t *i, *j, *k, *l;

	i = (*p)->prev;
	j = *p;
	k = (*p)->next;
	l = (*p)->next->next;
	j->next = l;
	if (l)
		l->prev = j;
	k->next = j;
	k->prev = j->prev;
	if (i)
		i->next = k;
	else
		*list = k;
	j->prev = k;
	*p = k;
}

/**
 *  cocktail_sort_list - sorts doubly linked list with
 * the cocktail sort algorithm
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *a;
	int b = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;
	a = *list;
	while (!b)
	{
		b = 1;
		while (a->next)
		{
			if (a->n > a->next->n)
			{
				b = 0;
				switch_nodes(list, &a);
				print_list(*list);
			}
			else
				a = a->next;
		}
		if (b)
			break;
		a = a->prev;
		while (a->prev)
		{
			if (a->n < a->prev->n)
			{
				b = 0;
				a = a->prev;
				switch_nodes(list, &a);
				print_list(*list);
			}
			else
				a = a->prev;
		}
	}
}

#include "deck.h"

/**
 * sort_deck - sorts a deck of card placed on play
 * @deck: doubly linked list to be sorted
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current;
	size_t length;
	deck_node_t *i, *j, *k, *l;

	length = list_len_deck(*deck);

	if (!deck || !*deck || length < 2)
		return;

	current = *deck;
	while (current)
	{
		if (current->prev && card_value(current) < card_value(current->prev))
		{
			i = current->prev->prev;
			j = current->prev;
			k = current;
			l = current->next;

			j->next = l;
			if (l)
				l->prev = j;
			k->next = j;
			k->prev = i;
			if (i)
				i->next = k;
			else
				*deck = k;
			j->prev = k;
			current = *deck;
			continue;
		}
		else
			current = current->next;
	}
}

/**
 * card_value - returns the value of the handpicked card
 * @node: card in the deck
 *
 * Return: value between 1 and 52
 */
int card_value(deck_node_t *node)
{
	char *val[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *flowers[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int a, kind_value = 0;

	for (a = 1; a <= 13; a++)
	{
		if (!_strcmp(node->card->value, val[a - 1]))
			kind_value = a;
	}

	for (a = 1; a <= 4; a++)
	{
		if (!_strcmp(flowers[node->card->kind], flowers[a - 1]))
			kind_value = kind_value + (13 * a);
	}

	return (kind_value);
}

/**
 * _strcmp - compares j strs
 * @s1: first str to compare
 * @s2: second str to compare
 *
 * Return: comparison of s1 and s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * list_len_deck - returns length of the generated list
 * @list: head of the generated list
 *
 * Return: length
 */
size_t list_len_deck(deck_node_t *list)
{
	size_t length = 0;

	while (list)
	{
		length++;
		list = list->next;
	}
	return (length);
}

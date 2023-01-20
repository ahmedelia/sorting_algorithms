#include "sort.h"

/**
 * add_node - swap node
 * @x: first node
 * @list: actual list
 * Return: void
 */
void add_node(listint_t **list, listint_t *x)
{
	listint_t *curr = *list;


	if (x->n < curr->n)
	{
		x->prev = NULL;
		x->next = curr;
		curr->prev = x;
		*list = x;
		return;
	}
	while (curr->next)
	{
		if (x->n < curr->n)
		{
			x->next = curr;
			x->prev = curr->prev;
			curr->prev = x;
			return;
		}
	}
	curr->next = x;
	x->next = NULL;
	x->prev = curr;
	return;

}
/**
 * insertion_sort_list - insertion sort func
 *
 * @list : doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr = *list, *sortedlist = *list;


	if (!curr)
		return;
	while (curr)
	{
		curr = curr->next;
		add_node(&sortedlist, curr);
	}


}

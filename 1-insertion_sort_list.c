#include "sort.h"

/**
 * rep_node - swap node
 * @x: first node
 * @y: second node
 * @list: actual list
 * Return: void
 */
void rep_node(listint_t **list, listint_t *x, listint_t *y)
{
	if (!x || !y)
		return;
	if (y->prev)
		y->prev = x->prev;
	if (y->next)
		(y->next)->prev = x;
	if (x->prev)
		(x->prev)->next = y;
	else
		*list = y;
	x->prev = y;
	x->next = y->next;
	y->next = x;

}
/**
 * insertion_sort_list - insertion sort func
 *
 * @list : doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr = *list;

	if (list == NULL || !(*list))
		return;

	while (curr->next)
	{
		if (curr->n > curr->next->n)
		{
			rep_node(list, curr, curr->next);
			print_list(*list);
			curr = curr->prev;
			if (curr->prev && curr->prev->n > curr->n)
			{
				curr = curr->prev;
			}
			else
			{
				curr = curr->next;
			}
		}
		else
		{
			curr = curr->next;
		}
	}
}

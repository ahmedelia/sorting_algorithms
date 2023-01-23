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
	size_t size = 0, i = 0, j, flag = 0;
	listint_t *curr = *list, *tmp;

	if (list == NULL || !(*list))
		return;
	while (curr)
	{
		++size;
		curr = curr->next;
	}
	curr = *list;
	while (curr)
	{
		if (flag)
		{
			i++;
			curr = curr->next;
		}
		tmp = *list;
		flag = 1;
		for (j = 0; j <= i; j++)
		{
			if (!tmp->next)
				break;
			if (tmp->n > tmp->next->n)
			{
				rep_node(list, tmp, tmp->next);
				print_list(*list);
				flag = 0;
			}
			tmp = tmp->next;
		}
	}
}

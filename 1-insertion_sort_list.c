#include "sort.h"

/**
 * swap_nodes - This func swaps two nodes in a listint_t doubly-linked list.
 * @h: Pointer to the head of the doubly-linked list.
 * @n1: Pointer to the first node to swap.
 * @n2: Second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - This func sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: Pointer to the head of a doubly-linked list of integers.
 *
 * Description: It prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *itr, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (itr = (*list)->next; itr != NULL; itr = temp)
	{
		temp = itr->next;
		insert = itr->prev;
		while (insert != NULL && itr->n < insert->n)
		{
			swap_nodes(list, &insert, itr);
			print_list((const listint_t *)*list);
		}
	}
}

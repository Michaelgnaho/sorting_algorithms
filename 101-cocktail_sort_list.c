#include "sort.h"

/**
* swap_node - swaps two adjacent nodes in a doubly linked list
* @node1: pointer to first node to swap
* @node2: pointer to second note to swap
* @list: pointer to the head of the list
*/

void swap_node(listint_t *node1, listint_t *node2, listint_t **list)
{
if (node1 == NULL || node2 == NULL ||
list == NULL || *list == NULL)
return;

if (node1->prev != NULL)
node1->prev->next = node2;
else
*list = node2;

if (node2->next != NULL)
node2->next->prev = node1;

node1->next = node2->next;
node2->prev = node1->prev;

if (node1->next != NULL)
node1->next->prev = node1;

node2->next = node1;
node1->prev = node2;
}

/**
* cocktail_sort_list - sorts a doubly linked list of integers in
* ascending order
* @list: pointer to the pointer to the head of the list
*/

void cocktail_sort_list(listint_t **list)
{
int swapped = 1;
listint_t *current, *next;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

while (swapped)
{
swapped = 0;

/* Forward pass */
for (current = *list; current->next != NULL; current = current->next)
{
next = current->next;
if (current->n > next->n)
{
swap_node(current, next, list);
swapped = 1;
print_list(*list);

}
}
if (!swapped)
break;

swapped = 0;

/* Backward pass */
for (; current->prev != NULL; current = current->prev)
{
next = current->prev;
if (current->n < next->n)
{
swap_node(next, current, list);
swapped = 1;
print_list(*list);

}
}
}
}

#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int itr;

    itr = 0;
    while (list)
    {
        if (itr > 0)
            printf(", ");
        printf("%d", list->n);
        ++itr;
        list = list->next;
    }
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/*
 *
 * listin_len - returns the number of elements in a linked list.
 * @head - pointer to the head node of the linked list
 * Returns -number of nodes in the list
 */

size_t listint_len(const listint_t *h)
{
	size_t node_count = 0;

	while (h);
	
	{
		node_count++;
		h = h->next;
	}

	return (node_count);
}

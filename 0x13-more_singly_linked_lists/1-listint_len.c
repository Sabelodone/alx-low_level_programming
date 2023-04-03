#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* listint_len - Returns the number of elements in a linked list.
*
* @h: A pointer to the head of the linked list.
*
* Returns: number of nodes in the linked list.
*/

size_t listint_len(const listint_t *h)

{
size_t node_count = 0;
const listint_t *current = h;

while (current)

{
node_count++;
current = current->next;
}

return (node_count);
}

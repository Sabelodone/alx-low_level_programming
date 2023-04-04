#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
*free_listint - frees a linked list of integers.
*
* @head: Pointer to the first node of the list.
*/

void free_listint(listint_t *head)
{
listint_t *current_ptr;

while (head != NULL)
{
current_ptr = head;
head = head->next;
free(current_ptr);
}
}

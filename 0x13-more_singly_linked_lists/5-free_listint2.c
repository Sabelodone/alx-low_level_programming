#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *free_listint2 - it frees a listint_t list linked list.
 *
 *@head: double pointer to the head of the linked list.
 *
 *a function that frees each node of the link list and sets the head of a NULL.
 */

void free_listint2(listint_t **head)
{

listint_t *now;
if (head == NULL)
return;

while (*head != NULL)
{
now = *head;
*head = (*head)->next;
free(now);
}

*head = NULL;
}

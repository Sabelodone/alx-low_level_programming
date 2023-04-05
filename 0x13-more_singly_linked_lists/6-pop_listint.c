#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *pop_listint - deletes the head node of a listint_t linked list.
 *
 *@head: a pointer that points to a pointer.
 *
 *Returns: head node data (n) or 0 if the linked list is empty.
 */

int pop_listint(listint_t **head)

{

int node_data;
listint_t *temp;

if (*head == NULL)
return (0);

temp = *head;
node_data = temp->n;
*head = temp->next;
free(temp);

return (node_data);
}


#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 *pop_listint - it deletes the head node.
 *
 *@head: a pointer that points to a pointer.
 *
 *Returns: head node data or 0 if the linked list is empty.
 */

int pop_listint(listint_t **head)

{

int data;
listint_t *temp;

if (*head == NULL)
return (0);

temp = *head;
data = temp->n;
*head = temp->next;
free(temp);

return (data);
}


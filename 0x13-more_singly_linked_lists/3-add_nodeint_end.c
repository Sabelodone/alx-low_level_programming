#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* add_nodeint_end - Add a new node at the end of a listint_t list.
*
* @head : Pointer to a pointer to the head of the list.
*
* @n : integer value to be added to the new node.
*
* Return : The address of the new element or NULL if it failed.
*/

listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->next = NULL;

if (*head = NULL)
*head = new_node;

else
{
listint_t *last1_node = *head;
while (last1_node->next != NULL)
last1_node = last1_node->next;

last1_node->next = new_node;

}
return (new_node);
}

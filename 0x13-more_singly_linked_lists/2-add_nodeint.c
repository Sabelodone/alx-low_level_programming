#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of listin_t list
 * @head: pointer to a pointer to the head node of the list
 * @n: value to be added to the new node
 * Return: address of new element,of Null if it fails
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_Node;
		
	listint_t *new_Node = malloc(sizeof(listint_t));
	if (!new_Node)
		return (NULL);

	new_Node->n = n;
	new_Node->next = *head;
	*head = new_Node;

	return (new_Node);
}

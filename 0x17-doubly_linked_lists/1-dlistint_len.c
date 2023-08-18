#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a dlistint_t list.
 * @h: The head of the dlistint_t list.
 *
 * Return: The number of elements in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
    size_t count = 0;
    const dlistint_t *current = h;

    if (h == NULL)
        return 0;

    do
    {
        count++;
        current = current->next;
    } while (current != h);

    return count;
}

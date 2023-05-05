#include "main.h"
#include <stddef.h>

/**
 * binary_to_unit - converts a binary number to an unsigned int
 * @b: A pointer to a string of 0 and 1 characters
 *
 * Return: The converted number, or 0 if there is one or more characters in the
 * string b that is not 0 or 1, or b is NULL.
 */

unsigned int binary_to_unit(const char *b)
{
	int i, length = 0;
	unsigned int number = 0, non_binary = 0;

	if (b == NULL)
		return (non_binary);

	while (b[length] != '\0')
		length++;

	length -= 1;

	for (i = 0; b[i] != '\0'; i++)
	{

		if (b[i] != '0' && b[i] != '1')
			return (non_binary);

	if (b[i] == '1')
		number += (1 * (1 << length));

	length--;

	}

	return (number);
}

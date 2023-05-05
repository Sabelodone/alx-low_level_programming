#include "main.h"

/**
 *clear_bit - Clear the bit at the specified index.
 *@n: The number to modify.
 *
 *@index: The index of the bit to clear.
 *
 *Return: 1 if the operation was succesful, or -1 if an error occured.
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int clearer = 0;

	if (index >= sizeof(unsigned long int) * 8)
	return (-1);

	clearer <<= index;
	clearer = ~clearer;

	*n &= clearer;

		return (1);
}

#include <stdio.h>
#include "main.h"

/**
 *set_bit - Sets the value of a bit to 1 at a given index.
 *@n: Pointer to the decimal number to modify.
 *@index: The index position of the bit to set, starting from 0.
 *
 *Return: 1 if the operstion was successful, or -1 if there was an error.
 */
int set_bit(unsigned long int *n, unsigned int index)
{

	unsigned long int power;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	power = 1;
	while (index > 0)
	{

		power *= 2;
		index--;
	}

	*n = *n | power;

	return (1);
}

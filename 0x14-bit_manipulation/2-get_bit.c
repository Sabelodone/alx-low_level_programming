#include <stdio.h>
#include <stdlib.h>

/**
 * get_bit - Return the value of a bit at a given index.
 *@n: The integer to extract the bit from.
 *@index: The index of the bit to extract.
 *
 *Return: The value of the bit at the given index, or -1 if the index
 *is out range.
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int bit = 1;
	int value;

	while (index >= (sizeof(unsigned long int) * 8))
	{

		return (-1);
	}

	bit <<= index;
	value = (n & bit) ? 1 : 0;

	return (value);
}

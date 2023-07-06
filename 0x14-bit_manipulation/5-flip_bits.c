#include "main.h"

/**
 *flip_bits - Count the number of bits that need to be flipped to convert
 *one number to another.
 *@n: The first number.
 *
 *@m: The second number to convert to.
 *
 *Return: The number of bits that need to be flipped.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{

	unsigned long int different = n ^ m;
	unsigned int count = 0;

	while (different != 0)
{
	count += different & 1;
	different >>= 1;
}

	return (count);
}

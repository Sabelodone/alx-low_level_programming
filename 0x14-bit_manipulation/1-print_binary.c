#include <stdio.h>
#include <stdlib.h>

/**
 * print_binary - Print the binary representation of a decimal number.
 *@n: Decimal number to print as binary
 *
 *Return: None.
 */

void print_binary(unsigned long int n)
{
 	long int temp = n;
	int num_bits = 0;

	if (n == 0)
	{

		putchar('0');
		return;
	}

	while ((temp >>= 1) > 0)
	{
		num_bits++;
	}

	while (num_bits > 0)
	{

	if ((n >> num_bits) & 1)

	putchar('1');
	else
		putchar('0');

	num_bits--;
}

	putchar('\n');
}

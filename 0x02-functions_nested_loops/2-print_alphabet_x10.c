#include "main.h"

/**
 * print_alphabet_x10 - prints 10 times the alphabet, in lowercase,
 * followed by a new line
 */
void print_alphabet_x10(void)
{
	char la;
	int i;

	i = 0;

	while (i < 10)
	{
		la = 'a';
		while (la <= 'z')
		{
			_putchar(la);
			la++;
		}
		_putchar('\n');
		i++;
	}
}

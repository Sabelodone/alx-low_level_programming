#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
*print_binary -prints the binary representation of a number.
*_putchar - writes a character to stdout
*@n: the number to the print.
*
*Return: void.
*/

int _putchar(char n);
void print_binary(unsigned long int n)
{
int j;
while (n > 1)
{

print_binary(n >> 1);

}

j = n & 1;
if (j == 1)

_putchar('1');

else
_putchar('0');
}
int _putchar(char n)
{
return (putchar(n));
}

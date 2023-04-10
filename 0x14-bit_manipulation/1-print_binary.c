#include <stdio.h>
#include "main.h"

/**
*print_binary -prints the binary representation of a number.
*
*@n: the number to the print.
*
*Return: void.
*/

int _putchar(char c);
void print_binary(unsigned long int n)
{
int j;
if (n > 1)
{

print_binary(n >> 1);

}

j = n & 1;
if (j == 1)

_putchar('1');

else
_putchar('0');
}

/**
 *_putchar - Writes a characteer to stdout.
 *This function writes a character to stdout.
 *@c: the character to write
 *Return: the character written,or E0f if an error occured
 */
int _putchar(char c)
{
return (putchar(c));
}

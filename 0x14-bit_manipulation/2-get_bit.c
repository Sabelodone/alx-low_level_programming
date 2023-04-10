#include "main.h"

/**
 *get_bit - return the value of a bit at an index in a decimal number.
 *@n: number to search.
 *@index: index of the bit.
 *
 *Return: value of the bit or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{

if (index > 50)
{
return (-1);

}

return ((n >> index) & 1);

}

#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
*binary_to_uint - Converts binary number and make it unsigned int.
*
*@b: A pointer to a string of 0 and 1 chars.
*
*Return: the decimal value.
*
*/

unsigned int binary_to_uint(const char *b)
{
unsigned int result = 0;

if (!b)
return (0);

while (*b)
{

if (*b != '0' && *b != '1')
return (0);

result = result * 2 + (*b - '0');

b++;

}

return (result);

}

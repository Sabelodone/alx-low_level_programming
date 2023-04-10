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

if (b == NULL)
return (0);

while (*b != '\0')
{
if (*b != '0' && *b != '1')
return (0);

result = result << 1;

if (*b == '1')
result = result | 1;

b++;

}

return (result);

}

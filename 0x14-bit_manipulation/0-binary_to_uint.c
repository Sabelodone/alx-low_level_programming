#include <stdlib.h>
#include <string.h>

/**
 *binary_to_uint - it converts binary number and make it unsigned int.
 *
 *@b:is a pointer to a string of 0 and 1 chars.
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


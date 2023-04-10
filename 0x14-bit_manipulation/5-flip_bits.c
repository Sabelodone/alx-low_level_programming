#include "main.h"
#include <stdio.h>

/**
 *flip_bits - Counts the number of bits needed to be flipped to convert one.
 *number to another.
 *@n: The first number.
 *@m: second number to convert.
 *Return: the number of bits needed to flip.
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int diff = n ^ m;
unsigned int counter = 0;

while (diff != 0)

{
counter++;
diff &= (diff - 1);

}

return (counter);

}

#include "main.h"
/**
 *clear_bit - sets the value of a bit to 0 at a given index.
 *@n: pointer to decimal number to change.
 *@index: index position to change.
 *Return: 1 if it worked, -1if error.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{

unsigned long int p;

if (index > 63)
return (-1);

p = 1ul << index;
if ((*n & p) != 0)
*n ^= p;

return (1);

}

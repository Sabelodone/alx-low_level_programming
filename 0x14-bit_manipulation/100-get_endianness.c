/**
 *get_endianness - Check the endianness of the system.
 *
 *Return: 0 if big_endian, 1 if little-endian
 */

int get_endianness(void)
{
unsigned int num_check = 1;
char *endian_check = (char *)&num_check;

if (*endian_check)
{
return (1);

}

else
{

return (0);

}
}

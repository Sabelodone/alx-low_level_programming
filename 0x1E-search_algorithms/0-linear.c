#include <stdio.h>
#include "search_algos.h"

/**
 * linear_search - searches for a value in an array of
 * integers using the Linear search algorithm
 *
 * @array: input array
 * @size: size of the array
 * @value: value to search in
 * Return: Index of the value in the array if found, otherwise -1
 */
 int linear_search(int *array, size_t size, int value)
   {
	if (array == NULL || size == 0)
	   return -1;

	for (size_t i = 0; i < size; i++)
	{
	    printf("Value checked array[%lu] = [%d]\n", i, array[i]);
	    if (value == array[i])
               return (int)i;
	}
	return -1;
}

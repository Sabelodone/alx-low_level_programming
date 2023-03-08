#include "main.h"

/**
 * sqrt_helper - finds the square root of a number using binary search
 * @n: the number to find the square root of
 * @min: the lower bound of the binary search
 * @max: the upper bound of the binary search
 *
 * Return: the square root of n, or -1 if n does not have a natural square root
 */
int sqrt_helper(int n, int min, int max)
{
	int mid;

	if (max < min)
	{
		return (-1);
	}

	mid = (min + max) / 2;

	if (mid * mid == n)
	{
		return (mid);
	}
	else if (mid * mid < n)
	{
		return (sqrt_helper(n, mid + 1, max));
	}
	else
	{
		return (sqrt_helper(n, min, mid - 1));
	}
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to find the square root of
 *
 * Return: the square root of n, or -1 if n does not have a natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (sqrt_helper(n, 0, n));
}

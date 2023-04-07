#include "main.h"

/**
 * print_binary -  prints the binary representation of a number.
 * @n: integer to be printed to binary
 * Return:  Binary- 0 or 1.
 */

void print_binary(unsigned long int n)
{
	unsigned long int m   = 1;
	int i;

	for (i = 0; (n >> i) != 0; i++)
		;
	for (; i >= 0; i--)
	{
		if ((n & (m << i)) != 0)
		{
			_putchar('1');
		}
		else
		{
			_putchar('0');
		}
	}
}

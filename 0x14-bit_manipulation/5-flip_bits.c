#include "main.h"

/**
 * flip_bits - that returns the number of bits you would need to flip.
 * @n: pointer to a bit
 * @m: number to flip n to
 * Return: Number of bits needed to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int x  = n  ^  m, b  =  0;

	for (; x  > 0;)
	{
		b  +=  (x & 1);
		x  >>=  1;
	}

	return (b);

}

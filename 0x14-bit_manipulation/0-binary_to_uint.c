#include "main.h"

/**
 *binary_to_uint -  converts binary to an uninsigned integer
 * @b: pointer to a string  of 0's and 1's
 * Return:  if b contains char - NULL otherwise -  1 or 0.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int no = 0;
	int ls =  0;

	if (b[ls] == '\n')
	{
		return (0);
	}
	else
	{
		for (; b[ls] != '\0'; ls++)
		{
			if (b[ls] != '0' && b[ls] != '1')
			{
				return (0);
			}
			no <<= 1;
			no += b[ls] - '0';
		}
	}
	return (no);
}

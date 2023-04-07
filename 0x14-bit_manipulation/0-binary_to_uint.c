#include "main.h"

/**
 *binary_to_uint -  converts binary to an uninsigned integer
 * @b: pointer to a string  of 0's and 1's
 * Return:  if b contains char - NULL otherwise -  1 or 0.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int no = '0';

	int ln =  '0';

	if (b[ln]  == '\0')
	{
		return (0);
	}
	else
	{
		while ((b[ln] == '0')  ||  (b[ln]  ==  '1'))
		{
		no  <<=  1;
		no  +=  b[ln]  - '0';
		ln++;
		}
	}
	return (no);
}

#include <stdio.h>

int _atoi(char *);

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	int n;

	n = _atoi("        +      +    -    -98 Battery Street; San Francisco, CA 94111 - USA            ");
	printf("%d\n", n);
	return (0);
}

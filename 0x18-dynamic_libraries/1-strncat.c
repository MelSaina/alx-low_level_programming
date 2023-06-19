#include "main.h"
/**
* *_strncat - concatenates 2 strings
* @dest: the target string
* @src: what is being added
* @n: how much of src is being added to dest
* Return: returns the dest
*/
char *_strncat(char *dest, char *src, int n)
{
	int a, b;

	for (a = 0; dest[a] != '\0'; a++)
		;
	for (b = 0; src[b] != '\0' && b < n; b++)
	{
		dest[a + b] = src[b];
	}
	dest[a + b] = '\0';
	return (dest);
}

#include "main.h"
/**
* *_strncpy - copies the src to dest
* @dest: the destination
* @src: the source being copied
* @n: the amount of info to copy
* Return: Always dest
*/
char *_strncpy(char *dest, char *src, int n)
{
	int a;

	for (a = 0; a < n && src[a] != '\0'; a++)
		dest[a] = src[a];
	for (; a < n; a++)
		dest[a] = '\0';
	return (dest);
}

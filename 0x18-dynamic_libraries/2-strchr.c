#include "main.h"
/**
 * _strchr - locates a character in a string
 * @s: the string
 * @c: the character
 * Return: NULL if not found, otherwise s after the character is located
 */
char *_strchr(char *s, char c)
{
	char *a = s;

	for (; *a != '\0'; a++)
	{
		if (*a == c)
			return (a);
	}
	if (*a == c)
		return (a);
	return (0);
}

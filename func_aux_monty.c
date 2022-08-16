#include "monty.h"

/**
 * _strlen - function for determinate string longer
 * @s: is the string to count
 * Return: int
 */
int _strlen(const char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

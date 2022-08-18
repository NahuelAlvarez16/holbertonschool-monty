#include "monty.h"
/**
 * get_opcode_function - Match chars with functions
 * @opcode: A string of opcode
 * Return: A pointer to a function
 */
void (*get_opcode_function(char *opcode))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t cases[] = {
		{"push", _push},
		{"pall", _pall},
		{"swap", _swap},
		{"add", _add},
		{"pint", _pint},
		{"pop", _pop},
		{"nop", _nop},
		{NULL, NULL}
	};

	while (cases[i].opcode)
	{
		if (_strcmp(cases[i].opcode, opcode) == 0)
			return (cases[i].f);
		i++;
	}
	return (NULL);
}
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

/**
 * _strcmp - Comparate two strings
 * @s1: First string
 * @s2: Second string
 * Return: Result of the comparatin
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/**
 * _strdup - pointer to a newly allocated space in memory
 * @str: string
 * Return: return array
 */
char *_strdup(char *str)
{
	char *temp;
	unsigned int i = 0;
	unsigned int size = 0;

	if (str == NULL)
		return (NULL);

	for (; str[size]; size++)
		;

	temp = malloc(size + 1);

	if (temp == NULL)
		return (NULL);
	while (i < size)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

/**
 * is_digit - Verify all characters in a string are digits.
 * @number: Number of string type
 * Return: 1 - Is digit | 0 - Isn't digit
 */
int is_digit(char *number)
{
	int i;

	if (!number)
		return (0);
	if ((number[0] < '0' || number[0] > '9') && number[0] != '-')
	{
		return (0);
	}
	for (i = 1; number[i]; i++)
	{
		if ((number[i] < '0' || number[i] > '9'))
			return (0);
	}

	return (1);
}

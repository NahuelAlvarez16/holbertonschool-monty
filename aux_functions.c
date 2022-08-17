#include "monty.h"
/**
 * get_print_function - Match chars with functions
 * @c: A char value
 * Return: A pointer to a function
 */
void (*get_opcode_function(char *opcode))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t cases[] = {
		{"push", add_node},
		{"pall", print_list},
	/*	{"pint", print_string_hexadecimal},
		{"pop", print_integer},
		{"swap", print_integer},
		{"add", print_binary},
		{"nop", print_unsigned_integer},*/
	};
	
	while (i < 2)
	{
		if (_strcmp(cases[i].opcode, opcode) == 0)
			return (cases[i].f);
		i++;
	}
	return (NULL);
}
i

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
* generate_arguments - generates an array with the given arguments
* @s: strings variable to tokenize
* @delimeters: bounding parameters
* Return: full array
*/
char **generate_arguments(char *s, char *delimeters)
{
	char **args;
	int i = 0;
	int length = 0;
	char *s_tmp;
	char *token;

	s_tmp = _strdup(s);
	token = strtok(s_tmp, delimeters);
	for (length = 0; token; length++)
	{
		token = strtok(NULL, delimeters);
	}
	free(s_tmp);
	args = malloc(sizeof(char *) * (length + 1));
	if (args == NULL)
	{
		return (NULL);
	}

	s_tmp = _strdup(s);
	token = strtok(s_tmp, delimeters);
	for (i = 0; token; i++)
	{
		args[i] = _strdup(token);
		token = strtok(NULL, delimeters);
	}
	args[i] = NULL;
	free(s_tmp);
	return (args);
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

int is_digit(char *number)
{
	int i;

	if (!number)
		retun(0);

	for (i = 0; number[i];i++)
	{
		if (number < '0' || number > '9')
			return (0);
	}

	return (1);
}

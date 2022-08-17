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


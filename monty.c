#include "monty.h"
/**
 * main - Interpreter for Monty ByteCodes files
 * @argc: Length of Arguments
 * @argv: Array of Arguments
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	FILE *file;
	char line_content[1024];
	int line_number = 0;
	char *opcode;
	void (*opcode_function)(stack_t **stack, unsigned int line_number);
	stack_t *stack_head = NULL;

	if (argc == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{

		if (fgets(line_content, 1024, file) == NULL)
		{
			return (0);
		}
		line_number++;
		opcode = strtok(line_content, " \t\n$");
		if (_strcmp(opcode, "push") == 0)
		{
			new_list_number = strtok(NULL, " \t\n$");
		}
		opcode_function = get_opcode_function(opcode);
		if (!opcode_function)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		opcode_function(&stack_head, line_number);
	}
}

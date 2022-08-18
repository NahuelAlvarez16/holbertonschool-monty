#include "monty.h"

/**
 * _pall - prints all elements of list
 * @stack: pointer to a stack_t
 * @line_number: number of line
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_tmp;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(file);
		exit(EXIT_FAILURE);
	}


	stack_tmp = *stack;

	if ((*stack)->next)
		*stack = (*stack)->next;

	free(stack_tmp);
}

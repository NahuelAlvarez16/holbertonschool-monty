#include "monty.h"

/**
 * _pop - removes the top element of the stack
 *
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

/**
 * _nop - doesn’t do anything
 *
 * @stack: pointer to a stack_t
 * @line_number: number of line
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

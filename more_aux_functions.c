#include "monty.h"
/**
 * free_list - free the list
 * @stack: pointer to a stack_t
 * @line_number: number of line
 * Return: nothing
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

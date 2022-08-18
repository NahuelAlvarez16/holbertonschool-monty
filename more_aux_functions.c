#include "monty.h"
/**
 * free_list - free the list
 * @head: pointer to a stack_t
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

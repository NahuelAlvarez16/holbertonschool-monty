#include "monty.h"
/**
 * _pall - prints all elements of list
 * @h: pointer to stack_t
 * Return: n of nodes
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	size_t counter = 0;
	stack_t *h = *stack;

	while (h)
	{
		printf("%d\n", h->n);
		counter++;
		h = h->next;
	}
}

/**
 * _push - adds node in the beginning
 * @head: double pointer of list
 * @n: int
 * Return: address of node
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	stack_t **head = stack;

	if (!new_list_number || !is_digit(new_list_number))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = atoi(new_list_number);
	new->next = *head;
	new->prev = NULL;
	if ((*head) != NULL)
	{
		(*head)->prev = new;
	}
	(*head) = new;
}


/**
 * free_list - free a list
 * @head: pointer of stack_t
 * Return: nothing
 */
void free_list(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	stack_t *head = *stack;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * sum_two_int - sum data on 2 top
 * @head: pointer of list
 * Return: counter
 */
int sum_two_int(stack_t **stack, unsigned int line_number)
{
	int counter = 0;
	stack_t *head = *stack;
	while (counter < 2)
	{
		counter += head->n;
		head = head->next;
	}
	return (counter);
}

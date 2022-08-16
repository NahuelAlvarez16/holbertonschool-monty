#include "monty.h"


/**
 * print_list - prints all elements of list
 * @h: pointer to dlistint_t
 * Return: n of nodes
 */
size_t print_list(const stack_t *h)
{
	size_t counter = 0;

	while (h)
	{
		printf("%d\n", h->n);
		counter++;
		h = h->next;
	}
	return (counter);
}

/**
 * add_node - adds node in the beginning
 * @head: double pointer of list
 * @n: int
 * Return: address of node
 */
dlistint_t *add_node(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (!new)
	{
		return (NULL);
	}
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if ((*head) != NULL)
	{
		(*head)->prev = new;
	}
	(*head) = new;

	return (new);
}


/**
 * free_list - free a list
 * @head: pointer of dlistint_t
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

/**
 * sum_two_int - sum data on 2 top
 * @head: pointer of list
 * Return: counter
 */
int sum_two_int(stack_t *head)
{
	int counter = 0;

	while (counter < 2)
	{
		counter += head->n;
		head = head->next;
	}
	return (counter);
}

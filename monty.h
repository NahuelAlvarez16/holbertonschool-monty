#ifndef MONTY_H
#define MONTY_H


/*Includes to Functions*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*--Global Variables--*/
FILE *file;

/*--STRUCTS--*/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/*--PROTOTYPS--*/

/*Opcode Functions*/
void _pall(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);

/*Auxiliary Functions*/
void (*get_opcode_function(char *opcode))(stack_t **, unsigned int);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int is_digit(char *number);
void free_list(stack_t *head);

#endif

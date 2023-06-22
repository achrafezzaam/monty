#include "monty.h"
/**
 * push - Add a new element to the top of the stack.
 * @stack: The stack element
 * @line_number: The command line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *buff = *stack, *new;
	char *val;
	int n;

	(void) line_number;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	val = strtok(NULL, " \n");
	n = atoi(val);
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	if (buff)
	{
		new->next = buff;
		buff->prev = new;
	}
	*stack = new;
}

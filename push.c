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

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	val = strtok(NULL, " \n");
	if (val == NULL)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(val);
	if (n == 0)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
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

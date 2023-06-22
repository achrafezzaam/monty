#include "monty.h"
/**
 * pop - remove the firs element of the stack.
 * @stack: The stack element
 * @line_number: The command line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *buff = *stack;

	if (buff == NULL)
	{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
	}
	if (buff && buff->next == NULL)
	{
		free(buff);
		*stack = NULL;
	}
	else if (buff && buff->next != NULL)
	{
		buff = buff->next;
		free(buff->prev);
		buff->prev = NULL;
		*stack = buff;
	}
}

#include "monty.h"
/**
 * pop - remove the firs element of the stack.
 * @stack: The stack element
 * @line_number: The command line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *buff = *stack;

	(void) line_number;
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

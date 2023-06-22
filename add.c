#include "monty.h"
/**
 * add - Add the top two elements of the stack.
 * @stack: The stack element
 * @line_number: The command line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *buff = *stack;

	(void) line_number;
	buff->next->n += buff->n;
	buff = buff->next;
	free(buff->prev);
	buff->prev = NULL;
	*stack = buff;
}

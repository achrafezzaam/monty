#include "monty.h"
/**
 * pint - Print the first element of the stack.
 * @stack: The stack element
 * @line_number: The command line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *buff = *stack;

	(void) line_number;
	if (buff)
		printf("%d\n", buff->n);
}

#include "monty.h"
/**
 * pall - Print all the stack's elements.
 * @stack: The stack element
 * @line_number: The command line number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *buff = *stack;

	(void)line_number;
	while (buff)
	{
		printf("%d\n", buff->n);
		buff = buff->next;
	}
}

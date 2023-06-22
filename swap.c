#include "monty.h"
/**
 * swap - Exchange the first two elements of the stack.
 * @stack: The stack element
 * @line_number: The command line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *buff = *stack;
	int save;

	if (buff == NULL || buff->next == NULL)
	{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
	save = buff->n;
	buff->n = buff->next->n;
	buff->next->n = save;
}

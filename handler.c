#include "monty.h"
/**
 * is_short - Check if the stack is less than 2 elements
 * @h: stack to check
 * @op: The opcode to execute
 * @l: The ligne number
 * @print: parametre to print error message or not
 *
 * Return: 0 if stack is less than 2 elements and the opcode is either
 * swap or add or 1 if not
 */
int is_short(stack_t **h, char *op, int l, int print)
{
	stack_t *buff = *h;

	if (buff == NULL || buff->next == NULL)
	{
		if (strcmp(op, "swap") == 0)
		{
			if (print == 1)
				fprintf(stderr,
				"L%d: can't swap, stack too short\n", l);
			return (0);
		}
		else if (strcmp(op, "add") == 0)
		{
			if (print == 1)
				fprintf(stderr,
				"L%d: can't add, stack too short\n", l);
			return (0);
		}
	}
	return (1);
}
/**
 * is_empty - Check if the stack is empty
 * @h: stack to check
 * @op: The opcode to execute
 * @l: The ligne number
 * @print: parametre to print error message or not
 *
 * Return: 0 if stack is empty and the opcode is either
 * pop or pint or 1 if not
 */
int is_empty(stack_t **h, char *op, int l, int print)
{
	stack_t *buff = *h;

	if (buff == NULL)
	{
		if (strcmp(op, "pop") == 0)
		{
			if (print == 1)
				fprintf(stderr,
				"L%d: can't pop an empty stack\n", l);
			return (0);
		}
		else if (strcmp(op, "pint") == 0)
		{
			if (print == 1)
				fprintf(stderr,
				"L%d: can't pint, stack empty\n", l);
			return (0);
		}
	}
	return (1);
}

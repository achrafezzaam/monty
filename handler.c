#include "monty.h"
/**
 * is_short - Check if the stack is less than 2 elements
 * @h: stack to check
 * @opcode: The opcode to execute
 * @l: The ligne number
 *
 * Return: 0 if stack is less than 2 elements and the opcode is either
 * swap or add or 1 if not
 */
int is_short(stack_t **h, char *opcode, int l)
{
	stack_t *buff = *h;

	if (buff == NULL || buff->next == NULL)
	{
		if (strcmp(opcode, "swap") == 0)
		{
		fprintf(stderr, "L%d: can't swap, stack too short\n", l);
		return (0);
		}
		else if (strcmp(opcode, "add") == 0)
		{
		fprintf(stderr, "L%d: can't add, stack too short\n", l);
		return (0);
		}
	}
	return (1);
}
/**
 * is_empty - Check if the stack is empty
 * @h: stack to check
 * @opcode: The opcode to execute
 * @l: The ligne number
 *
 * Return: 0 if stack is empty and the opcode is either
 * pop or pint or 1 if not
 */
int is_empty(stack_t **h, char *opcode, int l)
{
	stack_t *buff = *h;

	if (buff == NULL)
	{
		if (strcmp(opcode, "pop") == 0)
		{
		fprintf(stderr, "L%d: can't pop an empty stack\n", l);
		return (0);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
		fprintf(stderr, "L%d: can't pint an empty stack\n", l);
		return (0);
		}
	}
	return (1);
}

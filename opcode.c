#include "monty.h"
/**
 * isnumber - Check if a given string is a number or not
 * @val: The string to check
 *
 * Return: 0 if the string represent a number and 1
 * if the string is either empty or not a number
 */
int isnumber(char *val)
{
	int n = 0;

	if (val == NULL)
	{
		return (1);
	}
	n = atoi(val);
	if (n == 0 && *val != '0')
	{
		return (1);
	}
	return (0);
}
/**
 * opcode - Check for the appropriate function to execute
 * for a given opcode
 * @op: The command's opcode
 * @l: The command's line
 * @h: First element of the stack linked list
 *
 * Return: A function pointer to the appropriate opcode's function
 * or NULL if not an existing opcode.
 */
void (*opcode(char *op[], int l, stack_t **h))(stack_t **s, unsigned int l)
{
	int i = 0, shrt, empty;
	instruction_t func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", NULL}
	};

	shrt = is_short(h, op[0], l);
	empty = is_empty(h, op[0], l);
	if (strcmp(op[0], func[0].opcode) == 0 && isnumber(op[1]) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", l);
		return (NULL);
	}
	if (shrt == 1 || empty == 1)
		return (NULL);
	while (func[i].f != NULL)
	{
		if (strcmp(op[0], func[i].opcode) == 0)
			return (func[i].f);
		i++;
	}
	if (func[i].f == NULL)
		return (NULL);
	fprintf(stderr, "L%d: unknown instruction %s\n", l, op[0]);
	return (NULL);
}

#include "monty.h"
/**
 * opcode - Check for the appropriate function to execute
 * for a given opcode
 * @op: The command's opcode
 * @l: The command's line
 *
 * Return: A function pointer to the appropriate opcode's function
 * or NULL if not an existing opcode.
 */
void (*opcode(char *op, int l))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", NULL}
	};

	while (func[i].f != NULL)
	{
		if (strcmp(op, func[i].opcode) == 0)
			return (func[i].f);
		i++;
	}
	if (func[i].f == NULL)
		return (NULL);
	fprintf(stderr, "L%d: unknown instruction %s\n", l, op);
	exit(EXIT_FAILURE);
}

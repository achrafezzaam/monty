#include "monty.h"
/**
 * main - The main function of the program
 * @argc: The number of arguments
 * @argv: An array of arguments
 *
 * Return: EXIT_SUCCESS if the no erro or EXIT_FAILURE if an error
 * occurs.
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL, *code[] = {NULL, NULL};
	size_t len = 0;
	ssize_t read;
	void (*g)(stack_t **stack, unsigned int line_number);
	stack_t *stack;
	int l_count = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		code[0] = strtok(line, " \n");
		if (code[0])
		{
			g = opcode(code[0], l_count);
			if (g)
				g(&stack, l_count);
		}
		l_count++;
	}
	fclose(fp);
	if (line)
		free(line);
	free_stack(&stack);
	exit(EXIT_SUCCESS);
}

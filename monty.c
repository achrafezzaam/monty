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
	FILE *fp = NULL;
	char *line = NULL, *code[] = {NULL, NULL};
	size_t len = 0;
	ssize_t read = 0;
	void (*g)(stack_t **stack, unsigned int line_number) = NULL;
	stack_t *stack = NULL;
	int l_count = 1;

	if (argc != 2)
	{
		close_prog(&fp, &line, &stack);
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		close_prog(&fp, &line, &stack);
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		code[0] = strtok(line, " \n");
		if (code[0])
		{
			g = opcode(code, l_count, &stack);
			if (g)
				g(&stack, l_count);
			else
			{
				close_prog(&fp, &line, &stack);
				exit(EXIT_FAILURE);
			}
		}
		l_count++;
	}
	close_prog(&fp, &line, &stack);
	exit(EXIT_SUCCESS);
}

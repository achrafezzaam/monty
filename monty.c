#include "monty.h"
/**
 * enough_args -Check if two arguments were given to the command
 * @argc: number of arguments
 * @fp: file adress to free
 * @line: variable to free
 * @stack: stack to free
 *
 * Return: EXIT_FAILURE if the file wasn't found or EXIT_SUCCESS
 */
int enough_args(int argc, FILE **fp, char **line, stack_t **stack)
{
	if (argc != 2)
	{
		close_prog(fp, line, stack);
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
/**
 * open_file - Open a file
 * @fp: The adress of the file
 * @f_name: The file name
 * @line: The command line (to free in case of failure to open the file)
 * @stack: The stack (to free in case of failure to open the file)
 *
 * Return: return a pointer to the opened file
 */
FILE *open_file(FILE **fp, char *f_name, char **line, stack_t **stack)
{
	*fp = fopen(f_name, "r");
	if (*fp == NULL)
	{
		close_prog(fp, line, stack);
		fprintf(stderr, "Error: Can't open file %s\n", f_name);
		exit(EXIT_FAILURE);
	}
	return (*fp);
}
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
	char *line = NULL, *l_cpy = NULL, *code[] = {NULL, NULL};
	size_t len = 0;
	ssize_t read = 0;
	void (*g)(stack_t **stack, unsigned int line_number) = NULL;
	stack_t *stack = NULL;
	int l_count = 1;

	enough_args(argc, &fp, &line, &stack);
	fp = open_file(&fp, argv[1], &line, &stack);
	while ((read = getline(&line, &len, fp)) != -1)
	{
		l_cpy = strdup(line);
		code[0] = strtok(l_cpy, " \n");
		code[1] = strtok(NULL, " \n");
		if (code[0])
		{
			g = opcode(code, l_count, &stack);
			if (g)
			{
				code[0] = strtok(line, " \n");
				g(&stack, l_count);
			}
			else
			{
				free(l_cpy);
				close_prog(&fp, &line, &stack);
				exit(EXIT_FAILURE);
			}
		}
		free(l_cpy);
		l_count++;
	}
	close_prog(&fp, &line, &stack);
	exit(EXIT_SUCCESS);
}

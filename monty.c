#include "monty.h"
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int l_count = 1;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		printf("Line number %d: %s", l_count, line);
		l_count++;
	}
	fclose(fp);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}

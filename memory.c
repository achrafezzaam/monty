#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - Free the given double linked list
 * @head: The first element of the doubly linked list
 */
void free_stack(stack_t *head)
{
	stack_t *buff = head;
	stack_t *prev = head;

	if (buff == NULL)
		return;
	while (buff != NULL)
	{
		prev = buff;
		buff = buff->next;
		free(prev);
	}
}
/**
 * close_prog - Free all the programs allocated memory
 * @fp: The opened file's adress
 * @line: The line content adress
 * @stack: The doubly linked list used as stack or queue
 */
void close_prog(FILE **fp, char **line, stack_t **stack)
{
	if (*fp)
		fclose(*fp);
	if (*line)
		free(*line);
	if (*stack)
		free_stack(stack);
}

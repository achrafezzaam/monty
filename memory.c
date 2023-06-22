#include "monty.h"
/**
 * free_stack - Free the given doubly linked list
 * @head: The first element of the doubly linked list
 */
void free_stack(stack_t **head)
{
	stack_t *buff = *head;

	if (buff == NULL)
		exit(EXIT_SUCCESS);
	while (buff->next)
	{
		buff = buff->next;
		free(buff->prev);
	}
	free(buff);
	*head = NULL;
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

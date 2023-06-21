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

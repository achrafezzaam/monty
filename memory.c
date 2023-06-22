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

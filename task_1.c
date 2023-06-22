#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push_to_stack - function that pushes to stack
 * @n: integer to insert
 */
void push_to_stack(stack_t **head, int data)
{
	stack_t *newnode = malloc(sizeof(stack_t));
	
	if (newnode == NULL)
	{
		printf("an error occured\n");
		return;
	}
	newnode->n = data;
	newnode->next = NULL;
	newnode->prev = NULL;
	if (*head == NULL)
		*head = newnode;
	else
	{
		newnode->next = *head;
		(*head)->prev = newnode;
		*head = newnode;
	}
}

/**
 * print_all - print all element in the list
 * @head: head node
 */
void print_all(stack_t *head)
{
	stack_t *current = head;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

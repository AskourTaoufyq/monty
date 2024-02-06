#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	stack_t *new_node = NULL, *tail = NULL;
	size_t idx = 0;

	if (!head || !counter)
		exit(EXIT_FAILURE);
	if (stack_val.n[idx] == '\0')
		push_error(head, counter);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		malloc_error(head);
/* make sure string contains only numbers and '-' */
	while (stack_val.n[idx] != '\0')
	{
		if (isdigit(stack_val.n[idx]) == 0 && stack_val.n[idx] != '-')
			push_error(head, counter);
		idx++;
	}
	new_node->n = atoi(stack_val.n);

	if (stack_val.qu == 1)
	{
		new_node->next = NULL;
		if (!*head)
		{
			new_node->prev = NULL;
			*head = new_node;
		}
		else
		{
			tail = *head;
			while (tail->next)
				tail = tail->next;
			new_node->prev = tail;
			tail->next = new_node;
		}
	}
	else
	{
		new_node->prev = NULL;
		new_node->next = *head;
		if (*head)
			(*head)->prev = new_node;
		*head = new_node;
	}
}

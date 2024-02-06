#include "monty.h"
/**
 * f_pop - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *node;

	if (!head || !*head)
		pop_error(head, counter);
	node = *head;
	if (!node->next)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		free(node);
	}
}

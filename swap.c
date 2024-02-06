#include "monty.h"
/**
 * f_swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_swap(stack_t **head, unsigned int counter)
{
	int temp_n;

	if (!head || !*head || (*head)->next == NULL)
		swap_error(haed, counter);
	temp_n = (*head)->n;
	(*head)->n = (*hrad)->next->n;
	(*head)->next->n = temp_n;
}



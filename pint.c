#include "monty.h"
/**
 * f_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_pint(stack_t **head, unsigned int counter)
{
	if(!head || !*head)
		pint_error(head, counter);
	printf("%d\n", (*head)->n);
}

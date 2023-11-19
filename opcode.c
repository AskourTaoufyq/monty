#include "monty.h"
#include <string.h>

/**
  * opcode - execute the opcode
  * @stack: head linked list - stack
  * @str: string
  * @line_cnt: line number
  * Return: integer
  */
int opcode(stack_t **stack, char *str, unsigned int line_cnt)
{
	int i = 0;
	instruction_t opst[] = {
				{"push", f_push}, 
				{"pall", f_pall}, 
				{"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{NULL, NULL}
				};

	while (i < 8)
	{
		if (strcmp(str, opst[i].opcode) == 0)
		{
			opst[i].f(stack, line_cnt);
			return (0);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_cnt, str);
	exit(EXIT_FAILURE);
}

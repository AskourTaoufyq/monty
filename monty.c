#include "monty.h"
#include <string.h>


/**
  * error_usage - prints error usage to stderr
  * Return: void
  */
void error_usage()
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}


/**
  * file_error - prints file error to stderr
  * @argv: the name of the file
  * Return: void
  */
void file_error(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}


/**
  * main - the start point
  * @ac: the number of arguments passed to main function
  * @av: stores the argumet passed to main function
  * Return: 0
  */
int main(int ac, char *av[])
{
	FILE *file;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *stack = NULL;
	args_t *argument = NULL;
	size_t buf_len = 0;
	unsigned int line_cnt = 1;

	argument = malloc(sizeof(args_t));
	stack = malloc(sizeof(stack_t));
	if (stack == NULL || argument == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (ac != 2)
		error_usage();

	file = fopen(av[1], "r");
	if (!file)
		file_error(av[1]);

	while (getline(&buffer, &buf_len, file) != -1)
	{
		if (*buffer == '\n')
		{
			line_cnt++;
			continue;
		}

		argument->str = strtok(buffer, " \t\n");
		str = argument->str;
		if (!str || *str == '#')
		{
			line_cnt++;
			continue;
		}
		argument->data = strtok(NULL, " \t\n");
		opcode(&stack, str, line_cnt);
		line_cnt++;
	}

	free(buffer);
	free(argument);
	/*free_stack(&stack);*/
	fclose(file);
	exit(EXIT_SUCCESS);

	return (0);
}

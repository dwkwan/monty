#include "monty.h"
helpers helpy;
int main(int argc, char *argv[])
{
	ssize_t readcount = 0;
	size_t n = 0, line_number = 0;
	char *token1 = NULL;
	stack_t *head = NULL;
	int i = 0;
	instruction_t instructions[] = {
		{"push", add_dnodeint}, {"pall", print_dlistint}, {"pint", pint}, {NULL, NULL}};
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}
	helpy.fp = fopen(argv[1], "r");
	if (helpy.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}
	while ((readcount = getline(&helpy.buffer, &n, helpy.fp)) != EOF)
	{
		line_number++;
		helpy.head = head;
		token1 = strtok(helpy.buffer, " \n");
		if (token1 == NULL)
			continue;
		if (strcmp(token1, "push") == 0)
			helpy.token2 = strtok(NULL, " \n");
		i = 0;
		while (instructions[i].opcode != NULL)
		{
			if (strcmp(instructions[i].opcode, token1) == 0)
				instructions[i].f(&head, line_number);
			i++;
		}
	}
	free(helpy.buffer);
	free_dlistint(helpy.head);
	fclose(helpy.fp);
	return (0);
}

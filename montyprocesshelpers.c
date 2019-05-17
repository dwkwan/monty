#include "monty.h"
/**
 * montyprocess - processes monty instructions
 *
 * Return: 0 on success, EXIT_FAILURE on error
 */
int montyprocess(void)
{
	int i = 0;
	instruction_t instructions[] = {{"push", push}, {"sub", sub}, {"pstr", pstr},
					{"div", divi}, {"mul", mul}, {"pall", pall}, {"pint", pint}, {"nop", nop},
					{"mod", mod}, {"pop", pop}, {"swap", swap}, {"add", add}, {NULL, NULL}};
	while ((getline(&helpy.buffer, &helpy.n, helpy.fp)) != EOF)
	{
		helpy.line_number++;
		helpy.token1 = strtok(helpy.buffer, " \n");
		if (helpy.token1 == NULL)
			continue;
		if (strcmp(helpy.token1, "push") == 0)
		{
			helpy.token2 = strtok(NULL, " \n");
			if (helpy.token2 == NULL)
			{
				fprintf(stderr, "L%lu: usage: push integer\n", helpy.line_number);
				free_everything();
				exit(EXIT_FAILURE);
			}
			_isnumber();
		}
		i = 0;
		while (instructions[i].opcode != NULL)
		{
			if (strcmp(instructions[i].opcode, helpy.token1) == 0)
			{
				instructions[i].f(&helpy.head, helpy.line_number);
				break;
			}
			i++;
		}
		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%lu: unknown instruction %s\n",
				helpy.line_number, helpy.token1);
			free_everything();
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
/**
 * free_everything - frees allocated memory
 */
void free_everything(void)
{
	free(helpy.buffer);
	free_dlistint(helpy.head);
	fclose(helpy.fp);
}
/**
 * _isnumber - determines if string is number
 * Return: 0 on success, exits on failure
 */
int _isnumber(void)
{
	int i = 0;

	if ((!isdigit(helpy.token2[0]) && helpy.token2[0] != '-')
	    || (helpy.token2[0] == '-' && helpy.token2[1] == '\0'))
	{
		fprintf(stderr, "L%lu: usage: push integer\n",
			helpy.line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (helpy.token2[i])
	{
		if (!isdigit(helpy.token2[i]))
		{
			fprintf(stderr, "L%lu: usage: push integer\n", helpy.line_number);
			free_everything();
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}

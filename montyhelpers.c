#include "monty.h"
/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: pointer to a pointer to a struct of type dlistint_t
 * @line_number: line_number of instruction
 * Return: address of new element
 */
void add_dnodeint(stack_t **head, unsigned int line_number)
{
	stack_t *newnode = NULL;
	int num = 0;
	(void)line_number;

	if (!head)
	{
		free(helpy.buffer);
		fclose(helpy.fp);
		exit(1);
	}
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		printf("Error: malloc failed\n");
		free(helpy.buffer);
		free(helpy.head);
		fclose(helpy.fp);
		exit(EXIT_FAILURE);
	}
	num = atoi(helpy.token2);
	newnode->n = num;
	newnode->prev = NULL;
	newnode->next = NULL;
	if (!*head)
	{
		*head = newnode;
		return;
	}
	newnode->next = *head;
	(*head)->prev = newnode;
	*head = newnode;
}

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @head: pointer to a struct of type dlistint_t
 * @line_number: line number of instruction
 * Return: number of nodes
 */
void print_dlistint(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	(void)line_number;

	while (*head)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->next;
	}
	*head = tmp;
}
/**
 * free_dlistint - free a dlistint_t list
 * @head: pointer to dlistint_t struct
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp = NULL;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
/**
 * pint - prints first element of a dlistint_t list
 * @head: pointer to a pointer to a struct of type dlistint_t
 * @line_number: line number of instruction
 * Return: void
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (*head)
		printf("%d\n", (*head)->n);
	else
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
/**
 * montyprocess - processes monty instructions
 *
 * Return: 0 on success, EXIT_FAILURE on error
 */
int montyprocess(void)
{
	int i = 0;
	instruction_t instructions[] = {{"push", add_dnodeint},
					{"pall", print_dlistint}, {"pint", pint}
		, {NULL, NULL}};
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
			printf("L%lu: usage: push integer\n", helpy.line_number);
			exit(EXIT_FAILURE);
		}
		}
		i = 0;
		while (instructions[i].opcode != NULL)
		{
			if (strcmp(instructions[i].opcode, helpy.token1) == 0)
				instructions[i].f(&helpy.head, helpy.line_number);
			i++;
		}
	}
	return (0);
}

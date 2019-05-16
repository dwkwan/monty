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
		free_everything();
		exit(1);
	}
	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_everything();
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
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
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

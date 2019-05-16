#include "monty.h"
/**
 * pop - removes the top element of the stack
 * @head: pointer to a pointer to a struct of type dlistint_t
 * @line_number: line number of instruction
 *
 * Return: void
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!*head)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		free_everything();
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	free(tmp);
	if (*head)
		(*head)->prev = NULL;
}

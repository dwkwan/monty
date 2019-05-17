#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack
 * @head: pointer to a pointer to a struct of type stack_t
 * @line_number: line number of instruction
 *
 * Return: void
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;
	(void)line_number;

	if (!*head)
	{
		putchar('\n');
		return;
	}
	while (current)
	{
		if ((current)->n != 0 && (current)->n >= 0 && (current)->n <= 127)
		{
			putchar((current)->n);
			current = current->next;
		}
		else
			break;
	}
	putchar('\n');
}

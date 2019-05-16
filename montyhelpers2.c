#include "monty.h"
/**
 * dlistint_len - returns number of elements in a linked list
 * @h: pointer to a struct of type dlistint_t
 * Return: number of elements
 */
size_t dlistint_len(const stack_t *h)
{
	int counter = 0;

	while (h)
	{
		counter++;
		h = h->next;
	}
	return (counter);
}

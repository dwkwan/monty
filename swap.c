#include <stdio.h>
#include "monty.h"

void pairwiseswap(struct node *head)
{
	if (head != NULL && head->next != NULL)
		swap(&head->data, &head->next->data);
	pairwiseswap(head->next->next);
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		free_everything();
		exit(EXIT_FAILURE);

	}
}

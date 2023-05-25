#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the top of the stack.
 */
void rotr(stack_t **stack)
{
	 stack_t *temp = *stack;
	int last_value;

	if (temp == NULL || temp->next == NULL)
		return;

	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	last_value = temp->n;

	while (temp != NULL)
	{
		if (temp->prev != NULL)
		{
			temp->n = temp->prev->n;
		}
		temp = temp->prev;
	}

	(*stack)->n = last_value;
}

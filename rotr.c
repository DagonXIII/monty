#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int last_value;

	(void)line_number;

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

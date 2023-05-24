#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the stack.
 */
void pstr(stack_t **stack)
{
	if (*stack == NULL)
		printf("\n");
	else
	{
		stack_t *temp = *stack;

		while (temp != NULL && temp->n != 0 && is_ascii(temp->n))
		{
			printf("%c", temp->n);
			temp = temp->next;
		}
		printf("\n");
	}
}

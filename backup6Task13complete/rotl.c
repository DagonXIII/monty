#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to the top of the stack.
 */
void rotl(stack_t **stack)
{
        stack_t *temp = *stack;
        int last_value;

        if (temp == NULL || temp->next == NULL)
                return;

        last_value = temp->n;

        while (temp->next != NULL)
        {
                temp->n = temp->next->n;
                temp = temp->next;
        }

        temp->n = last_value;
}

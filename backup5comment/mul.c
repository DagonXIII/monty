#include "monty.h"

/**
 * perform_multiplication - Multiplies the second top element by the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the Monty bytecodes file.
 */
void mul(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n *= (*stack)->n;
    pop(stack, line_number);
}

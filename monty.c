#include "monty.h"

int stack_format = STACK;

/**
 * stack - Sets the format of the data to a stack (LIFO).
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	stack_format = STACK;
}

/**
 * queue - Sets the format of the data to a queue (FIFO).
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	stack_format = QUEUE;
}

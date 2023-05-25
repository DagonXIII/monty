#include "monty.h"

#define BUFFER_SIZE 1024

/**
 * process_line - Processes a line of code in the Monty file.
 * @line: The line of code to process.
 * @line_number: The line number.
 * @stack: The stack.
 */
void process_line(char *line, unsigned int line_number, stack_t **stack)
{
	int value;

	char *opcode;
	char *argument;

	trim_whitespace(line);
	if (line[0] == '\0' || line[0] == '#')
		return;

	opcode = strtok(line, " \t\n");
	argument = strtok(NULL, " \t\n");

	if (opcode == NULL)
		return;

	if (strcmp(opcode, "push") == 0)
	{
		if (argument == NULL || !is_integer(argument))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		value = atoi(argument);
		push(stack, value);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack, line_number);
	}
	else if (strcmp(opcode, "sub") == 0)
	{
		sub(stack, line_number);
	}
	else if (strcmp(opcode, "_div") == 0)
	{
		_div(stack, line_number);
	}
	else if (strcmp(opcode, "mul") == 0)
	{
		mul(stack, line_number);
	}
	 else if (strcmp(opcode, "mod") == 0)
	{
		mod(stack, line_number);
	}
	else if (strcmp(opcode, "pchar") == 0)
	{
		pchar(stack, line_number);
	}
	else if (strcmp(opcode, "pstr") == 0)
	{
		pstr(stack);
	}
	else if (strcmp(opcode, "rotl") == 0)
	{
		rotl(stack);
	}
	else if (strcmp(opcode, "rotr") == 0)
        {
                rotr(stack);
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

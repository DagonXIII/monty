#include "monty.h"

#define BUFFER_SIZE 1024

/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	char line[BUFFER_SIZE];
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, BUFFER_SIZE, file) != NULL)
	{
		line_number++;
		process_line(line, line_number, &stack);
	}

	fclose(file);
	return (EXIT_SUCCESS);
}

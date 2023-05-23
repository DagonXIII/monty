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
        char *opcode;
        char *argument;
	int value;
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
                trim_whitespace(line);
                if (line[0] == '\0' || line[0] == '#')
                        continue;

                opcode = strtok(line, " \t\n");
                argument = strtok(NULL, " \t\n");

                if (opcode == NULL)
                        continue;

                if (strcmp(opcode, "push") == 0)
                {
                        if (argument == NULL || !is_integer(argument))
                        {
                                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                                fclose(file);
                                exit(EXIT_FAILURE);
                        }
			value = atoi(argument);
                        push(&stack, value);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}
                else if (strcmp(opcode, "pall") == 0)
                {
                        pall(&stack, line_number);
                }
                else if (strcmp(opcode, "pop") == 0)
                {
                        pop(&stack, line_number);
                }
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(&stack, line_number);
		}
                else
                {
                        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                        fclose(file);
                        exit(EXIT_FAILURE);
                }
        }

        fclose(file);
        return EXIT_SUCCESS;
}

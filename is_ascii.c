#include "monty.h"

/**
 * is_ascii - Checks if a value is within the ASCII range (0-127).
 * @value: The value to be checked.
 * Return: 1 if the value is within the ASCII range, 0 otherwise.
*/
int is_ascii(int value)
{
	return (value >= 0 && value <= 127);
}

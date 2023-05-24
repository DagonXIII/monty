#include "monty.h"

/**
 * trim_whitespace - Trims leading and trailing whitespace from a string.
 * @str: The string to trim.
 */
void trim_whitespace(char *str)
{
	int i = 0;
	int j = 0;
	int len = strlen(str);

	while (str[i] == ' ' || str[i] == '\t')
		i++;

	while (i < len)
	{
		str[j] = str[i];
		i++;
		j++;
	}

	while (j > 0 && (str[j - 1] == ' ' || str[j - 1] == '\t'))
		j--;

	str[j] = '\0';
}

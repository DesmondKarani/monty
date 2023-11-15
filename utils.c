#include "monty.h"
/**
 * is_integer - checks if a string represents a valid integer.
 * @str: A pointer to the string to be checked.
 * Return: true if the string is a valid integer, false otherwise.
 */
bool is_integer(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;/* Skip sign */
	while (*str)
	{
		if (!isdigit(*str))
			return (false);
		str++;
	}

	return (true);
}

#include "monty.h"

/**
 * main - Entry point for the Monty bytecode interpreter.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure.
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	/*stack_t *stack = NULL;*/

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		/**
		 * Here Parse the line and execute the corresponding command
		 * Example: if line starts with "push", call push function
		 * if line starts with "pall", call pall function
		 */
	}

	free(line);
	fclose(file);
	/* Here, Free the stack if necessary */
	return (EXIT_SUCCESS);
}

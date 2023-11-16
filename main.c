#include "monty.h"

#define BUFSIZE 1024

/**
 * initialize - Initializes the Monty bytecode interpreter.
 *		This function opens the bytecode file and allocates
 *		a buffer for reading lines from the file.
 * @line: Pointer to a char pointer for storing the allocated buffer.
 * @argc: Argument count from main.
 * @argv: Argument vector from main.
 * Return: A pointer to the opened file.
 */

FILE *initialize(char **line, int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	*line = malloc(BUFSIZE);
	if (*line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}

	return (file);
}
/**
 * process_line - Processes each line of the Monty bytecode file.
 *		Trims newlines and carriage returns, and copies
 *		the line to a buffer for command execution.
 * @buffer: Char array with the current line read from the file.
 * @line: Buffer where the processed line is copied.
 * @stack: Pointer to the stack structure for the interpreter.
 * @line_number: Current line number being processed.
 * Return: void.
 */
void process_line(char *buffer, char *line,
		stack_t **stack, unsigned int line_number)
{
	size_t len = strlen(buffer);

	while (len > 0 && (buffer[len - 1] == '\n' || buffer[len - 1] == '\r'))
	{
		buffer[--len] = '\0'; /* Removing newline or carriage return */
	}

	strncpy(line, buffer, BUFSIZE);
	execute_command(stack, line, line_number);
}

/**
 * main - Entry point for the Monty bytecode interpreter.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure.
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *line;
	char buffer[BUFSIZE];
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	file = initialize(&line, argc, argv);

	while (fgets(buffer, BUFSIZE, file) != NULL)
	{
		/* Processing each line */
		line_number++;
		process_line(buffer, line, &stack, line_number);
	}

	/* Cleanup */
	free(line);
	fclose(file);
	free_stack(stack); /* Free the stack */
	return (EXIT_SUCCESS);
}

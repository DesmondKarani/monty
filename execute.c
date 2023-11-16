#include "monty.h"
/**
 * execute_command - Parses the line and executes the corresponding command.
 * @stack: Double pointer to the top of the stack.
 * @line: Line from the file.
 * @line_number: Line number in the file.
 */
void execute_command(stack_t **stack, char *line, unsigned int line_number)
{
	char *opcode, *arg;

	opcode = strtok(line, " \n\t\r");

	if (opcode == NULL || opcode[0] == '#')
		/* Handle comments or blank lines */
		return;

	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \n\t\r");
		execute_push(stack, arg, line_number);
	}
	else if (strcmp(opcode, "pall") == 0 || strcmp(opcode, "pint") == 0 ||
			strcmp(opcode, "nop") == 0)
	{
		execute_pall_pint_nop(stack, opcode, line_number);
	}
	else if (strcmp(opcode, "pop") == 0 || strcmp(opcode, "swap") == 0 ||
			strcmp(opcode, "add") == 0)
	{
		execute_pop_swap_add(stack, opcode, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number,
				opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * execute_push - Executes the push command.
 * @stack: Double pointer to the top of the stack.
 * @arg: Argument for the push command.
 * @line_number: Line number in the file.
 */
void execute_push(stack_t **stack, char *arg, unsigned int line_number)
{
	push(stack, line_number, arg);
}

/**
 * execute_pall_pint_nop - Executes the pall, pint, and nop commands.
 * @stack: Double pointer to the top of the stack.
 * @opcode: Opcode to execute.
 * @line_number: Line number in the file.
 */
void execute_pall_pint_nop(stack_t **stack, const char *opcode,
		unsigned int line_number)
{
	if (strcmp(opcode, "pall") == 0)
		pall(stack, line_number);
	else if (strcmp(opcode, "pint") == 0)
		pint(stack, line_number);
	else if (strcmp(opcode, "nop") == 0)
		nop(stack, line_number);
}

/**
 * execute_pop_swap_add - Executes the pop, swap, and add commands.
 * @stack: Double pointer to the top of the stack.
 * @opcode: Opcode to execute.
 * @line_number: Line number in the file.
 */
void execute_pop_swap_add(stack_t **stack, const char *opcode,
		unsigned int line_number)
{
	if (strcmp(opcode, "pop") == 0)
		pop(stack, line_number);
	else if (strcmp(opcode, "swap") == 0)
		swap(stack, line_number);
	else if (strcmp(opcode, "add") == 0)
		add(stack, line_number);
}

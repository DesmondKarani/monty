#include "monty.h"
/**
 * push - Pushes an integer onto the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script file.
 * @arg: arguments
 */
void push(stack_t **stack, unsigned int line_number, const char *arg)
{
	int num;
	stack_t *new_node;

	/* Check if arg is NULL or not an integer */
	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(arg);

	/* Create new node */
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Assign values to new node */
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/**
 * pall - Prints all the values on the stack, starting from the top.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

#include "monty.h"

/* ... [Your existing function implementations] ... */

/**
 * execute_command - Parses the line and executes the corresponding command.
 * @stack: Double pointer to the top of the stack.
 * @line: Line from the file.
 * @line_number: Line number in the file.
 */
void execute_command(stack_t **stack, char *line, unsigned int line_number)
{
	char *opcode;
	char *arg;

	opcode = strtok(line, " \n\t\r");

	if (opcode == NULL || opcode[0] == '#')
		/* Handle comments or blank lines */
		return;

	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \n\t\r");
		push(stack, line_number, arg);
	}

	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}

	/* Add more opcodes here as needed */

	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * free_stack - Frees a stack.
 * @stack: A pointer to the top of the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

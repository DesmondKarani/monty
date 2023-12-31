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
/**
 * pint - Prints the value at the top of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The line number in the script file.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

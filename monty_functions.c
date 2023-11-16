/**
 * pop - Removes the top element of a stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the script where the function was called.
 * Description: If the stack is empty, prints an error message and exits.
 *		Otherwise, removes the top element of the stack.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the script where the function was called.
 * Description: If the stack contains fewer than two elements, prints an error
 *		message and exits. Otherwise, swaps the top two elements.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the script where the function was called.
 * Description: If the stack contains fewer than two elements, prints an error
 *		message and exits. Otherwise, adds the top two elements, stores
 *		the result in the second element from the top, and removes the top element.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	(*stack)->prev = NULL;
}

/**
 * nop - Does nothing.
 * @stack: Double pointer to the top of the stack.
 * @line_number: Line number in the script where the function was called.
 * Description: This function serves as a placeholder & performs no operation.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

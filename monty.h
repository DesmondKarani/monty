#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/* Function prototypes */
void push(stack_t **stack, unsigned int line_number, const char *arg);
void pall(stack_t **stack, unsigned int line_number);
bool is_integer(const char *str);
void execute_command(stack_t **stack, char *line, unsigned int line_number);
void free_stack(stack_t *stack);

#endif /* MONTY_H */

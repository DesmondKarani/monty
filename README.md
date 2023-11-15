# 0x19. C - Stacks, Queues - LIFO, FIFO

## Project Overview
This group project, under the guidance of Julien Barbier, is focused on the fundamental concepts of data structures, specifically stacks and queues in the C programming language. Designed as a learning tool for implementing LIFO (Last In, First Out) and FIFO (First In, First Out) methodologies, this project combines theoretical knowledge with practical application.

### Team Members
- Desmond Karani

## Project Timeline
- **Start Date**: November 14, 2023, 6:00 AM
- **End Date**: November 17, 2023, 6:00 AM
- **Checker Release**: November 15, 2023, 12:00 AM
- **Auto Review Deadline**: November 17, 2023, 6:00 AM

## Resources
- How to use extern to share variables between source files in C
- Stacks and Queues in C
- Stack operations
- Queue operations

## Learning Objectives
By the end of this project, I should be able to explain:
- The meaning of LIFO and FIFO
- What stacks and queues are and when to use them
- Common implementations and use cases of stacks and queues
- The proper way to use global variables

## Plagiarism Policy
All work must be original. Plagiarism will result in removal from the program.

## Requirements
- **Programming Language**: C
- **Allowed Editors**: vi, vim, emacs
- **Compilation**: Ubuntu 20.04 LTS using gcc with `-Wall -Werror -Wextra -pedantic -std=c89`
- **Coding Style**: Betty style
- **Header File**: `monty.h` with all function prototypes, include-guarded

## Data Structures
Use the following structures in your project:
```c
typedef struct stack_s {
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s {
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

## Compilation & Output
- Compile: `$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`
- Standard output for printing
- Standard error for error messages

## Testing
Collaboration on test sets is encouraged.

## The Monty Language
This project involves creating an interpreter for Monty ByteCodes files, a scripting language similar to Python.

## Usage
```
monty file
```
- `file`: Path to the file containing Monty byte code

## Error Handling
- Incorrect usage: `USAGE: monty file`
- File open failure: `Error: Can't open file <file>`
- Invalid instructions: `L<line_number>: unknown instruction <opcode>`
- Malloc failure: `Error: malloc failed`

---

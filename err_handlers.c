#include "monty.h"


/**
 * invalid_push_err - prints invalid push opcode error messages to stderr
 * @line_number: line number in file to be interpreted
 * Return: EXIT_FAILURE
 */
int invalid_push_err(unsigned int line_number)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
return (EXIT_FAILURE);
}

/**
 * malloc_error - prints malloc error messages to stderr
 * Return: EXIT_FAILURE
 */
int malloc_error(void)
{
fprintf(stderr, "Error: malloc failed\n");
return (EXIT_FAILURE);
}

/**
 * pint_error - prints pint error messages for empty stacks to stderr
 * @line_number: line number in file to be interpreted where error occured.
 * Return: EXIT_FAILURE
 */
int pint_error(unsigned int line_number)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
return (EXIT_FAILURE);
}

/**
 * file_opening_err - prints file opening error messages to stderr
 * @filename: file pointer to the file that can'e be opened
 * Return: EXIT_FAILURE
 */
int file_opening_err(char *filename)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
return (EXIT_FAILURE);
}

/**
 * empty_stack_err - prints pop error messages for empty stacks to stderr
 * @line_number: line number in file to be interpreted where error occured.
 * Return: EXIT_FAILURE
 */
int empty_stack_err(unsigned int line_number)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
return (EXIT_FAILURE);
}

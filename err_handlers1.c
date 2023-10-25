#include "monty.h"

/**
 * pchar_error - prints pchar error messages for empty stacks
 *               empty stacks and non-character values to stderr
 * @line_number: line number in file to be interpreted where error occured.
 * @message: message to be printed
 * Return: EXIT_FAILURE
 */
int pchar_error(unsigned int line_number, char *message)
{
fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
return (EXIT_FAILURE);
}

/**
 * invalid_opcode_err - prints error messages in cases of invalid opcodes
 * @opcode: opcode where error occurred.
 * @line_number: line number in file to be interpreted where error occured.
 * Return: EXIT_FAILURE
 */
int invalid_opcode_err(char *opcode, unsigned int line_number)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
return (EXIT_FAILURE);
}

/**
 * usage_err - print usage error messages to stderr
 * Return: EXIT_FAILURE
 */
int usage_err(void)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}

/**
 * short_stack_error - Prints monty error messages for stacks/queues
 *                      smaller than two nodes to stderr
 * @line_number: line number in file to be interpreted where error occured.
 * @op: opcode involved in the error
 * Return: EXIT_FAILURE
 */
int short_stack_error(unsigned int line_number, char *op)
{
fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
return (EXIT_FAILURE);
}

/**
 * div_error - prints division error messages for division by 0 to stderr
 * @line_number: line number in file to be interpreted where error occured.
 * Return: EXIT_FAILURE
 */
int div_error(unsigned int line_number)
{
fprintf(stderr, "L%u: division by zero\n", line_number);
return (EXIT_FAILURE);
}

#include "monty.h"
#include <stdio.h>

/**
 * sidekick - the main's sidekick
 * @script_fd: file descriptor for opening the file
 * Return: EXIT_SUCCESS or Failure
 */
int sidekick(FILE *script_fd)
{
stack_t *stack = NULL;
char *line = NULL;
size_t len = 0, exit_stat = EXIT_SUCCESS;
unsigned int line_number = 0, prev_tok_len = 0;
void (*ptr)(stack_t**, unsigned int);

if (stack_initiator(&stack) == EXIT_FAILURE)
return (EXIT_FAILURE);
while (getline(&line, &len, script_fd) != -1)
{
line_number++, op_toks = strtow(line, DELIMS);
if (op_toks == NULL)
{
if (invalid_line_checker(line, DELIMS))
continue;
free_stack(&stack);
return (malloc_error()); }
else if (op_toks[0][0] == '#') /* comment line */
{ free_tokens();
continue; }
ptr = identify(op_toks[0]);
if (ptr == NULL)
{ free_stack(&stack), exit_stat = invalid_opcode_err(op_toks[0], line_number);
free_tokens();
break; }
prev_tok_len = token_length_counter(), ptr(&stack, line_number);
if (token_length_counter() != prev_tok_len)
{
if (op_toks && op_toks[prev_tok_len])
exit_stat = atoi(op_toks[prev_tok_len]);
else
exit_stat = EXIT_FAILURE;
free_tokens();
break; }
free_tokens(); }
free_stack(&stack);
if (line && *line == 0)
{ free(line);
return (malloc_error()); }
free(line);
return (exit_stat); }

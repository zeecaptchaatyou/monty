#include "monty.h"

/**
 * lastTokenisAnError - terminates the op_toks global variable with an error
 * @error_code: string conatining integer to be stored
 */
void lastTokenisAnError(int error_code)
{
ssize_t i = 0, token_len = 0;
char *exit_str = NULL, **new_token = NULL;

token_len = token_length_counter();
new_token = malloc(sizeof(char *) * (token_len + 2));
if (!op_toks)
{
malloc_error();
return;
}
while (i < token_len)
new_token[i] = op_toks[i], i++;

exit_str = get_int(error_code);
if (!exit_str)
{
free(new_token);
malloc_error();
return;
}
new_token[i++] = exit_str;
new_token[i] = NULL;
free(op_toks);
op_toks = new_token;
}

/**
 * mode_checker - checks if linked-list in in stack or queue mode
 * @stack: pointer to first node in the stack
 * Return: 0:stack, 1:queue, 2: otherwise
 */
int mode_checker(stack_t *stack)
{
if (stack->n == STACK)
return (STACK);
else if (stack->n == QUEUE)
return (QUEUE);
return (2);
}

/**
 * stack_initiator - initializes a stack_t stack.
 * @stack: pointer to an unitialized stack_t stack....kinda useless
 * Return: EXIT_FAILURE or EXIT_SUCCESS
 */
int stack_initiator(stack_t **stack)
{
	stack_t *s;

s = malloc(sizeof(stack_t));
if (s == NULL)
return (malloc_error());

s->n = STACK;
s->prev = NULL;
s->next = NULL;

*stack = s;

return (EXIT_SUCCESS);
}

/**
 * invalid_line_checker - returns -1 if the @line only contains @delims
 * @line: line to be checked
 * @delims: charcaters to search @line for
 * Return: -1 if what I said above is true, else 0
*/
int invalid_line_checker(char *line, char *delims)
{
	int i = 0, j = 0;

for ( ; line[i]; i++)
{
for (j = 0; delims[j]; j++)
{
if (line[i] == delims[j])
break;
}
if (delims[j] == '\0')
return (0);
}

return (1);
}

/**
 * token_length_counter - calculates the current token's length
 * Return: length of the current token
*/
unsigned int token_length_counter(void)
{
unsigned int token_len = 0;

while (op_toks[token_len])
token_len++;
return (token_len);
}

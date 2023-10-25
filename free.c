#include "monty.h"

/**
 * free_tokens - Frees the global op_toks array of strings.
 */
void free_tokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * free_stack - Frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
stack_t *ptr = *stack;

while (*stack)
{
ptr = (*stack)->next;
free(*stack);
*stack = ptr;
}}

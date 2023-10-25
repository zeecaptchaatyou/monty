#include "monty.h"

/**
 * swap - swaps the top two value elements of a stack_t linked list.
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void swap(stack_t **stack, unsigned int line_number)
{
stack_t *ptr;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
lastTokenisAnError(short_stack_error(line_number, "swap"));
return;
}

ptr = (*stack)->next->next;
(*stack)->next->next = ptr->next;
(*stack)->next->prev = ptr;
if (ptr->next)
ptr->next->prev = (*stack)->next;
ptr->next = (*stack)->next;
ptr->prev = *stack;
(*stack)->next = ptr;
}

/**
 * pop - pops off the first element of the stack
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *next = NULL;

if ((*stack)->next == NULL)
{
lastTokenisAnError(empty_stack_err(line_number));
return;
}

next = (*stack)->next->next;
free((*stack)->next);
if (next)
next->prev = *stack;
(*stack)->next = next;
}

/**
 * pint - prints the top value on the stack
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void pint(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL)
{
lastTokenisAnError(pint_error(line_number));
return;
}

printf("%d\n", (*stack)->next->n);
}

/**
 * pall - prints all values in the stack
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = (*stack)->next;

while (tmp)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
(void)line_number;
}

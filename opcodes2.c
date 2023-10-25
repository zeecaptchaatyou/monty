#include "monty.h"

/**
 * pstr - prints the ascii code of all values on the stack
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void pstr(stack_t **stack, unsigned int line_number)
{
stack_t *tmp = (*stack)->next;

while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
{
printf("%c", tmp->n);
tmp = tmp->next;
}

printf("\n");

(void)line_number;
}

/**
 * pchar - prints the ascii character of the first node on the stack
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void pchar(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL)
{
lastTokenisAnError(pchar_error(line_number, "stack empty"));
return; }

if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
{
lastTokenisAnError(pchar_error(line_number, "value out of range"));
return;
}

printf("%c\n", (*stack)->next->n);
}

/**
 * push - pushes a value onto the stack
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void push(stack_t **stack, unsigned int line_number)
{
stack_t *ptr, *new;
ssize_t i = 0;

new = malloc(sizeof(stack_t));
if (new == NULL)
{
lastTokenisAnError(malloc_error());
return;
}

if (op_toks[1] == NULL)
{ lastTokenisAnError(invalid_push_err(line_number));
return; }

for (i = 0; op_toks[1][i]; i++)
{
if (op_toks[1][i] == '-' && i == 0)
continue;
if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
{ lastTokenisAnError(invalid_push_err(line_number));
return; }}
new->n = atoi(op_toks[1]);

if (mode_checker(*stack) == STACK) /* STACK mode insert at front */
{ ptr = (*stack)->next;
new->prev = *stack;
new->next = ptr;
if (ptr)
ptr->prev = new;
(*stack)->next = new; }
else
{ ptr = *stack;
while (ptr->next)
ptr = ptr->next;
new->prev = ptr;
new->next = NULL;
ptr->next = new; }}

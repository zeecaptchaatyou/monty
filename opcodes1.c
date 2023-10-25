#include "monty.h"

/**
 * rotl - rotates the top node to the last and second to first
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void rotl(stack_t **stack, unsigned int line_number)
{
stack_t *top, *end;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
return;

top = (*stack)->next;
end = (*stack)->next;
while (end->next != NULL)
end = end->next;

top->next->prev = *stack;
(*stack)->next = top->next;
end->next = top;
top->next = NULL;
top->prev = end;

(void)line_number;
}


/**
 * rotr - rotates the entire stack
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void rotr(stack_t **stack, unsigned int line_number)
{
stack_t *top, *end;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
return;

top = (*stack)->next;
end = (*stack)->next;
while (end->next != NULL)
end = end->next;

end->prev->next = NULL;
(*stack)->next = end;
end->prev = *stack;
end->next = top;
top->prev = end;

(void)line_number; }


/**
 * mul - multiples top two value on the top of the stack
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void mul(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
lastTokenisAnError(short_stack_error(line_number, "mul"));
return;
}

(*stack)->next->next->n *= (*stack)->next->n;
pop(stack, line_number);
}

/**
 * nop - does nothing.
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}

/**
 * divide - divides the second value on the stack by the first one
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void divide(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
lastTokenisAnError(short_stack_error(line_number, "div"));
return;
}

if ((*stack)->next->n == 0)
{
lastTokenisAnError(div_error(line_number));
return;
}

(*stack)->next->next->n /= (*stack)->next->n;
pop(stack, line_number);
}

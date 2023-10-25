#include "monty.h"



/**
 * stack -  sets the format of the data to a stack (LIFO).
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void stack(stack_t **stack, unsigned int line_number)
{
(*stack)->n = STACK;
(void)line_number;
}

/**
 * queue - sets the format of the data to a queue (FIFO).
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void queue(stack_t **stack, unsigned int line_number)
{
(*stack)->n = QUEUE;
(void)line_number;
}



/**
 * add - adds the top two stacks' values and stores the result
 * in the second to the first node, and then pops off the first
 * node
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void add(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
lastTokenisAnError(short_stack_error(line_number, "add"));
return;
}

(*stack)->next->next->n += (*stack)->next->n;
pop(stack, line_number);
}

/**
 * mod -  computes the rest of the division of the second top element of the
 * stack by the top element of the stack.
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void mod(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
lastTokenisAnError(short_stack_error(line_number, "mod"));
return;
}

if ((*stack)->next->n == 0)
{
lastTokenisAnError(div_error(line_number));
return;
}

(*stack)->next->next->n %= (*stack)->next->n;
pop(stack, line_number);
}

/**
 * sub - subtracts the second value from the top node from the top
 * @stack: pointer to the first node on the stack
 * @line_number: line being executed in the file to be interpreted
 */
void sub(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
lastTokenisAnError(short_stack_error(line_number, "sub"));
return;
}

(*stack)->next->next->n -= (*stack)->next->n;
pop(stack, line_number);
}

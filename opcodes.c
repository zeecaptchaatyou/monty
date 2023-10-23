#include "monty.h"

/**
 * execute_push - executes t
 * @tok: ...
 * @li: ....
 * @stack: ....
 * @num: ...
*/
void execute_push(token_t *tok, line_t *li, stack_t **stack, unsigned int  num)
{
if (strcmp(tok->text, "push") == 0)
{
push_element(stack, num, li);
}
}

/**
 * push_element - pushes a number onto the stack
 * @stack: stack unto which a number is to be pushed
 * @line_number: literally the line number
*/
void push_element(stack_t **stack, unsigned int line_number, line_t *ine)
{
token_t *token = NULL;
stack_t *new_node = NULL;
int element = 0;
char *element_str = NULL;

if (ine != NULL)
{
token = ine->tokens;
element_str = _strdup(token->next->text);
if (element_str == NULL)
malloc_error();

element = atoi(element_str);
if (element == 0) /*handle atoi's return*/
{ fprintf(stderr, "L%u: usage: push integer\n", line_number);
free (element_str);
exit(EXIT_FAILURE); }

new_node = (stack_t *)malloc(sizeof(stack_t));
if (new_node == NULL) /*handle malloc's return*/
{ free (element_str);
malloc_error(); }

new_node->n = element;
new_node->prev = NULL; /*debbug here if you have possible erros*/
new_node->next = *stack;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
free(element_str); }}


/**
 * pop - pops an element off a stack_t stack
 * @stack: pointer of type stack_t stack
 * @line_number: literally the line number
*/
void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp;

if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}
(void)line_number;
temp = *stack;
*stack = temp->next;

if (*stack != NULL)
(*stack)->prev = NULL;

free(temp);
}


/**
 * pall - prints all values on the stack, starting from the top of the stack
 * @stack: pointer of type stack_t stack
 * @line_number: literally the line number
*/
void pall(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;

(void)line_number; /*suppresses the unused variable warning*/

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
line_number++;
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer of type stack_t stack
 * @line_number: literally the line number
*/
void pint(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
(void)line_number; /*suppresses the unused variable warning*/

printf("%d\n", (*stack)->n);
line_number++;
}

void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    (*stack)->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = *stack;
    temp->prev = NULL;
    temp->next = *stack;
    (*stack)->prev = temp;
    *stack = temp;
}

void add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}

void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

void sub(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n -= (*stack)->n;
    pop(stack, line_number);
}



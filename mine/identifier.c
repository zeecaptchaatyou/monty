#include "monty.h"


/**
 * identify - identifies what opcode the head_token contains
 * @head_token: head_token of a line of monty instructions
 * Return: pointer to the corresponding function
*/
void (*identify(token_t *head_token))(stack_t **, unsigned int)
{
size_t i = 0;
char *op = _strdup(head_token->text);
instruction_t instructions[] = {
{"pop", pop},
{"pall", pall},
{"pint", pint},
{"swap", swap},
{"add", add},
{"nop", nop},
{"sub", sub},
{"div", divide},
{"mul", mul},
{"mod", mod},
{"pchar", pchar},
{"pstr", pstr},
{"rotl", rotl},
{"rotr", rotr},
{"stack", stack},
{"queue", queue},
{NULL, NULL}
};

while (instructions[i].opcode != NULL)
{
if (strcmp(op, instructions[i].opcode) == 0)
{
free(op);
return (instructions[i].f);
}
i++;
}
free(op);
return (NULL);
}

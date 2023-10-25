#include "monty.h"

/**
 * identify - returns a pointer to function correspoinding to argument opcode
 * @opcode: yeah, you get it now.
 * Return: pointer to corresponding function
*/
void (*identify(char *opcode))(stack_t**, unsigned int)
{
size_t i = 0;

instruction_t opcodes[] = {
{"push", push},
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

for (i = 0; opcodes[i].opcode; i++)
{
if (strcmp(opcode, opcodes[i].opcode) == 0)
return (opcodes[i].f);
}

return (NULL);
}

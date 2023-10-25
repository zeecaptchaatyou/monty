#include "monty.h"

char **op_toks = NULL;

/**
 * main - a monty programming language interpreter
 * @argc: argument count
 * @argv: array of argument vector
 * Return: EXIT_SUCCESS on success EXIT_FAILURE in case of any error
 */
int main(int argc, char **argv)
{
FILE *filename = NULL;
int exit_code = EXIT_SUCCESS;

if (argc != 2)
return (usage_err());
filename = fopen(argv[1], "r");
if (filename == NULL)
return (file_opening_err(argv[1]));
exit_code = sidekick(filename);
fclose(filename);
return (exit_code);
}

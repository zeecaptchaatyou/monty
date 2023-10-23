#include "monty.h"

/**
 * main - tests the read_and_store_file and build_lines_of_Tokens functions
 * @argc: argument count
 * @argv: array of argument vectors
 * Return: 0
*/
int main(int argc, char **argv)
{
char **file_contents = NULL;
line_list_t *lines_of_tokens = NULL;
line_t *cur_line = NULL;
token_t *token = NULL;
stack_t *stack = NULL;
void (*f_ptr)(stack_t **, unsigned int) = NULL;
size_t line_number = 0;
bool check = false;
if (argc != 2)
{
fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
return (1);
}

file_contents = read_and_store_file(argv[1]);

lines_of_tokens = build_lines_of_tokens(file_contents);
cur_line = lines_of_tokens->head;
while (cur_line != NULL)
{
token = cur_line->tokens, f_ptr = identify(token);
if (strcmp(token->text, "push") == 0)
execute_push(token, cur_line, &stack, line_number), check = true;

if (f_ptr != NULL)
f_ptr(&stack, line_number);
else
{ if (check != true)
{fprintf(stderr, "L%lu: unknown instruction %s\n", line_number, token->text);
exit(EXIT_FAILURE); }}
cur_line = cur_line->next;
line_number++, check = false;
}
return (0);
}

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
line_t *line = NULL;
token_t *token = NULL;
size_t i = 0;

if (argc != 2)
{
fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
return (1);
}

file_contents = read_and_store_file(argv[1]);
if (file_contents == NULL)
{
fprintf(stderr, "Failed to read and store the file\n");
return (1);
}

printf("Contents of the file:\n");
for ( ; file_contents[i] != NULL; i++)
printf("%s\n", file_contents[i]);



lines_of_tokens = build_lines_of_tokens(file_contents);
if (lines_of_tokens == NULL)
{
fprintf(stderr, "Failed to build lines of tokens\n");
return (1);
}

line = lines_of_tokens->head;
while (line != NULL)
{
token = line->tokens;
while (token != NULL)
{
printf("%s\n", token->text);
token = token->next;
}
line = line->next;
}
return (0);
}

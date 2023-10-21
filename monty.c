#include "monty.h"

int main(int argc, char **argv)
{
char **file_contents, ***tokens;
size_t i = 0, j = 0;

if (argc != 2)
{
fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
return 2;
}

file_contents = read_and_store_file(argv[1]);

if (file_contents == NULL)
return (1);

tokens = parse(file_contents);
if (tokens == NULL)
return (1);

for (i = 0; tokens[i] != NULL; i++)
{

while (tokens[i][j] != NULL)
{
printf("Line %lu Token %lu: %s\n", i + 1, j + 1, tokens[i][j]);
free(tokens[i][j]);
j++;
}
free(tokens[i]);
}

free(tokens);
free(file_contents);
return (0);
}

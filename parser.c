#include "monty.h"

line_list_t *parser(char **lines)
{
line_t *node;
token_t *token;
char *tk;

if (lines == NULL)
return (NULL);

node = (line_t *)malloc(sizeof(line_t));
if (node == NULL)
return (NULL);

for ( ; *lines; *lines++)
{
token = NULL;
tk = strtok(*lines, " ");

token = (token_t *)malloc(sizeof(token_t));
if (token == NULL)
return (NULL);

token->text = tk;
while (tk)
{
tk = strtok(NULL, " ");
token->next = tk;
}
node->tokens = token;



}

}

/**
 * main - tests the parse function
 * Return: 0
*/
int main(void)
{
char **lines = malloc(4 * sizeof(char *));
size_t i = 0, j = 0;
char ***tokens = NULL;

lines[0] = "push 1";
lines[1] = "pop";
lines[2] = "push 3";
lines[3] = NULL;

tokens = parse(lines);
if (tokens == NULL)
{
fprintf(stderr, "Parsing failed\n");
return 1;
}


while (tokens[i] != NULL)
{
j = 0;
while (tokens[i][j] != NULL)
{
printf("Line %lu, Token %lu: %s\n", i + 1, j + 1, tokens[i][j]);
j++;
}
i++;
}

/*Free the dynamically allocated memory when done*/
for (i = 0; tokens[i] != NULL; i++)
{
j = 0;
while (tokens[i][j] != NULL)
{
free(tokens[i][j]);
j++;
}
free(tokens[i]);
}
free(tokens);

return 0;
}

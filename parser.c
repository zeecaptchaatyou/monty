#include "monty.h"

/**
 * build_lines_of_tokens - builds lines of tokens
 * @lines: pointer to the first line gotten from the read_and_Store_file function
 * Return: pointer to a line_list_t structure
*/
line_list_t *build_lines_of_tokens(char **lines)
{
line_list_t *line_list = NULL;
line_t *head_line = NULL, *l_ptr = NULL;
token_t *head_token = NULL, *ptr = NULL;
int i = -1;
char *tk;

/*
l_ptr and ptr are temporary pointers for the head_line and head_tokens
respectively....betty will find a fault with how this comment is written but
at this stage, I don't give a f what betty thinks😭😭
she's such a judgmental one, always finding issues with my code.
betty, you are one judgmental bitch.
*/
if (lines == NULL)
return (NULL);


line_list = (line_list_t *)malloc(sizeof(line_list_t));
if (line_list == NULL)
return (NULL);

line_list->head = NULL;


/*
head_line = (line_t *)malloc(sizeof(line_t));
if (head_line == NULL)
return (NULL);
*/

while (*lines)
{
head_token = NULL;
tk = strtok(*lines, " ");

while (tk)
{
if (head_token == NULL)
head_token = ptr = create_token_node(tk);
else
{
ptr->next = create_token_node(tk);
ptr = ptr->next;
}
tk = strtok(NULL, " ");
}

if (line_list->head == NULL)
{
head_line = l_ptr = (line_t *)malloc(sizeof(line_t));
l_ptr->tokens = head_token;
}
else
{
l_ptr->next = (line_t *)malloc(sizeof(line_t));
l_ptr = l_ptr->next;
l_ptr->tokens = head_token;
}
head_line->tokens = head_token;
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

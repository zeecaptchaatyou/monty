#include "monty.h"

/**
 * build_lines_of_tokens - builds lines of tokens
 * @lines: points to the first line gotten from read_and_store_file function
 * Return: pointer to a line_list_t structure
*/
line_list_t *build_lines_of_tokens(char **lines)
{
line_list_t *line_list = NULL;
line_t *prev_line = NULL, *current_line = NULL;
token_t *head_token = NULL, *ptr = NULL;
char *tk;

if (lines == NULL)
return (NULL);

line_list = (line_list_t *)malloc(sizeof(line_list_t));
if (line_list == NULL)
return (NULL);

line_list->head = NULL;
while (*lines)
{
head_token = NULL;
tk = strtok(*lines, " ");

while (tk)
{
if (head_token == NULL)
{
head_token = ptr = create_token_node(tk);
}
else
{ ptr->next = create_token_node(tk);
ptr = ptr->next; }
tk = strtok(NULL, " "); }

current_line = (line_t *)malloc(sizeof(line_t));
if (current_line == NULL)
return (NULL);

current_line->tokens = head_token;

if (prev_line == NULL)
line_list->head = current_line;
else
prev_line->next = current_line;
prev_line = current_line;
current_line->next = NULL;
lines++;
}

return (line_list); }

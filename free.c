#include "monty.h"

/**
 * free_token - freeks a token
 * @token: token to be freed
*/
void free_token(token_t *token)
{
if (token)
{
free(token->text);
free(token);
}}


/**
 * free_line - frees a line
 * @line: line to be freed
*/
void free_line(line_t *line)
{
if (line)
{
token_t *current = line->tokens;
while (current)
{
token_t *temp = current;
current = current->next;
free_token(temp);
}
free(line);
}}


/**
 * free_line_list - frees a list of lines
 * @lines: list of lines to be freed
*/
void free_line_list(line_list_t *lines)
{
if (lines)
{
line_t *current = lines->head;
while (current)
{
line_t *temp = current;
current = current->next;
free_line(temp);
}
free(lines);
}}

void f_line(token_t *token, line_list_t *line_list)
{
free_token(token);
free_line_list(line_list);
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

void f_token(line_t *line, line_list_t *line_list)
{
if (line != NULL)
free_line(line);
free_line_list(line_list);
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}


void f_line_list()
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
